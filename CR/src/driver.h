//
// Created by kirill on 17.11.2020.
//

#ifndef COURSEWORK_DRIVER_H
#define COURSEWORK_DRIVER_H

#include <iostream>
#include <sstream>

#define CSV_IO_NO_THREAD
#include "../fast-cpp-csv-parser/csv.h"

#include "truck_brand.h"

struct Driver
{
    Driver();
    Driver(const Driver &driver);

    std::string surname;
    std::string name;
    std::string patronymic;
    TruckBrand truck_brand;

    Driver *prev;
    Driver *next;
};

struct DriverList
{
    Driver *head;
    Driver *tail;
    int size;

    [[nodiscard]] Driver *Get(int index) const;
    Driver *Add(const Driver &driver);
    void Delete(int index);
    void PrintAll() const;
    void Print(int index) const;
    void Free();

    void _check_index(const int &index) const;
};

struct DriverDataBase
{
    DriverList list{};
    std::string db_path;

    explicit DriverDataBase(const std::string &db_path_ = "../dbs/driverdb.csv");

    void _load_base();

    void Exit();

    // Request handler interface

    // Administrator Console interface
};

#endif //COURSEWORK_DRIVER_H
