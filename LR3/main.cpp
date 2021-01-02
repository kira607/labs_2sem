#include <iostream>
#include <sstream>
#include <cstring>

#include "truck/lib_truck.h"

enum Command
{
    Add,
    Load,
    Save,
    Print,
    Help,
    Exit,
    Skip,
    NONE,
};

struct Input
{
    Command command = Command::NONE;
    int argc = 0;
    char **argv = nullptr;
};

Input GetInput()
{
    const int buff_size = 100 + 1;
    char *line = new char[buff_size];
    std::cin.getline(line, buff_size, '\n');
    if(line[0] == '\0')
    {
        return Input{Command::Skip};
    }
    if(std::cin.fail())
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Input input;
    input.argc = 0;
    input.argv = (char**)malloc(sizeof(char*) * 1);

    std::stringstream ss{line};
    std::string word;
    while(getline(ss, word, ' '))
    {
        input.argv[input.argc] = new char[word.size()];
        strcpy(input.argv[input.argc], word.c_str());
        size_t new_size = sizeof(char*) * (input.argc + 2);
        input.argv = (char**)realloc(input.argv, new_size);
        ++input.argc;
    }
    return input;
}

void RunCommand(TruckList &list, Input input)
{
    switch(input.command)
    {
        case Add:
            break;
        case Load:
            break;
        case Save:
            break;
        case Print:
            break;
        case Help:
        {
            std::cout << "\nCommands\n";
            std::cout << "add - add new item in list\n";
            std::cout << "load <file> - load list from file\n";
            std::cout << "save <path> - save list in file\n";
            std::cout << "print [index] - print all items (when [index] given prints item with index)\n";
            std::cout << "help - see this help\n";
            std::cout << "exit - exit program\n\n";
        }
            break;
        case Exit:
            break;
        case Skip:
            break;
        case NONE:
            break;
    }
}

Command ParseInput(Input &input)
{
    std::string command_str;
    int command_pos;
    for(command_pos = 0; command_pos < input.argc; ++command_pos)
    {
        if(strcmp(input.argv[command_pos], " ") != 0)
        {
            command_str = input.argv[command_pos];
        }
    }

    input.command = Command::NONE;
    if(command_str == "add") input.command = Command::Add;
    if(command_str == "load") input.command = Command::Load;
    if(command_str == "save") input.command = Command::Save;
    if(command_str == "print") input.command = Command::Print;
    if(command_str == "help") input.command = Command::Help;
    if(command_str == "exit") input.command = Command::Exit;

    int arg_pos;
    std::string arg_str;
    for(arg_pos = command_pos; arg_pos < input.argc; ++arg_pos)
    {
        if(strcmp(input.argv[arg_pos], " ") != 0)
        {
            arg_str = input.argv[arg_pos];
        }
    }

    switch(input.command)
    {
        case Load:

        case Save:
        case Print:
        case Add:
        case Help:
        case Exit:
        case Skip:
        case NONE:
        default:
          return input.command;
    }
}

void StripInput(Input &input)
{
    for(int i = 0; i < input.argc; ++i)
    {
        if(strcmp(input.argv[i], " ") != 0)
        {
            std::string value = input.argv[i];
        }
    }
}

int main()
{
    TruckList list{};
    const std::string prompt = "LR3$>";
    Command command = Command::NONE;

    while(command != Command::Exit)
    {
        std::cout << prompt;
        Input input = GetInput();
        if(input.command == Command::Skip) continue;
        if((command = ParseInput(input)) == Command::NONE)
        {
            std::cout << "Unknown command '" << input.argv[0] << "'. Try 'help'\n";
            continue;
        }
        input.command = command;
        RunCommand(list, input);
    }
    return 0;
}
