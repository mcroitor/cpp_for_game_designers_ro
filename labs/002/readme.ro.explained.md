# Crearea și utilizarea claselor. Proiecte complexe. Construirea proiectului

## Scop

După finalizarea acestei sarcini, studentul se va familiariza cu caracteristicile implementării clasei și interacțiunii cu obiectele clasei. Studentul va primi, de asemenea, cunoștințe de bază despre construcție din linia de comandă a proiectelor.

## Sarcina

Sarcina se bazează pe lucrările anterioare de laborator. Pentru simplificarea procesului de lucru se propune să se efectueze pașii în mediul de dezvoltare [`Visual Studio Code`](https://code.visualstudio.com/Download), și cu compilatorul instalat [`MinGW G++`](https://www.msys2.org), program de construire a proiectelor [`make`](https://en.wikipedia.org/wiki/Make_(software)). De asemenea, pe calculator trebuie să fie instalat [`Git`](https://git-scm.com/downloads).

### Crearea unei ramuri

Deschideți consola și navigați în directorul `SnakeGame`. Obțineți ultimele modificări ale proiectului, executând comenzile:

```bash
# select default branch
git checkout main
# get last changes
git pull
```

Creati o ramură nouă pentru a efectua sarcina:

```bash
# create branch and switch to
git checkout -B lab02
```

### Adăugarea fișierelor cpp

Pentru fiecare fișier `hpp` creat anterior, creați un fișier `cpp` corespunzător. Fiecare fișier C++ trebuie să conțină implementările funcțiilor claselor declarate în fișierele anterioare. Conținutul aproximativ al fișierelor `cpp`.

1. `apple.cpp`

```cpp
#include "apple.hpp"

Apple::Apple() {}
Apple::Apple(const Point &position) {}
Point Apple::GetPosition() const {}
```

2. `board.cpp`

```cpp
#include "board.hpp"

Board::Board(int width, int height) {}
int Board::GetWidth() const {}
int Board::GetHeight() const {}
```

3. `direction.cpp`

```cpp
#include "direction.hpp"
```

4. `game_engine.cpp`

```cpp
#include "game_engine.hpp"

GameEngine::GameEngine() {}
void GameEngine::Init() {}
void GameEngine::Run() {}
```

5. `painter.cpp`

```cpp
#include "painter.hpp"

void Painter::DrawImage(Point topLeft, Point bottomRight, char **image) {}
void Painter::WriteText(Point position, char *text) {}
```

6. `pont.cpp`

```cpp
#include "point.hpp"
```

7. `snake.cpp`

```cpp
#include "snake.hpp"

Snake::Snake() {}
Snake::Snake(const Point &_position) {}
void Snake::Move(Direction direction) {}
int Snake::GetSize() const {}
Point Snake::GetPosition() const {}
void Snake::Eat(const Apple &apple) {}
```

Creati fisierul `main.cpp` care va contine punctul de intrare:

```cpp
#include "game_engine.hpp"

int main() {
    GameEngine engine;
    engine.Init();
    engine.Run();
    return 0;
}
```

### Compilarea din linia de comandă

Pentru verificarea funcționării compilatorului, în consolă navigați în directorul proiectului și executați următoarea comandă:

```bash
g++ apple.cpp -o apple.o -c
```

Cheia `-o` indică compilatorului să creeze un fișier obiect. În urma executării acestei comenzi în director va fi creat fișierul `apple.o`.

### Crearea fișierului de construcție

În directorul proiectului creați fișierul de construcție `Makefile` cu următorul conținut:


```makefile
all: SnakeGame

SnakeGame: apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o
	g++ -o Snake.exe apple.o board.o direction.o game_engine.o painter.o point.o snake.o main.o

apple.o:
	g++ apple.cpp -o apple.o -c

board.o:
	g++ board.cpp -o board.o -c

direction.o:
	g++ direction.cpp -o direction.o -c

game_engine.o:
	g++ game_engine.cpp -o game_engine.o -c

painter.o:
	g++ painter.cpp -o painter.o -c

point.o:
	g++ point.cpp -o point.o -c

snake.o:
	g++ snake.cpp -o snake.o -c

main.o:
	g++ main.cpp -o main.o -c

clean:
	rm -f *.o *.exe
```

In linia de comandă executați următoarele comenzi:

```bash
# clean directory from objects and executables
make clean
# build application
make
```

In directoriul proiectului va fi creată aplicația `Snake.exe` și o serie de fișiere obiect, cu extensia `.o`.

### Publicarea ramurii și îmbinarea acesteia

```bash
# add all files to tracking
git add *
# check status
git status
# create a commit
git commit -m "first compilation"
# push commit to remote repository
git push
```

Dupa aceasta puteti interclasa ramura `lab02` in ramura `main`, prin intermediul crearii unui pull request pe GitHub.

## Prezentare

La lucrare de laborator în Moodle adaugați referința repozitoriu.

## Evaluare

- `2p` - implementarea metodelor pentru structuri
- `4p` - crearea fișierului de construcție
- `1p` - crearea fișierului `.gitignore`
- `1p` - adaugarea in fisier `README.md` modului de construire a proiectului
- `2p` - adăugarea fișierelor `cpp` și fișierului de construcție pe GitHub în ramura `lab02`
- `-1p` - pentru fiecare zi de întârziere
- `-5p` - pentru copierea codului de la colegi
