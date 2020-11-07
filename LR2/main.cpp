#include <iostream>

#include "matrix.h"
#include "menu.h"

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

    std::stringstream file_content;
    std::string plus = "+\n", equals = "=\n";

    file_content << String(a)
                 << std::right << std::setw(4) << plus
                 << String(b)
                 << std::right << std::setw(4) << equals
                 << String(c);

    std::cout << file_content.str();

    std::ofstream fout("output.txt");
    fout << file_content.str();

    Delete(a);
    Delete(b);
    Delete(c);
    return 0;
}
