#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

// Rucksack Reorganization
int main()
{
    std::ifstream MyReadFile("inputs/day03.txt");
    std::string rucksack;
    int32_t sum = 0;

    while (std::getline(MyReadFile, rucksack))
    {
        std::string compartment2 = rucksack.substr(rucksack.size() / 2);
        size_t compartment_size = rucksack.size() / 2;
        uint32_t priorities = 0;
        for (size_t i = 0; i < compartment_size; i++)
        {
            if (compartment2.find(rucksack[i]) != std::string::npos)
            {
                if (islower(rucksack[i]))
                {
                    priorities += rucksack[i] - 96; // a = 95
                }
                else
                {
                    priorities += rucksack[i] - 38; // A = 65
                }
                break;
            };
        }
        sum += priorities;
    }
    std::cout << sum << "\n";
}
