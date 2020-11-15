#include <iostream>

#define CSV_IO_NO_THREAD
#include "fast-cpp-csv-parser/csv.h"



enum class TruckBrand
{
    Volvo = 1,
    MercedesBenz = 2,
    Man = 3,
    Daf = 4,
    Scania = 5,
    Iveco = 6,
    Renault = 7,
    Nissan = 8,
    Tatra = 9,
    Mitsubishi = 10,
    NONE = 0
};

struct Truck
{
    Truck()
    {
        brand = TruckBrand::NONE;
        capacity = 0;
        transportation_distance = 0;
        mileage_per_day = 0;
        prev = nullptr;
        next = nullptr;
    }

    Truck(const Truck &truck)
    {
        brand = truck.brand;
        capacity = truck.capacity;
        transportation_distance = truck.transportation_distance;
        mileage_per_day = truck.mileage_per_day;
        prev = nullptr;
        next = nullptr;
    }

    TruckBrand brand;
    int capacity;
    int transportation_distance;
    int mileage_per_day;

    Truck *prev;
    Truck *next;
};

struct TruckList 
{
    Truck *head;
    Truck *tail;
    int size;

    [[nodiscard]] Truck *Get(int index) const
    {
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

    Truck *Add(const Truck &truck)
    {
        auto *new_truck = new Truck();
        *new_truck = truck;

        if (size == 0)
        {
            head = new_truck;
            tail = new_truck;
        }
        else
        {
            new_truck->prev = tail;
            new_truck->prev->next = new_truck;
            new_truck->next = nullptr;
            tail = new_truck;
        }

        ++size;
        return head;
    }

    void Delete(int index)
    {
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

    void PrintAll() const
    {
        for(int i = 0; i < size; ++i)
        {
            Print(i);
        }
    }

    void Print(int index) const
    {
        auto t = Get(index);
        std::cout << static_cast<int>(t->brand) << " " <<
                  t->capacity << " " <<
                  t->transportation_distance << " " <<
                  t->mileage_per_day << "\n";
    }

    void Free()
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
};

int main()
{
    TruckList truck_list{};
    Truck tr{};

    io::CSVReader<4> in("../base.csv");
    in.read_header(io::ignore_extra_column, "brand", "capacity", "transportation_distance", "mileage_per_day");
    int brand_code;
    while(in.read_row(brand_code, tr.capacity, tr.transportation_distance, tr.mileage_per_day))
    {
        tr.brand = static_cast<TruckBrand>(brand_code);
        truck_list.Add(tr);
    }

    truck_list.PrintAll();

    std::cout << truck_list.size << "\n";

    truck_list.Print(0);

    std::cout << truck_list.size << "\n";

    truck_list.Delete(2);

    std::cout << truck_list.size << "\n";

    truck_list.Delete(100);

    std::cout << truck_list.size << "\n";

    truck_list.Delete(0);

    std::cout << truck_list.size << "\n";

    truck_list.Delete(truck_list.size-1);

    std::cout << truck_list.size << "\n";




    truck_list.Free();

    return 0;
 }
