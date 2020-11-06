#ifndef LAB2_INPUT_H
#define LAB2_INPUT_H

#define _min_int std::numeric_limits<int>::min()
#define _max_int std::numeric_limits<int>::max()

#include <iostream>
#include <sstream>

int Input(const std::string& message = "Input: ", int l = _min_int, int r = _max_int);
int InputElement(int i, int j);

#endif //LAB2_INPUT_H
