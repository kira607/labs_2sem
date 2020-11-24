#ifndef COURSEWORK_ROUTE_DB_H
#define COURSEWORK_ROUTE_DB_H

#define CSV_IO_NO_THREAD
#include "../../fast-cpp-csv-parser/csv.h"

#include "route_list.h"
#include "../destination.h"

struct RouteDataBase
{
    RouteList list{};
    std::string db_path;

    explicit RouteDataBase(const std::string &db_path_ = "../dbs/routedb.csv");

    void _loadDataBase();

    void Exit();

    // Request handler interface

    [[nodiscard]] const Route *Find(Destination destination) const;

    // Administrator Console interface
};

#endif //COURSEWORK_ROUTE_DB_H
