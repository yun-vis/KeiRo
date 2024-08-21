cmake_minimum_required( VERSION 3.8 )
PROJECT( KeiRo )
set( Target_Name KeiRo )
set(CMAKE_MACOSX_RPATH OFF)

#----------------------------------------------------------------------
# cmake setting
#----------------------------------------------------------------------
message( "CMAKE_BINARY_DIR: " ${CMAKE_BINARY_DIR} )
message( "CMAKE_SOURCE_DIR: " ${CMAKE_SOURCE_DIR} )
## set output folder
## set(CMAKE_INCLUDE_CURRENT_DIR ON)
#set( CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
#set( CMAKE_LIBRARY_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
#set( CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${CMAKE_BINARY_DIR}/bin" )
##set( SEPARATE_BUILD ON)

# basic library configuration
add_subdirectory( Base )
add_subdirectory( Graph )
add_subdirectory( Optimization )
add_subdirectory( Composite )
add_subdirectory( Geometry )
add_subdirectory( FileIO )
add_subdirectory( UI )

# target binary configuration
if(EXISTS "${CMAKE_SOURCE_DIR}/Metabopolis")
    add_subdirectory( Metabopolis )
    message( "The system will build Metabopolis" )
endif()
if(EXISTS "${CMAKE_SOURCE_DIR}/Harmony")
#    add_subdirectory( Harmony )
    message( "The system will build Harmony" )
endif()
if(EXISTS "${CMAKE_SOURCE_DIR}/ResponsiveLens")
    add_subdirectory( ResponsiveLens )
    message( "The system will build ResponsiveLens" )
endif()
#if(EXISTS "${CMAKE_SOURCE_DIR}/Test")
#    add_subdirectory( Test )
#    message( "The system will build Test" )
#endif()

# Copy directories
file(COPY ${CMAKE_SOURCE_DIR}/config/ DESTINATION ${CMAKE_BINARY_DIR}/config/)
file(COPY ${CMAKE_SOURCE_DIR}/data/ DESTINATION ${CMAKE_BINARY_DIR}/data/)
