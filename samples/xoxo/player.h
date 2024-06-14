#ifndef _XOXO_PLAYER_H_
#define _XOXO_PLAYER_H_

#include "board.h"
#include "coordonate.h"

class Player
{

public:
    Coordonate Move(const Board &) const;
};

#endif // _XOXO_PLAYER_H_