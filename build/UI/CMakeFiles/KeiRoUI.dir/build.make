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
include UI/CMakeFiles/KeiRoUI.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include UI/CMakeFiles/KeiRoUI.dir/compiler_depend.make

# Include the progress variables for this target.
include UI/CMakeFiles/KeiRoUI.dir/progress.make

# Include the compile flags for this target's objects.
include UI/CMakeFiles/KeiRoUI.dir/flags.make

UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o: UI/KeiRoUI_autogen/mocs_compilation.cpp
UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o -MF CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o -c /home/alsuwazj/KeiRo/build/UI/KeiRoUI_autogen/mocs_compilation.cpp

UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/build/UI/KeiRoUI_autogen/mocs_compilation.cpp > CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.i

UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/build/UI/KeiRoUI_autogen/mocs_compilation.cpp -o CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o: ../UI/src/GraphicsBase.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsBase.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsBase.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsBase.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o: ../UI/src/GraphicsCellItem.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsCellItem.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsCellItem.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsCellItem.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o: ../UI/src/GraphicsPathItem.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsPathItem.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsPathItem.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsPathItem.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o: ../UI/src/GraphicsEdgeItem.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsEdgeItem.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsEdgeItem.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsEdgeItem.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o: ../UI/src/GraphicsPolygonItem.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsPolygonItem.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsPolygonItem.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsPolygonItem.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o: ../UI/src/GraphicsVertexItem.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsVertexItem.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsVertexItem.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsVertexItem.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o: ../UI/src/GraphicsView.cpp
UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o -c /home/alsuwazj/KeiRo/UI/src/GraphicsView.cpp

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/GraphicsView.cpp > CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/GraphicsView.cpp -o CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.s

UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o: UI/CMakeFiles/KeiRoUI.dir/flags.make
UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o: ../UI/src/MainWindow.cpp
UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o: UI/CMakeFiles/KeiRoUI.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o -MF CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o.d -o CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o -c /home/alsuwazj/KeiRo/UI/src/MainWindow.cpp

UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.i"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alsuwazj/KeiRo/UI/src/MainWindow.cpp > CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.i

UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.s"
	cd /home/alsuwazj/KeiRo/build/UI && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alsuwazj/KeiRo/UI/src/MainWindow.cpp -o CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.s

# Object files for target KeiRoUI
KeiRoUI_OBJECTS = \
"CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o" \
"CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o"

# External object files for target KeiRoUI
KeiRoUI_EXTERNAL_OBJECTS =

UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/KeiRoUI_autogen/mocs_compilation.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsBase.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsCellItem.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPathItem.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsEdgeItem.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsPolygonItem.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsVertexItem.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/GraphicsView.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/src/MainWindow.cpp.o
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/build.make
UI/libKeiRoUI.so.1.0: /usr/lib/x86_64-linux-gnu/libQt5Svg.so.5.15.3
UI/libKeiRoUI.so.1.0: /usr/lib/x86_64-linux-gnu/libQt5OpenGL.so.5.15.3
UI/libKeiRoUI.so.1.0: /usr/lib/x86_64-linux-gnu/libQt5Widgets.so.5.15.3
UI/libKeiRoUI.so.1.0: /usr/lib/x86_64-linux-gnu/libQt5Gui.so.5.15.3
UI/libKeiRoUI.so.1.0: /usr/lib/x86_64-linux-gnu/libQt5Core.so.5.15.3
UI/libKeiRoUI.so.1.0: UI/CMakeFiles/KeiRoUI.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alsuwazj/KeiRo/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Linking CXX shared library libKeiRoUI.so"
	cd /home/alsuwazj/KeiRo/build/UI && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/KeiRoUI.dir/link.txt --verbose=$(VERBOSE)
	cd /home/alsuwazj/KeiRo/build/UI && $(CMAKE_COMMAND) -E cmake_symlink_library libKeiRoUI.so.1.0 libKeiRoUI.so.1 libKeiRoUI.so

UI/libKeiRoUI.so.1: UI/libKeiRoUI.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate UI/libKeiRoUI.so.1

UI/libKeiRoUI.so: UI/libKeiRoUI.so.1.0
	@$(CMAKE_COMMAND) -E touch_nocreate UI/libKeiRoUI.so

# Rule to build all files generated by this target.
UI/CMakeFiles/KeiRoUI.dir/build: UI/libKeiRoUI.so
.PHONY : UI/CMakeFiles/KeiRoUI.dir/build

UI/CMakeFiles/KeiRoUI.dir/clean:
	cd /home/alsuwazj/KeiRo/build/UI && $(CMAKE_COMMAND) -P CMakeFiles/KeiRoUI.dir/cmake_clean.cmake
.PHONY : UI/CMakeFiles/KeiRoUI.dir/clean

UI/CMakeFiles/KeiRoUI.dir/depend:
	cd /home/alsuwazj/KeiRo/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alsuwazj/KeiRo /home/alsuwazj/KeiRo/UI /home/alsuwazj/KeiRo/build /home/alsuwazj/KeiRo/build/UI /home/alsuwazj/KeiRo/build/UI/CMakeFiles/KeiRoUI.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : UI/CMakeFiles/KeiRoUI.dir/depend

