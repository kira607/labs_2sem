//
// Created by K on 15.09.2020.
//

#include "files_lib.h"
#include "delete_words_with_char.h"
#include "print_array_of_strings.h"

int main()
{
    char *input_file_name = (char*)"../input.txt";
    char **strings{};
    int lines_number = ReadFromFile(input_file_name, strings);
    if(lines_number == -1 || strings == nullptr)
    {
        std::cout << "An Error occurred while reading file\n";
        return 1;
    }


    char **original_strings;
    original_strings = (char**)malloc(sizeof(char*)*lines_number);
    for (int line = 0; line < lines_number; ++line)
    {
        original_strings[line] = (char*)malloc(sizeof(char)*strlen(strings[line]));
        strcpy(original_strings[line], strings[line]);
    }

    char bad_char;
    std::cout << "\nInput char:";
    std::cin >> bad_char;
    std::cout << "Deleting words with char: " << bad_char << "\n";
    DeleteWordsWithChar(strings, lines_number, bad_char);

    std::cout << "RESULT:\n=======================================================\n";
    PrintArrayOfStrings(strings, lines_number);
    std::cout << "\n=======================================================\n";

    std::cout << "Writing changes in file...\n";
    char *output_file_name = (char*)"../output.txt";
    WriteInFile(output_file_name, original_strings, strings, bad_char, lines_number);
    std::cout << "Done\n";
    return 0;
}
