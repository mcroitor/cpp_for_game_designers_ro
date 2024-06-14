#include <iostream>

int main() {
    int coolValue = 256;
    int * intPtr;
    char * charPtr;

    intPtr = &coolValue;
    charPtr = (char*)&coolValue;

    std::cout << "Cool value = " << coolValue << std::endl;
    std::cout << "pointer of cool value = " << intPtr << std::endl;
    std::cout << "access value by pointer = " << *intPtr << std::endl;
    std::cout << "first byte = " << (int)*charPtr << std::endl;
    std::cout << "second byte = " << (int)*(charPtr + 1) << std::endl;
    std::cout << "third byte = " << (int)*(charPtr + 2) << std::endl;
    std::cout << "fourth byte = " << (int)*(charPtr + 3) << std::endl;

    return 0;
}