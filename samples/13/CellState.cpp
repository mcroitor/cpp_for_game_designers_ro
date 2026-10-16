#include <iostream>

enum class CellState: char
{
    None = ' ',
    X = 'X',
    O = 'O'
};

std::ostream& operator<<(std::ostream& os, CellState state)
{
    return os << static_cast<char>(state);
}

int main()
{
    CellState board[3][3] = {{CellState::X, CellState::None, CellState::None},
                             {CellState::None, CellState::X, CellState::None},
                             {CellState::O, CellState::None, CellState::O}};

    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 3; ++j)
        {
            std::cout << board[i][j];
            if (j < 2) std::cout << "|";
        }
        std::cout << std::endl;
        if (i < 2) std::cout << "-----" << std::endl;
    }
    return 0;
}