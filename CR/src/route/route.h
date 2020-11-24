#ifndef COURSEWORK_ROUTE_H
#define COURSEWORK_ROUTE_H

#include "../destination.h"

struct Route
{
    Route();
    Route(const Route &driver);

    Destination destination;
    int distance;
    int loading_time;
    int drivers;
    int target_time_in_transit;

    Route *prev;
    Route *next;
};

#endif //COURSEWORK_ROUTE_H
