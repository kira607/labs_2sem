#include "truck.h"
#include "driver.h"
#include "route.h"

int main()
{
    TruckDataBase truck_db = TruckDataBase("../dbs/truckdb.csv");
    truck_db.list.PrintAll();

    std::cout << "=============\n";

    DriverDataBase driver_db = DriverDataBase("../dbs/driverdb.csv");
    driver_db.list.PrintAll();

    std::cout << "=============\n";

    RouteDataBase route_db = RouteDataBase();
    route_db.list.PrintAll();

    return 0;
 }
