#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

int main()
{
    std::ifstream MyReadFile("inputs/day02.txt");
    std::string round;

    int32_t total_score = 0;
    std::unordered_map<char, int32_t> opponent_shapes = {
        {'A', 1}, {'B', 2}, {'C', 3}};
    std::unordered_map<char, int32_t> my_shapes = {
        {'X', 1}, {'Y', 2}, {'Z', 3}};

    while (std::getline(MyReadFile, round))
    {
        char opponent_shape = round[0];
        char my_shape = round[2];
        total_score += my_shapes[my_shape];
        // rock looses to paper
        if (my_shapes[my_shape] == 3 && opponent_shapes[opponent_shape] == 1)
        {
            total_score += 0;
        }
        // paper wins rock
        else if (
            my_shapes[my_shape] == 1 && opponent_shapes[opponent_shape] == 3)
        {
            total_score += 6;
        }
        else if (my_shapes[my_shape] > opponent_shapes[opponent_shape])
        {
            total_score += 6;
        }
        else if (my_shapes[my_shape] == opponent_shapes[opponent_shape])
        {
            total_score += 3;
        }
    }

    // Part 1
    std::cout << total_score << "\n";
}
