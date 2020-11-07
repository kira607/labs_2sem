#include "matrix.h"

Matrix2 InputDimensions()
{
    Matrix2 result{};
    result.width = Input("Width: ", 1);
    result.height = Input("Height: ", 1);
    return result;
}

Matrix2 CreateMatrix(int w, int h, GenType gen_type)
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
        return result;
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

std::string String(const Matrix2 &m)
{
    std::stringstream ss;
    for(int i = 0; i < m.height; ++i)
    {
        for(int j = 0; j < m.width; ++j)
        {
            ss << std::right << std::setw(5) << m.matrix[i][j] << " ";
        }
        ss << "\n";
    }
    return ss.str();
}

void Print(const Matrix2 &m)
{
    std::cout << String(m);
}

Matrix2 Sum(const Matrix2 &a, const Matrix2 &b)
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

void Delete(Matrix2 &m)
{
    for(int i = 0; i < m.height; ++i)
    {
        free(m.matrix[i]);
    }
    free(m.matrix);
}
