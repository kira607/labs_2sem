//
// Created by kirill on 20.11.2020.
//

#ifndef COURSEWORK_DATE_H
#define COURSEWORK_DATE_H

#include <string>
#include <ctime>

struct Date
{
    std::string default_format;
    tm *date;

    Date();
    void Parse(const std::string &date_str, const std::string &format = "");
    [[nodiscard]] std::string String() const;
};

#endif //COURSEWORK_DATE_H
