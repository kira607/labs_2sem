cmake_minimum_required(VERSION 3.15)
project(LabN)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES main.cpp)

add_executable(LabN ${SOURCE_FILES})
