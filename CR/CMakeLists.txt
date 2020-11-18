cmake_minimum_required(VERSION 3.15)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES src/main.cpp src/truck.cpp src/truck.h src/driver.cpp src/driver.h src/truck_brand.h)

add_executable(CourseWork ${SOURCE_FILES})
