#ifndef _POINT_H_
#define _POINT_H_

#define DLLEXPORT __declspec(dllexport)

class DLLEXPORT Point
{
    int _x, _y;

public:
    Point(int x, int y);
    Point(const Point&);
    ~Point();

    Point operator = (const Point&);
    int GetX() const;
    int GetY() const;
};

DLLEXPORT bool operator == (const Point&, const Point&);

extern "C" DLLEXPORT Point CreatePoint(int x, int y);

#endif