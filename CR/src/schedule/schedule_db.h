#ifndef COURSEWORK_SCHEDULE_DB_H
#define COURSEWORK_SCHEDULE_DB_H

#define CSV_IO_NO_THREAD
#include "../../fast-cpp-csv-parser/csv.h"

#include "schedule.h"
#include "../driver/driver.h"
#include "../truck/truck.h"

struct ScheduleDataBase
{
    Schedule list{};
    std::string db_path;

    explicit ScheduleDataBase(const std::string &db_path_ = "../dbs/scheduledb.csv");

    bool IsFree(Truck *truck) const;
    bool IsFree(Driver *driver) const;

    void Exit();

    void _loadDataBase();
    static int *_parseDriversIdsStr(const std::string &drivers_ids_str, int &drivers_count);
};

#endif //COURSEWORK_SCHEDULE_DB_H
