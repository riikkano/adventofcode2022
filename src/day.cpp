
#include <fstream>
#include <iostream>
#include <list>
#include <string>
// #include <vector>
// #include <algorithm>
// #include <unordered_map>

std::list<std::string> split(std::string s, char delimiter)
{
    std::list<std::string> items;
    std::string item{};
    for (char c : s)
    {
        if (c != delimiter)
        {
            item.push_back(c);
        }
        else if (c == delimiter)
        {
            items.push_back(item);
            item.clear();
        }
    }
    items.push_back(item); // add last item
    return items;
}

int main()
{
    std::ifstream MyReadFile("inputs/day.txt");
    std::string line;
    std::getline(MyReadFile, line);
    std::cout << line;
    std::string s{"hek,kasi,adoa,23,sjdas,123"};
    auto splitted = split(s, ',');
    for (auto i : splitted)
    {
        std::cout << i << std::endl;
    }
}
