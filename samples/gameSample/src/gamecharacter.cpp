#include "gamecharacter.hpp"

GameCharacter::GameCharacter(std::string name, Point position)
    : _attack(10),
      _defence(2),
      _health(100),
      _name(name),
      _position(position),
      _viewRangeRadius(3)
{
}

void GameCharacter::Move(Direction direction)
{
    switch (direction)
    {
    case Direction::north: // top
        _position.x -= 1;
        break;
    case Direction::south: // bottom
        _position.x += 1;
        break;
    case Direction::east: // right
        _position.y += 1;
        break;
    case Direction::west: // left
        _position.y -= 1;
        break;
    }
}
Point GameCharacter::PositionToMove(Direction direction) const
{
    Point position = _position;
    switch (direction)
    {
    case Direction::north: // top
        position.x -= 1;
        break;
    case Direction::south: // bottom
        position.x += 1;
        break;
    case Direction::east: // right
        position.y += 1;
        break;
    case Direction::west: // left
        position.y -= 1;
        break;
    }
    return position;
}
void GameCharacter::Cure(size_t value)
{
    _health += value;
}

MapPart GameCharacter::ViewRange() const
{
    return MapPart();
}

void GameCharacter::Attack(GameCharacter &gameCharacter) const
{
    size_t damage = 0;
    if (this->_attack >= gameCharacter._defence)
    {
        damage = this->_attack - gameCharacter._defence;
    }
    if (gameCharacter._health >= damage)
    {
        gameCharacter._health -= gameCharacter._health - damage;
    }
    else
    {
        gameCharacter._health = 0;
    }
}

Point GameCharacter::Position() const
{
    return _position;
}

std::string GameCharacter::Name() const {
    return _name;
}