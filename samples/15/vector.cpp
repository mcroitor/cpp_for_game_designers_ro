#include <iostream>

struct vector {
    float x, y, z;
};

vector operator + (vector a, vector b) {
    return vector {b.x + a.x, b.y + a.y, b.z + a.z};
}

std::ostream& operator << (std::ostream& out, const vector& a) {
    out << "{" << a.x << ",  " << a.y << ",  " << a.z << "}";
    return out;
}

int main() {
    vector a {1, 2, 3};
    vector b {3, 2, 1};

    vector c = a + b; // c = operator+ (a, b)

    std::cout << c << " = " << a << " + " << b;
    return 0;
}