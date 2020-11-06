#include "gen.h"

int GenElement(GenType gen_type, int width, int i, int j)
{
    switch (gen_type)
    {
        case GenType::Zero:
            return 0;
        case GenType::One:
            return 1;
        case GenType::Random:
        {
            std::random_device rd;
            std::mt19937 Rand(rd());
            return std::abs(static_cast<int>(Rand())) % 10;
        }
        case GenType::Fill0:
            return i*width+j;
        case GenType::Fill1:
            return i*width+j+1;
        case GenType::Input:
            return InputElement(i, j);
        case GenType::File:
        case GenType::None:
        default:
            return -1;
    }
}