#include <iostream>
#include <algorithm>
#include <vector>


template<typename InputIterator, typename Predicate>
InputIterator find_if(InputIterator begin, InputIterator end, Predicate predicate) {
    while(begin != end) {
        if(predicate(*begin)) {
            return begin;
        }
        ++begin;
    }
    return begin;

}

template<typename InputIterator, typename TYPE>
 InputIterator find(InputIterator begin, InputIterator end, TYPE value) {
    while(begin != end) {
        if((*begin==value)) {
            return begin;
        }
        ++begin;
    }
    return begin;

}

bool isOdd(int x) { return x % 2 == 1; }

int main() {
    std::vector<int> data {8, 12, 10, 5, 4, 9, 13, 15};

    int a = 12;

    std::vector<int>::iterator result = std::find(data.begin(), data.end(), a);

    if(result != data.end()) {
        std::cout << "found " << *result << std::endl;
    }
    else {
        std::cout << a << " not found in the container" << std::endl;
    }
    
    result = std::find_if(data.begin(), data.end(), isOdd);
    
    if(result != data.end()) {
        std::cout << "found " << *result << std::endl;
    }
    else {
        std::cout << a << " not found in the container" << std::endl;
    }
    
    return 0;
}