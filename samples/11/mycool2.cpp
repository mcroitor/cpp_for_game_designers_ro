#include <iostream>

int a = 10;

void foo() {
    std::cout << a << std::endl;
    a++;
}

int main() {
    
    foo();
    foo();
    foo();
    foo();

    return 0;
}