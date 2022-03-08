cmake_minimum_required(VERSION 3.20)
project(GitProject C)

set(CMAKE_C_STANDARD 11)

add_executable(GitProject main.c
        str/string/string_.c
        str/string/string_.h
        str/string/tasks/tasks.h
        str/string/tasks/removeNonLetters.h
        str/string/tasks/removeAdjacentEqualLetters.h
        str/string/tasks/digitToStartWithPreservingOrderForAll.h str/string/tasks/transformsNumbersToSpaces.h str/string/tasks/transformsAllWordsW1ToW2.h)

add_subdirectory(libs)
target_link_libraries(GitProject data_stuctures)
target_link_libraries(GitProject algorithms)

