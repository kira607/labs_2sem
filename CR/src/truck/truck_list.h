#ifndef COURSEWORK_TRUCK_LIST_H
#define COURSEWORK_TRUCK_LIST_H

#include <iostream>
#include <sstream>

#include "truck.h"

struct TruckList
{
    Truck *head;
    Truck *tail;
    int size;

    [[nodiscard]] Truck *Get(int index) const;
    Truck *Add(const Truck &truck);
    void Delete(int index);
    void PrintAll() const;
    void Print(int index) const;
    void Free();

    void _check_index(const int &index) const;
};

#endif //COURSEWORK_TRUCK_LIST_H
