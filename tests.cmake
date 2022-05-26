cmake_minimum_required(VERSION 3.19.0)

set(PROJECTLIBTESTS AlgorithmAnalysisTests)
set(GOOGLETEST_DIR {CMAKE_SOURCE_DIR}/dependencies/googletest/build/)

link_directories(
    ${GOOGLETEST_DIR}/lib
    ${CMAKE_ARCHIVE_OUTPUT_DIRECTORY}   
    ${CMAKE_LIBRARY_OUTPUT_DIRECTORY} 
)

include_directories(
    ${GOOGLETEST_DIR}/include/
    ${CMAKE_SOURCE_DIR}/src/  
)

aux_source_directory(${CMAKE_SOURCE_DIR}/test PROJECTLIBTESTSRC)

add_executable(${PROJECTLIBTESTS} ${PROJECTLIBTESTSRC})

target_link_libraries(${PROJECTLIBTESTS} PUBLIC
    gtest_main
    gtest.a
    pthread
    ${PROJECTLIB}
    )

add_test(
    NAME ${PROJECTLIBTESTS}
    COMMAND ${PROJECTLIBTESTS}
)