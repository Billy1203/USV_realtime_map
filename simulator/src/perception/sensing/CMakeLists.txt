PROJECT(sensing)
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.3)
SET(CMAKE_BUILD_TYPE Release) # Release, RelWithDebInfo
#SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")
ADD_COMPILE_OPTIONS(-std=c++11 )
ADD_COMPILE_OPTIONS(-std=c++14 )

find_package(catkin REQUIRED COMPONENTS
    roscpp 
    roslib  
    pcl_ros 
    sensor_msgs 
    geometry_msgs 
    nav_msgs
)
find_package(Eigen3 REQUIRED)

catkin_package(
    DEPENDS Eigen
    CATKIN_DEPENDS roscpp roslib pcl_ros
)

include_directories(
    SYSTEM 
    ${catkin_INCLUDE_DIRS}
    ${Eigen_INCLUDE_DIRS}.
)

add_executable(
    pcl_node
    src/pointcloud_node.cpp
)

target_link_libraries( pcl_node
    ${catkin_LIBRARIES}
    ${PCL_LIBRARIES}
)
