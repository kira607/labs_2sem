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
        RequestLoader rl;
        Request request = rl.Load(argv[1]);

        std::time_t now_time = std::time(nullptr);
        Date now = Date(now_time);

        schedule_db.Update(&now);

        if(request.departure_date.time <= now.time)
        {
            std::cerr << "reqested departure date has past!\n";
            return 100;
        }

        Route *target_route = route_db.Find(request.destination);
        int full_delivery_time = target_route->target_time_in_transit * 2 + target_route->loading_time;
        request.target_route = target_route;

        Delivery delivery = Delivery(request.departure_date.time, full_delivery_time);
        request.arrival_date = Date(delivery.end);

        Truck *truck = truck_db.Find(&request);
        if(!truck)
        {
            std::cerr << "Could not find free trucks on this date\n";
            return 120;
        }
        std::cout << "truck id:" << truck->id << "\n";
        delivery.truck_id = truck->id;

        int *drivers_ids = driver_db.Find(&request);
        if(!drivers_ids)
        {
            std::cerr << "Could not find free drivers on this date\n";
            return 121;
        }

        std::cout << "drivers ids: ";
        for(int i = 0; i < request.target_route->drivers; ++i)
        {
            std::cout << drivers_ids[i] << ";";
        }
        std::cout << "\n";
        delivery.drivers = request.target_route->drivers;
        delivery.drivers_ids = drivers_ids;

        schedule_db.Add(&delivery);

        return 0;
    }

    return 255;
 }
