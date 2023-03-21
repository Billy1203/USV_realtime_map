cmake_minimum_required(VERSION 2.8.3)
project(usv_msgs)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS 
  message_generation 
  std_msgs
  nav_msgs
  geometry_msgs
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

add_message_files(FILES
  ThrustCommand.msg
  MPCCommand.msg
  PolynomialTrajectory.msg
)

add_service_files(
  FILES
  GlbObsRcv.srv
) 

generate_messages(DEPENDENCIES
  std_msgs
  geometry_msgs
  nav_msgs
)

catkin_package(
  CATKIN_DEPENDS message_runtime std_msgs
)
