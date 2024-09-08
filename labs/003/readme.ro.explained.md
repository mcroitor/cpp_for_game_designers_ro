# Constructori și operatori

## Scop

În cadrul acestei lucrări, studentul va învăța să redefinească operatori, precum și să se familiarizeze cu definiția și opțiunile de utilizare a constructorilor.

În plus, această lucrare va pregăti proiectul pentru a utiliza biblioteca standard C++.

## Sarcina

Sarcina se bazează pe lucrările anterioare de laborator.

### Crearea ramurii lab03

Deschideți fereastra de consolă și navigați în directorul `SnakeGame`. Obțineți ultimele modificări ale proiectului, rulând comenzile:

```bash
# select default branch
git checkout main
# get last changes
git pull
```

Creați o ramură nouă denumită `lab03` și comutați-vă la aceasta:

```bash
# create branch and switch to
git checkout -B lab03
```

### Actualizarea clasei `Point`

Modificați fișierul antet `point.hpp` astfel:

```cpp
#pragma once

#include <iostream>

struct Point{
   int x;
   int y;

   Point(int _x = 0, int _y = 0);
   Point(const Point& other);

   Point operator = (const Point& other);
   bool operator == (const Point& other) const;
};

std::istream& operator >> (std::istream& in, Point& point);
std::ostream& operator << (std::ostream& out, const Point& point);
```

Modificați fișierul `point.cpp` astfel:

```cpp
#include "point.hpp"

Point::Point(int _x, int _y) : x(_x), y(_y) {}

Point::Point(const Point &other) : x(other.x), y(other.y) {}

Point Point::operator=(const Point &other)
{
    x = other.x;
    y = other.y;
    return *this;
}

bool Point::operator==(const Point &other) const
{
    return x == other.x && y == other.y;
}

std::istream& operator >> (std::istream& in, Point& point){
    int x, y;
    in >> x >> y;
    point = Point(x, y);
    return in;
}

std::ostream& operator << (std::ostream& out, const Point& point){
    out << point.x << " " << point.y;
    return out;
}
```

### Actualizarea clasei `Apple`

Modificați fișierul antet `apple.hpp` astfel:

```cpp
#pragma once

#include <iostream>
#include "point.hpp"

class Apple {
   Point _position;
public:
   Apple();
   Apple(const Point& position);
   Apple(const Apple& other);
   Point GetPosition() const;

   Apple operator = (const Apple& other);
   bool operator == (const Apple& other) const;
};

std::istream& operator >> (std::istream& in, Apple& apple);
std::ostream& operator << (std::ostream& out, const Apple& apple);
```

Modificați fișierul `apple.cpp` astfel:

```cpp
#include "apple.hpp"

Apple::Apple() : _position(0, 0) {}

Apple::Apple(const Point &position) : _position(position) {}

Apple::Apple(const Apple &other) : _position(other.GetPosition()) {}

Point Apple::GetPosition() const
{
    return _position;
}

Apple Apple::operator = (const Apple& other){
    _position = other.GetPosition();
    return *this;
}
bool Apple::operator == (const Apple& other) const{
    return GetPosition() == other.GetPosition();
}

std::istream& operator >> (std::istream& in, Apple& apple){
    Point position;
    in >> position;
    apple = Apple(position);
    return in;
}

std::ostream& operator << (std::ostream& out, const Apple& apple){
    out << apple.GetPosition();
    return out;
}
```

### Actualizarea clasei `Board`

Modificați fișierul antet `board.hpp` astfel:

```cpp
#pragma once

#include <iostream>

class Board {
   int _width;
   int _height;
public:
   Board(int width = 20, int height = 20);
   Board(const Board& other);
   int GetWidth() const;
   int GetHeight() const;

   Board operator = (const Board& other);
   bool operator == (const Board& other) const;
};

std::istream& operator >> (std::istream& in, Board& board);
std::ostream& operator << (std::ostream& out, const Board& board);
```

Modificați fișierul `board.cpp` astfel:

```cpp
#include "board.hpp"

Board::Board(int width, int height) : _width(width), _height(height) {}

Board::Board(const Board &other) : _width(other.GetWidth()), _height(other.GetHeight()) {}

int Board::GetWidth() const
{
    return _width;
}

int Board::GetHeight() const
{
    return _height;
}

Board Board::operator=(const Board &other)
{
    _width = other.GetWidth();
    _height = other.GetHeight();
    return *this;
}

bool Board::operator==(const Board &other) const
{
    return GetWidth() == other.GetWidth() && GetHeight() == other.GetHeight();
}

std::istream &operator>>(std::istream &in, Board &board)
{
    int width, height;
    in >> width >> height;
    board = Board(width, height);
    return in;
}

std::ostream &operator<<(std::ostream &out, const Board &board)
{
    out << board.GetWidth() << " " << board.GetHeight();
    return out;
}
```

### Actualizarea clasei `Direction`

Modificați fișierul antet `direction.hpp` astfel:

```cpp
#pragma once

#include <iostream>

enum class Direction {
   Top, Left, Right, Bottom
};

std::ostream& operator<<(std::ostream& out, const Direction& direction);
```

Modificați fișierul `direction.cpp` astfel:

```cpp
#include "direction.hpp"

std::ostream& operator<<(std::ostream& out, const Direction& direction){
    switch (direction)
    {
    case Direction::Top:
        out << "Top";
        break;
    case Direction::Left:
        out << "Left";
        break;
    case Direction::Right:
        out << "Right";
        break;
    case Direction::Bottom:
        out << "Bottom";
        break;
    default:
        break;
    }
    return out;
}
```

### Clasa abstractă `AbstractPainter`

Creați fișierul antet `abstract_painter.hpp`:

```cpp
#pragma once

#include "point.hpp"

struct AbstractPainter {
   virtual void DrawImage(Point topLeft, Point bottomRight, char** image) = 0;
   virtual void WriteText(Point position, char* text) = 0;
};
```

### Actualizarea clasei `Painter`

Modificați fișierul antet `painter.hpp` astfel:

```cpp
#pragma once

#include "abstract_painter.hpp"

class Painter: public AbstractPainter {
public:
   virtual void DrawImage(Point topLeft, Point bottomRight, char** image);
   virtual void WriteText(Point position, char* text);
};
```

### Verificare

Verificați corectitudinea modificărilor efectuate, compilând proiectul din linia de comandă:

```bash
make
```

### Fixarea modificărilor

Fixați modificările în depozitul local și trimiteți-le pe GitHub:

```bash
git add .
git commit -m "feat(lab03): add constructors and operators"
git push origin lab03
```

Creați cerere de tragere a modificărilor (Pull Request) în ramura `main` a depozitului.

## Prezentare

La lucrare de laborator în Moodle adaugați referința repozitoriu.

## Evaluare

- `2p` - implementarea constructorilor
- `2p` - implementarea operatorilor de copiere
- `2p` - implementarea operatorilor de comparație
- `2p` - implementarea operatorilor de citire și afișare
- `2p` - implementarea clasei abstracte de bază
- `-1p` - pentru fiecare zi de întârziere
- `-5p` - pentru plagiat
