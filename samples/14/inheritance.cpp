#include <iostream>

using namespace std;

const double PI = 3.14159265358979;

struct point
{
    float x;
    float y;
};

class figure
{
    point coordinates;

public:
    virtual float area() = 0;
};

class square : public figure
{
    double length;

public:
    square(double x) : length(x) {}

    float area()
    {
        return length * length;
    };
};

class circle: public figure
{
    double radius;

public:
    circle(double r) : radius(r) {}
    float area()
    {
        return PI * radius * radius;
    };
};

double getArea(figure* f) {
    return f->area();
}

int main()
{
    square *_square = new square(5);
    circle *_circle = new circle(6);
    
    cout << "square area = " << getArea(_square) << endl;
    cout << "circle area = " << getArea(_circle) << endl;

    delete _square;
    delete _circle;
    return 0;
}