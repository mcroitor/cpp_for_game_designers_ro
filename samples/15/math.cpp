#include <iostream>
#include <cmath>
#include <stdexcept>

struct Vector
{
    float x, y;

    Vector operator=(const Vector &v)
    {
        x = v.x;
        y = v.y;
        return *this;
    }
};

float abs(Vector v)
{
    return sqrt(v.x * v.x + v.y * v.y);
}
// operator overloading
Vector operator+(Vector a, Vector b)
{
    return {a.x + b.x, a.y + b.y};
}

std::ostream &operator<<(std::ostream &out, const Vector &p)
{
    out << "{" << p.x << ", " << p.y << "}";
    return out;
}

std::istream &operator>>(std::istream &in, Vector &p)
{
    char begin, delim, end;

    in >> begin;
    if(begin != '{') {
        // throw "[ERROR] invalid data format, broken open bracket";
        throw begin;
    }
    in >> p.x;
    in >> delim;
    if(delim != ',') {
        // throw "[ERROR] invalid data format, broken delimiter";
        throw delim;
    }
    in >> p.y;
    in >> end;
    if(end != '}') {
        //throw "[ERROR] invalid data format, broken close bracket";
        throw end;
    }
    return in;
}

using namespace std;
int main()
{
    Vector a = {6, 8};
    cout << "a = "<< a;
    Vector b = {-9, 3};

    try {
        cin >> a;
    }
    catch(char e) {
        cout << "[ERROR] invalid data format, error code: " << e << std::endl;
    }
    Vector c = a + b;

    cout << abs(a) << std::endl;
    cout << a << "+";
    cout << b << "=";
    cout << c << std::endl;
    return 0;
}
