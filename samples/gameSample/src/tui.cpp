#include "tui.hpp"

#include <iostream>
#include <windows.h>
#include <WinUser.h>

int TUI::ScanKeys()
{
    if (GetAsyncKeyState(VK_UP))
    {
        return VK_UP;
    }
    if (GetAsyncKeyState(VK_DOWN))
    {
        return VK_DOWN;
    }
    if (GetAsyncKeyState(VK_LEFT))
    {
        return VK_LEFT;
    }
    if (GetAsyncKeyState(VK_RIGHT))
    {
        return VK_RIGHT;
    }
    if (GetAsyncKeyState(VK_ESCAPE))
    {
        return VK_ESCAPE;
    }
    return VK_NONAME;
}

void TUI::SetCursor(Point position)
{
    std::cout << "\033[" << position.y << ";" << position.x << "H";
}

void TUI::Draw(const std::vector<std::string> &data)
{
    std::string output = "";
    for (auto line : data)
    {
        output += line + "\n";
    }
    TUI::Write({0, 0}, output);
}

void TUI::Write(Point position, const std::string& message){
    TUI::SetCursor(position);
    std::cout << message;
}

void TUI::Clear(Point position, size_t count) {
    std::string blank(count, ' ');
    TUI::Write(position, blank);
}

void TUI::ClearScreen() {
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    size_t columns, rows;
  
    GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
    columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    std::string blank(columns, ' ');
    for(size_t i = 0; i < rows; ++i) {
        TUI::Write({0, i}, blank);
    }
}
