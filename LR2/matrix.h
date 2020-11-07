#ifndef LAB2_MATRIX_H
#define LAB2_MATRIX_H

#include <iostream>
#include <malloc.h>
#include <iomanip>
#include <fstream>
#include <random>

#include "gen.h"
#include "input.h"

struct Matrix2
{
    int width = 0;
    int height = 0;
    int **matrix = nullptr;
};

Matrix2 InputDimensions();

Matrix2 CreateMatrix(int w, int h, GenType gen_type = GenType::Zero);

Matrix2 LoadMatrix(const std::string& file_name);

std::string String(const Matrix2 &m);

void Print(const Matrix2 &m);

Matrix2 Sum(const Matrix2 &a, const Matrix2 &b);

void Delete(Matrix2 &m);

#endif //LAB2_MATRIX_H
