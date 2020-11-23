#include "schedule.h"

Delivery::Delivery()
{
    _init();
}

Delivery::Delivery(std::time_t start_time, int hours)
{
    _init();
    start = start_time;
    end = start + hours * 60 * 60;
}

void Delivery::_init()
{
    start = 0;
    end = 0;
    drivers_ids = nullptr;
    truck_id = -1; 
    next = nullptr;
    prev = nullptr;
}

Delivery *Schedule::Get(int index) const
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

ScheduleDataBase::ScheduleDataBase(const std::string &db_path_)
{
    db_path = db_path_;
    _loadDataBase();
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

void ScheduleDataBase::Exit()
{
    list.Free();
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