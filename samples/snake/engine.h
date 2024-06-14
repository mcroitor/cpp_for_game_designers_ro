#pragma once
#include "map.h"
#include "snake.h"
#include "apple.h"

class engine
{
    snake _snake;
    map _map;
    apple _apple;

public:
    engine();

    void Play();
};
