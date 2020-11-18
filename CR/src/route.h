//
// Created by kirill on 18.11.2020.
//

#ifndef COURSEWORK_ROUTE_H
#define COURSEWORK_ROUTE_H

#include <iostream>
#include <sstream>

#define CSV_IO_NO_THREAD
#include "../fast-cpp-csv-parser/csv.h"

#include "destination.h"

struct Route
{
    Route();
    Route(const Route &driver);

    Destination destination;
    int distance;
    int loading_time;
    int drivers;

    Route *prev;
    Route *next;
};

struct RouteList
{
    Route *head;
    Route *tail;
    int size;

    [[nodiscard]] Route *Get(int index) const;
    Route *Add(const Route &route);
    void Delete(int index);
    void PrintAll() const;
    void Print(int index) const;
    void Free();

    void _check_index(const int &index) const;
};

struct RouteDataBase
{
    RouteList list{};
    std::string db_path;

    explicit RouteDataBase(const std::string &db_path_ = "../dbs/driverdb.csv");

    void _load_base();

    void Exit();

    // Request handler interface

    // Administrator Console interface
};

#endif //COURSEWORK_ROUTE_H
