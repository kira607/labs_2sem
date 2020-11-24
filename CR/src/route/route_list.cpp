#include "route_list.h"

Route *RouteList::Get(int index) const
{
    _check_index(index);

    auto r = head;
    for(int i = 0; i < index; ++i)
    {
        if(r->next)
            r = r->next;
        else
            return nullptr;
    }
    return r;
}

Route *RouteList::Add(const Route &route)
{
    auto *new_route = new Route(route);

    if (size == 0)
    {
        head = new_route;
        tail = new_route;
        new_route->prev = nullptr;
        new_route->next = nullptr;
    }
    else
    {
        new_route->prev = tail;
        new_route->prev->next = new_route;
        new_route->next = nullptr;
        tail = new_route;
    }

    ++size;
    return new_route;
}

void RouteList::Delete(int index)
{
    _check_index(index);

    if(size == 1 && index == 0)
    {
        Free();
        return;
    }

    if(index == 0)
    {
        Route *new_head = head->next;
        delete head;
        head = new_head;
        head->prev = nullptr;
        --size;
        return;
    }

    if(index == size - 1)
    {
        Route *new_tail = tail->prev;
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

void RouteList::PrintAll() const
{
    for(int i = 0; i < size; ++i)
    {
        Print(i);
    }
}

void RouteList::Print(int index) const
{
    _check_index(index);
    auto r = Get(index);
    std::cout << str(r->destination) << " "
              << r->distance << " "
              << r->loading_time << " "
              << r->drivers << "\n";
}

void RouteList::Free()
{
    Route *r = head;
    while(r != nullptr)
    {
        Route *next = r->next;
        delete r;
        r = next;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

void RouteList::_check_index(const int &index) const
{
    if (index < 0 || index >= size)
    {
        std::stringstream message;
        message << "Index out of range (possible [0-" << size-1 << "], given " << index << ")";
        throw std::out_of_range(message.str().c_str());
    }
}