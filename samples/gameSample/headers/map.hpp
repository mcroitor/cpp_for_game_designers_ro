#ifndef __MAP_H__
#define __MAP_H__

#include "point.hpp"
#include <vector>
#include <string>

/**
 * @brief The map representation, without characters
 * 
 */
class Map
{
    std::vector<std::string> map;

public:
    /**
     * @brief Construct a new Map object
     */
    Map();
    /**
     * @brief Loads the map
     * 
     * @param map The map
     */
    void Load(const std::vector<std::string> &);
    /**
     * @brief Check if a position on map has a wall
     * 
     * @param pos The position for checking
     * @return true if the position of a wall
     * @return false otherwise
     */
    bool IsWall(Point) const;
    /**
     * @brief returns all data
     * 
     * @return const std::vector<std::string>& 
     */
    const std::vector<std::string>& Data() const;

    size_t GetWidth() const;
    size_t GetHeight() const;
};

#endif