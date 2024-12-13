#include "mymath.h"
#include <string>
#include <iostream>

int total_tests = 0;
int total_asserts = 0;
int failed_asserts = 0;

bool my_assert(bool expression, std::string message) {
    ++ total_asserts;
    if(!expression) {
        ++ failed_asserts;
        std::cerr << "failed assert: " << message << std::endl;
    }
    return expression;
}

void test_min() {
    std::cout << "test min" << std::endl;
    ++ total_tests;
    my_assert(my::min(1, 1) == 1, "my::min(1, 1) == 1");
    my_assert(my::min(0, 1) == 0, "my::min(0, 1) == 0");
    my_assert(my::min(10, 1) == 4, "my::min(10, 1) == 4");
}

void test_mod(){
    std::cout << "test mod" << std::endl;
    ++ total_tests;
    my_assert(my::mod(0) == 0, "my::mod(0) == 0");
    my_assert(my::mod(5) == 5, "my::mod(5) == 5");
    my_assert(my::mod(-5) == 5, "my::mod(-5) == 5");

}

int main() {
    test_min();
    test_mod();
    std::cout << "Statistics:" << std::endl
                << "\ttotal tests:" << total_tests << std::endl
                << "\ttotal asserts:" << total_asserts << std::endl
                << "\tfailed asserts:" << failed_asserts << std::endl;
    return 0;
}