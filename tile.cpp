#include "Tile.h"

Tile& Tile::operator= (const Tile& tile)
{
    if(this == &tile)
    {
        return *this;
    }

    m_display_num = tile.m_display_num;

    return *this;
}

std::ostream& operator<< (std::ostream& out, const Tile& tile)
{
    out << ' ';
    
    if(tile.m_display_num)
    {
        if(tile.m_display_num < 10)
        {
            out << ' ';
        }
        out << tile.m_display_num;
    }
    else
    {
        out << "  ";
    }

    out << ' ';

    return out;

}