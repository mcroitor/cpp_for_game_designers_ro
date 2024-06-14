#ifndef __GAME_CHARACTER_H__
#define __GAME_CHARACTER_H__

#include <string>

#include "point.hpp"
#include "direction.hpp"
#include "mappart.hpp"

/**
 * @brief Basic game character (Hero, Monsters etc.)
 *
 */
class GameCharacter
{
protected:
  size_t _attack;
  size_t _defence;
  size_t _health;
  std::string _name;
  Point _position;
  size_t _viewRangeRadius;

public:
  /**
   * @brief Construct a new Game Character object
   *
   * @param name The name of the character
   * @param position The position of the character
   */
  GameCharacter(std::string, Point);

  /**
   * @brief Move the character in the direction
   *
   * @param direction The direction of movement
   */
  void Move(Direction);

  /**
   * @brief Detect position for movement
   *
   * @return Point
   */
  Point PositionToMove(Direction) const;

  /**
   * @brief Cure the character
   *
   * @param hit points for health restoration
   */
  void Cure(size_t);

  /**
   * @brief not implemented, no idea
   *
   * @return MapPart
   */
  MapPart ViewRange() const;

  /**
   * @brief returns the position of the character
   *
   * @return Point
   */
  Point Position() const;

  /**
   * @brief get name of the character
   *
   * @return std::string
   */
  std::string Name() const;

  /**
   * @brief attack another character
   *
   * @param character attacked character
   */
  void Attack(GameCharacter &) const;
};

#endif // __GAME_CHARACTER_H__
