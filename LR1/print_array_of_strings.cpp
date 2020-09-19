//
// Created by kirill on 19.09.2020.
//

#include "print_array_of_strings.h"

void PrintArrayOfStrings(char **strings, int lines_number)
{
    for(int line = 0; line < lines_number; ++line)
    {
        printf("%s", strings[line]);
    }
}