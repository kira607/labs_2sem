//
// Created by kirill on 19.09.2020.
//

#include "strcat_impl.h"

char *strcat (char *dest, char character)
{
    char* char_ptr = (char*)malloc(sizeof(char)*2);
    *char_ptr = character;
    *(char_ptr + 1) = '\0';
    auto result = strcat(dest, char_ptr);
    free(char_ptr);
    return strcat(dest, result);
}