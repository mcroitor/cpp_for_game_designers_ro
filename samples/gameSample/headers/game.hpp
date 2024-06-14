#ifndef _GAME_H_
#define _GAME_H_

#include "map.hpp"
#include "hero.hpp"
#include "monster.hpp"

#include <vector>
#include <string>

/**
 * @brief game engine
 *
 */
class Game
{
    Map map;
    Hero hero;
    std::vector<Monster> monsters;

    const std::vector<std::string> Data() const;

public:
    /**
     * @brief Construct a new Game object
     *
     */
    Game();
    /**
     * @brief load data from stage description file
     * @param filename
     */
    void Init(const std::string &);
    /**
     * @brief main loop start
     * 
     */
    void Run();
};

#endif // _GAME_H_