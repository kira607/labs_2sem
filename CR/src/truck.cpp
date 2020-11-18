//
// Created by kirill on 17.11.2020.
//

#include "truck.h"

Truck::Truck()
{
    brand = TruckBrand::NONE;
    capacity = 0;
    transportation_distance = 0;
    mileage_per_day = 0;
    prev = nullptr;
    next = nullptr;
}

Truck::Truck(const Truck &truck)
{
    brand = truck.brand;
    capacity = truck.capacity;
    transportation_distance = truck.transportation_distance;
    mileage_per_day = truck.mileage_per_day;
    prev = nullptr;
    next = nullptr;
}

[[nodiscard]] Truck *TruckList::Get(int index) const
{
    _check_index(index);

    auto t = head;
    for(int i = 0; i < index; ++i)
    {
        if(t->next)
            t = t->next;
        else
            return nullptr;
    }
    return t;
}

Truck *TruckList::Add(const Truck &truck)
{
    auto *new_truck = new Truck();
    *new_truck = truck;

    if (size == 0)
    {
        head = new_truck;
        tail = new_truck;
        new_truck->prev = nullptr;
        new_truck->next = nullptr;
    }
    else
    {
        new_truck->prev = tail;
        new_truck->prev->next = new_truck;
        new_truck->next = nullptr;
        tail = new_truck;
    }

    ++size;
    return new_truck;
}

void TruckList::Delete(int index)
{
    _check_index(index);

    if(size == 1 && index == 0)
    {
        Free();
        return;
    }

    if(index == 0)
    {
        Truck *new_head = head->next;
        delete head;
        head = new_head;
        head->prev = nullptr;
        --size;
        return;
    }

    if(index == size - 1)
    {
        Truck *new_tail = tail->prev;
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

void TruckList::PrintAll() const
{
    for(int i = 0; i < size; ++i)
    {
        Print(i);
    }
}

void TruckList::Print(int index) const
{
    _check_index(index);
    auto t = Get(index);
    std::cout << static_cast<int>(t->brand) << " " <<
              t->capacity << " " <<
              t->transportation_distance << " " <<
              t->mileage_per_day << "\n";
}

void TruckList::Free()
{
    Truck *t = head;
    while(t != nullptr)
    {
        Truck *next = t->next;
        delete t;
        t = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void TruckList::_check_index(const int &index) const
{
    if (index < 0 || index >= size)
    {
        std::stringstream message;
        message << "Index out of range (possible [0-" << size-1 << "], given " << index << ")";
        throw std::out_of_range(message.str().c_str());
    }
}

TruckDataBase::TruckDataBase(const std::string &db_path_)
{
    db_path = db_path_;
    _load_base();
}

void TruckDataBase::_load_base()
{
    Truck tr{};

    io::CSVReader<4> in(db_path);
    in.read_header(io::ignore_extra_column, "brand", "capacity", "transportation_distance", "mileage_per_day");
    int brand_code;
    while(in.read_row(brand_code, tr.capacity, tr.transportation_distance, tr.mileage_per_day))
    {
        tr.brand = static_cast<TruckBrand>(brand_code);
        list.Add(tr);
    }
}

void TruckDataBase::Exit()
{
    list.Free();
}
