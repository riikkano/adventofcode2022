#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Rucksack Reorganization part 2
int main()
{
    std::ifstream MyReadFile("inputs/day03.txt");
    std::string rucksack1;
    std::string rucksack2;
    std::string rucksack3;
    int32_t sum = 0;

    while (std::getline(MyReadFile, rucksack1))
    {
        std::getline(MyReadFile, rucksack2);
        std::getline(MyReadFile, rucksack3);
        uint32_t priorities = 0;
        for (char item : rucksack1)
        {
            if (rucksack2.find(item) != std::string::npos &&
                rucksack3.find(item) != std::string::npos)
            {
                if (islower(item))
                {
                    priorities += item - 96; // a = 95
                }
                else
                {
                    priorities += item - 38; // A = 65
                }
                break;
            };
        }
        sum += priorities;
    }
    std::cout << sum << "\n";
}
