cmake_minimum_required(VERSION 3.0.0)
project(tohex VERSION 0.1.0)
add_library(tohex tohex.cpp)

add_executable(test_tohex tohex_test.cpp)
target_link_libraries(test_tohex tohex gtest gtest_main)