#include "route.h"

Route::Route()
{
    destination = Destination::NONE;
    distance = 0;
    loading_time = 0;
    drivers = 0;
    target_time_in_transit = 0;

    prev = nullptr;
    next = nullptr;
}

Route::Route(const Route &route)
{
    destination = route.destination;
    distance = route.distance;
    loading_time = route.loading_time;
    drivers = route.drivers;
    target_time_in_transit = route.target_time_in_transit;

    prev = nullptr;
    next = nullptr;
}
