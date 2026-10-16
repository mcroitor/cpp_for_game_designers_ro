#include <iostream>

struct A {
    int p;
    A(int param = 20): p {param} {
        std::cout << "A constructor called, p = " << p << std::endl;
    }
    int getP() const {
        return p;
    }
};

struct B: A {
    B(int param = 10): A {param} {
        std::cout << "B constructor called, p = " << getP() << std::endl;
    }
};

int main() {
    B b;
    return 0;
}
