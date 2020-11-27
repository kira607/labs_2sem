//
// Created by kirill on 27.11.2020.
//

#include "dbs.h"

DataBases::DataBases()
{
    schedule_db = ScheduleDataBase();
    truck_db = TruckDataBase(&schedule_db);
    driver_db = DriverDataBase(&schedule_db);
    route_db = RouteDataBase();
}
