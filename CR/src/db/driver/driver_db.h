#ifndef COURSEWORK_DRIVER_DB_H
#define COURSEWORK_DRIVER_DB_H

#define CSV_IO_NO_THREAD

#include <iomanip>

#include "../../../fast-cpp-csv-parser/csv.h"
#include "driver_list.h"
#include "../schedule/schedule_db.h"
#include "../../common/request.h"
#include "../../common/input.h"

struct DriverDataBase
{
    DriverList list{};
    std::string db_path{};
    ScheduleDataBase *schedule{};

    DriverDataBase() = default;
    explicit DriverDataBase(ScheduleDataBase *schedule_p, const std::string &db_path_ = "../dbs/driverdb.csv");

    void PrintAll() const;
    void Print(int index) const;
    
    int *Find(Request *request) const;

    void Edit(int index);
    void Add();
    void Delete(int index);

    void Exit();

    void _loadDataBase();
    void _updateDbFile();
};

#endif //COURSEWORK_DRIVER_DB_H
