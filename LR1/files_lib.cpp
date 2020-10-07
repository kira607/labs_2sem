//
// Created by kirill on 19.09.2020.
//


#include "files_lib.h"

int ReadFromFile(const std::string& file_name, char **strings)
{
    // open file
    FILE *input_file;
    if((input_file = fopen(file_name.c_str(), "r")) == nullptr)
    {
        std::cout << "Could not open \"" << file_name << "\"\n";
        return -1;
    }

    int chunk_len = 10;
    int line = 0;
    int line_size = 0;
    strings[0] = (char*)malloc(sizeof(char) * chunk_len);
    char current_char;
    while((current_char = static_cast<char>(fgetc(input_file))) != EOF)
    {
        ++line_size;

        // extend memory for string if needed
        if(line_size % chunk_len == 0)
        {
            strings[line] = (char*)realloc(strings[line], sizeof(char) * (line_size + chunk_len));
        }

        // add current_char in string
        strcat(strings[line], current_char);

        // to new line if needed
        if (current_char == '\n')
        {
            strcat(strings[line], '\0');
            line_size -= line_size;
            ++line;
            strings[line] = (char*)calloc(chunk_len, sizeof(char));
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

void WriteInFile(const std::string& file_name, char *string)
{
    FILE* output_file;
    // write in file
    if((output_file = fopen(file_name.c_str(), "w")) == nullptr)
    {
        std::cout << "Could not open \"" << file_name << "\"\n";
        return;
    }
    fputs(string, output_file);
    fclose(output_file);
}