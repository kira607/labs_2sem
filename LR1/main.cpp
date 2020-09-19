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
    const int max_string_len = 256;
    const int max_strings_capacity = 256;
    char* strings[max_strings_capacity];
    int lines_number = ReadFromFile(input_file_name, strings, max_string_len, max_strings_capacity);
    char bad_char;
    printf("Input char:");
    scanf("%c", &bad_char);
    printf("Deleting words with char: %c\n", bad_char);
    DeleteWordsWithChar(strings, lines_number, max_string_len, bad_char);
    std::cout << "Writing changes in file...\n";
    WriteInFile(output_file_name, strings, lines_number);
    return 0;
}
