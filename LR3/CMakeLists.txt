cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES main.cpp)

add_executable(Lab3 ${SOURCE_FILES})
