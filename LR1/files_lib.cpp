//
// Created by kirill on 19.09.2020.
//


#include "files_lib.h"

int ReadFromFile(const std::string& file_name, char **strings, int string_len, int strings_capacity)
{
    FILE *input_file = nullptr;
    if((input_file = fopen(file_name.c_str(), "r")) == nullptr)
    {
        std::cout << "Could not open \"" << file_name << "\"\n";
        return -1;
    }
    int line = 0;
    strings[0] = (char*)malloc(sizeof(char)*string_len);
    while(fgets(strings[line], string_len, input_file) != nullptr)
    {
        if (line - strings_capacity + 1)
        {
            ++line;
            strings[line] = (char *) malloc(sizeof(char) * string_len);
        }
        else
        {
            break;
        }
    }
    fclose(input_file);
    return line;
}

void WriteInFile(const std::string& file_name, char **strings, int lines_number)
{
    FILE* output_file = nullptr;
    // write in file
    if((output_file = fopen(file_name.c_str(), "w")) == nullptr)
    {
        std::cout << "Could not open \"" << file_name << "\"\n";
        return;
    }

    for(int line = 0; line < lines_number; ++line)
    {
        fputs(strings[line], output_file);
    }

    fclose(output_file);
}