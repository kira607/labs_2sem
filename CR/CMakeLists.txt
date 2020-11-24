cmake_minimum_required(VERSION 3.15)
project(CourseWork)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -Wall")

set(TRUCK 
    src/truck/truck.cpp 
    src/truck/truck.h 
    src/truck/truck_list.cpp 
    src/truck/truck_list.h 
    src/truck/truck_db.cpp 
    src/truck/truck_db.h
)

set(SCHEDULE 
    src/schedule/delivery.cpp 
    src/schedule/delivery.h 
    src/schedule/schedule.cpp 
    src/schedule/schedule.h 
    src/schedule/schedule_db.cpp 
    src/schedule/schedule_db.h
)

set(DRIVER
    src/driver/driver.cpp 
    src/driver/driver.h 
    src/driver/driver_list.cpp 
    src/driver/driver_list.h 
    src/driver/driver_db.cpp 
    src/driver/driver_db.h
)

set(ROUTE 
    src/route/route.cpp 
    src/route/route.h 
    src/route/route_list.cpp 
    src/route/route_list.h 
    src/route/route_db.cpp 
    src/route/route_db.h
)

set(COMMON  
    src/main.cpp 
    src/truck_brand.cpp
    src/truck_brand.h 
    src/destination.cpp 
    src/destination.h 
    src/date.cpp 
    src/date.h 
    src/request.cpp 
    src/request.h
)

set(SOURCE_FILES
    ${TRUCK}
    ${ROUTE}
    ${DRIVER}
    ${SCHEDULE}
    ${COMMON}
)

add_executable(CourseWork ${SOURCE_FILES})
