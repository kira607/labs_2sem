//
// Created by kirill on 18.11.2020.
//

#include "truck_brand.h"

std::string str(TruckBrand truck_brand)
{
    switch (truck_brand)
    {
        case TruckBrand::Volvo: return "Volvo";
        case TruckBrand::MercedesBenz: return "MercedesBenz";
        case TruckBrand::Man: return "Man";
        case TruckBrand::Daf: return "Daf";
        case TruckBrand::Scania: return "Scania";
        case TruckBrand::Iveco: return "Iveco";
        case TruckBrand::Renault: return "Renault";
        case TruckBrand::Nissan: return "Nissan";
        case TruckBrand::Tatra: return "Tatra";
        case TruckBrand::Mitsubishi: return "Mitsubishi";
        case TruckBrand::NONE: return "NONE";
    }
}

