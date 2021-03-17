cmake_minimum_required( VERSION 3.8 )
PROJECT( Base VERSION 1.0 DESCRIPTION "The Base module of the KeiRo package")
set( Target_Name KeiRoBase )

#include(GNUInstallDirs)
message( "GNUInstallDirs: " ${GNUInstallDirs} )

set( MAIN_PROJECT_ROOT "${CMAKE_SOURCE_DIR}/.." )

add_library(${Target_Name} SHARED
        src/Base.cpp
        src/Color.cpp
        src/Common.cpp
        src/Config.cpp
        src/Coord2.cpp
        src/Edge2.cpp
        src/Line2.cpp
        src/Rectangle2.cpp
        src/Polygon2.cpp
        src/Object.cpp
#        src/Label.cpp
#        src/Grid2.cpp
#        src/Compression.cpp
        )

set_target_properties(${Target_Name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER "src/Base.h;src/Color.h;src/Common.h;src/Config.h;src/Coord2.h;src/Line2.h;src/Rectangle2.h;src/Polygon2.h;src/Object.h;src/Timer.h"
        )

#----------------------------------------------------------------------
# path setting
#----------------------------------------------------------------------

target_include_directories(${Target_Name}
        PUBLIC
        /opt/local/include/
  	)

if( APPLE )
    target_link_directories(${Target_Name}
            PUBLIC
            /opt/local/lib/
            )
    set( CUSTOM_LIBRARIES "-lboost_thread-mt -lgmp -lcgal -lmpfr")
elseif( UNIX )
    link_directories(${Target_Name}
            PUBLIC
            /opt/local/lib/
            )
    set( CUSTOM_LIBRARIES "-lgmp -lmpfr")
endif()
target_link_libraries(${Target_Name} PUBLIC ${CUSTOM_LIBRARIES})

#----------------------------------------------------------------------
# CGAL
#----------------------------------------------------------------------
set(CGAL_DO_NOT_WARN_ABOUT_CMAKE_BUILD_TYPE TRUE)
find_package(CGAL REQUIRED COMPONENTS Core)
#set( CMAKE_BUILD_TYPE Release)

if(CGAL_FOUND)
    message(STATUS "-- LinkingCGAL")
    include_directories(${CGAL_INCLUDE_DIRS})
    target_link_libraries(${Target_Name} PUBLIC ${CGAL_LIBRARIES})
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
