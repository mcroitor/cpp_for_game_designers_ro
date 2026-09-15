#include "position.hpp"

struct Renderer{
    void PutChar(Position p, char c);
    void PutString(Position p, char* s);
    void ClearChar(Position p);
    void Clear();
    int GetWidth();
    int GetHeight();
};