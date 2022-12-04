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
    int32_t sum = 0;
    while (std::getline(MyReadFile, line))
    {
        std::string elf1 = line.substr(0, line.find(','));
        std::string elf2 = line.substr(line.find(',') + 1, line.size());
        // parse lower and higher bounds for elf1
        int32_t elf1_low = std::stoi(elf1.substr(0, elf1.find('-')));
        int32_t elf1_high =
            std::stoi(elf1.substr(elf1.find('-') + 1, line.size()));
        // parse lower and higher bounds for elf2
        int32_t elf2_low = std::stoi(elf2.substr(0, elf2.find('-')));
        int32_t elf2_high =
            std::stoi(elf2.substr(elf2.find('-') + 1, line.size()));

        if (elf1_low <= elf2_low && elf2_low <= elf1_high)
        {
            sum += 1;
        }
        else if (elf1_low <= elf2_high && elf2_high <= elf1_high)
        {
            sum += 1;
        }
        else if (elf2_low <= elf1_low && elf1_low <= elf2_high)
        {
            sum += 1;
        }
        else if (elf2_low <= elf1_high && elf1_high <= elf2_high)
        {
            sum += 1;
        }
    }
    std::cout << sum << "\n";
}
