# USV_realtime_map
Build esdf map for planning in USV_Simulator

启动仿真器
roslaunch usv_launch swarm_scenario.launch


add两个node，1）USV_0/pcl/PointCloud2, 2) USV_0/image

启动键盘控制
roslaunch usv_launch keydrive.launch


启动esdf建图
roslaunch fiesta cow_and_lady.launch
