#include "Board.h"
#include "Random.h"

std::ostream& operator<< (std::ostream& out, const Board& board)
{
    for(int line{ 0 }; line < g_consoleLines; ++line)
    {
        out << '\n';
    }

    for(int row{ 0 }; row < 4; ++row)
    {
        for(int tile{ 0 }; tile < 4; ++tile)
        {
            out << board.m_board[row][tile];
        }
        out << '\n';
    }

    return out;
}

bool Board::moveTile(Direction direction)
{
    Point empty{};

    for(int row{ 0 }; row < 4; ++row)
    {
        for(int tile{ 0 }; tile < 4; ++tile)
        {
            if (m_board[row][tile].isEmpty())
            {
                empty = Point{tile, row};
                break;
            }
        }
    }

    Direction neg{ -direction };
    Point slide{ empty.getAdjacentPoint( neg.getDirection() ) };

    if( slide >= Point{0,0} && slide <= Point{3,3} )
    {
        int temp{ m_board[slide.getY()][slide.getX()] };

        m_board[empty.getY()][empty.getX()] = Tile{ temp };

        m_board[slide.getY()][slide.getX()] = Tile{ 0 };

        return true;
    }

    return false;
}

void Board::randomizeBoard()
{
    for(int i { 0 }; i < 500; ++i)
    {
        while(true)
        {
            Input random{ Random::get(0, max_inputs) };

            Direction randomDirection{ random };

            if(!moveTile(random))
            {
                continue;
            }

            break;
        }
    }
}

bool Board::isCorrect()
{
    int compare{ 1 };

    for(int x{ 0 }; x < 4; ++x)
    {
        for(int y{ 0 }; y < 4; ++y)
        {
            if(m_board[x][y] != compare)
            {
                return false;
            }

            ++compare;
            
            if(compare > 15)
            {
                compare = 0;
            }
        }
    }

    return true;
}