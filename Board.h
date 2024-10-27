#ifndef BOARD_H
#define BOARD_H

#include "Tile.h"
#include "Direction.h"
#include "Point.h"

constexpr int g_consoleLines{ 25 };

class Board
{
private:
    static constexpr int b_size{ 4 };
    Tile m_board[b_size][b_size]{
        Tile{ 1 }, Tile { 2 }, Tile { 3 } , Tile { 4 },
        Tile { 5 } , Tile { 6 }, Tile { 7 }, Tile { 8 },
        Tile { 9 }, Tile { 10 }, Tile { 11 }, Tile { 12 },
        Tile { 13 }, Tile { 14 }, Tile { 15 }, Tile { 0 } };

public:
    friend std::ostream& operator<< (std::ostream& out, const Board& board);

    bool moveTile(Direction direction);

    void randomizeBoard();

    bool isCorrect();
};

#endif