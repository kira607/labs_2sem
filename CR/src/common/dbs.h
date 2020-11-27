#ifndef COURSEWORK_DBS_H
#define COURSEWORK_DBS_H

#include "../libdb.h"

struct DataBases
{
    ScheduleDataBase schedule_db;
    TruckDataBase truck_db;
    DriverDataBase driver_db;
    RouteDataBase route_db;

    DataBases();
};

#endif //COURSEWORK_DBS_H
