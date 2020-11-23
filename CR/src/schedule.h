#ifndef COURSEWORK_SCHEDULE_H
#define COURSEWORK_SCHEDULE_H

#include <iostream>
#include <sstream>
#include <ctime>

#define CSV_IO_NO_THREAD
#include "../fast-cpp-csv-parser/csv.h"

struct Delivery
{
    time_t start;
    time_t end;
    int *drivers_ids;
    int drivers;
    int truck_id;

    Delivery *next;
    Delivery *prev;

    Delivery();
    Delivery(std::time_t start_time, int hours);
    void _init();
};

struct Schedule
{
    Delivery *head;
    Delivery *tail;
    int size;

    [[nodiscard]] Delivery *Get(int index) const;
    Delivery *Add(const Delivery &delivery);
    void Delete(int index);
    void PrintAll() const;
    void Print(int index) const;
    void Free();

    void _check_index(const int &index) const;
};

struct ScheduleDataBase
{
    Schedule list{};
    std::string db_path;

    explicit ScheduleDataBase(const std::string &db_path_ = "../dbs/scheduledb.csv");

    void _loadDataBase();
    int *_parseDriversIdsStr(const std::string &drivers_ids_str, int &drivers_count);

    void Exit();

    // Request handler interface

    // Administrator Console interface
};

#endif //COURSEWORK_SCHEDULE_H
