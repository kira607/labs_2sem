#ifndef COURSEWORK_DRIVER_H
#define COURSEWORK_DRIVER_H

#include "../truck_brand.h"

struct Driver
{
    Driver();
    Driver(const Driver &driver);

    int id;
    std::string surname;
    std::string name;
    std::string patronymic;
    TruckBrand truck_brand;

    Driver *prev;
    Driver *next;
};

#endif //COURSEWORK_DRIVER_H
