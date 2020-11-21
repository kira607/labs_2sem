#include "truck.h"
#include "driver.h"
#include "route.h"
#include "request.h"

int func(int (*f)(int))
{
    return f(114);
}

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

        int i = 4, j = 4;
        int r = func([j](int i) -> int{return i + j;});

        const Route *target_route;

        std::cout << r << "\n";
        //target_route = route_db.Find([&](const Route &r) -> bool
        //                             { return r.destination == Destination::NONE; });
        return 0;
    }

    return 255;
 }
