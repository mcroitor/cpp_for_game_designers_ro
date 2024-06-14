#include "engine.h"
#include "coordonate.h"

#include <iostream>

Engine::Engine(): stage(0)
{
}

void Engine::Run()
{
    bool xMove = true;
    Coordonate move;
    while (!GameOver())
    {
        std::cout << "move: " << std::endl;
        if (xMove)
        {
            move = xPlayer_.Move(board_);
        }
        else
        {
            move = oPlayer_.Move(board_);
        }
        xMove = !xMove;
        board_.DoMove(move);
        ++ stage;
    }
}

bool Engine::GameOver() const
{
    // TODO: implement
    return stage == 20;
}