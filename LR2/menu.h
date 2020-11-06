#ifndef LAB2_MENU_H
#define LAB2_MENU_H

#include <iostream>
#include <fstream>

#include "matrix.h"

void PrintMainMenu();

GenType ChooseGenType();

bool TryLoad(Matrix2 &m);

void Menu(Matrix2 &m);

#endif //LAB2_MENU_H
