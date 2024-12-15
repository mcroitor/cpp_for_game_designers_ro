#include <iostream>
#include <map>
#include <string>

int main()
{
    std::map<std::string, int> to_number = {
        {"one", 1}, 
        {"two", 2}, 
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9},
    };

    for(auto it = to_number.begin(); it != to_number.end(); ++it){
        std::cout << (*it).first << " -> " << it->second << std::endl;
    }

    std::map<int, std::string> from_number = {
        {1, "one"}, 
        {2, "two"}, 
        {3, "three"},
        {4, "four"},
        {5, "five"},
        {6, "six"},
        {7, "seven"},
        {8, "eight"},
        {9, "nine"},
    };
    std::string first, second;

    std::cin >> first >> second;

    int result = to_number[first] + to_number[second];
    
    std::cout << first << " + " << second << " = " << from_number[result] << std::endl;

    return 0;
}
