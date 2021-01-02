#ifndef COURSEWORK_TRUCK_DB_H
#define COURSEWORK_TRUCK_DB_H

#define CSV_IO_NO_THREAD

#include <iomanip>
#include <fstream>

// #include "../../../fast-cpp-csv-parser/csv.h"
#include "truck_list.h"

struct TruckDataBase
{
    TruckList list{};

    TruckDataBase() = default;

    void PrintAll() const;
    void Print(int index) const;

    void Edit(int index);
    void Add();
    void Delete(int index);

    void Exit();

    void _loadDataBase();
    void _updateDbFile() const;
};

#endif //COURSEWORK_TRUCK_DB_H
