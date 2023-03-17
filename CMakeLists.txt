cmake_minimum_required(VERSION 3.23.0)
project(atm_controller)

set(CMAKE_CXX_FLAGS "-std=c++14 -pthread")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -Wall -g -pthread")

file(GLOB_RECURSE src_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} src/*.cpp)
file(GLOB_RECURSE header_files RELATIVE ${CMAKE_CURRENT_SOURCE_DIR} include/*.h)

add_library(
    ${PROJECT_NAME}_lib
    ${src_files}
    ${header_files}
)
target_include_directories(${PROJECT_NAME}_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

if (test OR TEST)
    enable_testing()
    file(GLOB_RECURSE test_sources RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/test *_test.cpp)

    foreach(test_source ${test_sources})
        string(REPLACE ".cpp" "" test_name ${test_source})
        set(test_binary_name ${PROJECT_NAME}_${test_name})

        add_executable(${test_binary_name} test/${test_source})
        target_link_libraries(${test_binary_name} gmock gtest_main gtest glog)
        target_link_libraries(${test_binary_name} ${PROJECT_NAME}_lib)
        add_test(NAME ${test_binary_name} COMMAND ${test_binary_name})
    endforeach()
endif()