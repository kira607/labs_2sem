//
// Created by kirill on 19.09.2020.
//

#include "delete_words_with_char.h"

void DeleteWordsWithChar(char **strings, int lines_number, char bad_char)
{
    for(int line = 0; line < lines_number; ++line)
    {
        char *string = strings[line];
        char *new_string = (char*)calloc(sizeof(char), strlen(string));
        char *word = (char*)calloc(sizeof(char), strlen(string));

        if(!IfStringContainsChar(string, bad_char)) continue;

        for(unsigned long character_pos = 0; character_pos < strlen(string); ++character_pos)
        {
            char character = string[character_pos];
            if (character == ' ' || character == '\n' || character == EOF || character == '\0')
            {
                if(!IfStringContainsChar(word, bad_char))
                {
                    strcat(new_string, word);
                    strcat(new_string, character);
                }
                free(word);
                word = (char*)calloc(sizeof(char), strlen(string));
                continue;
            }
            else
            {
                strcat(word, character);
            }
        }

        free(strings[line]);
        if(new_string[strlen(new_string) - 1] != '\n')
        {
            strcat(new_string, '\n');
        }
        strings[line] = new_string;
    }
}