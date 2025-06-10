# Iteratori și Containere

- [Iteratori și Containere](#iteratori-și-containere)
  - [Biblioteca standard C++](#biblioteca-standard-c)
  - [Iteratori](#iteratori)
    - [Iteratori de intrare](#iteratori-de-intrare)
    - [Iteratori de ieșire](#iteratori-de-ieșire)
    - [Iteratori secvențiali](#iteratori-secvențiali)
    - [Iteratori bidirecționali](#iteratori-bidirecționali)
    - [Iteratori cu acces aleator](#iteratori-cu-acces-aleator)
  - [Containere](#containere)
  - [Containere secvențiale](#containere-secvențiale)
    - [Vector](#vector)
    - [Listă](#listă)
    - [Coada dublă (deque)](#coada-dublă-deque)
  - [Containere asociative](#containere-asociative)
    - [Set](#set)
    - [Dicționar (map)](#dicționar-map)
  - [Bibliografie](#bibliografie)

## Biblioteca standard C++

Standardul limbajului C++ include nu doar descrierea nucleului limbajului (sintaxă, semantică etc.), ci și descrierea bibliotecii standard. Componenta principală a bibliotecii standard C++ este Biblioteca Standardă de Șabloane (eng. _STL - Standard Template Library_).

STL oferă un set de componente generice, bine proiectate și coerente. O atenție deosebită a fost acordată pentru ca toți algoritmii șablon să funcționeze nu doar cu structurile de date din bibliotecă, ci și cu structuri de date native C++. De exemplu, toți algoritmii funcționează cu pointeri obișnuiți. Proiectarea ortogonală a bibliotecii permite ca structurile de date din bibliotecă să fie folosite cu algoritmi proprii, iar algoritmii bibliotecii – cu structuri de date proprii. Cerințele semantice și de complexitate bine definite garantează că orice componentă a utilizatorului va funcționa corect și eficient cu biblioteca. Această flexibilitate asigură aplicabilitate largă.

Un alt aspect important este eficiența. C++ a avut succes deoarece combină expresivitatea cu eficiența. S-a acordat multă atenție pentru ca fiecare componentă să aibă o implementare generică eficientă, comparabilă cu una scrisă manual.

Biblioteca standard C++ este compusă din mai multe părți:

- biblioteca standard C;
- suport pentru limbajul C++;
- concepte;
- bibliotecă de diagnosticare;
- gestionarea memoriei;
- fluxuri de date;
- biblioteca STL;
- gestionarea thread-urilor;
- alte biblioteci suplimentare.

Fișierele header ale bibliotecii standard nu au extensie; bibliotecile C încep cu litera c (de exemplu, în loc de math.h se folosește `cmath`). Biblioteca standard C++ este declarată în spațiul de nume __std__.

Cea mai mare parte a bibliotecii standard C++ este STL. STL conține cinci tipuri principale de componente:

- _algoritm (algorithm)_: definește o procedură de calcul.
- _container (container)_: gestionează un set de obiecte în memorie.
- _iterator (iterator)_: oferă algoritmilor acces la conținutul containerului.
- _obiect funcțional (function object)_: încapsulează o funcție într-un obiect pentru a fi folosit de alte componente.
- _adaptor (adaptor)_: adaptează un component pentru a oferi o interfață diferită.
- _interval (range)_: reprezintă o pereche de iteratori care marchează începutul și sfârșitul unei secvențe.

Această împărțire reduce numărul de componente. De exemplu, în loc să scriem o funcție de căutare pentru fiecare tip de container, avem o singură versiune care funcționează cu oricare, atâta timp cât sunt îndeplinite cerințele de bază.

## Iteratori

Noțiunea de iterator este strâns legată de cea de container. Un __container__ este un obiect care conține un grup de alte obiecte (de obicei de același tip). Structuri de date binecunoscute precum vectorul, lista, stiva, harta – sunt containere.

Pentru a accesa elementele containerelor se folosesc iteratorii. Un __iterator__ este un obiect care oferă acces la elementele containerului și permite parcurgerea acestora. În primele implementări ale bibliotecii standard C++, iteratorul era realizat ca un pointer către elementul containerului.

Există mai multe tipuri de iteratori, care formează o ierarhie și se deosebesc prin anumite proprietăți:

- __Iteratori de intrare__ (eng. _Input iterators_) – permit citirea valorilor din container.
- __Iteratori de ieșire__ (eng. _Output iterators_) – permit scrierea valorilor în container.
- __Iteratori secvențiali__ (eng. _Consecutive iterators_) – baza pentru majoritatea algoritmilor, moștenesc proprietățile iteratorilor de intrare și ieșire.
- __Iteratori bidirecționali__ (eng. _Bidirectional iterators_) – permit deplasarea înainte și înapoi în container.
- __Iteratori cu acces aleator__ (eng. _Random access iterators_) – au toate proprietățile iteratorilor bidirecționali, plus operații de distanță și ordonare între iteratori.

Iteratorii au următoarele proprietăți de bază:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| constructor de copiere | `It(j);`     | Se creează o copie a iteratorului. Se presupune existența unui destructor |
|                      | `It i(j);`     |                                              |
|                      | `It i = j;`    |                                              |
| obținerea valorii    | `*i`           | returnează o referință la elementul containerului |
| incrementare prefixată | `++i`        | trece la următorul element                   |
| incrementare postfixată | `i++`       | trece la următorul element                   |

### Iteratori de intrare

Permite citirea valorilor din container.

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| operator de atribuire | `i = j`       |                                              |
| operator de egalitate | `i == j`      |                                              |
| operator de inegalitate | `i != j`    |                                              |

### Iteratori de ieșire

Permite scrierea valorilor în container.

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| atribuire element   | `*i = a`        | returnează o referință la element, permite scrierea în container |

### Iteratori secvențiali

Sunt baza pentru majoritatea algoritmilor și moștenesc proprietățile iteratorilor de intrare și ieșire. Au și proprietăți suplimentare, precum parcurgerea secvențială a elementelor containerului.

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| parcurgere secvențială | `++i`, `*i`  | permite accesul la fiecare element, în ordine |

### Iteratori bidirecționali

Permit deplasarea înainte și înapoi în container. Au toate proprietățile iteratorilor secvențiali, plus:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| decrementare prefixată | `--i`        | Există j astfel încât `i == ++j`. Dacă `i == j`, atunci `--i == --j` |
| decrementare postfixată | `i--`       | Dacă `i == j`, atunci `i-- == j--`           |

### Iteratori cu acces aleator

Au toate proprietățile iteratorilor bidirecționali, plus operații de distanță și ordonare:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| deplasare cu n elemente | `i += n`    |                                              |
|                      | `i + n`        | `i + n == n + i`                             |
|                      | `n + i`        |                                              |
| deplasare cu n elemente | `i -= n`    |                                              |
|                      | `i - n`        |                                              |
| distanță între iteratori | `i - j`    | `i == j + (i - j)`                           |
| acces prin index     | `a[n]`         | `*(a + n)`                                   |
| ordonare            | `i < j`         | `i - j > 0`                                  |
|                      | `i > j`        | `j < i`                                      |
|                      | `i <= j`       | `!(j < i)`                                   |
|                      | `i >= j`       | `!(i < j)`                                   |

## Containere

Un container este un obiect care conține alte obiecte (de același tip), numite elemente. Biblioteca standard C++ oferă containere tipice precum: _listă_, _vector_, _coadă_, _mapă_, _set_ etc. Accesul la elemente se face prin intermediul iteratorilor.

Containerele trebuie să respecte anumite cerințe generale, pentru a permite utilizarea lor uniformă, indiferent de implementare. Astfel, containerele sunt adesea interschimbabile.

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| tipul elementelor   | `C::value_type` |                                              |
|                     | `C::reference`  |                                              |
|                     | `C::const_reference` |                                         |
|                     | `C::pointer`    |                                              |
| iterator            | `C::iterator`   |                                              |
| iterator constant   | `C::const_iterator` |                                         |
|                     | `C::difference_type` |                                         |
|                     | `C::size_type`  |                                              |
| constructor implicit| `C u;`          |                                              |
|                     | `C()`           |                                              |
| constructor de copiere | `C(a)`       |                                              |
|                     | `C u(a);`       |                                              |
|                     | `C u = a;`      |                                              |
| destructor          | `~C()`          |                                              |
|                     | `a.begin()`     | Iterator la primul element                   |
|                     | `a.end()`       | Iterator după ultimul element                |
| comparare           | `a == b`        |                                              |
| inegalitate         | `a != b`        |                                              |
| copiere             | `r = a`         |                                              |
|                     | `a.size()`      | Numărul de elemente                          |
|                     | `a.max_size()`  | Numărul maxim de elemente                    |
|                     | `a.empty()`     | `a.size() == 0`                              |
| ordonare            | `a < b`         |                                              |
|                     | `a > b`         |                                              |
|                     | `a <= b`        |                                              |
|                     | `a >= b`        |                                              |
|                     | `a.swap(b)`     |                                              |

## Containere secvențiale

Containerele secvențiale stochează elementele într-o ordine liniară strictă. Exemple: __vector__, __listă__, __coadă__, __șir de caractere__.

Proprietăți obligatorii ale containerelor secvențiale:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| constructor         | `C(n, t)`       | creează un container cu n elemente egale cu t |
|                     | `C a(n, t);`    |                                              |
|                     | `C(i, j)`       | creează container pe intervalul `[i, j)`, unde `i` și `j` sunt iteratori |
|                     | `C a(i, j);`    | idem                                 |
| inserare            | `a.insert(p, t)`| inserează t înainte de iteratorul p          |
|                     | `a.insert(p, n, t)` | inserează n elemente t înainte de p      |
|                     | `a.insert(p, i, j)` | inserează intervalul `[i, j)` înainte de p |
| ștergere            | `a.erase(i)`    | șterge elementul la iteratorul i             |
|                     | `a.erase(i, j)` | șterge intervalul `[i, j)`                   |

### Vector

Vectorul (_vector_) este un container care stochează elemente ordonate. Suportă inserare, ștergere și căutare. Inserarea și ștergerea au complexitate O(n).

Proprietăți suplimentare:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| acces la element    | `a[n]`          | referință la elementul cu indexul n          |
|                     | `a.at(n)`       | referință la elementul n, aruncă excepție dacă n depășește dimensiunea |
| adăugare element    | `a.push_back(t)`| adaugă t la sfârșit                          |
| ștergere ultimul    | `a.pop_back()`  | șterge ultimul element                       |
| redimensionare      | `a.resize(n)`   | schimbă dimensiunea la n                     |
|                     | `a.resize(n, t)`| schimbă dimensiunea la n, noile elemente sunt t |

Se recomandă folosirea vectorilor în locul tablourilor dinamice. Vectorii oferă siguranță și ușurință în utilizare.

Exemplu de utilizare:

```cpp
#include <iostream>
#include <vector>

int main() {
  std::vector<int> v = {1, 2, 3, 4, 5};
  v.push_back(6);
  v[2] = 33;
  for(int el : v) {
    std::cout << el << " ";
  }
  std::cout << std::endl;
  return 0;
}
```

### Listă

Lista (_list_) este un container cu elemente ordonate. Inserarea și ștergerea au complexitate O(1).

Proprietăți suplimentare:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| inserare element    | `a.push_front(t)`| adaugă t la început                          |
|                     | `a.push_back(t)` | adaugă t la sfârșit                          |
| ștergere element    | `a.pop_front()`  | șterge primul element                        |
|                     | `a.pop_back()`   | șterge ultimul element                       |
| acces la element    | `a.front()`      | referință la primul element                  |
|                     | `a.back()`       | referință la ultimul element                 |

### Coada dublă (deque)

Deque-ul (_deque_) este un container cu elemente ordonate, permite inserare și ștergere la ambele capete în O(1). Accesul la elemente prin operatorul [] sau at() are complexitate O(1).

Proprietăți suplimentare:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| inserare element    | `a.push_back(t)` | adaugă t la sfârșit                          |
|                     | `a.push_front(t)`| adaugă t la început                          |
| ștergere element    | `a.pop_front()`  | șterge primul element                        |
|                     | `a.pop_back()`   | șterge ultimul element                       |
| acces la element    | `a.front()`      | referință la primul element                  |
|                     | `a.back()`       | referință la ultimul element                 |
|                     | `a[n]`           | referință la elementul cu indexul n          |

## Containere asociative

Containerele asociative stochează elemente sub formă de perechi cheie-valoare. Exemple: __set__, __map__, __multiset__, __multimap__.

### Set

Setul (_set_) este un container cu elemente unice ordonate crescător (implicit după operatorul <). Inserarea și ștergerea au complexitate O(log n).

Proprietăți obligatorii:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| constructor         | `C()`           | creează un set gol                           |
|                     | `C(a)`          | creează set din a                            |
|                     | `C(i, j)`       | creează set pe intervalul `[i, j)`           |
| inserare            | `a.insert(t)`   | inserează t în set                           |
|                     | `a.insert(i, j)`| inserează intervalul `[i, j)`                |
| ștergere            | `a.erase(t)`    | șterge t din set                             |
|                     | `a.erase(i)`    | șterge elementul la iteratorul i             |
|                     | `a.erase(i, j)` | șterge intervalul `[i, j)`                   |
| golire              | `a.clear()`     | șterge toate elementele                      |
| căutare             | `a.find(t)`     | iterator la t sau `a.end()` dacă nu există   |
|                     | `a.count(t)`    | numărul de apariții ale lui t                |
|                     | `a.lower_bound(t)` | iterator la primul element ≥ t             |
|                     | `a.upper_bound(t)` | iterator la primul element > t              |
|                     | `a.equal_range(t)` | pereche de iteratori pentru t               |

_Multiset-ul_ permite elemente duplicate.

### Dicționar (map)

Dicționarul (_map_) este un container cu perechi cheie-valoare ordonate după cheie (implicit după operatorul <). Inserarea și ștergerea au complexitate O(log n).

Proprietăți obligatorii:

| proprietate         | expresie        | observație                                   |
| ------------------- | --------------- | -------------------------------------------- |
| constructor         | `C()`           | creează un dicționar gol                     |
|                     | `C(a)`          | creează dicționar din a                      |
|                     | `C(i, j)`       | creează dicționar pe intervalul `[i, j)`     |
| inserare            | `a.insert({k, v})` | inserează perechea `{k, v}`                |
|                     | `a.insert(i, j)`| inserează intervalul `[i, j)`                |
|                     | `a[k] = v`      | inserează sau actualizează valoarea pentru cheia k |
| acces la element    | `a[k]`          | referință la valoarea pentru cheia k         |
|                     | `a.at(k)`       | referință la valoarea pentru cheia k, aruncă excepție dacă nu există |
| ștergere            | `a.erase(k)`    | șterge elementul cu cheia k                  |
|                     | `a.erase(i)`    | șterge elementul la iteratorul i             |
|                     | `a.erase(i, j)` | șterge intervalul `[i, j)`                   |
| golire              | `a.clear()`     | șterge toate elementele                      |
| căutare             | `a.find(k)`     | iterator la cheia k sau `a.end()` dacă nu există |
|                     | `a.count(k)`    | numărul de apariții ale cheii k              |
|                     | `a.lower_bound(k)` | iterator la primul element ≥ k             |
|                     | `a.upper_bound(k)` | iterator la primul element > k              |
|                     | `a.equal_range(k)` | pereche de iteratori pentru k               |

Se recomandă folosirea dicționarului ca container asociativ implicit, deoarece oferă toate proprietățile setului și permite stocarea perechilor cheie-valoare.

Exemplu de utilizare:

```cpp
#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> m = {{"one", 1}, {"two", 2}, {"three", 3}};
  m["four"] = 4;
  m["two"] = 22;
  for(auto el : m) {
    std::cout << el.first << " " << el.second << std::endl;
  }
  return 0;
}
```

_Multimap-ul_ permite chei duplicate.

## Bibliografie

1. [Întoarcerea la C++ – C++ modern, Microsoft](https://learn.microsoft.com/ro-ro/cpp/cpp/welcome-back-to-cpp-modern-cpp?view=msvc-170)
2. [Containers library, CPP Reference](https://en.cppreference.com/w/cpp/container)
