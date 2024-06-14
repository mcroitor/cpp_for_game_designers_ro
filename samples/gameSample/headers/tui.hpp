#ifndef _TUI_H_
#define _TUI_H_

#include "point.hpp"
#include <vector>
#include <string>

/**
 * @brief class for communication with I/O
 * 
 */
struct TUI {
    /**
     * @brief scan pressed keyboard keys
     * 
     * @return int arrows or escape
     */
    static int ScanKeys();
    /**
     * @brief Set the Cursor object
     * 
     * @param position position of cursor on screen
     */
    static void SetCursor(Point);
    /**
     * @brief draw map
     * 
     * @param data map data
     */
    static void Draw(const std::vector<std::string>&);

    /**
     * @brief Print a text message in the specified position
     * 
     * @param position position
     * @param message message
     */
    static void Write(Point, const std::string&);

    /**
     * @brief fill line with space from position
     * 
     * @param position
     * @param number of spaces
     */
    static void Clear(Point, size_t);

    /**
     * @brief clear active screen
     * 
     */
    static void ClearScreen();
};

#endif