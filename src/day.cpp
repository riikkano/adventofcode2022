#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ifstream MyReadFile("inputs/day03.txt");
    std::string line;
    std::getline(MyReadFile, line);
    std::cout << line;
}
