#include "map.hpp"
#include "defines.hpp"
#include <iterator>

Map::Map() {}
void Map::Load(const std::vector<std::string> & data) {
    std::copy(
        data.begin(), data.end(), std::back_inserter(map));
}
const std::vector<std::string> &Map::Data() const
{
    return map;
}

bool Map::IsWall(Point position) const {
    return map[position.x][position.y] == (char)GraphicObject::WALL;
}

size_t Map::GetWidth() const {
    return map[0].size();
}

size_t Map::GetHeight() const {
    return map.size();
}