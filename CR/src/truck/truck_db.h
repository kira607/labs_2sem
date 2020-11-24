#ifndef COURSEWORK_TRUCK_DB_H
#define COURSEWORK_TRUCK_DB_H

#define CSV_IO_NO_THREAD
#include "../../fast-cpp-csv-parser/csv.h"

#include "truck_list.h"
#include "../schedule/schedule_db.h"

struct TruckDataBase
{
    TruckList list{};
    std::string db_path{};
    ScheduleDataBase &schedule;

    explicit TruckDataBase(ScheduleDataBase &schedule_ref, const std::string &db_path_ = "../dbs/truckdb.csv");

    void _loadDataBase();

    void Exit();

    // Request handler interface

    //request.truck_brand, request.cargo_weight, target_route->distance
    Truck *Find(TruckBrand tb, int cargo_weight, int dist) const;

    // Administrator Console interface
};

#endif //COURSEWORK_TRUCK_DB_H
