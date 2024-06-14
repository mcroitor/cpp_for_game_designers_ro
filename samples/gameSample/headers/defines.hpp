#ifndef _DEFINES_H_
#define _DEFINES_H_

/**
 * @brief map definition objects
 * 
 */
enum class GraphicObject: char {
    EMPTY = '.',
    WALL = '#',
    HERO = '@',
    MONSTER = 'M',
    CHEST = '*'
};

#endif