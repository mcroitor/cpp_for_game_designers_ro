#ifndef _POINT_H_
#define _POINT_H_

#include <cstddef>
#include <iostream>

struct Point {
    size_t x, y;
};

bool operator==(const Point& p1, const Point& p2);

std::istream& operator>> (std::istream&, Point&);
std::ostream& operator<< (std::ostream&, const Point&);

#endif