# Install script for directory: /home/alsuwazj/KeiRo/Base

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
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so.1.0"
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so.1"
      )
    if(EXISTS "${file}" AND
       NOT IS_SYMLINK "${file}")
      file(RPATH_CHECK
           FILE "${file}"
           RPATH "")
    endif()
  endforeach()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/alsuwazj/KeiRo/lib/libKeiRoBase.so.1.0;/home/alsuwazj/KeiRo/lib/libKeiRoBase.so.1")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/alsuwazj/KeiRo/lib" TYPE SHARED_LIBRARY FILES
    "/home/alsuwazj/KeiRo/build/Base/libKeiRoBase.so.1.0"
    "/home/alsuwazj/KeiRo/build/Base/libKeiRoBase.so.1"
    )
  foreach(file
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so.1.0"
      "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so.1"
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
  if(EXISTS "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so")
    file(RPATH_CHECK
         FILE "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so"
         RPATH "")
  endif()
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/alsuwazj/KeiRo/lib/libKeiRoBase.so")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/alsuwazj/KeiRo/lib" TYPE SHARED_LIBRARY FILES "/home/alsuwazj/KeiRo/build/Base/libKeiRoBase.so")
  if(EXISTS "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so" AND
     NOT IS_SYMLINK "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so")
    if(CMAKE_INSTALL_DO_STRIP)
      execute_process(COMMAND "/usr/bin/strip" "$ENV{DESTDIR}/home/alsuwazj/KeiRo/lib/libKeiRoBase.so")
    endif()
  endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/alsuwazj/KeiRo/lib/Base.h;/home/alsuwazj/KeiRo/lib/Color.h;/home/alsuwazj/KeiRo/lib/Common.h;/home/alsuwazj/KeiRo/lib/Config.h;/home/alsuwazj/KeiRo/lib/Coord2.h;/home/alsuwazj/KeiRo/lib/Line2.h;/home/alsuwazj/KeiRo/lib/Rectangle2.h;/home/alsuwazj/KeiRo/lib/Polygon2.h;/home/alsuwazj/KeiRo/lib/Object.h;/home/alsuwazj/KeiRo/lib/Timer.h")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  file(INSTALL DESTINATION "/home/alsuwazj/KeiRo/lib" TYPE FILE FILES
    "/home/alsuwazj/KeiRo/Base/src/Base.h"
    "/home/alsuwazj/KeiRo/Base/src/Color.h"
    "/home/alsuwazj/KeiRo/Base/src/Common.h"
    "/home/alsuwazj/KeiRo/Base/src/Config.h"
    "/home/alsuwazj/KeiRo/Base/src/Coord2.h"
    "/home/alsuwazj/KeiRo/Base/src/Line2.h"
    "/home/alsuwazj/KeiRo/Base/src/Rectangle2.h"
    "/home/alsuwazj/KeiRo/Base/src/Polygon2.h"
    "/home/alsuwazj/KeiRo/Base/src/Object.h"
    "/home/alsuwazj/KeiRo/Base/src/Timer.h"
    )
endif()

