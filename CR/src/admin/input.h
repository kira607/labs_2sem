#ifndef COURSEWORK_INPUT_H
#define COURSEWORK_INPUT_H

#define _min_int std::numeric_limits<int>::min()
#define _max_int std::numeric_limits<int>::max()

#include <iostream>

int Input(const std::string& message = "Input: ", int l = _min_int, int r = _max_int);

#endif //COURSEWORK_INPUT_H
