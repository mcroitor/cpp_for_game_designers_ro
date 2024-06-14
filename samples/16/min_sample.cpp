#include <iostream>

template<typename TYPE>
TYPE min1(TYPE a, TYPE b) {
    return a < b ? a : b;
}

template<typename TYPE1, typename TYPE2>
auto min2(TYPE1 a, TYPE2 b) {
    return a < b ? a : b;
}

int main() {
    int a = 2, b = 3;
    float c = 1.5;

    std::cout << min1(a, b) << std::endl;
    std::cout << min1<float>(a, c) << std::endl;
    std::cout << min2(b, c) << std::endl;
    return 0;
}