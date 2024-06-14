#include "mymath.h"
#include <iostream>

int main() {
    int a = 5;
    int b = -10;

    std::cout << my::min(a, b) << std::endl;
    std::cout << my::mod(b) << std::endl;
    std::cout << my::mod(a) << std::endl;
    return 0;
}
