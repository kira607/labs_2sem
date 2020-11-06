cmake_minimum_required(VERSION 3.15)
project(Lab2)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(SOURCE_FILES main.cpp gen.cpp input.cpp matrix.cpp menu.cpp  )
set(HEADERS               gen.h   input.h   matrix.h   menu.h    )

add_executable(Lab2 ${SOURCE_FILES})
