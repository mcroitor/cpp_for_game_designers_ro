#include "point.hpp"

bool operator==(const Point &p1, const Point &p2)
{
    return (p1.x == p2.x && p1.y == p2.y);
}
std::istream &operator>>(std::istream &in, Point &p)
{
    in >> p.x >> p.y;
    return in;
}
std::ostream &operator<<(std::ostream &out, const Point &p)
{
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}