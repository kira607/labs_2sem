//
// Created by kiril on 20.11.2020.
//

#include "request.h"

Request RequestLoader::Load(const std::string &file_name)
{
    int destination_code;
    int truck_brand_code;
    std::string departure_date;

    io::CSVReader<4> in(file_name);
    in.read_header(io::ignore_extra_column, "destination", "departure_date", "cargo_weight", "truck_brand");
    while(in.read_row(destination_code, departure_date, request.cargo_weight, truck_brand_code))
    {
        request.destination = static_cast<Destination>(destination_code);
        request.truck_brand = static_cast<TruckBrand>(truck_brand_code);
        request.departure_date.SetFromString(departure_date);
    }
    return request;
}

RequestHandler::RequestHandler(const std::string &file_path)
{
    request_path = file_path;
}

void RequestHandler::Run()
{
    RequestLoader rl;
    request = rl.Load(request_path);
    //find
}