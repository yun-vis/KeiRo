cmake_minimum_required( VERSION 3.8 )
PROJECT( FileIO VERSION 1.0 DESCRIPTION "The FileIO module of the KeiRo package")
set( Target_Name KeiRoFileIO )
set(CMAKE_MACOSX_RPATH OFF)

#include(GNUInstallDirs)
#message( "GNUInstallDirs: " ${GNUInstallDirs} )

set( MAIN_PROJECT_ROOT "${CMAKE_SOURCE_DIR}/.." )

add_library(${Target_Name} SHARED
#add_library(${Target_Name} STATIC
#        src/sbgn.cpp
#        src/sbml.cpp
        src/svg.cpp
        src/data.cpp
        src/metadata.cpp
        )

set_target_properties(${Target_Name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
#        PUBLIC_HEADER "src/sbgn.h;src/sbml.h;src/svg.h"
        PUBLIC_HEADER "src/svg.h;src/metadata.h;src/data.h"
        )

#----------------------------------------------------------------------
# path setting
#----------------------------------------------------------------------
#set(THIRD_PARTY_INCLUDE ${CMAKE_SOURCE_DIR}/third_party/libSBGN2/src/ )
#set(THIRD_PARTY_LIB ${CMAKE_SOURCE_DIR}/third_party/ )

target_include_directories(${Target_Name}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Base/src/
        ${CMAKE_SOURCE_DIR}/Graph/src/
        ${CMAKE_SOURCE_DIR}/Composite/src/
#        ${CMAKE_SOURCE_DIR}/third_party/libSBGN2/build/install/include/
        #${THIRD_PARTY_INCLUDE}
        )
message(${CMAKE_SOURCE_DIR}/third_party/libSBGN2/build/install/lib/)
target_link_directories(${Target_Name}
        PUBLIC
        ${CMAKE_BINARY_DIR}/Base/
        ${CMAKE_BINARY_DIR}/Graph/
        ${CMAKE_BINARY_DIR}/Composite/
#        ${CMAKE_SOURCE_DIR}/third_party/libSBGN2/build/install/lib/
        )
set( CUSTOM_LIBRARIES "-lKeiRoBase -lKeiRoGraph -lKeiRoComposite -lcgal")
target_link_libraries(${Target_Name} PUBLIC ${CUSTOM_LIBRARIES}
#        /opt/local/lib/libsbgn-static.a
#        ${CMAKE_SOURCE_DIR}/third_party/libSBGN2/build/install/lib/libsbgn-static.a
        )

#----------------------------------------------------------------------
# QT
#----------------------------------------------------------------------
message(STATUS "-- Linking qt")
set(QT_REQUIRED_COMPONENTS Core Gui Svg Widgets OpenGL Xml)
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
#        DESTINATION ${CMAKE_INSTALL_DATAROOTDIR}/pkgconfig)
