# Tipuri de date derivate

- [Tipuri de date derivate](#tipuri-de-date-derivate)
  - [pseudonime](#pseudonime)
  - [enumerări](#enumerări)
  - [structuri](#structuri)
  - [clase](#clase)
    - [Cuvântul cheie this](#cuvântul-cheie-this)
  - [Bibliografie](#bibliografie)

## pseudonime

Pentru a reduce codul și a îmbunătăți citirea codului sursă, se pot defini pseudonime tipurilor. În plus, definirea pseudonimelor facilitează lucrul cu pointeri la funcții.

Pseudonimele tipurilor se definesc cu ajutorul cuvântului cheie __typedef__.

```cpp
// imbunatatim citirea codului
typedef unsigned char age_type;

// comod pentru crearea pointerilor la functii.
// [pointer la functie](https://sweethome.gitbook.io/advanced-cpp/particularities/function_pointers)
typedef void (*pfunc_type)(void);

// reducem numele tipului lung
typedef std::vector<unsigned int>::const_iterator const_iterator;

age_type age;
pfunc_type handlers[10];
const_iterator it;
```

Totodata, in C++11 a fost introdus un nou mod de a defini pseudonimele tipurilor, care este mai flexibil si mai puternic decat __typedef__. Acesta se numeste __aliasuri de tipuri__ (type aliases) care se definesc cu ajutorul cuvintului cheie __using__.

Sintaxa:

```cpp
using <nume nou al tipului> = <tip>;
```

Exemple:

```cpp
using BYTE = unsigned char;
using WORD = unsigned short int;

BYTE byte;
WORD word;
```

## enumerări

Enumerările sunt un tip de date personalizat definit ca un set de constante întregi. O variabilă de enumerare poate lua valori doar din setul de valori specificat.

Sintaxa:

```cpp
enum class <nume tip> {
  <constanta_1>,
  <constanta_2>,
  ...
  <constanta_n>
};
```

Exemple de declarații a enumerărilor:

```cpp
enum class CURRENCY {
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

enum struct direction_t {
  north,
  south,
  east,
  west
};
```

Valoarea enumerarii se specifica prin `<nume tip>::<cume constanta>`.

Constantele enumerarilor implicit obtin valori intregi consecutive, incepand cu zero. Prin urmare, constanta `CURRENCY::MDL` va fi egala cu zero, `CURRENCY::USD` va fi egala cu unu, si asa mai departe. Cu toate acestea, nu este recomandat sa folositi valori numerice pentru a lucra cu enumerarile, ci numele lor.

Exemplu de utilizare a enumerarilor:

```cpp
CURRENCY valuta = CURRENCY::MDL;
color_type backgroundColor = color_type::white;
direction_t direction = direction_t::east;
```

## structuri

Structura este un tip de date derivat care combina valorile altor tipuri de date de baza sau structuri. Exemple de structuri includ numere complexe, puncte pe plan sau vectori planare ca o combinatie a doua variabile reale.

```cpp
struct <nume tip> {
  /* tip_1 */ /* camp_1 */;
  /* tip_2 */ /* camp_2 */;
  // ...
  /* tip_n */ /* camp_n */;
};
```

Exemplu de declarare a structurii _punct pe plan_:

```cpp
struct point_t {
  double x;
  double y;
};
```

Declararea unui obiect de structură este echivalentă cu declararea unei variabile. Inițializarea obiectului poate fi efectuată prin enumerarea valorilor câmpurilor obiectului separate prin virgulă și încadrate în acolade:

```cpp
point_t pt {1., 0.};
pt.x = -3.7;
pt.y = 12.2;
```

Acces la câmpurile structurii se realizează cu ajutorul operatorului `.`. De exemplu, pentru a accesa coordonata x a punctului `pt` se folosește `pt.x`.

## clase

Clasele reprezintă o extensie a structurilor. Ele permit gruparea nu numai a datelor sub un singur nume, ci și a funcțiilor care operează cu aceste date.

Formal, _clasa este un tip de date personalizat care descrie o abstractizare a obiectelor din lumea reală_. O instanță a clasei (adică o variabilă a acestui tip) se numește _obiect_ (în general, orice variabilă poate fi numită obiect a unui tip).

Sintaxa de declarare a clasei:

```cpp
class <nume clasa> {
private:
  /* tip_1 */ /* camp_1 */;
  /* tip_2 */ /* camp_2 */;
  // ...
  /* tip_n */ /* camp_n */;

public:
  /* tip_1 */ /* metoda_1 */;
  /* tip_2 */ /* metoda_2 */;
  // ...
  /* tip_n */ /* metoda_n */;
};
```

Variabile definite in clasa se numesc __date-membru__ (member data), __atribute__ (attributes) sau __câmpuri__ (fields), funcțiile definite în clasă se numesc __funcții-membru__ (member functions) sau __metode__ (methods).

In cadrul clasei se poate controla accesul la datele si functiile declarate, facandu-le disponibile pentru utilizator sau ascunzandu-le. Acest lucru se realizeaza cu ajutorul cuvintelor cheie __public__, __private__ si __protected__, care definesc accesul imediat pentru un grup de membri ai clasei.

Implicit, toate datele-membru și metodele clasei sunt private.

> In limbajul C++ structurile se deosebesc de clase doar prin acces: in structuri accesul la elemente este deschis implicit, in clase accesul la elemente este inchis implicit.

Exemplu de declarare a clasei _personaj de joc_:

```cpp
class GameCharacter {
  std::string _name;
  size_t      _health;
  size_t      _attack;
  size_t      _defence;
  point_t     _position;

public:
  GameCharacter(string); // constructor
  void Move(direction_t);

  void Attack(GameCharacter&);
}
```

De obicei în C++ se separă declarația clasei (și nu numai) de implementare. O practică bună este de a crea pentru fiecare clasă două fișiere: în _fișierul header_ se descrie clasa, în _fișierul sursă_ se implementează metodele.

La descrierea realizării metodelor clasei se folosește următoarea sintaxă:

```cpp
<tip date returnabil> <nume clasa>::<nume metoda>(<parametri>) {
  <corpul functiei>
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
        case direction_t::north: // top
            _position.x -= 1;
            break;
        case direction_t::south: // bottom
            _position.x += 1;
            break;
        case direction_t::east: // right
            _position.y += 1;
            break;
        case direction_t::west: // left
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
        gameCharacter._health -= gameCharacter._health - damage;
    }
    else {
        gameCharacter._health = 0;
    }    
}
```

### Cuvântul cheie this

Clasa descrie un set de obiecte cu aceleași proprietăți și comportament, însă comportamentul (adică utilizarea metodelor) se referă la un obiect specific. Pentru a indica că acțiunea se referă la obiect, se folosește cuvântul cheie __this__. Acest cuvânt cheie reprezintă un pointer la (obiectul curent) care oferă acces la proprietățile și metodele obiectului prin operatorul săgeată `->`.

Cuvântul cheie __this__ poate fi folosit numai în metodele clasei.

Exemplu de utilizare:

```cpp
void GameCharacter::Move(direction_t direction)
{
    switch (direction) {
        case direction_t::north: // top
            this->_position.x -= 1;
            break;
        case direction_t::south: // bottom
            this->_position.x += 1;
            break;
        case direction_t::east: // right
            this->_position.y += 1;
            break;
        case direction_t::west: // left
            this->_position.y -= 1;
            break;
    }
}
```

Mai detaliat clasele sunt discutate în contextul [programării orientate pe obiecte](./14_oop.md).

## Bibliografie

1. [Standardul limbajului C++](https://github.com/cplusplus/draft/releases/tag/n4917)
2. [cppreference.com](https://en.cppreference.com/w/cpp/language/class)
