#include "schedule_db.h"

ScheduleDataBase::ScheduleDataBase(const std::string &db_path_)
{
    db_path = db_path_;
    _loadDataBase();
}

bool ScheduleDataBase::IsFree(Truck *truck) const
{
    Delivery *pDelivery = list.head;
    while(pDelivery)
    {
        pDelivery = pDelivery->next;
    }
    return false;
}
    
bool ScheduleDataBase::IsFree(Driver *driver)
{
    return false;
}

void ScheduleDataBase::Exit()
{
    list.Free();
}

void ScheduleDataBase::_loadDataBase()
{
    Delivery delivery{};
    std::string drivers_ids_str;

    io::CSVReader<4> in(db_path);
    in.read_header(io::ignore_extra_column, "start", "end", "truck_id", "drivers_ids");
    while(in.read_row(delivery.start, delivery.end, delivery.truck_id, drivers_ids_str))
    {
        delivery.drivers_ids = _parseDriversIdsStr(drivers_ids_str, delivery.drivers);
        list.Add(delivery);
    }
}

int *ScheduleDataBase::_parseDriversIdsStr(const std::string &drivers_ids_str, int &drivers_count)
{
    drivers_count = 0;
    int *drivers_ids = new int[1];
    std::stringstream ss{drivers_ids_str};
    int read_element;
    while(ss >> read_element)
    {
        drivers_ids[drivers_count] = read_element;
        ++drivers_count;
        drivers_ids = (int*)realloc(drivers_ids, sizeof(int) * (drivers_count + 1));
    }
    return drivers_ids;
}