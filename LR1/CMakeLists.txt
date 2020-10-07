cmake_minimum_required(VERSION 3.15)
project(Lab1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES main.cpp files_lib.cpp delete_words_with_char.cpp if_string_contains_char.cpp strcat_impl.cpp print_array_of_strings.cpp)

add_executable(Lab1 ${SOURCE_FILES})