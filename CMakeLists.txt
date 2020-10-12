cmake_minimum_required( VERSION 3.8 )
PROJECT( KEIRO )
set( Target_Name KeiRo )

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

add_subdirectory( Base )
add_subdirectory( Graph )
add_subdirectory( Composite )
add_subdirectory( FileIO )
add_subdirectory( UI )
#add_subdirectory( Metabopolis )
#add_subdirectory( Harmony )
add_subdirectory( ResponsiveLens )

# Copy directories
file(COPY ${CMAKE_SOURCE_DIR}/config/ DESTINATION ${CMAKE_BINARY_DIR}/config/)
file(COPY ${CMAKE_SOURCE_DIR}/data/ DESTINATION ${CMAKE_BINARY_DIR}/data/)
