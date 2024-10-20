# Install script for directory: /home/alsuwazj/KeiRo/Graph

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/usr/local")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Debug")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  foreach(file
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so.1.0"
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so.1.0;/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/alsuwazj/KeiRo/lib" TYPE SHARED_LIBRARY FILES
    "/home/alsuwazj/KeiRo/build/Graph/libKeiRoGraph.so.1.0"
    "/home/alsuwazj/KeiRo/build/Graph/libKeiRoGraph.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so.1.0"
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      if(CMAKE_INSTALL_DO_STRIP)
        execute_process(COMMAND "/usr/bin/strip" "${file}")
      endif()
    endif()
  endforeach()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  if(EXISTS "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/alsuwazj/KeiRo/lib" TYPE SHARED_LIBRARY FILES "/home/alsuwazj/KeiRo/build/Graph/libKeiRoGraph.so")
  if(EXISTS "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoGraph.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/alsuwazj/KeiRo/lib/BaseVertexProperty.h;/home/alsuwazj/KeiRo/lib/BaseEdgeProperty.h;/home/alsuwazj/KeiRo/lib/BaseGraphProperty.h;/home/alsuwazj/KeiRo/lib/BaseUndirectedGraph.h;/home/alsuwazj/KeiRo/lib/GridVertexProperty.h;/home/alsuwazj/KeiRo/lib/GridEdgeProperty.h;/home/alsuwazj/KeiRo/lib/GridGraphProperty.h;/home/alsuwazj/KeiRo/lib/GridGraph.h;/home/alsuwazj/KeiRo/lib/SchematicVertexProperty.h;/home/alsuwazj/KeiRo/lib/SchematicEdgeProperty.h;/home/alsuwazj/KeiRo/lib/SchematicGraphProperty.h;/home/alsuwazj/KeiRo/lib/SchematicGraph.h;/home/alsuwazj/KeiRo/lib/TreeEdgeProperty.h;/home/alsuwazj/KeiRo/lib/TreeVertexProperty.h;/home/alsuwazj/KeiRo/lib/TreeGraphProperty.h;/home/alsuwazj/KeiRo/lib/TreeGraph.h;/home/alsuwazj/KeiRo/lib/TreeDirectedGraph.h;/home/alsuwazj/KeiRo/lib/PropertyGraph.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/alsuwazj/KeiRo/lib" TYPE FILE FILES
    "/home/alsuwazj/KeiRo/Graph/src/BaseVertexProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/BaseEdgeProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/BaseGraphProperty.h"
    "/home/alsuwazj/KeiRo/Graph/
        src/BaseUndirectedGraph.h"
    "/home/alsuwazj/KeiRo/Graph/src/GridVertexProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/GridEdgeProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/GridGraphProperty.h"
    "/home/alsuwazj/KeiRo/Graph/
        src/GridGraph.h"
    "/home/alsuwazj/KeiRo/Graph/src/SchematicVertexProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/SchematicEdgeProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/SchematicGraphProperty.h"
    "/home/alsuwazj/KeiRo/Graph/
        src/SchematicGraph.h"
    "/home/alsuwazj/KeiRo/Graph/src/TreeEdgeProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/TreeVertexProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/TreeGraphProperty.h"
    "/home/alsuwazj/KeiRo/Graph/src/TreeGraph.h"
    "/home/alsuwazj/KeiRo/Graph/
        src/TreeDirectedGraph.h"
    "/home/alsuwazj/KeiRo/Graph/src/PropertyGraph.h"
    )
endif()

