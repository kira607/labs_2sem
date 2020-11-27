#ifndef COURSEWORK_ROUTE_DB_H
#define COURSEWORK_ROUTE_DB_H

#define CSV_IO_NO_THREAD

#include "../../fast-cpp-csv-parser/csv.h"
#include "route_list.h"
#include "../common/destination.h"

struct RouteDataBase
{
    RouteList list{};
    std::string db_path;

    explicit RouteDataBase(const std::string &db_path_ = "../dbs/routedb.csv");

    void PrintAll() const;
    void Print(int index) const;
    
    [[nodiscard]] Route *Find(Destination destination) const;

    void Exit();

    void _loadDataBase();
};

#endif //COURSEWORK_ROUTE_DB_H
