#include "truck_list.h"

Truck *TruckList::Get(int index) const
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
    auto *new_truck = new Truck(truck);

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
    std::cout << str(t->brand) << " "
              << t->capacity << " "
              << t->transportation_distance << " "
              << t->mileage_per_day << "\n";
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