#ifndef LAB2_GEN_H
#define LAB2_GEN_H

#include <random>

#include "input.h"

enum class GenType
{
    Zero = 1,
    One = 2,
    Random = 3,
    Fill0 = 4,
    Fill1 = 5,
    Input = 6,
    File = 7,
    None,
};

int GenElement(GenType gen_type, int width, int i, int j);

#endif //LAB2_GEN_H
