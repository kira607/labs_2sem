#include "truck_db.h"

TruckDataBase::TruckDataBase(ScheduleDataBase &schedule, const std::string &db_path_):
schedule(schedule)
{
    db_path = db_path_;
    _loadDataBase();
}

Truck *TruckDataBase::Find(Request *request) const
{
    Truck *pTruck = list.head;
    while(pTruck)
    {
        std::cout << "check: " << pTruck->id << "\n";
        if(
            (pTruck->brand != request->truck_brand) ||
            (pTruck->capacity < request->cargo_weight) || 
            (pTruck->transportation_distance < request->target_route->distance) ||
            (!schedule.IsFree(pTruck, request))
        )
        {
            pTruck = pTruck->next;
            continue;
        }
        return pTruck;
    }
    return nullptr;
}

void TruckDataBase::Exit()
{
    list.Free();
}

void TruckDataBase::_loadDataBase()
{
    Truck truck{};

    io::CSVReader<5> in(db_path);
    in.read_header(io::ignore_extra_column, "id", "brand", "capacity", "transportation_distance", "mileage_per_day");
    int brand_code;
    while(in.read_row(truck.id, brand_code, truck.capacity, truck.transportation_distance, truck.mileage_per_day))
    {
        truck.brand = static_cast<TruckBrand>(brand_code);
        list.Add(truck);
    }
}
