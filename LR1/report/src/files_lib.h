//
// Created by kirill on 19.09.2020.
//

#ifndef LAB1_FILES_LIB_H
#define LAB1_FILES_LIB_H

#include <iostream>
#include <cstring>
#include <string>

#include "strcat_impl.h"

int ReadFromFile(const std::string& file_name, char **&strings);
void WriteInFile(const std::string&, char **, char **, char, int);

#endif //LAB1_FILES_LIB_H
