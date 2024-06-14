#ifndef _MONSTER_H_
#define _MONSTER_H_

#include "gamecharacter.hpp"
#include <ios>

class Monster : public GameCharacter
{
public:
    Monster(const std::string& = "Monster", Point = {1, 1});
    Monster(const Monster& other);

    Monster operator = (const Monster& other);

    bool operator == (const Monster& other) const;
};

std::istream& operator>> (std::istream&, Monster&);
std::ostream& operator<< (std::ostream&, const Monster&);

#endif