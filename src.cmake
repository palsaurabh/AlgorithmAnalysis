cmake_minimum_required(VERSION 3.19.0)

set(CMAKE_POSITION_INDEPENDENT_CODE ON)

include_directories(
    ${CMAKE_SOURCE_DIR}/src
)

aux_source_directory(${CMAKE_SOURCE_DIR}/src PROJECTLIBSRC)

add_library(${PROJECTLIB} STATIC ${PROJECTLIBSRC})

set(CMAKE_POSITION_INDEPENDENT_CODE OFF)