cmake_minimum_required( VERSION 3.8 )
PROJECT( UI VERSION 1.0 DESCRIPTION "The UI module of the KeiRo package")
set( Target_Name KeiRoUI )

#include(GNUInstallDirs)
#message( "GNUInstallDirs: " ${GNUInstallDirs} )

add_library(${Target_Name} SHARED
        src/GraphicsBase.cpp
        src/GraphicsCellItem.cpp
        src/GraphicsEdgeItem.cpp
        src/GraphicsPolygonItem.cpp
        src/GraphicsVertexItem.cpp
        src/GraphicsView.cpp
        src/MainWindow.cpp
        )

set_target_properties(${Target_Name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER "src/GraphicsBase.h;src/GraphicsCellItem.h;src/GraphicsEdgeItem.h;src/GraphicsPolygonItem.h;src/GraphicsVertexItem.h;src/GraphicsView.h;src/MainWindow.h;"
        )

#----------------------------------------------------------------------
# path setting
#----------------------------------------------------------------------

if( APPLE )

target_include_directories(${Target_Name}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Base/src/
        ${CMAKE_SOURCE_DIR}/Graph/src/
        ${CMAKE_SOURCE_DIR}/third_party/libSBGN2/build/install/include/
        )

target_link_directories(${Target_Name}
        PUBLIC
        ${CMAKE_BINARY_DIR}/Base/
        ${CMAKE_BINARY_DIR}/Graph/
        ${CMAKE_SOURCE_DIR}/third_party/libSBGN2/build/install/lib/
        )
elseif( UNIX )

    set( CMAKE_PREFIX_PATH "/home/$ENV{USER}/MyLib/release/qt5-package/5.8/gcc_64/lib/cmake/Qt5")

    target_include_directories(${Target_Name}
            PUBLIC
#            /opt/local/include/
#            /usr/include/
#            /usr/include/x86_64-linux-gnu/
            ${CMAKE_SOURCE_DIR}/Base/src/
            ${CMAKE_SOURCE_DIR}/Graph/src/
#            ${QT5_PATH_DIR}/include/
            )

    link_directories( ${Target_Name}
            PUBLIC
#            /opt/local/lib/
#            /usr/lib/
#            /usr/lib/x86_64-linux-gnu/
            ${CMAKE_BINARY_DIR}/Base/
            ${CMAKE_BINARY_DIR}/Graph/
#            ${QT5_PATH_DIR}/lib/
            )
endif()

if( APPLE )
    set( CUSTOM_LIBRARIES "-lKeiRoBase")
elseif( UNIX )
    set( CUSTOM_LIBRARIES "")
    #    set( CUSTOM_LIBRARIES "-lmpfr")
endif()
target_link_libraries(${Target_Name} PRIVATE ${CUSTOM_LIBRARIES}
        )
#${THIRD_PARTY_LIB}/libSBGN2/build/src/sbgn/libsbgn-static.a

#----------------------------------------------------------------------
# cmake setting
#----------------------------------------------------------------------
## set output folder
#set(CMAKE_INCLUDE_CURRENT_DIR ON)
#message( "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
#message( "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
#set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")
#set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin")

#----------------------------------------------------------------------
# compiler setting
#----------------------------------------------------------------------
set(CMAKE_C_COMPILER /usr/bin)

#if( APPLE )
#    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -framework Accelerate -DEIGEN_USE_BLAS -framework OpenGL -framework GLUT" )
#    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -DIL_STD -O3 -DNDEBUG" )
#    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -Wno-deprecated -DIL_STD -O3 -DNDEBUG" )
#    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -Wno-deprecated -DIL_STD -O3 -DNDEBUG -openmp -omp" )
#    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -Wno-deprecated -DIL_STD" )
#elseif( UNIX )
#    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11 -lboost_graph" )
#    set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -DIL_STD -O3 -DNDEBUG" )
#    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -Wno-deprecated -DIL_STD -O3 -DNDEBUG" )
#    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -Wno-deprecated -DIL_STD -O3 -DNDEBUG -openmp -omp" )
#    #set( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-inline -g -Wall -Wno-deprecated -DIL_STD" )
#elseif (WIN32)
#    set( CMAKE_CXX_STANDARD 11)
#endif()


#----------------------------------------------------------------------
# sources
#----------------------------------------------------------------------

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
# OpenCV
#----------------------------------------------------------------------
#message(STATUS "-- Linking OpenCV")
#find_package( OpenCV )

#target_link_libraries(${Target_Name}
#        PUBLIC
#        ${OpenCV_LIBS}
#)

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
#        DESTINATION ${CMAKE
