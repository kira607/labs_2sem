#include "input.h"

int Input(const std::string& message, int l, int r)
{
    int element;
    bool input = true;
    while (input)
    {
        std::cout << message;
        std::cin >> element;
        if (std::cin.fail() || (element < l || element > r))
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
