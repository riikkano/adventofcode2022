#include <fstream>
#include <iostream>
#include <string>
#include <vector>
#define bit_length 12

char get_bit_criteria(size_t n, size_t zero_counter)
{
    char bit_criteria = '0';
    if (n - zero_counter < zero_counter)
    {
        bit_criteria = '0';
    }
    else if (n - zero_counter >= zero_counter)
    {
        bit_criteria = '1';
    }
    return bit_criteria;
}

char get_bit_criteria2(size_t n, size_t zero_counter)
{
    char bit_criteria = '0';
    if (n - zero_counter <= zero_counter)
    {
        bit_criteria = '0';
    }
    else if (n - zero_counter > zero_counter)
    {
        bit_criteria = '1';
    }
    return bit_criteria;
}

int main()
{
    // 7.00-9.15
    std::cout << "Day3";

    // Read file
    std::string line;

    std::ifstream MyReadFile("inputs/binary_diagnostic.txt");
    std::vector<std::string> binaries;

    size_t zero_counter = 0;

    while (std::getline(MyReadFile, line))
    {
        // Tallenna bitti
        binaries.push_back(line);
        if (line[0] == '0')
        {
            zero_counter++;
        }
    }

    // Check intial bit_criteria
    char bit_criteria_o = get_bit_criteria(binaries.size(), zero_counter);
    char bit_criteria_co2 =
        get_bit_criteria2(binaries.size(), binaries.size() - zero_counter);

    zero_counter = 0;
    size_t j = 0; // bit iterator

    std::vector<std::string> accepted_binaries = {};
    accepted_binaries.reserve(binaries.size());

    std::vector<std::string> o_generator = binaries;

    while (o_generator.size() > 1)
    {
        zero_counter = 0;
        accepted_binaries = {};
        for (size_t i = 0; i < o_generator.size(); i++)
        {
            if (o_generator[i][j] == bit_criteria_o)
            {
                accepted_binaries.push_back(o_generator[i]);
                if (o_generator[i][j + 1] == '0')
                {
                    zero_counter++;
                }
            }
        }
        j++;
        bit_criteria_o =
            get_bit_criteria(accepted_binaries.size(), zero_counter);
        o_generator = accepted_binaries;
    }

    std::vector<std::string> co2_rubber = binaries;

    zero_counter = 0;
    j = 0; // bit iterator
    while (co2_rubber.size() > 1)
    {
        zero_counter = 0;
        accepted_binaries = {};
        for (size_t i = 0; i < co2_rubber.size(); i++)
        {
            if (co2_rubber[i][j] == bit_criteria_co2)
            {
                accepted_binaries.push_back(co2_rubber[i]);
                if (co2_rubber[i][j + 1] == '0')
                {
                    zero_counter++;
                }
            }
        }
        j++;
        bit_criteria_co2 = get_bit_criteria2(
            accepted_binaries.size(), accepted_binaries.size() - zero_counter);
        co2_rubber = accepted_binaries;
    }

    std::bitset<bit_length> co2(co2_rubber[0]);
    std::bitset<bit_length> o(o_generator[0]);

    std::cout << "\t" << co2.to_ulong() * o.to_ulong();
}