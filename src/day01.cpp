#include <fstream>
#include <iostream>
#include <string>

int main()
{
    std::ifstream MyReadFile("inputs/day01.txt");
    std::string line;
    std::getline(MyReadFile, line);
    std::cout << line;
}