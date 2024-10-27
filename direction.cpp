#include "Direction.h"

Direction Direction::operator- () const
{
    if(m_direction == down)
    {
        return Direction{ up };
    }

    if(m_direction == up)
    {
        return Direction{ down };
    }

    if(m_direction == left)
    {
        return Direction{ right };
    }

    return Direction{ left };
}

std::ostream& operator<< (std::ostream& out, const Direction& direction)
{
    std::string_view print{ printDirections(direction.m_direction) };

    if( print != "ignore" )
    {
        out << print;
    }
    else
    {
        out << ' ';
    }

    return out;
}

Direction Direction::randomDirection()
{
    Input direction{ Random::get(0, max_inputs) };

    return Direction{ direction };
}