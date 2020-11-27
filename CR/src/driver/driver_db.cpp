#include "driver_db.h"

DriverDataBase::DriverDataBase(ScheduleDataBase &schedule_ref, const std::string &db_path_)
:schedule(schedule_ref)
{
    db_path = db_path_;
    _loadDataBase();
}

int *DriverDataBase::Find(Request *request)
{
    Driver *pDriver = list.head;
    int *drivers_ids = new int[request->target_route->drivers];
    int found_free_drivers = 0;
    while(pDriver)
    {
        if((request->truck_brand != pDriver->truck_brand) ||
           (!schedule.IsFree(pDriver, request))
        )
        {
            pDriver = pDriver->next;
            continue;
        }
        drivers_ids[found_free_drivers] = pDriver->id;
        ++found_free_drivers;
        if(found_free_drivers < request->target_route->drivers)
        {
            pDriver = pDriver->next;
            continue;
        }
        return drivers_ids;
    }
    return nullptr;
}

void DriverDataBase::Exit()
{
    list.Free();
}

void DriverDataBase::_loadDataBase()
{
    Driver driver{};

    io::CSVReader<5> in(db_path);
    in.read_header(io::ignore_extra_column, "id", "name", "surname", "patronymic", "brand_code");
    int brand_code;
    while(in.read_row(driver.id, driver.name, driver.surname, driver.patronymic, brand_code))
    {
        driver.truck_brand = static_cast<TruckBrand>(brand_code);
        list.Add(driver);
    }
}