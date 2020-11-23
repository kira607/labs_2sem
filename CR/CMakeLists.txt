cmake_minimum_required(VERSION 3.15)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES src/main.cpp src/truck.cpp src/truck.h src/driver.cpp src/driver.h src/truck_brand.h src/route.cpp src/route.h src/destination.cpp src/destination.h src/truck_brand.cpp src/date.cpp src/date.h src/request.cpp src/request.h src/schedule.cpp src/schedule.h)

add_executable(CourseWork ${SOURCE_FILES})
