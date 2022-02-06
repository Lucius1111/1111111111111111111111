cmake_minimum_required(VERSION 3.20)
project(GitProject C)

set(CMAKE_C_STANDARD 11)

add_executable(GitProject main.c
        libs/data_stuctures/vector/vector.c
        libs/data_stuctures/vector/vector.h
        )

add_subdirectory(libs)
target_link_libraries(GitProject data_stuctures)