#include "truck/truck_db.h"
#include "driver/driver_db.h"
#include "route/route_db.h"
#include "schedule/schedule_db.h"
#include "request.h"

int main(int argc, char *argv[])
{
    ScheduleDataBase schedule_db = ScheduleDataBase("../dbs/scheduledb.csv");
    TruckDataBase truck_db = TruckDataBase(schedule_db);
    DriverDataBase driver_db = DriverDataBase(schedule_db);
    RouteDataBase route_db = RouteDataBase();
    

    if (argc == 1)
    {
        // Administrator console
        return 127;
    }
    else if (argc == 2)
    {
        // Handle request
        //RequestHandler rh(std::string{argv[1]});
        //rh.Run();

        //std::time_t now = std::time(nullptr);

        RequestLoader rl;
        Request request = rl.Load(argv[1]);

        const Route *target_route = route_db.Find(request.destination);

        int full_delivery_time = target_route->target_time_in_transit * 2 + target_route->loading_time;

        Delivery delivery = Delivery(request.departure_date.time, full_delivery_time);

        truck_db.list.PrintAll();

        Truck *truck = truck_db.Find(request.truck_brand, request.cargo_weight, target_route->distance);

        // Truck DB find by request.truck_brand, request.cargo_weight, target_route->distance

        
        // Driver DB find by request.departure_date, target_route->drivers

        return 0;
    }

    return 255;
 }
