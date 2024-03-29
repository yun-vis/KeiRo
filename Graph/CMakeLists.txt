cmake_minimum_required( VERSION 3.8 )
PROJECT( Graph VERSION 1.0 DESCRIPTION "The Graph module of the KeiRo package")
set( Target_Name KeiRoGraph )

#include(GNUInstallDirs)
message( "GNUInstallDirs: " ${GNUInstallDirs} )

set( MAIN_PROJECT_ROOT "${CMAKE_SOURCE_DIR}/.." )

add_library(${Target_Name} SHARED
        src/BaseVertexProperty.cpp
        src/BaseEdgeProperty.cpp
        src/BaseGraphProperty.cpp
        src/BaseUndirectedGraph.cpp
        src/SchematicVertexProperty.cpp
        src/SchematicEdgeProperty.cpp
        src/SchematicGraphProperty.cpp
        src/SchematicGraph.cpp
        src/GridEdgeProperty.cpp
        src/GridVertexProperty.cpp
        src/GridGraphProperty.cpp
        src/GridGraph.cpp
        src/TreeEdgeProperty.cpp
        src/TreeVertexProperty.cpp
        src/TreeGraphProperty.cpp
        src/TreeGraph.cpp
        src/TreeDirectedGraph.cpp
        )

set_target_properties(${Target_Name} PROPERTIES
        VERSION ${PROJECT_VERSION}
        SOVERSION 1
        PUBLIC_HEADER "src/BaseVertexProperty.h;src/BaseEdgeProperty.h;src/BaseGraphProperty.h;
        src/BaseUndirectedGraph.h;src/GridVertexProperty.h;src/GridEdgeProperty.h;src/GridGraphProperty.h;
        src/GridGraph.h;src/SchematicVertexProperty.h;src/SchematicEdgeProperty.h;src/SchematicGraphProperty.h;
        src/SchematicGraph.h;src/TreeEdgeProperty.h;src/TreeVertexProperty.h;src/TreeGraphProperty.h;src/TreeGraph.h;
        src/TreeDirectedGraph.h;src/PropertyGraph.h"
        )

#----------------------------------------------------------------------
# path setting
#----------------------------------------------------------------------

target_include_directories(${Target_Name}
        PUBLIC
        ${CMAKE_SOURCE_DIR}/Base/src/
        )

if( APPLE )
    target_link_directories(${Target_Name}
            PUBLIC
            ${CMAKE_BINARY_DIR}/Base/
            )
    set( CUSTOM_LIBRARIES "-lKeiRoBase")
elseif( UNIX )
    link_directories(${Target_Name}
            PUBLIC
            ${CMAKE_BINARY_DIR}/Base/
            )
#    set( CUSTOM_LIBRARIES "-lmpfr")
endif()
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
