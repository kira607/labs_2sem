#include "route_db.h"

RouteDataBase::RouteDataBase(const std::string &db_path_)
{
    db_path = db_path_;
    _loadDataBase();
}

const Route *RouteDataBase::Find(Destination destination) const
{
    for(int i = 0; i < list.size; ++i)
    {
        Route *current_route = list.Get(i);
        if(current_route->destination == destination)
        {
            return current_route;
        }
    }
    return nullptr;
}

void RouteDataBase::Exit()
{
    list.Free();
}

void RouteDataBase::_loadDataBase()
{
    Route route{};

    io::CSVReader<5> in(db_path);
    in.read_header(io::ignore_extra_column, "destination_code", "distance", "loading_time", "drivers", "time_in_transit");
    int destination_code;
    while(in.read_row(destination_code, route.distance, route.loading_time, route.drivers,
                      route.target_time_in_transit))
    {
        route.destination = static_cast<Destination>(destination_code);
        list.Add(route);
    }
}