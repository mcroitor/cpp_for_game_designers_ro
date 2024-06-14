#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

int main() {
    std::deque<int> d {8, 12, 10, 5, 4, 9, 13, 15};
    std::vector<int> s {8, 12, 10, 5, 4, 9, 13, 15};

    bool result = std::equal(d.begin(), d.end(), s.begin());

    if(result) {
        std::cout << " equal" << std::endl;
    }
    else {
        std::cout << " not equal" << std::endl;
    }
    return 0;
}