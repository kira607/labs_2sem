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

[[nodiscard]] Driver *DriverList::Get(int index) const
{
    _check_index(index);

    auto d = head;
    for(int i = 0; i < index; ++i)
    {
        if(d->next)
            d = d->next;
        else
            return nullptr;
    }
    return d;
}

Driver *DriverList::Add(const Driver &driver)
{
    auto *new_driver = new Driver(driver);

    if (size == 0)
    {
        head = new_driver;
        tail = new_driver;
        new_driver->prev = nullptr;
        new_driver->next = nullptr;
    }
    else
    {
        new_driver->prev = tail;
        new_driver->prev->next = new_driver;
        new_driver->next = nullptr;
        tail = new_driver;
    }

    ++size;
    return new_driver;
}

void DriverList::Delete(int index)
{
    _check_index(index);

    if(size == 1 && index == 0)
    {
        Free();
        return;
    }

    if(index == 0)
    {
        Driver *new_head = head->next;
        delete head;
        head = new_head;
        head->prev = nullptr;
        --size;
        return;
    }

    if(index == size - 1)
    {
        Driver *new_tail = tail->prev;
        delete tail;
        tail = new_tail;
        tail->next = nullptr;
        --size;
        return;
    }

    auto t = Get(index);

    if (!t)
    {
        return;
    }

    t->next->prev = t->prev;
    t->prev->next = t->next;
    delete t;
    --size;
}

void DriverList::PrintAll() const
{
    for(int i = 0; i < size; ++i)
    {
        Print(i);
    }
}

void DriverList::Print(int index) const
{
    _check_index(index);
    auto d = Get(index);
    std::cout << d->name << " "
              << d->surname << " "
              << d->patronymic << " "
              << str(d->truck_brand) << "\n";
}

void DriverList::Free()
{
    Driver *d = head;
    while(d != nullptr)
    {
        Driver *next = d->next;
        delete d;
        d = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void DriverList::_check_index(const int &index) const
{
    if (index < 0 || index >= size)
    {
        std::stringstream message;
        message << "Index out of range (possible [0-" << size-1 << "], given " << index << ")";
        throw std::out_of_range(message.str().c_str());
    }
}

DriverDataBase::DriverDataBase(const std::string &db_path_)
{
    db_path = db_path_;
    _load_base();
}

void DriverDataBase::_load_base()
{
    Driver driver{};

    io::CSVReader<4> in(db_path);
    in.read_header(io::ignore_extra_column, "surname", "name", "patronymic", "brand_code");
    int brand_code;
    while(in.read_row(driver.name, driver.surname, driver.patronymic, brand_code))
    {
        driver.truck_brand = static_cast<TruckBrand>(brand_code);
        list.Add(driver);
    }
}

void DriverDataBase::Exit()
{
    list.Free();
}
