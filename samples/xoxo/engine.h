#ifndef _XOXO_ENGINE_H_
#define _XOXO_ENGINE_H_

#include "board.h"
#include "player.h"

class Engine
{
    Board board_;
    Player xPlayer_;
    Player oPlayer_;
    int stage;

public:
    Engine();
    void Run();

private:
    bool GameOver() const;
};

#endif // _XOXO_ENGINE_H_