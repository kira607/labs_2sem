//
// Created by kirill on 18.11.2020.
//

#ifndef COURSEWORK_DESTINATION_H
#define COURSEWORK_DESTINATION_H

#include <string>

enum class Destination
{
    Omsk,
    Kaliningrad,
    StPetersburg,
    Novgorod,
    Sochi,
    Murmansk,
    NONE
};

std::string str(Destination destination);

#endif //COURSEWORK_DESTINATION_H
