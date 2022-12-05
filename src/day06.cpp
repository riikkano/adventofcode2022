
#include <fstream>
#include <iostream>
#include <string>
// #include <list>
// #include <algorithm>
// #include <unordered_map>

// Day 6: Tuning Trouble part 2
int main()
{
    std::ifstream MyReadFile("inputs/day06.txt");
    std::string line{};
    std::getline(MyReadFile, line);
    size_t marker_size{14}; // in part 1 marker_size = 4;

    for (size_t i = 0; i < line.size(); i++)
    {
        std::string marker{line.substr(i, marker_size)};
        size_t unique{0};
        for (char c : marker)
        {
            size_t pos_first{marker.find_first_of(c)};
            size_t pos_last{marker.find_last_of(c)};
            if (pos_first == pos_last)
            {
                unique++;
            }
            else
            {
                break;
            }
        }
        if (unique == marker.size())
        {
            std::cout << i + marker.size() << std::endl;
            break;
        }
    }
}
