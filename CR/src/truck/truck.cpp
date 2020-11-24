#include "truck.h"

Truck::Truck()
{
    id = -1;
    brand = TruckBrand::NONE;
    capacity = 0.f;
    transportation_distance = 0;
    mileage_per_day = 0;
    prev = nullptr;
    next = nullptr;
}

Truck::Truck(const Truck &truck)
{
    id = truck.id;
    brand = truck.brand;
    capacity = truck.capacity;
    transportation_distance = truck.transportation_distance;
    mileage_per_day = truck.mileage_per_day;
    prev = nullptr;
    next = nullptr;
}