# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/yiheng/.local/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/yiheng/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/yiheng/Projects/simulator/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/yiheng/Projects/simulator/build

# Utility rule file for otter_gazebo__xacro_auto_generate_to_devel_space_.

# Include any custom commands dependencies for this target.
include simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/compiler_depend.make

# Include the progress variables for this target.
include simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/progress.make

simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_: /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf/otter_gazebo.urdf

/home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf
/home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf/otter_gazebo.urdf: simulator/otter_gazebo/urdf/otter_gazebo.urdf
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yiheng/Projects/simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Copying to devel space: /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf/otter_gazebo.urdf"
	cd /home/yiheng/Projects/simulator/build/simulator/otter_gazebo && /home/yiheng/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E copy_if_different /home/yiheng/Projects/simulator/build/simulator/otter_gazebo/urdf/otter_gazebo.urdf /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf/otter_gazebo.urdf

simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/otter_gazebo.urdf.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_description/urdf/parts.mininertia.urdf.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/sensors/otter_camera.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_description/urdf/materials.urdf.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/sensors/otter_imu.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/sensors/otter_3d_lidar.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/sensors/otter_p3d.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/dynamics/otter_gazebo_wind_plugin.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_description/urdf/propeller.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/sensors/otter_lidar.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/thrusters/otter_gazebo_thruster_plugin.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_description/urdf/otter_base.urdf.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/sensors/otter_gps.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/thrusters/otter_gazebo_thruster_config.xacro
simulator/otter_gazebo/urdf/otter_gazebo.urdf: /home/yiheng/Projects/simulator/src/simulator/otter_gazebo/urdf/dynamics/otter_gazebo_dynamics_plugin.xacro
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yiheng/Projects/simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "xacro: generating urdf/otter_gazebo.urdf from urdf/otter_gazebo.urdf.xacro"
	cd /home/yiheng/Projects/simulator/src/simulator/otter_gazebo && /home/yiheng/Projects/simulator/build/catkin_generated/env_cached.sh xacro -o /home/yiheng/Projects/simulator/build/simulator/otter_gazebo/urdf/otter_gazebo.urdf urdf/otter_gazebo.urdf.xacro

/home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/yiheng/Projects/simulator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "creating dir /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf"
	cd /home/yiheng/Projects/simulator/build/simulator/otter_gazebo && /home/yiheng/.local/lib/python3.8/site-packages/cmake/data/bin/cmake -E make_directory /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf

otter_gazebo__xacro_auto_generate_to_devel_space_: simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_
otter_gazebo__xacro_auto_generate_to_devel_space_: simulator/otter_gazebo/urdf/otter_gazebo.urdf
otter_gazebo__xacro_auto_generate_to_devel_space_: /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf
otter_gazebo__xacro_auto_generate_to_devel_space_: /home/yiheng/Projects/simulator/devel/share/otter_gazebo/urdf/otter_gazebo.urdf
otter_gazebo__xacro_auto_generate_to_devel_space_: simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/build.make
.PHONY : otter_gazebo__xacro_auto_generate_to_devel_space_

# Rule to build all files generated by this target.
simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/build: otter_gazebo__xacro_auto_generate_to_devel_space_
.PHONY : simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/build

simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/clean:
	cd /home/yiheng/Projects/simulator/build/simulator/otter_gazebo && $(CMAKE_COMMAND) -P CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/cmake_clean.cmake
.PHONY : simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/clean

simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/depend:
	cd /home/yiheng/Projects/simulator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/yiheng/Projects/simulator/src /home/yiheng/Projects/simulator/src/simulator/otter_gazebo /home/yiheng/Projects/simulator/build /home/yiheng/Projects/simulator/build/simulator/otter_gazebo /home/yiheng/Projects/simulator/build/simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : simulator/otter_gazebo/CMakeFiles/otter_gazebo__xacro_auto_generate_to_devel_space_.dir/depend

