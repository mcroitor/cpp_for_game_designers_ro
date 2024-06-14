#include <iostream>

struct Man {
    int age;
};

void print(Man& a) {
    a.age = 20;
}

int main() {
    Man* const man = new Man();

    man->age = 10;
    return 0;
}
