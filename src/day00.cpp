#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::string line; 

    std::ifstream MyReadFile("inputs/day00.txt");

    std::getline(MyReadFile,line);
    int32_t previousReading = std::stoi(line);
    std::cout << line << " (N/A - no previous measurement)\n";
   
    int32_t counter = 0;

    while (std::getline(MyReadFile, line)){
        int32_t reading = std::stoi(line);
        if (reading > previousReading) {
            std::cout << line << " (increased)\n";
            counter ++;
        }
        if (reading < previousReading) {
            std::cout << line << " (decreased)\n";
        }
        previousReading = reading;
    }
     std::cout << "No. larger than the previous measurement: " << counter;
    return 0;
}