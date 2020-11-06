#include "menu.h"

void PrintMainMenu()
{
    std::cout << "1 - Заполнить матрицу нулями" << "\n";
    std::cout << "2 - Заполнить матрицу единицами" << "\n";
    std::cout << "3 - Заполнить матрицу случайными числами (0-9)" << "\n";
    std::cout << "4 - Заполнить матрицу порядковыми номерами (с 0)" << "\n";
    std::cout << "5 - Заполнить матрицу порядковыми номерами (с 1)" << "\n";
    std::cout << "6 - Заполнить матрицу вручную" << "\n";
    std::cout << "7 - Загрузить матрицу из файла" << "\n";
}

GenType ChooseGenType()
{
    int option;
    PrintMainMenu();
    option = Input("Input: ", 1, 7);
    return static_cast<GenType>(option);
}

bool TryLoad(Matrix2 &m)
{
    std::string file_name;
    std::cout << "Input name of file: ";
    std::cin >> file_name;
    Matrix2 lm = LoadMatrix(file_name);

    if (lm.width != m.width || lm.height != m.height)
    {
        std::cout << "Loaded matrix has different dimensions with defined.\n"
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
