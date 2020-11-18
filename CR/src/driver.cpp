//
// Created by kirill on 17.11.2020.
//

#include "driver.h"

Driver::Driver()
{
    surname = "NONE";
    name = "NONE";
    patronymic = "NONE";
    truck_brand = TruckBrand::NONE;

    prev = nullptr;
    next = nullptr;
}

Driver::Driver(const Driver &driver)
{
    surname = driver.surname;
    name = driver.name;
    patronymic = driver.patronymic;
    truck_brand = driver.truck_brand;

    prev = nullptr;
    next = nullptr;
}

Driver *DriverList::Get(int index) const
{
    return nullptr;
}

Driver *DriverList::Add(const Driver &driver)
{
    return nullptr;
}

void DriverList::Delete(int index)
{

}

void DriverList::PrintAll() const
{

}

void DriverList::Print(int index) const
{

}

void DriverList::Free()
{

}

void DriverList::_check_index(const int &index) const
{

}

DriverDataBase::DriverDataBase(const std::string &db_path_)
{

}

void DriverDataBase::_load_base()
{

}

void DriverDataBase::Exit()
{

}
