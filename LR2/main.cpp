#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <fstream>
#include <random>

#define _min_int std::numeric_limits<int>::min()
#define _max_int std::numeric_limits<int>::max()

enum class GenType
{
    Zero = 1,
    One = 2,
    Random = 3,
    Fill0 = 4,
    Fill1 = 5,
    Input = 6,
    File = 7,
    None,
};

struct Matrix2
{
    int width, height;
    int **matrix;
};

int Input(const std::string& message = "Input: ", int l = _min_int, int r = _max_int)
{
    int element;
    bool input = true;
    while(input)
    {
        std::cout << message;
        std::cin >> element;
        if(std::cin.fail() || (element < l || element > r))
            std::cout << "Wrong input!\n";
        else
            input = false;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    return element;
}

int InputElement(int i, int j)
{
    std::stringstream ss;
    ss << "Input element ["<<i<<"]["<<j<<"]: ";
    return Input(ss.str());
}

int GenElement(GenType gen_type, int width = 0, int i = 0, int j = 0)
{
    switch (gen_type)
    {
        case GenType::Zero:
            return 0;
        case GenType::One:
            return 1;
        case GenType::Random:
        {
            std::random_device rd;
            std::mt19937 Rand(rd());
            return std::abs(static_cast<int>(Rand())) % 10;
        }
        case GenType::Fill0:
            return i*width+j;
        case GenType::Fill1:
            return i*width+j+1;
        case GenType::Input:
            return InputElement(i, j);
        case GenType::File:
        case GenType::None:
            return -1;
    }
}

Matrix2 CreateMatrix(int w, int h, GenType gen_type = GenType::Zero)
{
    Matrix2 result = Matrix2();
    result.width = w;
    result.height = h;
    result.matrix = (int**)calloc(result.height, sizeof(int*));
    for(int i = 0; i < result.height; ++i)
    {
        result.matrix[i] = (int*)calloc(result.width, sizeof(int));
        for(int j = 0; j < result.width; ++j)
        {
            int new_element = GenElement(gen_type, result.width, i, j);
            result.matrix[i][j] = new_element;
        }
    }
    return result;
}

Matrix2 LoadMatrix(const std::string& file_name)
{
    Matrix2 result = Matrix2();

    std::ifstream fin(file_name);
    if(!fin)
    {
        throw std::exception();
    }
    fin >> result.width >> result.height;

    result.matrix = (int**)calloc(result.height, sizeof(int*));
    for(int i = 0; i < result.height; ++i)
    {
        result.matrix[i] = (int*)calloc(result.width, sizeof(int));
        for(int j = 0; j < result.width; ++j)
        {
            int new_element;
            fin >> new_element;
            result.matrix[i][j] = new_element;
        }
    }

    return result;
}

void Print(Matrix2 m)
{
    for(int i = 0; i < m.height; ++i)
    {
        for(int j = 0; j < m.width; ++j)
        {
            std::cout << std::right << std::setw(5) << m.matrix[i][j] << " ";
        }
        std::cout << "\n";
    }
}

Matrix2 Sum(Matrix2 a, Matrix2 b)
{
    if(a.width != b.width || a.height != b.height)
    {
        throw std::exception();
    }

    Matrix2 result = CreateMatrix(a.width, a.height, GenType::Zero);
    for(int i = 0; i < a.height; ++i)
    {
        for(int j = 0; j < a.width; ++j)
        {
            result.matrix[i][j] = a.matrix[i][j] + b.matrix[i][j];
        }
    }

    return result;
}

void Delete(Matrix2 m)
{
    for(int i = 0; i < m.height; ++i)
    {
        free(m.matrix[i]);
    }
}

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

Matrix2 InputDimensions()
{
    Matrix2 result{};
    result.width = Input("Width: ", 1);
    result.height = Input("Height: ", 1);
    return result;
}

void Menu(Matrix2 &m)
{
    GenType task = ChooseGenType();
    if (task != GenType::File)
    {
        m = CreateMatrix(m.width, m.height, task);
    }
    else
    {
        std::string file_name;
        std::cout << "Input name of file: ";
        std::cin >> file_name;
        Matrix2 lm = LoadMatrix(file_name);
        if(lm.width != m.width || lm.height != m.height)
        {
            std::cout << "Loaded matrix has different dimensions with defined.\n"
                         "Choose other file or generate matrix with the proposed options.\n";
        }
        else
        {
            m = lm;
        }
    }

    std::cout << "Resulting matrix:\n";
    Print(m);
}

int main()
{
    std::cout << "Matrix addition program. (c) 2020\n"
                 "Enter the dimensions of the summed matrices: \n";

    Matrix2 a = InputDimensions(), b = a;

    std::cout << "\nMatrix 1: \n\n";
    Menu(a);
    std::cout << "\nMatrix 2: \n\n";
    Menu(b);

    Matrix2 c = Sum(a, b);
    std::cout << "============================================\n"
                 "Sum:\n";
    Print(a);
    std::cout << "  +\n";
    Print(b);
    std::cout << "  =\n";
    Print(c);

    // Write(file, a);
    // Write(file, b);
    // Write(file);
    // Write(file, c);

    Delete(a);
    Delete(b);
    Delete(c);
    return 0;
}
