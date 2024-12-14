# Iteratori și containere

- [Iteratori și containere](#iteratori-și-containere)
  - [Biblioteca standard C++](#biblioteca-standard-c)
  - [Iteratori](#iteratori)
    - [Iteratori de citire](#iteratori-de-citire)
    - [Iteratori de scriere](#iteratori-de-scriere)
    - [Iteratori consecutivi](#iteratori-consecutivi)
    - [Iteratori bidirecționali](#iteratori-bidirecționali)
    - [Iteratori de acces aleatoriu](#iteratori-de-acces-aleatoriu)
  - [Containere](#containere)
  - [Containere secvențiale](#containere-secvențiale)
    - [Vector](#vector)
    - [Lista](#lista)
    - [Coadă bidirecțională](#coadă-bidirecțională)
  - [Containere asociative](#containere-asociative)
    - [Set](#set)
    - [Dicționar](#dicționar)
  - [Bibliografie](#bibliografie)

## Biblioteca standard C++

Standardul limbajului C++ include nu numai descrierea nucleului limbajului (sintaxa, semantica etc.), ci și descrierea bibliotecii standard. O parte importantă a bibliotecii standard C++ este Biblioteca Standard de Șabloane (_en. STL - Standard Template Library_).

Biblioteca Standard de Șabloane oferă un set de componente generice bine construite și care funcționează împreună. S-a acordat o atenție deosebită asigurării faptului că toate algoritmii șabloanelor funcționează nu numai cu structurile de date din bibliotecă, ci și cu structurile de date C++ încorporate. De exemplu, toți algoritmii funcționează cu pointeri obișnuiți. Proiectul ortogonal al bibliotecii (adică fiecare parte a sa este autonomă și independentă) permite programatorilor să utilizeze structurile de date ale bibliotecii cu propriii algoritmi și algoritmii bibliotecii cu propriile structuri de date. Cerințele semantice și de complexitate bine definite garantează că componenta utilizatorului va funcționa cu biblioteca și că va funcționa eficient. Această flexibilitate oferă o gamă largă de aplicații pentru bibliotecă.

O altă considerație importantă este eficiența. Limbajul C++ este popular pentru că combină puterea expresivă cu eficiența. S-a depus mult efort pentru a asigura că fiecare componentă din bibliotecă are o implementare generală care oferă eficiență de execuție comparabilă cu implementarea manuală.

Biblioteca Standard C++ este împărțită în mai multe părți:

- biblioteca standard limbajului C;
- biblioteca de support pentru limbajul C++;
- concepte;
- biblioteca de diagnosticare;
- managementul memoriei;
- fluxuri de date;
- biblioteca STL;
- managementul firelor de execuție;
- alte biblioteci.

Fișierele antet ale bibliotecii standard urmează următoarele reguli: fișierul antet este scris fără extensie; bibliotecile limbajului C încep cu litera `c` (de exemplu, în loc de `math.h` se folosește `cmath`). Biblioteca standard C++ este declarată în spațiul de nume __`std`__.

Cea mai mare parte a bibliotecii standard C++ este reprezentată de biblioteca STL (Standard Template Library). Biblioteca STL conține cinci tipuri principale de componente:

- _algoritmi (en. algorithm)_: definește proceduri de calcul;
- _containere (en. container)_: gestionează un set de obiecte în memorie;
- _iteratori (en. iterator)_: oferă algoritmilor un mijloc de acces la conținutul containerului;
- _obiecte funcționale (en. function object)_: încapsulează o funcție într-un obiect pentru a fi utilizată de alte componente;
- _adaptori (en. adaptor)_: adaptează o componentă pentru a oferi o interfață diferită.
- _interval (en. range)_: o pereche de iteratori care definesc începutul și sfârșitul unei secvențe.

Această structurare a bibliotecii permite micșorarea numărului de componente. De exemplu, în loc să scriem o funcție de căutare pentru fiecare tip de container, oferim o singură versiune care funcționează cu fiecare dintre ele, atâta timp cât sunt îndeplinite cerințele de bază.

## Iteratori

Notiunea de iteratori este strâns legată de notiunea de containere. Prin __container__ se înțelege un obiect care conține un grup de alte obiecte (de obicei de același tip). Astfel, structurile de date bine cunoscute, cum ar fi vectorul, lista, stiva, coada, harta, setul, sunt containere.

Pentru a accesa elementele containerelor, se folosesc iteratori. __Iteratorul__ este un obiect care oferă acces la elementele containerului și permite să le parcurgem. În primele implementări ale bibliotecii standard C++, iteratorul era implementat ca un pointer la elementul containerului.

Există mai multe tipuri de iteratori. Acestea definesc o ierarhie, diferind între ele prin prezența (absența) unor proprietăți:

- __Iteratori de citire__ (en. _Input iterators_) - permit citirea valorilor obiectelor containerului.
- __Iteratori de scriere__ (en. _Output iterators_) - permit scrierea valorilor în container.
- __Iteratori secvențiali__ (en. _Consecutive iterators_) - sunt de bază pentru majoritatea algoritmilor și moștenesc proprietățile iteratorilor de citire și de ieșire.
- __Iteratori bidirecționali__ (en. _Bidirectional iterators_) - permit deplasarea în ambele direcții.
- __Iteratori de acces aleator__ (en. _Random access iterators_) - permit deplasarea la orice element al containerului.

Iteratorii au următoarele proprietăți de bază:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| constructor de copiere | `It(j);`   | Se creează o copie a iteratorului. Se presupune existența destructorului |
|                  | `It i(j);`       |                                              |
|                  | `It i = j;`      |                                              |
| luarea valorii   | `*i`             | Se returnează o referință la elementul containerului |
| preincrementare  | `++i`            | Se schimbă iteratorul la următorul element al containerului |
| postincrementare | `i++`            | Se schimbă iteratorul la următorul element al containerului |

### Iteratori de citire

Iteratorii de citire (en. _Input iterators_) permit citirea valorilor obiectelor containerului.

Iteratorii de citire au următoarele proprietăți adiționale:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| operatorul de copiere | `i = j`     |                                              |
| operatorul de comparare | `i == j`  |                                              |
|                  | `i != j`         |                                              |

### Iteratori de scriere

Iteratorii de scriere (en. _Output iterators_) permit scrierea valorilor în container.

Iteratorii de scriere au următoarele proprietăți adiționale:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| operatorul de atribuire | `*i = j`  |                                              |

### Iteratori consecutivi

Iteratorii consecutivi (en. _Consecutive iterators_) sunt de bază pentru majoritatea algoritmilor și moștenesc proprietățile iteratorilor de citire și de ieșire.

### Iteratori bidirecționali

Iteratorii bidirecționali (en. _Bidirectional iterators_) permit deplasarea prin elementele containerelor în ambele direcții. Aceștia moștenesc toate proprietățile iteratorilor consecutivi, dar adaugă și următoarele proprietăți:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| predecrementare  | `--i`            | Se presupune ca există așa `j` ca `i == ++j`. Dacă `i == j`, atunci `--i == --j` |
| postdecrementare | `i--`            |                                              |

### Iteratori de acces aleatoriu

Iteratorii de acces aleator (en. _Random access iterators_) are toate proprietățile iteratorilor bidirecționali. În plus, aceștia permit deplasarea la orice element al containerului și este definită operație de comparare a iteratorilor.

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| deplasare la n elemente | `i += n`  |                                              |
|                  | `i + n`          | `i + n == n + i`                             |
|                  | `n + i`          |                                              |
|                  | `i -= n`         |                                              |
|                  | `i - n`          |                                              |
| distanța între doi iteratori | `i - j` | `i == j + (i - j)`                        |
| acces după index | `a[n]`           | `*(a + n)`                                   |
| comparare a iteratorilor | `i < j`  | `i - j > 0`                                  |
|                  | `i < j`          | `i - j > 0`                                  |
|                  | `i > j`          | `j < i`                                      |
|                  | `i <= j`         | `!(j < i)`                                   |
|                  | `i >= j`         | `!(i < j)`                                   |

## Containere

Sub __container__ se înțelege un obiect care conține un grup de alte obiecte (de obicei de același tip). Biblioteca standard C++ oferă o serie de containere tipice, cum ar fi: _`vector`_, _`list`_, _`queue`_, _`map`_, _`set`_ etc. Accesul la elementele containerelor se realizează prin iteratori.

Către containere se aplică o serie de cerințe comune. Acestea sunt necesare pentru a asigura utilizarea uniformă a containerelor, indiferent de implementare. Prin urmare, containerele sunt adesea interschimbabile.

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| tip element container | `C::value_type` |                                          |
|                  | `C::reference`   |                                              |
|                  | `C::const_reference` |                                          |
|                  | `C::pointer`     |                                              |
| iterator         | `C::iterator`    |                                              |
| iterator constant | `C::const_iterator` |                                          |
|                  | `C::difference_type` |                                          |
|                  | `C::size_type`   |                                              |
| constructor implicit | `C u;`   |                                                  |
|                  | `C()`            |                                              |
| constructor de copiere | `C(a)`    |                                               |
|                  | `C u(a);`        |                                              |
|                  | `C u = a;`       |                                              |
| destructor       | `~C()`           |                                              |
|                  | `a.begin()`      | Returnează un iterator care indică primul element al containerului |
|                  | `a.end()`        | Returnează un iterator care indică după ultimul element al containerului |
| comparare        | `a == b`         |                                              |
|                  | `a != b`         |                                              |
| copiere          | `r = a`          |                                              |
|                  | `a.size()`       | Returnează numărul de elemente din container |
|                  | `a.max_size()`   | Returnează numărul maxim de elemente pe care le poate conține containerul |
|                  | `a.empty()`      | `a.size() == 0`                              |
| ordonare         | `a < b`          |                                              |
|                  | `a > b`          |                                              |
|                  | `a <= b`         |                                              |
|                  | `a >= b`         |                                              |
|                  | `a.swap(b)`      |                                              |

## Containere secvențiale

Containerele secvențiale păstrează elementele într-o secvență strict liniară. Containerele secvențiale includ structuri de date bine cunoscute, cum ar fi __vectorul__, __lista__, __coada__ și __șirul de caractere__.

Proprietățile de bază ale containerelor secvențiale sunt:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| constructor      | `C(n, t)`        | creează un container cu `n` elemente egale cu `t` |
|                  | `C a(n, t);`     |                                              |
|                  | `C(i, j)`        | creează un container pe baza intervalului de iteratori |
|                  | `C a(i, j);`     |                                              |
| inserare         | `a.insert(p, t)` | inserează elementul `t` înaintea iteratorului `p` |
|                  | `a.insert(p, n, t)` | inserează `n` elemente `t` înaintea iteratorului `p` |
|                  | `a.insert(p, i, j)` | inserează intervalul semi-deschis `[i, j)` înaintea iteratorului `p` |
| eliminare        | `a.erase(i)`     | elimină elementul la care se referă iteratorul `i` |
|                  | `a.erase(i, j)`  | elimină intervalul semi-deschis `[i, j)` din container |

### Vector

__Vector__ (en. _vector_) este un container care păstrează elementele în ordine liniară. Vectorul suportă operațiile de inserare, ștergere și căutare a elementelor. Inserarea și ștergerea elementelor din vector se realizează în timpul O(n), unde n este numărul de elemente din vector.

În afară de proprietățile obligatorii ale containerelor secvențiale, vectorul are următoarele proprietăți:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| acces la element | `a[n]`           | returnează o referință la elementul cu indexul `n` |
|                  | `a.at(n)`        | returnează o referință la elementul cu indexul `n`. Dacă `n` este în afara intervalului, se generează o excepție |
| adăugare element | `a.push_back(t)` | adaugă elementul `t` la sfârșitul vectorului |
| ștergere element | `a.pop_back()`   | elimină ultimul element din vector           |
| schimbarea dimensiunii | `a.resize(n)` | schimbă dimensiunea vectorului la `n` elemente. Dacă `n` este mai mare decât dimensiunea actuală, noile elemente sunt inițializate cu valoarea implicită |
|                  | `a.resize(n, t)` | schimbă dimensiunea vectorului la `n` elemente. Dacă `n` este mai mare decât dimensiunea actuală, noile elemente sunt inițializate cu valoarea `t` |

În loc de vectori dinamic din limbajul C, în C++ se recomandă utilizarea containerelor vector. Vectorii au toate proprietățile vectorilor din limbajul C, dar asigură siguranța și ușurința de utilizare.

Exemplu de utilizare a vectorului:

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

### Lista

__Lista__ (en. _list_) este un container care păstrează elementele în ordine liniară. Lista suportă operațiile de inserare, ștergere și căutare a elementelor. Inserarea și ștergerea elementelor din listă se realizează în timpul O(1), unde n este numărul de elemente din listă.

În afară de proprietățile obligatorii ale containerelor secvențiale, lista are următoarele proprietăți:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| înserarea elementului | `a.push_front(t)` | adaugă elementul `t` la începutul listei |
|                      | `a.push_back(t)`  | adaugă elementul `t` la sfârșitul listei |
| ștergerea elementului | `a.pop_front()`   | elimină primul element din listă       |
|                      | `a.pop_back()`    | elimină ultimul element din listă       |
| acces la element      | `a.front()`       | returnează o referință la primul element din listă |
|                      | `a.back()`        | returnează o referință la ultimul element din listă |

### Coadă bidirecțională

__Coada bidirecțională__ (en. deque) este un container care păstrează elementele în ordine liniară. Acest container suportă operațiile de inserare, ștergere și căutare a elementelor. Inserarea și ștergerea elementelor din coadă se realizează în timpul O(1), unde n este numărul de elemente din coadă.

În afară de proprietățile obligatorii ale containerelor secvențiale, coada bidirecțională are următoarele proprietăți:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| adăugare element | `a.push_back(t)` | adaugă elementul `t` la sfârșitul cozii     |
|                  | `a.push_front(t)` | adaugă elementul `t` la începutul cozii     |
| ștergere element | `a.pop_front()`  | elimină primul element din coadă             |
|                  | `a.pop_back()`   | elimină ultimul element din coadă            |
| acces la element | `a.front()`      | returnează o referință la primul element din coadă |
|                  | `a.back()`       | returnează o referință la ultimul element din coadă |
|                 | `a[n]`           | returnează o referință la elementul cu indexul `n` din coadă |

## Containere asociative

Containerele asociative păstrează elementele ca o pereche cheie-valoare. Elementele sunt sortate în funcție de cheie. Containerele asociative includ structuri de date bine cunoscute, cum ar fi __mulțime__, __dicționar__, __mulțime cu repetări__ și __dicționar cu repetări__.

### Set

__Mulțimea__ (en. _set_) este un container care păstrează elementele unice ordonate în ordine crescătoare. Mulțimea suportă operațiile de inserare, ștergere și căutare a elementelor. Inserarea și ștergerea elementelor din mulțime se realizează în timpul $O(log(n))$, unde n este numărul de elemente din mulțime.

Proprietățile de bază ale mulțimii sunt:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| constructor      | `C()`            | creează o mulțime goală                      |
|                  | `C(a)`           | creează o mulțime din a                      |
|                  | `C(i, j)`        | creează o mulțime pe baza intervalului de iteratori |
| inserare         | `a.insert(t)`    | inserează elementul t în mulțime             |
|                  | `a.insert(i, j)` | inserează intervalul semi-deschis `[i, j)` în mulțime |
| ștergere         | `a.erase(t)`     | elimină elementul t din mulțime              |
|                  | `a.erase(i)`     | elimină elementul la care se referă iteratorul i |
|                  | `a.erase(i, j)`  | elimină intervalul semi-deschis `[i, j)` din mulțime |
|                  | `a.clear()`      | elimină toate elementele din mulțime         |
| căutare          | `a.find(t)`      | returnează iteratorul la elementul t, dacă acesta există în mulțime, altfel returnează `a.end()` |
|                  | `a.count(t)`     | returnează numărul de elemente t din mulțime |
|                  | `a.lower_bound(t)` | returnează iteratorul la primul element care nu este mai mic decât t |  
|                  | `a.upper_bound(t)` | returnează iteratorul la primul element care este mai mare decât t |
|                  | `a.equal_range(t)` | returnează o pereche de iteratori, primul dintre care este egal cu `a.lower_bound(t)`, iar al doilea - `a.upper_bound(t)` |

Exemplu de utilizare a mulțimii:

```cpp
#include <iostream>
#include <set>

int main() {
  std::set<int> s = {1, 2, 3, 4, 5};

  s.insert(6);
  s.insert(2);

  for(auto el : s) {
    std::cout << el << " ";
  }
  std::cout << std::endl;

  return 0;
}
```

Mulțimea cu repetări (en. _multiset_) este similară cu mulțimea, dar permite stocarea elementelor duplicate.

### Dicționar

__Dicționar__ (en. _map_) este un container care păstrează elementele ca perechi cheie-valoare unice ordonate în ordine crescătoare a cheilor. Dicționarul suportă operațiile de inserare, ștergere și căutare a elementelor. Inserarea și ștergerea elementelor din dicționar se realizează în timpul $O(log(n))$, unde n este numărul de elemente din dicționar.

Proprietățile de bază ale dicționarului sunt:

| proprietate      | expresie         | observații                                   |
| ---------------- | ---------------- | -------------------------------------------- |
| constructor      | `C()`            | creează un dicționar gol                     |
|                  | `C(a)`           | creează un dicționar din a                   |
|                  | `C(i, j)`        | creează un dicționar pe baza intervalului de iteratori |
| inserare         | `a.insert({k, v})` | inserează perechea `{k, v}` în dicționar     |
|                  | `a.insert(i, j)` | inserează intervalul semi-deschis `[i, j)` în dicționar |
|                  | `a[k] = v`       | inserează perechea `{k, v}` în dicționar, dacă cheia `k` nu există, altfel actualizează valoarea după cheie `k` |
| acces la element | `a[k]`           | returnează o referință la valoarea după cheia `k` |
|                  | `a.at(k)`        | returnează o referință la valoarea după cheia `k`. Dacă cheia `k` nu există, se generează o excepție |
| ștergere         | `a.erase(k)`     | elimină elementul cu cheia `k` din dicționar |
|                  | `a.erase(i)`     | elimină elementul la care se referă iteratorul i |
|                  | `a.erase(i, j)`  | elimină intervalul semi-deschis `[i, j)` din dicționar |
|                  | `a.clear()`      | elimină toate elementele din dicționar        |
| căutare          | `a.find(k)`      | returnează iteratorul la elementul cu cheia `k`, dacă acesta există în dicționar, altfel returnează `a.end()` |
|                  | `a.count(k)`     | returnează numărul de elemente cu cheia `k` din dicționar |
|                  | `a.lower_bound(k)` | returnează iteratorul la primul element care nu este mai mic decât k |
|                  | `a.upper_bound(k)` | returnează iteratorul la primul element care este mai mare decât k |
|                  | `a.equal_range(k)` | returnează o pereche de iteratori, primul dintre care este egal cu `a.lower_bound(k)`, iar al doilea - `a.upper_bound(k)` |

Exemplu de utilizare a dicționarului:

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

Dicționarul cu repetări (en. _multimap_) este similar cu dicționarul, dar permite stocarea elementelor cu chei identice.

## Bibliografie

1. [Welcome back to C++ - Modern C++, Microsoft](https://learn.microsoft.com/en-us/cpp/cpp/welcome-back-to-cpp-modern-cpp)
2. [Containers library, CPP Reference](https://en.cppreference.com/w/cpp/container)
