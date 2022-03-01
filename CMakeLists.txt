cmake_minimum_required(VERSION 3.20)
project(GitProject C)

set(CMAKE_C_STANDARD 11)

add_executable(GitProject main.c
        str/string/string_.c
        str/string/string_.h
        str/string/tasks/tasks.c
        str/string/tasks/tasks.h)

add_subdirectory(libs)
add_subdirectory(str)
target_link_libraries(GitProject data_stuctures)
target_link_libraries(GitProject algorithms)
