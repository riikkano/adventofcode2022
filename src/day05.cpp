#include <deque>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>
// #include <algorithm>
// #include <unordered_map>

// Day 5: Supply Stacks part 2
int main()
{
    std::ifstream MyReadFile("inputs/day05.txt");
    std::string line;
    size_t pile_count = 0;

    // find number of how many piles to create
    while (std::getline(MyReadFile, line))
    {
        if (line.empty())
        {
            break;
        }
        for (char c : line)
        {
            if (c == '[') // skip crates
            {
                break;
            }

            else if ('1' <= c && c <= '9')
            {
                pile_count = int32_t(c) - '0';
            }
        }
    }

    // create the piles
    std::vector<std::deque<char>> piles;
    for (size_t i = 0; i < pile_count; i++)
    {
        piles.push_back(std::deque<char>{});
    }

    // initialize crate stacks with crates
    MyReadFile.seekg(0);
    while (std::getline(MyReadFile, line))
    {
        if (line.empty())
        {
            break;
        }
        size_t location = 0;
        for (size_t i = 1; i < line.size();
             i += 4) // every 4th character is a crate
        {
            char c = line.at(i);
            if ('A' <= c && c <= 'Z') // is uppercase letter in ASCII
            {
                char &crate = c;
                std::deque<char> &pile = piles.at(location);
                pile.push_back(crate);
            }
            location += 1;
        }
    }

    // move crates from pile to pile accordingly
    while (std::getline(MyReadFile, line))
    {
        size_t start = line.find("move ") + 5;
        size_t end = line.find(" from");
        int32_t repetitions = std::stoi(line.substr(start, end - start));
        start = line.find("from ") + 5;
        end = line.find(" to");
        int32_t position1 = std::stoi(line.substr(start, end - start));
        start = line.find("to ") + 3;
        end = line.size();
        int32_t position2 = std::stoi(line.substr(start, end - start));

        std::deque<char> pile_to_move = {};
        // load the pile
        for (size_t i = 1; i <= repetitions; i++)
        {
            char &crate = piles.at(position1 - 1).front();
            pile_to_move.push_front(crate);
            piles.at(position1 - 1).pop_front();
        }
        // unload the pile
        for (size_t i = 1; i <= repetitions; i++)
        {
            char &crate = pile_to_move.front();
            piles.at(position2 - 1).push_front(crate);
            pile_to_move.pop_front();
        }
    }

    for (std::deque crates : piles)
    {
        std::cout << crates.front();
    }
    std::cout << std::endl;
}
