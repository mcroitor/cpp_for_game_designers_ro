#ifndef _HERO_H_
#define _HERO_H_

#include "gamecharacter.hpp"

/**
 * @brief The Hero Character
 *
 */
class Hero : public GameCharacter
{
public:
    /**
     * @brief Construct a new Hero object
     *
     * @param name The name of the Hero
     * @param position The position of the Hero
     */
    Hero(const std::string & = "Hero", Point = {1, 1});
};

#endif