#ifndef COURSEWORK_DRIVER_DB_H
#define COURSEWORK_DRIVER_DB_H

#define CSV_IO_NO_THREAD
#include "../../fast-cpp-csv-parser/csv.h"

#include "driver_list.h"
#include "../schedule/schedule_db.h"
#include "../request.h"

struct DriverDataBase
{
    DriverList list{};
    std::string db_path;
    ScheduleDataBase &schedule;

    explicit DriverDataBase(ScheduleDataBase &schedule_ref, const std::string &db_path_ = "../dbs/driverdb.csv");

    int *Find(Request *request);

    void Exit();

    void _loadDataBase();
};

#endif //COURSEWORK_DRIVER_DB_H
