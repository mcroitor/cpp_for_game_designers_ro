#include <iostream>

#define min(a,b) (((a) < (b)) ? (a) : (b))

int main() {
    int a = min(2 & 1, 5);
    std::cout << a << std::endl;
    return 0;
}