cmake_minimum_required(VERSION 2.8)
PROJECT (name)
find_package(OpenCV REQUIRED )
set( NAME_SRC
        roboCore.cpp
        BlobDetection.cpp
        )

set( NAME_HEADERS
        BlobDetection.h
        )

INCLUDE_DIRECTORIES( ${CMAKE_CURRENT_SOURCE_DIR}/include )
link_directories( ${CMAKE_BINARY_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
add_executable( name ${NAME_SRC} ${NAME_HEADERS} )

target_link_libraries( name ${OpenCV_LIBS} )