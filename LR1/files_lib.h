//
// Created by kirill on 19.09.2020.
//

#ifndef LAB1_FILES_LIB_H
#define LAB1_FILES_LIB_H

#include <iostream>
#include <cstring>
#include <string>

int ReadFromFile(const std::string& file_name, char **strings, int string_len, int strings_capacity);
void WriteInFile(const std::string& file_name, char **strings, int lines_number);

#endif //LAB1_FILES_LIB_H
