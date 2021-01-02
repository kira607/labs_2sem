cmake_minimum_required(VERSION 3.15)
project(Lab3)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(TRUCK
        truck/truck_brand.cpp
        truck/truck_brand.h
        truck/truck.cpp
        truck/truck.h
        truck/truck_list.cpp
        truck/truck_list.h
        # truck/truck_db.cpp
        # truck/truck_db.h
        truck/lib_truck.h

)

set(SOURCE_FILES main.cpp ${TRUCK})

add_executable(Lab3 ${SOURCE_FILES})
