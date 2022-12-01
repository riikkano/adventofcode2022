#include <algorithm>
#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ifstream MyReadFile("inputs/day01.txt");
    std::string line;
    std::vector<uint32_t> sums = {};

    int32_t sum = 0;
    while (std::getline(MyReadFile, line))
    {
        if (line.empty())
        {
            sums.push_back(sum);
            sum = 0;
        }
        else
        {
            int32_t calories = std::stoi(line);
            sum = sum + calories;
        }
    }

    auto max = std::max_element(sums.begin(), sums.end());
    std::cout << "hello";
}