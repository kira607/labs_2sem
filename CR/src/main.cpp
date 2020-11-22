#include "truck.h"
#include "driver.h"
#include "route.h"
#include "request.h"

int main(int argc, char *argv[])
{
    TruckDataBase truck_db = TruckDataBase("../dbs/truckdb.csv");
    DriverDataBase driver_db = DriverDataBase("../dbs/driverdb.csv");
    RouteDataBase route_db = RouteDataBase("../dbs/routedb.csv");

    if (argc == 1)
    {
        // Administrator console
        return 0;
    }
    else if (argc == 2)
    {
        // Handle request
        //RequestHandler rh(std::string{argv[1]});
        //rh.Run();

        RequestLoader rl;
        Request request = rl.Load(argv[1]);

        const Route *target_route = route_db.Find(request.destination);

        // Truck DB find by request.truck_brand, request.cargo_weight, target_route->distance
        // Driver DB find by request.departure_date, target_route->drivers

        return 0;
    }

    return 255;
 }
