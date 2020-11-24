#ifndef COURSEWORK_TRUCK_H
#define COURSEWORK_TRUCK_H

#include "../truck_brand.h"

struct Truck
{
    Truck();
    Truck(const Truck &truck);

    int id;
    int capacity;
    int transportation_distance;
    int mileage_per_day;
    TruckBrand brand;

    Truck *prev;
    Truck *next;
};

#endif //COURSEWORK_TRUCK_H
