#ifndef POINT_H
#define POINT_H

#include "Direction.h"

class Point
{
private:
    int m_x{};
    int m_y{};

public:
    Point(int x=0, int y=0)
        : m_x{ x }
        , m_y{ y }
    {
    }

    friend bool operator== (const Point& p1, const Point& p2);
    friend bool operator!= (const Point& p1, const Point& p2);
    friend bool operator<= (const Point& p1, const Point& p2);
    friend bool operator>= (const Point& p1, const Point& p2);

    Point getAdjacentPoint(const Input direction) const;

    int& getX() { return m_x; }

    int& getY() { return m_y; }
};

#endif