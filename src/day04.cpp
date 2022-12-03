#include <fstream>
#include <iostream>
#include <string>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

int main()
{
    std::ifstream MyReadFile("inputs/day04.txt");
    std::string line;
    std::getline(MyReadFile, line);
    std::cout << line;
}
