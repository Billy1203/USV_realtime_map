cmake_minimum_required(VERSION 2.8.3)
project(usv_launch)

set(CMAKE_CXX_FLAGS "-std=c++11 ${CMAKE_CXX_FLAGS} -O3 -Wall")

find_package(catkin REQUIRED COMPONENTS 
  roscpp
)

include_directories(
  ${catkin_INCLUDE_DIRS}
  include
)

catkin_package(
  CATKIN_DEPENDS roscpp
)
