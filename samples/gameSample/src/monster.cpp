#include "monster.hpp"

Monster::Monster(const std::string &name, Point position) : GameCharacter(name, position) {}

Monster::Monster(const Monster &other): GameCharacter(other.Name(), other.Position()) {}

Monster Monster::operator=(const Monster &other) {
    _name = other._name;
    _position = other._position;
    return *this;
}

bool Monster::operator==(const Monster &other) const {
    return _name == other._name && _position == other._position;
}

std::istream &operator>>(std::istream &in, Monster & m)
{
    std::string name;
    Point position;
    in >> name >> position;
    m = Monster(name, position);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Monster & m)
{
    out << m.Name() << ": " << m.Position();
    return out;
}