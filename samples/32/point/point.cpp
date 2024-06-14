#include "point.h"

Point::Point(int x, int y) : _x{x}, _y{y} {}
Point::Point(const Point &other) : _x{other.GetX()}, _y{other.GetY()} {}
Point::~Point() {}

Point Point::operator=(const Point &other) {
    this->_x = other.GetX();
    this->_y = other.GetY();
    return *this;
}
int Point::GetX() const {
    return this->_x;
}
int Point::GetY() const {
    return this->_y;
}

bool operator==(const Point &left, const Point &right) {
    return left.GetX() == right.GetX() && left.GetY() == right.GetY();
}

Point CreatePoint(int x, int y) {
    return Point(x, y);
}