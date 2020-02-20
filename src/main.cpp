#include "to_string.h"
#include <iostream>
#include <vector>
#include <list>

int main (int, char **)
{
    char ch = -1;
    std::cout << to_string(ch) << std::endl;

    short sh = 0;
    std::cout << to_string(sh) << std::endl;

    int i = 2130706433;
    std::cout << to_string(i) << std::endl;

    long long l = 8875824491850138409;
    std::cout << to_string(l) << std::endl;

    std::string str = "12.34.56.78";
    std::cout << to_string(str) << std::endl;

    std::vector<int> vector{1, 2, 3, 4};
    std::cout << to_string(vector) << std::endl;

    std::vector<int> list{5, 6, 7, 8};
    std::cout << to_string(list) << std::endl;

    return 0;
}


