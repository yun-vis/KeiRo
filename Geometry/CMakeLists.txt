cmake_minimum_required( VERSION 3.10 )
PROJECT( Geometry VERSION 1.0 DESCRIPTION "The Geometry module of the KeiRo package")
set( Target_Name KeiRoGeometry )

#include(GNUInstallDirs)
message( "GNUInstallDirs: " ${GNUInstallDirs} )

set( MAIN_PROJECT_ROOT "${CMAKE_SOURCE_DIR}/.." )

add_library(${Target_Name} SHARED
        src/Voronoi.cpp
        )

set_target_properties(${Target_Name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER "src/Voronoi.h;src/Seed.h"
        )

#----------------------------------------------------------------------
# path setting
#----------------------------------------------------------------------

target_include_directories(${Target_Name}
        PUBLIC
        /opt/local/include/
        ${CMAKE_SOURCE_DIR}/Base/src/
        )

link_directories(${Target_Name}
        PUBLIC
        /opt/local/lib/
        ${CMAKE_BINARY_DIR}/Base/
        )
set( CUSTOM_LIBRARIES "")
set( CUSTOM_LIBRARIES "-lmpfr")
#set( CUSTOM_LIBRARIES "-lKeiRoBase -lboost_thread-mt -lgmp -lcgal -lmpfr")
target_link_libraries(${Target_Name} PUBLIC ${CUSTOM_LIBRARIES})

#----------------------------------------------------------------------
# Boost
#----------------------------------------------------------------------
set(Boost_USE_STATIC_LIBS OFF)
set(Boost_USE_MULTITHREADED ON)
set(Boost_USE_STATIC_RUNTIME OFF)
find_package(Boost)

if(Boost_FOUND)
    message(STATUS "-- Linking boost")
    include_directories(${Boost_INCLUDE_DIRS})
    target_link_libraries(${Target_Name} ${Boost_LIBRARIES})
endif()

#----------------------------------------------------------------------
# CGAL
#----------------------------------------------------------------------
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)
find_package(CGAL REQUIRED COMPONENTS Core)
#set( CMAKE_BUILD_TYPE Release)

if(CGAL_FOUND)
    message(STATUS "-- LinkingCGAL")
    include_directories(${CGAL_INCLUDE_DIRS})
#    message("TEST " ${CGAL_INCLUDE_DIRS})
    target_link_libraries(${Target_Name} ${CGAL_LIBRARIES})
endif()

#----------------------------------------------------------------------
# install setting
#----------------------------------------------------------------------
set( INSTALL_LIBDIR ${CMAKE_SOURCE_DIR}/lib )
set( INSTALL_INCLUDEDIR ${CMAKE_SOURCE_DIR}/lib )

message( "INSTALL_LIBDIR: " ${INSTALL_LIBDIR} )
message( "INSTALL_INCLUDEDIR: " ${INSTALL_INCLUDEDIR} )

#configure_file(${Target_Name}.pc.in ${Target_Name}.pc @ONLY)

target_include_directories(${Target_Name} PRIVATE .)
install(TARGETS ${Target_Name}
        LIBRARY DESTINATION ${INSTALL_LIBDIR}
        PUBLIC_HEADER DESTINATION ${INSTALL_INCLUDEDIR}
        )

#install(FILES ${CMAKE_BINARY_DIR}/mylib.pc
#        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
