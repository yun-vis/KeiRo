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

# Include any dependencies generated for this target.
include Geometry/CMakeFiles/KeiRoGeometry.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include Geometry/CMakeFiles/KeiRoGeometry.dir/compiler_depend.make

# Include the progress variables for this target.
include Geometry/CMakeFiles/KeiRoGeometry.dir/progress.make

# Include the compile flags for this target's objects.
include Geometry/CMakeFiles/KeiRoGeometry.dir/flags.make

Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o: Geometry/CMakeFiles/KeiRoGeometry.dir/flags.make
Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o: ../Geometry/src/Voronoi.cpp
Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o: Geometry/CMakeFiles/KeiRoGeometry.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o"
	cd /home/alsuwazj/KeiRo/build/Geometry && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o -MF CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o.d -o CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o -c /home/alsuwazj/KeiRo/Geometry/src/Voronoi.cpp

Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.i"
	cd /home/alsuwazj/KeiRo/build/Geometry && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/Geometry/src/Voronoi.cpp > CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.i

Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.s"
	cd /home/alsuwazj/KeiRo/build/Geometry && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/Geometry/src/Voronoi.cpp -o CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.s

# Object files for target KeiRoGeometry
KeiRoGeometry_OBJECTS = \
"CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o"

# External object files for target KeiRoGeometry
KeiRoGeometry_EXTERNAL_OBJECTS =

Geometry/libKeiRoGeometry.so.1.0: Geometry/CMakeFiles/KeiRoGeometry.dir/src/Voronoi.cpp.o
Geometry/libKeiRoGeometry.so.1.0: Geometry/CMakeFiles/KeiRoGeometry.dir/build.make
Geometry/libKeiRoGeometry.so.1.0: /usr/lib/x86_64-linux-gnu/libgmpxx.so
Geometry/libKeiRoGeometry.so.1.0: /usr/lib/x86_64-linux-gnu/libmpfr.so
Geometry/libKeiRoGeometry.so.1.0: /usr/lib/x86_64-linux-gnu/libgmp.so
Geometry/libKeiRoGeometry.so.1.0: Geometry/CMakeFiles/KeiRoGeometry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libKeiRoGeometry.so"
	cd /home/alsuwazj/KeiRo/build/Geometry && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KeiRoGeometry.dir/link.txt --verbose=$(VERBOSE)
	cd /home/alsuwazj/KeiRo/build/Geometry && $(CMAKE_COMMAND) -E cmake_symlink_library libKeiRoGeometry.so.1.0 libKeiRoGeometry.so.1 libKeiRoGeometry.so

Geometry/libKeiRoGeometry.so.1: Geometry/libKeiRoGeometry.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate Geometry/libKeiRoGeometry.so.1

Geometry/libKeiRoGeometry.so: Geometry/libKeiRoGeometry.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate Geometry/libKeiRoGeometry.so

# Rule to build all files generated by this target.
Geometry/CMakeFiles/KeiRoGeometry.dir/build: Geometry/libKeiRoGeometry.so
.PHONY : Geometry/CMakeFiles/KeiRoGeometry.dir/build

Geometry/CMakeFiles/KeiRoGeometry.dir/clean:
	cd /home/alsuwazj/KeiRo/build/Geometry && $(CMAKE_COMMAND) -P CMakeFiles/KeiRoGeometry.dir/cmake_clean.cmake
.PHONY : Geometry/CMakeFiles/KeiRoGeometry.dir/clean

Geometry/CMakeFiles/KeiRoGeometry.dir/depend:
	cd /home/alsuwazj/KeiRo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alsuwazj/KeiRo /home/alsuwazj/KeiRo/Geometry /home/alsuwazj/KeiRo/build /home/alsuwazj/KeiRo/build/Geometry /home/alsuwazj/KeiRo/build/Geometry/CMakeFiles/KeiRoGeometry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : Geometry/CMakeFiles/KeiRoGeometry.dir/depend

