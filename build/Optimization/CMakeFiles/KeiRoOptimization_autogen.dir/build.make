# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/alsuwazj/KeiRo

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alsuwazj/KeiRo/build

# Utility rule file for KeiRoOptimization_autogen.

# Include any custom commands dependencies for this target.
include Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/progress.make

Optimization/CMakeFiles/KeiRoOptimization_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target KeiRoOptimization"
	cd /home/alsuwazj/KeiRo/build/Optimization && /usr/bin/cmake -E cmake_autogen /home/alsuwazj/KeiRo/build/Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/AutogenInfo.json Debug

KeiRoOptimization_autogen: Optimization/CMakeFiles/KeiRoOptimization_autogen
KeiRoOptimization_autogen: Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/build.make
.PHONY : KeiRoOptimization_autogen

# Rule to build all files generated by this target.
Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/build: KeiRoOptimization_autogen
.PHONY : Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/build

Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/clean:
	cd /home/alsuwazj/KeiRo/build/Optimization && $(CMAKE_COMMAND) -P CMakeFiles/KeiRoOptimization_autogen.dir/cmake_clean.cmake
.PHONY : Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/clean

Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/depend:
	cd /home/alsuwazj/KeiRo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alsuwazj/KeiRo /home/alsuwazj/KeiRo/Optimization /home/alsuwazj/KeiRo/build /home/alsuwazj/KeiRo/build/Optimization /home/alsuwazj/KeiRo/build/Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Optimization/CMakeFiles/KeiRoOptimization_autogen.dir/depend

