#ifndef _XOXO_BOARD_H_
#define _XOXO_BOARD_H_

#include "coordonate.h"

class Board
{
public:
    friend class Engine;

public:
    void DoMove(const Coordonate &);
};

#endif // _XOXO_BOARD_H_