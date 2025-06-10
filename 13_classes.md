# Tipuri de date definite de utilizator

- [Tipuri de date definite de utilizator](#tipuri-de-date-definite-de-utilizator)
  - [Pseudonime de tip](#pseudonime-de-tip)
  - [Enumerații](#enumerații)
  - [Structuri](#structuri)
  - [Clase](#clase)
    - [Cuvântul cheie this](#cuvântul-cheie-this)
  - [Bibliografie](#bibliografie)

## Pseudonime de tip

Pentru a îmbunătăți lizibilitatea programelor, se pot defini pseudonime pentru tipuri de date. De asemenea, definirea pseudonimelor simplifică lucrul cu pointeri la funcții și permite scurtarea tipurilor lungi, de exemplu la utilizarea containerelor STL.

Un pseudonim de tip se definește cu ajutorul cuvântului cheie __typedef__.

```cpp
// îmbunătățim lizibilitatea codului
typedef unsigned char age_type;

// util pentru crearea pointerilor la funcții.
// [Pointer la funcție](https://sweethome.gitbook.io/advanced-cpp/particularities/function_pointers)
typedef void (*pfunc_type)(void);

// scurtăm un tip lung
typedef std::vector<unsigned int>::const_iterator const_iterator;

age_type age;
pfunc_type handlers[10];
const_iterator it;
```

De asemenea, pseudonimele de tip pot fi definite cu ajutorul cuvântului cheie __using__.

Sintaxă:

```cpp
using <nume_nou_tip> = <tip>;
```

Exemple:

```cpp
using BYTE = unsigned char;
using WORD = unsigned short int;

BYTE byte;
WORD word;
```

## Enumerații

O enumerație este un tip de date definit de utilizator, reprezentat ca o listă de constante întregi. O variabilă de tip enumerație poate avea doar valorile definite în acea enumerație.

Sintaxă:

```cpp
enum <nume_tip> {
  <constantă_1>,
  <constantă_2>,
  ...
  <constantă_n>
};
```

sau

```cpp
enum class <nume_tip> {
  <constantă_1>,
  <constantă_2>,
  ...
  <constantă_n>
};
```

Exemple de declarare a enumerațiilor:

```cpp
enum CURRENCY {
  MDL,
  USD,
  EUR
};

enum class color_type {
  white,
  red,
  green,
  blue,
  black,
};

enum class direction_t {
  north,
  south,
  east,
  west
};
```

Constantele enumerațiilor primesc valori întregi consecutive, începând de la zero. Astfel, `CURRENCY::MDL` va avea valoarea zero, `CURRENCY::USD` valoarea unu etc. Totuși, este recomandat să se folosească numele constantelor definite în enumerație, nu valorile lor numerice.

Numele unei constante de enumerație se scrie ca `<nume_tip>::<nume_constantă>`.

Exemple de declarare și inițializare a variabilelor de tip enumerație:

```cpp
CURRENCY valuta = CURRENCY::MDL;
color_type backgroundColor = color_type::white;
direction_t direction = direction_t::east;
```

## Structuri

O structură este un tip de date definit de utilizator care grupează logic valori ale unor tipuri de bază sau ale altor structuri. Exemple de structuri pot fi un număr complex, un punct în plan sau un vector plan, ca reuniune a două variabile reale.

```cpp
struct <nume_structură> {
  /* tip_1 */ /* proprietate_1 */;
  /* tip_2 */ /* proprietate_2 */;
  // ...
  /* tip_n */ /* proprietate_n */;
};
```

Exemplu de declarare a structurii _punct în plan_:

```cpp
struct point_t {
  double x;
  double y;
};
```

Declararea unui obiect de tip structură este echivalentă cu declararea unei variabile. Inițializarea obiectului se poate face prin enumerarea valorilor câmpurilor între acolade:

```cpp
point_t pt {1., 0.};
pt.x = -3.7;
pt.y = 12.2;
```

Accesul la câmpurile structurii se face cu operatorul `.`.

## Clase

Clasele reprezintă o extensie a conceptului de structură. Ele permit gruparea nu doar a datelor sub un singur nume, ci și a funcțiilor care operează asupra acestor date.

Formal, _o clasă este un tip de date definit de utilizator care descrie o abstractizare a obiectelor din lumea reală_. Instanța unei clase (adică o variabilă de acest tip) se numește _obiect_ (în general, orice variabilă poate fi numită obiect al unui tip).

Sintaxa declarării unei clase:

```cpp
class <nume_clasă> {
private:
  /* tip_1 */ /* proprietate_1 */;
  /* tip_2 */ /* proprietate_2 */;
  // ...
  /* tip_n */ /* proprietate_n */;

public:
  /* tip_1 */ /* metodă_1 */;
  /* tip_2 */ /* metodă_2 */;
  // ...
  /* tip_n */ /* metodă_n */;
};
```

Variabilele declarate într-o clasă se numesc __membri-date__ (member data), __proprietăți__ (atribute) sau __câmpuri__ (fields), iar funcțiile declarate într-o clasă se numesc __membri-funcții__ (member functions) sau __metode__ (methods).

Într-o clasă se poate controla accesul la variabile și funcții, făcându-le publice sau ascunse. Acest lucru se realizează cu ajutorul cuvintelor cheie __public__, __private__ și __protected__, care stabilesc accesul pentru grupuri de membri ai clasei.

Implicit, accesul la membrii unei clase este privat.

> În C++, structurile diferă de clase doar prin accesul implicit: în structuri accesul la membri este public, iar în clase este privat.

Exemplu de declarare a clasei _personaj de joc_:

```cpp
class GameCharacter {
  std::string _name;
  size_t      _health;
  size_t      _attack;
  size_t      _defence;
  point_t     _position;

public:
  GameCharacter(std::string); // constructor
  void Move(direction_t);

  void Attack(GameCharacter&);
};
```

În C++ este obișnuit să se separe declarația clasei (și nu numai) de implementare. O bună practică este crearea pentru fiecare clasă a două fișiere: în _fișierul header_ se descrie clasa, iar în _fișierul sursă_ se scrie implementarea metodelor.

Pentru implementarea metodelor unei clase se folosește următoarea sintaxă:

```cpp
<tip_returnat> <nume_clasă>::<nume_metodă>(<parametri>) {
  <corp_functie>
}
```

```cpp
GameCharacter::GameCharacter(std::string name): 
    _name(name), _attack(10), _health(100), _defence(2)
{
}

void GameCharacter::Move(direction_t direction)
{
    switch (direction) {
        case direction_t::north: // sus
            _position.x -= 1;
            break;
        case direction_t::south: // jos
            _position.x += 1;
            break;
        case direction_t::east: // dreapta
            _position.y += 1;
            break;
        case direction_t::west: // stânga
            _position.y -= 1;
            break;
    }
}

void GameCharacter::Attack(GameCharacter & gameCharacter)
{
    size_t damage = 0;
    if(this->_attack >= gameCharacter._defence) {
        damage = this->_attack - gameCharacter._defence;
    }
    if(gameCharacter._health >= damage) {
        gameCharacter._health -= damage;
    }
    else {
        gameCharacter._health = 0;
    }    
}
```

### Cuvântul cheie this

O clasă descrie o mulțime de obiecte cu aceleași proprietăți și comportamente, însă comportamentul (adică utilizarea metodelor) se referă la un anumit obiect. Pentru a indica faptul că acțiunea se referă la obiectul curent, se folosește cuvântul cheie __this__. Acest cuvânt cheie reprezintă un pointer la obiectul curent, oferind acces la proprietățile și metodele obiectului prin operatorul _săgeată_ `->`.

Cuvântul cheie __this__ se folosește doar în contextul metodelor clasei.

Exemplu de utilizare:

```cpp
void GameCharacter::Move(direction_t direction)
{
    switch (direction) {
        case direction_t::north: // sus
            this->_position.x -= 1;
            break;
        case direction_t::south: // jos
            this->_position.x += 1;
            break;
        case direction_t::east: // dreapta
            this->_position.y += 1;
            break;
        case direction_t::west: // stânga
            this->_position.y -= 1;
            break;
    }
}
```

Mai detaliat, clasele sunt analizate în contextul [programării orientate pe obiect](./14_oop.md).

## Bibliografie

1. [Standardul limbajului C++](https://github.com/cplusplus/draft/releases/tag/n4917)
2. [cppreference.com](https://en.cppreference.com/w/cpp/language/class)
