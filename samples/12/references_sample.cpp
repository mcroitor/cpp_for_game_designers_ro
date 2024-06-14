#include <iostream>

int main() {
    int value = 10;
    int &ref = value;

    std::cout << "value: " << value << ", reference = " << ref << std::endl;
    value = 12;
    std::cout << "value: " << value << ", reference = " << ref << std::endl;
    ref = 15;
    std::cout << "value: " << value << ", reference = " << ref << std::endl;
    return 0;
}