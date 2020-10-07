//
// Created by K on 15.09.2020.
//

#include "files_lib.h"
#include "delete_words_with_char.h"
#include "print_array_of_strings.h"

int main()
{
    char *input_file_name = (char*)"../input.txt";
    char *output_file_name = (char*)"../output.txt";
    char **strings{};
    int lines_number = ReadFromFile(input_file_name, strings);
    if(lines_number == -1 || strings == nullptr)
    {

        return 1;
    }
    char **original_strings;
    original_strings = (char**)malloc(sizeof(char*)*lines_number);
    for (int line = 0; line < lines_number; ++line)
    {
        original_strings[line] = (char*)malloc(sizeof(char)*strlen(strings[line]));
        strcpy(original_strings[line], strings[line]);
    }
    PrintArrayOfStrings(strings,lines_number);
    char bad_char;
    printf("Input char:");
    scanf("%c", &bad_char);
    printf("Deleting words with char: %c\n", bad_char);
    DeleteWordsWithChar(strings, lines_number, bad_char);
    std::cout << "RESULT:\n=======================================================\n";
    PrintArrayOfStrings(strings, lines_number);
    std::cout << "=======================================================\n";
    std::cout << "Writing changes in file...\n";
    WriteInFile(output_file_name, strings, lines_number);
    return 0;
}
