#include "driver_db.h"

DriverDataBase::DriverDataBase(ScheduleDataBase &schedule_ref, const std::string &db_path_)
:schedule(schedule_ref)
{
    db_path = db_path_;
    _loadDataBase();
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