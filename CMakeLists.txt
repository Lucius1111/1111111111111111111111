cmake_minimum_required(VERSION 3.20)
project(GitProject C)

set(CMAKE_C_STANDARD 11)

add_executable(GitProject main.c libs/algorithms/array/array.c libs/algorithms/array/array.h libs/algorithms/algorithm.c)

add_subdirectory(libs)
target_link_libraries(GitProject data_stuctures)
target_link_libraries(GitProject algorithms)