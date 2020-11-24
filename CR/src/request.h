#ifndef COURSEWORK_REQUEST_H
#define COURSEWORK_REQUEST_H

#include <fstream>
#include <string>

#define CSV_IO_NO_THREAD
#include "../fast-cpp-csv-parser/csv.h"

#include "destination.h"
#include "truck_brand.h"
#include "date.h"

struct Request
{
    Destination destination = Destination::NONE;
    Date departure_date{};
    float cargo_weight{};
    TruckBrand truck_brand = TruckBrand::NONE;
};

struct RequestLoader
{
    Request request;
    Request Load(const std::string &file_name);
};

struct RequestHandler
{
    Request request;
    std::string request_path;

    explicit RequestHandler(const std::string &file_path);
    void Run();
};

#endif //COURSEWORK_REQUEST_H
