# Learning diary

This document summarizes what I have learned during this challenge.

## Days 04-06

**Day 4** was quick and easy to complete (took less than an hour). Learned that the ranges library (c++20) is not implemented in Apple Clang 14.0. The library could have been used to solve the problem.

**Day 5** felt laborious and took three hours to complete. The hard part was reading and parsing the input.

**Day 6** was quite easy and took around an hour. Solving the second part only required a change of variable.

I learned

* learned to use standard libraries more efficiently.
* that it is good to use `{}` when initialising variables with named type. This is because `{}` provides type checking in compile-time and provides errors when there is a loss of information (e.g. float to int) `int h = 0.2;` initializes h to 0, but `int h{0.2}`results in an error when compiling.

I also refreshed my memory on some data structures (mostly stacks and queues) and datatypes (e.g. sets).

I also dived into the world of compilers when debugging the code and when trying to figure out why some c++20 features and libraries are not working (e.g. modules and ranges library). Seems that the c++17 standard is a more suitable standard to use with Apple Clang 14 than c++20.

References and tools found:

* [Compiler support for C++20](<https://en.cppreference.com/w/cpp/compiler_support/20>)
* [XCode release notes](<https://developer.apple.com/documentation/xcode-release-notes/xcode-14-release-notes>)
* [Compiler explorer](<https://godbolt.org/>)

## Days 01-03

Problems felt achievable but I had some issues with applying the correct syntax. Some time was also wasted on logical errors in code or just not understanding the problem correctly. The time completing both parts stayed around two hours, (except the first day took only an hour). I decided not to polish my code too much, but to apply the lessons learned during the day to the next day.

I learned

* to read the instructions carefully (this will save at least 10-30min of frustration).
* how to use common [data structures in C++](<https://en.cppreference.com/w/cpp/container>).
* handling of [strings and characters in C++](<https://en.cppreference.com/w/cpp/string/basic_string>).
* applying [algorithms library in C++](<https://en.cppreference.com/w/cpp/algorithm>) to different problems.
* [why `size_t` matters.](<https://www.embedded.com/why-size_t-matters/>)
* `std::string::find()` returns `std::string::npos` when string of characters is not found, but `some_string[out_of_bounds]` returns `\0` which represents the termination of a string.
* to apply [modular arithmetics](<https://www.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/)what-is-modular-arithmetic>).
* to apply [graphs](<https://en.wikipedia.org/wiki/Graph_(abstract_data_type)>). E.g. rock-paper-scissors (day2) problem turned into a graph (part 2 needs "LOOSE" edges):
![rock-paper-scissors-graph](images/rock_paper_scissors.jpg)

## Day 00

I completed day 1 of 2021 to create a template for myself this year.

The first part was straightforward and quick to do. However, the second part took longer because at first I read the instructions wrong and the problem became more complicated in my head than it was (e.g. the format of the input did not change). After realizing the mistake and understanding the task, the problem took less than 30min.

I learned how to read text files and how to implement queues in C++. I also learned how to set up a C++ project and how to automate build and launch in VScode.

Resources used:

* <https://www.w3schools.com/cpp/cpp_files.asp>
* <https://en.cppreference.com/w/cpp/io/basic_fstream>
* <https://en.cppreference.com/w/cpp/container/deque>
* <https://stackoverflow.com/questions/9148488/how-do-i-compile-c-with-clang>
