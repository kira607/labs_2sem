#include "truck.h"
#include "driver.h"

int main()
{
    TruckDataBase truck_db = TruckDataBase("../dbs/truckdb.csv");
    truck_db.list.Print(10);

    DriverDataBase driver_db = DriverDataBase("../dbs/driverdb.csv");
    driver_db.list.PrintAll();

    return 0;
 }
