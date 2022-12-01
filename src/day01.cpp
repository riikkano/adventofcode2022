#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int main()
{
    std::ifstream MyReadFile("inputs/day01.txt");
    std::string line;
    std::vector<int32_t> sums = {};

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

    // add the last sum of calories
    sums.push_back(sum);

    std::sort(sums.begin(), sums.end());
    std::cout << sums[sums.size() - 1] + sums[sums.size() - 2] +
                     sums[sums.size() - 3]
              << "\t";
}