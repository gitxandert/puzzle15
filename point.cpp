#include "Point.h"

bool operator== (const Point& p1, const Point& p2)
{
    return (p1.m_x == p2.m_x && p1.m_y == p2.m_y);
}

bool operator!= (const Point& p1, const Point& p2)
{
    return (p1.m_x != p2.m_x || p1.m_y != p2.m_y);
}

bool operator<= (const Point& p1, const Point& p2)
{
    return (p1.m_x <= p2.m_x && p1.m_y <= p2.m_y);
}

bool operator>= (const Point& p1, const Point& p2)
{
    return (p1.m_x >= p2.m_x && p1.m_y >= p2.m_y);
}

Point Point::getAdjacentPoint(const Input direction) const
{
    switch(direction)
    {
    case up: return Point{m_x, m_y - 1};
    case down: return Point{m_x, m_y + 1};
    case left: return Point{m_x - 1, m_y};
    case right: return Point{m_x + 1, m_y};
    }

    return *this;
}