#include "direction.hpp"

#include <map>

const std::map<Direction, std::string> directions = {
    {Direction::north, "North"},
    {Direction::south, "South"},
    {Direction::west, "West"},
    {Direction::east, "East"},
};

std::string ToString(Direction direction) {
    return directions.at(direction);
}