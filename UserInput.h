#ifndef USERINPUT_H
#define USERINPUT_H

#include <iostream>
#include <string>
#include <string_view>
#include "Board.h"
#include "Point.h"
#include "Tile.h"
#include "Direction.h"
#include "board.cpp"
#include "direction.cpp"
#include "tile.cpp"
#include "point.cpp"

extern bool playing;

namespace UserInput
{
    void play15()
    {
        Board board{};

        board.randomizeBoard();
        
        std::cout << board << '\n';

        std::cout << "Enter a command: ";

        while(playing)
        {
            Input input{};

            std::cin >> input;

            Direction direction{ input };

            if(!board.moveTile(direction))
            {
                continue;
            }

            std::cout << board;

            if(board.isCorrect())
            {
                std::cout << "\nYou did it!! Congratulations!";
                break;
            }         
        }

        std::cout << "\n\nBye!\n\n";
    }
}

#endif