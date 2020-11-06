//
// Created by kirill on 19.09.2020.
//

#include "if_string_contains_char.h"

bool IfStringContainsChar(char* string, char bad_char)
{
    char *word_ptr = string;
    while(*word_ptr) // != nullptr
    {
        if(strchr(&bad_char, *word_ptr))
        {
            return true;
        }
        ++word_ptr;
    }
    return false;
}