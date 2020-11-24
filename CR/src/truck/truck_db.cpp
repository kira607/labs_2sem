#include "truck_db.h"

TruckDataBase::TruckDataBase(ScheduleDataBase &schedule, const std::string &db_path_):
schedule(schedule)
{
    db_path = db_path_;
    _loadDataBase();
}

Truck *TruckDataBase::Find(TruckBrand tb, float cargo_weight, int dist) const
{
    Truck *pTruck = list.head;
    while(pTruck)
    {
        if(pTruck->brand != tb)
            continue;
        if(pTruck->capacity < cargo_weight)
            continue;
        if(schedule.IsFree(pTruck))
            return pTruck;
        pTruck = pTruck->next;
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

    io::CSVReader<4> in(db_path);
    in.read_header(io::ignore_extra_column, "brand", "capacity", "transportation_distance", "mileage_per_day");
    int brand_code;
    while(in.read_row(brand_code, truck.capacity, truck.transportation_distance, truck.mileage_per_day))
    {
        truck.brand = static_cast<TruckBrand>(brand_code);
        list.Add(truck);
    }
}
