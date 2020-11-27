cmake_minimum_required( VERSION 3.8 )
PROJECT( Optimization VERSION 1.0 DESCRIPTION "The Optimization module of the KeiRo package")
set( Target_Name KeiRoOptimization )

#include(GNUInstallDirs)
message( "GNUInstallDirs: " ${GNUInstallDirs} )

set( MAIN_PROJECT_ROOT "${CMAKE_SOURCE_DIR}/.." )

add_library(${Target_Name} SHARED
        src/Schematization.cpp
        src/LaplacianOptimization.cpp
        )

set_target_properties(${Target_Name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER "src/LaplacianOptimization.h;src/Schematization.h")

#----------------------------------------------------------------------
# path setting
#----------------------------------------------------------------------

target_include_directories(${Target_Name}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Base/src/
        ${CMAKE_SOURCE_DIR}/Graph/src/
        )

target_link_directories(${Target_Name}
        PUBLIC
        ${CMAKE_BINARY_DIR}/Base/
        ${CMAKE_BINARY_DIR}/Graph/
        )
set( CUSTOM_LIBRARIES "-lKeiRoBase -lKeiRoGraph")
target_link_libraries(${Target_Name} PUBLIC ${CUSTOM_LIBRARIES})

#----------------------------------------------------------------------
# QT
#----------------------------------------------------------------------
message(STATUS "-- Linking qt")
set(QT_REQUIRED_COMPONENTS Core Gui Svg Widgets OpenGL)
find_package(Qt5 COMPONENTS ${QT_REQUIRED_COMPONENTS} REQUIRED)

# Add components to the target
foreach(component ${QT_REQUIRED_COMPONENTS})
    target_link_libraries(${Target_Name}
            PUBLIC
            Qt5::${component}
            )
endforeach()

# Enable automoc/uic/rcc
set_target_properties(${Target_Name}
        PROPERTIES
        AUTOMOC ON
        AUTOUIC ON
        AUTORCC ON
        )

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
#