#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main() {
    std::deque<int> d {8, 12, 10, 5, 4, 9, 13, 15};
    std::vector<int> s {10, 5, 4};

    auto result = std::search(d.begin(), d.end(), s.begin(), s.end());

    if(result != d.end()) {
        std::cout << "interval found" << std::endl;
    }
    else {
        std::cout << "interval not found" << std::endl;
    }
    return 0;
}