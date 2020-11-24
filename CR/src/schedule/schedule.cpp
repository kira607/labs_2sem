#include "schedule.h"

Delivery *Schedule::Get(int index) const
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

Delivery *Schedule::Add(const Delivery &delivery)
{
    auto *new_delivery = new Delivery(delivery);

    if (size == 0)
    {
        head = new_delivery;
        tail = new_delivery;
        new_delivery->prev = nullptr;
        new_delivery->next = nullptr;
    }
    else
    {
        new_delivery->prev = tail;
        new_delivery->prev->next = new_delivery;
        new_delivery->next = nullptr;
        tail = new_delivery;
    }

    ++size;
    return new_delivery;
}

void Schedule::Delete(int index)
{
    _check_index(index);

    if(size == 1 && index == 0)
    {
        Free();
        return;
    }

    if(index == 0)
    {
        Delivery *new_head = head->next;
        delete head;
        head = new_head;
        head->prev = nullptr;
        --size;
        return;
    }

    if(index == size - 1)
    {
        Delivery *new_tail = tail->prev;
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

void Schedule::PrintAll() const
{
    for(int i = 0; i < size; ++i)
    {
        Print(i);
    }
}

void Schedule::Print(int index) const
{
    _check_index(index);
    auto d = Get(index);
    std::cout << d->start << " "
              << d->end << " "
              << d->truck_id << " ";
    for(int i = 0; i < d->drivers; ++i)
    {
        std::cout << d->drivers_ids[i] << ",";
    }
    std::cout << "\n";
}

void Schedule::Free()
{
    Delivery *d = head;
    while(d != nullptr)
    {
        Delivery *next = d->next;
        delete d;
        d = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void Schedule::_check_index(const int &index) const
{
    if (index < 0 || index >= size)
    {
        std::stringstream message;
        message << "Index out of range (possible [0-" << size-1 << "], given " << index << ")";
        throw std::out_of_range(message.str().c_str());
    }
}
