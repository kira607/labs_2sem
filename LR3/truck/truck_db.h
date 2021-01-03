#ifndef COURSEWORK_TRUCK_DB_H
#define COURSEWORK_TRUCK_DB_H

#define CSV_IO_NO_THREAD

#include <iomanip>
#include <fstream>
#include <filesystem>

#include "fast-cpp-csv-parser/csv.h"
#include "truck_list.h"
#include "../input.h"

struct TruckDataBase
{
    TruckList list{};

    TruckDataBase() = default;

    void PrintAll() const;
    void Print(int index, bool print_header = false) const;

    void Edit(int index);
    void Add();
    void Delete(int index);

    void Exit();

    void Load(const std::string& db_path);
    void Save(const std::string& db_path) const;
};

#endif //COURSEWORK_TRUCK_DB_H
