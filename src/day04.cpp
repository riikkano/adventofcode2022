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
    int32_t sum = 0;
    while (std::getline(MyReadFile, line))
    {
        std::string elf1 = line.substr(0, line.find(','));
        std::string elf2 = line.substr(line.find(',') + 1, line.size());

        int32_t elf1_low = std::stoi(elf1.substr(0, elf1.find('-')));
        int32_t elf1_high =
            std::stoi(elf1.substr(elf1.find('-') + 1, line.size()));
        int32_t elf2_low = std::stoi(elf2.substr(0, elf2.find('-')));
        int32_t elf2_high =
            std::stoi(elf2.substr(elf2.find('-') + 1, line.size()));
        // elf2 area is within elf1 area
        if (elf1_low <= elf2_low && elf2_high <= elf1_high)
        {
            sum += 1;
        }
        // elf1 area is within elf2 area
        else if (elf2_low <= elf1_low && elf1_high <= elf2_high)
        {
            sum += 1;
        }
    }
    std::cout << sum << "\n";
}
