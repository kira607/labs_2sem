//
// Created by kirill on 17.11.2020.
//

#ifndef COURSEWORK_TRUCK_H
#define COURSEWORK_TRUCK_H

#include <iostream>
#include <sstream>

#define CSV_IO_NO_THREAD
#include "../fast-cpp-csv-parser/csv.h"

#include "truck_brand.h"

struct Truck
{
    Truck();
    Truck(const Truck &truck);

    TruckBrand brand;
    int capacity;
    int transportation_distance;
    int mileage_per_day;

    Truck *prev;
    Truck *next;
};

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

struct TruckDataBase
{
    TruckList list{};
    std::string db_path;

    explicit TruckDataBase(const std::string &db_path_ = "../dbs/truckdb.csv");

    void _loadDataBase();

    void Exit();

    // Request handler interface

    // Administrator Console interface
};

#endif //COURSEWORK_TRUCK_H
