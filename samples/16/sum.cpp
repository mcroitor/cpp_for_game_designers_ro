#include <iostream>

template<typename TYPE>
TYPE sum(TYPE p1, TYPE p2) {
    return p1 + p2;
}

struct point{
    int x, y;
};

int main() {
    int i1 = 10;
    int i2 = 1;
    double d1 = 1.5;
    double d2 = 1.9;

    point pt1, pt2, pt3;

    pt3 = sum(pt1, pt2);

    std::cout << i1 << " + " << i2 << " = " << sum(i1, i2) << std::endl;
    std::cout << d1 << " + " << d2 << " = " << sum(d1, d2) << std::endl;
    std::cout << i1 << " + " << d2 << " = " << sum<int>(i1, d2) << std::endl;
    std::cout << i1 << " + " << d2 << " = " << sum<double>(i1, d2) << std::endl;
    return 0;
}