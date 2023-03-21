#include <ros/ros.h>
#include <Eigen/Dense>
#include <nav_msgs/Path.h>
#include <nav_msgs/Odometry.h>
#include <sensor_msgs/PointCloud2.h>
#include <pcl/point_cloud.h>
#include <pcl/point_types.h>
#include <pcl/filters/crop_box.h>
#include <pcl/filters/passthrough.h>
#include <pcl/filters/extract_indices.h>
#include <pcl/common/transforms.h> 
#include <pcl/filters/voxel_grid.h>
#include <pcl_conversions/pcl_conversions.h>
#include <pcl/filters/statistical_outlier_removal.h>
#include <tf/transform_listener.h>

#include <chrono>

#include <ros/ros.h>
#include <tf2_ros/transform_broadcaster.h>
#include <geometry_msgs/TransformStamped.h>
#include <tf2/LinearMath/Quaternion.h>

geometry_msgs::TransformStamped transformStamped;

using namespace std;
using namespace Eigen;

ros::Publisher pub_cloud;
ros::Publisher pub_viz_cloud;
ros::Publisher pub_Transform;

ros::Subscriber odom_sub;
ros::Subscriber local_sensing_sub;

shared_ptr<tf::TransformListener> listener_ptr;
tf::StampedTransform tfs;

string namespace_;
double sensor_range;
bool has_odom(false);
bool has_local_sensing(false);

nav_msgs::Odometry _odom;
sensor_msgs::PointCloud2 _local_map_pcd;
pcl::VoxelGrid<pcl::PointXYZ> _voxel_sampler;
pcl::PointCloud<pcl::PointXYZ> _cloud_all_map, _local_map;

void rcvOdometryCallbck(const nav_msgs::Odometry& odom) {
    has_odom = true;
    _odom = odom;
    geometry_msgs::TransformStamped geo_tf;
    geo_tf.header = odom.header;
    geo_tf.transform.translation.x = odom.pose.pose.position.x;
    geo_tf.transform.translation.y = odom.pose.pose.position.y;
    geo_tf.transform.translation.z = odom.pose.pose.position.z;
    geo_tf.transform.rotation = odom.pose.pose.orientation;
    pub_Transform.publish(geo_tf);
}

pcl::PointCloud<pcl::PointXYZ> PointCloudRange(pcl::PointCloud<pcl::PointXYZ>& pc) {
    float angle_min, angle_max, range_min, range_max, angle_increment;

    angle_min = -M_PI;
    angle_max = M_PI;
    range_min = 1.5;
    range_max = 40;
    int beam_size = 800;// 1200差不多40m分辨率0.2
    angle_increment = (angle_max - angle_min)/beam_size;

    pcl::PointCloud<pcl::PointXYZ> output;
    pcl::PointXYZ new_point;
    vector<float> ranges_local;
    vector<float> height;
    ranges_local.assign(beam_size, range_max);
    height.assign(beam_size, -1);

    float range, angle;
    int index;
    float tw_x = _odom.pose.pose.position.x;
    float tw_y = _odom.pose.pose.position.y;
    for(auto point : pc) {
        range = hypot(point.y - tw_y, point.x - tw_x);
        angle = atan2(point.y - tw_y, point.x - tw_x);
        
        index = static_cast<int>((angle - angle_min)/angle_increment);
        if(index >= 0 && index < beam_size) {
            if(range < ranges_local[index] && range > range_min) {
                height[index] = point.z;
                ranges_local[index] = range;
            }
        }
    }
    vector<float> temp = ranges_local;
    for(size_t i = 0; i < ranges_local.size(); i++) {
        if(temp[i] == range_max) {
            int nan_num = 0, need_nan = 5;
            float ranges_sum = 0;
            bool front = false, back = false;
            for(int j = 0; j < need_nan; j++) {
                int ind_f = i+j >= ranges_local.size() ? i+j - ranges_local.size() : i+j;
                int ind_b = i-j < 0 ? ranges_local.size() + i-j : i-j;
                
                if(front) {
                    if(temp[ind_f] == range_max)
                        nan_num ++;
                    else {
                        ranges_sum = temp[ind_f];
                        front = false;
                    }
                }
                if(back) {
                    if(temp[ind_b] == range_max)
                        nan_num ++;
                    else{
                        ranges_sum = temp[ind_b];
                        back = false;
                    }
                }
                if(!front && !back) {
                    if(temp[ind_f] == range_max) {
                        nan_num ++;
                        front = true;
                    }
                    else 
                        ranges_sum = temp[ind_f];
                    
                    if(temp[ind_b] == range_max) {
                        nan_num ++;
                        back = true;
                    }
                    else
                        ranges_sum = temp[ind_b];
                }
                if(!front && !back)
                    break;
            }
            if(nan_num < need_nan) {
                ranges_local[i] = ranges_sum;
            }
        }
    }
    // range 从anglemin开始
    for(size_t i = 0; i<ranges_local.size(); i++) {
        angle = angle_min + angle_increment * i;
        new_point.x = ranges_local[i] * cos(angle) + tw_x;
        new_point.y = ranges_local[i] * sin(angle) +tw_y;
        new_point.z = height[i];
        output.push_back(new_point);
    }
    return output;
}
sensor_msgs::PointCloud2 publishVizCloud(pcl::PointCloud<pcl::PointXYZ>& c_in) {
    pcl::CropBox<pcl::PointXYZ> region; 
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>());
    region.setMin(Eigen::Vector4f(-sensor_range, -sensor_range, -3, 0));
    region.setMax(Eigen::Vector4f(sensor_range, sensor_range, 3.0, 255));
    region.setInputCloud(c_in.makeShared());
    region.filter(*cloud_out);
    // local to global
    pcl::PointCloud<pcl::PointXYZ> g_c;
    Eigen::Quaterniond q;
    q.x() = _odom.pose.pose.orientation.x;
    q.y() = _odom.pose.pose.orientation.y;
    q.z() = _odom.pose.pose.orientation.z;
    q.w() = _odom.pose.pose.orientation.w;
    Eigen::Matrix3d rot;
    rot = q;
    Eigen::Matrix4d tf_btol;
    Eigen::Translation3d tl_btol(tfs.getOrigin().x(), tfs.getOrigin().y(), tfs.getOrigin().z());
    tf_btol = (tl_btol * rot).matrix();
    pcl::transformPointCloud(*cloud_out,g_c,tf_btol);
    
    // 水面去除
    region.setMin(Eigen::Vector4f(-100, -100, 0.25, 0));
    region.setMax(Eigen::Vector4f(100, 100, 3.0, 255));
    region.setInputCloud(g_c.makeShared());
    region.filter(*cloud_out);
    cloud_out->width = cloud_out->points.size();
    cloud_out->height = 1;
    cloud_out->is_dense = true;

    sensor_msgs::PointCloud2 viz_c;
    pcl::toROSMsg(*cloud_out, viz_c);
    return viz_c;
}

void rcvLocalPointCloudCallBack(const sensor_msgs::PointCloud2& pointcloud_map) {
    // auto t1 = std::chrono::high_resolution_clock::now();
    has_local_sensing = true;
    _local_map.points.clear();

    try {
        listener_ptr->waitForTransform("map", pointcloud_map.header.frame_id, ros::Time(0), ros::Duration(0.3));
        listener_ptr->lookupTransform("map", pointcloud_map.header.frame_id, ros::Time(0), tfs);
    }
    catch(tf::TransformException &ex)
    {
        ROS_ERROR("[pc_process]:%s",ex.what());
        return;
    }

    pcl::PointCloud<pcl::PointXYZ> cloud_input;
    pcl::fromROSMsg(pointcloud_map, cloud_input);
    sensor_msgs::PointCloud2 viz_cloud = publishVizCloud(cloud_input);
    viz_cloud.header.frame_id = "map";
    pub_viz_cloud.publish(viz_cloud);

    // 降采样
    _voxel_sampler.setLeafSize(0.2f, 0.2f, 0.2f);
    _voxel_sampler.setInputCloud(cloud_input.makeShared());
    _voxel_sampler.filter(_cloud_all_map);
    // 区域提取
    pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_out (new pcl::PointCloud<pcl::PointXYZ>());
    pcl::CropBox<pcl::PointXYZ> region; 
    region.setNegative(false);
    region.setMin(Eigen::Vector4f(-40, -40, -3,0));
    region.setMax(Eigen::Vector4f(40, 40, 3.0,255));
    region.setInputCloud(_cloud_all_map.makeShared());
    region.filter(*cloud_out);
    _cloud_all_map = *cloud_out;

    // local to global
    Eigen::Quaterniond q;
    q.x() = _odom.pose.pose.orientation.x;
    q.y() = _odom.pose.pose.orientation.y;
    q.z() = _odom.pose.pose.orientation.z;
    q.w() = _odom.pose.pose.orientation.w;
    Eigen::Matrix3d rot;
    rot = q;
    Eigen::Matrix4d tf_btol;
    Eigen::Translation3d tl_btol(tfs.getOrigin().x(), tfs.getOrigin().y(), tfs.getOrigin().z());
    tf_btol = (tl_btol * rot).matrix();
    pcl::transformPointCloud(_cloud_all_map,_local_map,tf_btol);
    
    // 水面去除
    region.setMin(Eigen::Vector4f(-100, -100, 0.5, 0));
    region.setMax(Eigen::Vector4f(100, 100, 3.0, 255));
    region.setInputCloud(_local_map.makeShared());
    region.filter(*cloud_out);
    _local_map = *cloud_out;
    _local_map.width = _local_map.points.size();
    _local_map.height = 1;
    _local_map.is_dense = true;
    // pcl::PointCloud<pcl::PointXYZ>::Ptr cloud_filtered_inliers (new pcl::PointCloud<pcl::PointXYZ>);  
    // // Create the filtering object
    // pcl::StatisticalOutlierRemoval<pcl::PointXYZ> sor;
    // sor.setInputCloud (_local_map.makeShared());  //设置输入
    // sor.setMeanK (15);  //设置用于平均距离估计的 KD-tree最近邻搜索点的个数.
    // sor.setStddevMulThresh (1.0); //高斯分布标准差的倍数, 也就是 u+1*sigma,u+2*sigma,u+3*sigma 中的 倍数1、2、3 
    // sor.filter (*cloud_filtered_inliers); // 滤波后输出 

    // 平面range处理
    // pcl::PointCloud<pcl::PointXYZ> map_pc = PointCloudRange(*cloud_filtered_inliers);
    pcl::PointCloud<pcl::PointXYZ> map_pc = PointCloudRange(_local_map);
    pcl::toROSMsg(map_pc, _local_map_pcd);
    _local_map_pcd.header.frame_id = "map";

    pub_cloud.publish(_local_map_pcd);

    // auto t2 = std::chrono::high_resolution_clock::now();
	// std::chrono::duration<double> pc_process = t2 - t1;
	// std::cout << "pc_process: " << pc_process.count() * 1e3 << " ms\n";
}

int main(int argc, char** argv) {
    ros::init(argc, argv, "pcl_node");
    ros::NodeHandle nh("~");
    nh.param("namespace", namespace_, std::string("USV_0"));
    nh.param("sensor_range", sensor_range, 20.0);

    // subscribe point cloud
    local_sensing_sub = nh.subscribe("local_sensing", 1, rcvLocalPointCloudCallBack);
    odom_sub = nh.subscribe("odometry", 50, rcvOdometryCallbck);

    // publisher depth image and color image
    pub_cloud = nh.advertise<sensor_msgs::PointCloud2>("pcl_node/cloud", 10);
    pub_viz_cloud = nh.advertise<sensor_msgs::PointCloud2>("/viz_cloud", 10);
    pub_Transform = nh.advertise<geometry_msgs::TransformStamped>("Transform_esdf", 10);
    
    listener_ptr.reset(new tf::TransformListener(nh));
    listener_ptr->setExtrapolationLimit(ros::Duration(0.1));


    ros::spin();
}