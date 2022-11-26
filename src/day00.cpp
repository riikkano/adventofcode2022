#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string line; 

    std::ifstream MyReadFile("inputs/day00.txt");
   
    int32_t counter = 0;

    std::deque<int> values = {0,0,0,0};

    // Read first window
    for (int i=0; i < 3; i++) {
        std::getline(MyReadFile,line);
        int32_t reading = std::stoi(line);
        values.push_front(reading);
        values.pop_back();
    }

    // Initiate previous sum
    int previousSum = values[0] + values[1] + values[2];

    std::cout << previousSum << " (N/A - no previous measurement)\n";


    while (std::getline(MyReadFile, line)){
        int32_t reading = std::stoi(line);
        values.push_front(reading);
        values.pop_back();

        int sum = values[0] + values[1] + values[2];

        if (sum > previousSum) {
            std::cout << sum << " (increased)\n";
            counter ++;
        }
        if (sum < previousSum) {
            std::cout << sum << " (decreased)\n";
        }
        if (sum == previousSum){
            std::cout << sum << " (no change)\n";
        }
        previousSum = sum;
    }
     std::cout << "Number of larger than the previous sums: " << counter;
    return 0;
}