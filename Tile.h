#ifndef TILE_H
#define TILE_H

#include <iostream>

class Tile
{
private:
    int m_display_num{};

public:
    Tile(int num_to_display)
        : m_display_num{ num_to_display }
    {
    }

    Tile(Tile& tile)
        : Tile( tile.m_display_num )
    {
    }

    Tile& operator= (const Tile& tile);

    operator int() const { return m_display_num; }

    friend std::ostream& operator<< (std::ostream& out, const Tile& tile);

    int getNum() const { return m_display_num; }

    bool isEmpty() { return (m_display_num == 0); }
};

#endif