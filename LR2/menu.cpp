#include "menu.h"

void PrintMainMenu()
{
    std::cout << "1 - Fill matrix with 0" << "\n";
    std::cout << "2 - Fill matrix with 1" << "\n";
    std::cout << "3 - Fill matrix with random numbers (0-9)" << "\n";
    std::cout << "4 - Fill matrix with ordinal numbers (begin with 0)" << "\n";
    std::cout << "5 - Fill matrix with ordinal numbers (begin with 1)" << "\n";
    std::cout << "6 - Fill matrix manually" << "\n";
    std::cout << "7 - Load matrix form file" << "\n";
}

GenType ChooseGenType()
{
    PrintMainMenu();
    int option = Input("Input: ", 1, 7);
    return static_cast<GenType>(option);
}

bool TryLoad(Matrix2 &m)
{
    std::string file_name;
    std::cout << "Input name of file: ";
    std::cin >> file_name;

    Matrix2 lm = LoadMatrix(file_name);

    if (lm.width != m.width || lm.height != m.height || !lm.matrix)
    {
        std::cout << "Could not load matrix\n"
                     "File does not exist or\n"
                     "Loaded matrix has different dimensions with defined.\n"
                     "Choose other file or generate matrix with the proposed options.\n\n";
        return false;
    }

    m = lm;
    return true;
}

void Menu(Matrix2 &m)
{
    bool continue_ = true;
    while(continue_)
    {
        GenType task = ChooseGenType();
        if (task != GenType::File)
        {
            m = CreateMatrix(m.width, m.height, task);
            continue_ = false;
        }
        else
        {
            continue_ = !TryLoad(m);
        }
    }

    std::cout << "Resulting matrix:\n";
    Print(m);
}
