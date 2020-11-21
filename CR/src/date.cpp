//
// Created by kirill on 20.11.2020.
//

#include "date.h"

Date::Date()
{
    date = new tm;
    default_format = "%d.%m.%Y %H:%M";
}

void Date::Set(const std::string &date_str, const std::string &format) const
{
    std::string local_format;
    if (format.empty())
        local_format = default_format;
    else
        local_format = format;

    strptime(date_str.c_str(), local_format.c_str(), date);
}

[[nodiscard]] std::string Date::String() const
{
    int buff_size = 20;
    char buffer[buff_size];
    strftime(buffer, buff_size, default_format.c_str(), date);
    return std::string(buffer);
}
