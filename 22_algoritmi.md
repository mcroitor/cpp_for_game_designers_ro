# Algoritmi

- [Algoritmi](#algoritmi)
  - [Noțiunea de algoritm](#noțiunea-de-algoritm)
    - [Functor (obiect funcțional)](#functor-obiect-funcțional)
    - [Predicați](#predicați)
    - [Reguli de denumire a algoritmilor STL](#reguli-de-denumire-a-algoritmilor-stl)
  - [Algoritmi care nu modifică datele](#algoritmi-care-nu-modifică-datele)
    - [Operații de căutare](#operații-de-căutare)
  - [Algoritmi care modifică datele](#algoritmi-care-modifică-datele)
    - [Copiere](#copiere)
    - [Umplere](#umplere)
    - [Transformare](#transformare)
    - [Ștergere](#ștergere)
    - [Reordonare](#reordonare)
    - [Sortare](#sortare)
  - [Structura algoritmilor](#structura-algoritmilor)
    - [Căutarea unui element într-o colecție](#căutarea-unui-element-într-o-colecție)
    - [Căutarea unui element care satisface o condiție](#căutarea-unui-element-care-satisface-o-condiție)
    - [Copierea elementelor care satisfac o condiție](#copierea-elementelor-care-satisfac-o-condiție)
  - [Exemple de utilizare](#exemple-de-utilizare)
    - [Citirea și afișarea datelor](#citirea-și-afișarea-datelor)
    - [Căutarea primului număr par într-un vector](#căutarea-primului-număr-par-într-un-vector)
    - [Citire, sortare și căutare](#citire-sortare-și-căutare)
  - [Bibliografie](#bibliografie)

## Noțiunea de algoritm

> Algoritmul este o succesiune finită de acțiuni care conduc la un rezultat dorit.

Implementările algoritmilor din biblioteca standard C++ sunt foarte simple și eficiente. De aceea, este util să acordați timp pentru a studia sursele acestora.

Toți algoritmii din biblioteca standard de șabloane sunt separați de detaliile de implementare ale structurilor de date și folosesc ca parametri tipuri de iteratori. Astfel, pot funcționa cu structuri de date definite de utilizator, atâta timp cât acestea oferă tipuri de iteratori care respectă cerințele algoritmilor.

Algoritmii STL operează în principal cu containere și folosesc ca parametri intervale semi-deschise de iteratori.

### Functor (obiect funcțional)

> Un functor este un obiect al unei clase pentru care operatorul de apelare a funcției `()` este suprascris.

În declarația unei clase se poate suprascrie operatorul `()`. Dacă acest operator este definit, obiectele clasei pot fi folosite ca funcții. Astfel de obiecte se numesc obiecte funcționale sau functori. Functorii sunt utili atunci când funcția trebuie să aibă "memorie" sau ca alternativă la pointerii către funcții.

> Uneori, prin obiect funcțional se înțelege și un pointer la funcție.

Exemplu de functor care schimbă valorile a două variabile întregi și numără apelurile:

```cpp
/**
 * @file swap_functor.cpp
 * @brief Exemplu de utilizare a unui obiect funcțional
 * @details g++ -std=c++20 -o swap_functor swap_functor.cpp
 */
class _swap{
    static size_t counter;
    static void increment() { ++counter; }
public:
    _swap(){}
    void operator ()(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
        increment();
    }
    static size_t getNrCalls() {return counter; }
};

size_t _swap::counter = 0;

int main() {
    _swap swap;
    int a = 3, b = 5;
    swap(a, b);
    return 0;
}
```

### Predicați

> Un predicat este o funcție care returnează o valoare logică (bool).

Algoritmii STL folosesc predicați unari și binari.

Exemplu de predicat pentru verificarea parității unui număr:

```cpp
bool esteImpar(int value) {
   return value % 2 == 1;
}
```

### Reguli de denumire a algoritmilor STL

Pentru unii algoritmi există atât versiuni operative (rezultatul este salvat în segmentul indicat de iteratori), cât și versiuni de copiere. Decizia de a include sau nu o versiune de copiere a fost bazată pe eficiența algoritmului. Când costul operației este dominant față de costul copiei, versiunea de copiere nu este inclusă. De exemplu, `sort_copy` nu există, deoarece sortarea este mult mai costisitoare, iar utilizatorul poate apela `copy` înainte de `sort`.

Versiunea de copiere a unui algoritm se numește `algorithm_copy` (se adaugă sufixul `_copy`). În algoritmii de copiere nu se specifică sfârșitul celui de-al doilea interval, deoarece acesta poate fi calculat din lungimea primului interval.

Pentru unii algoritmi există și versiuni predicate. Algoritmii care primesc predicați au sufixul `_if` (care urmează după `_copy` în cazul algoritmilor de copiere).

Clasa `Predicate` este folosită ori de câte ori algoritmul așteaptă un obiect funcțional care, aplicat rezultatului dereferențierii iteratorului, returnează o valoare convertibilă la `bool`. Cu alte cuvinte, dacă algoritmul primește `Predicate pred` și un iterator `first`, trebuie să funcționeze corect în construcția `if (pred(*first)) {...}`. Se presupune că obiectul funcțional `pred` nu modifică elementul la care face referire iteratorul.

Clasa `BinaryPredicate` este folosită când algoritmul așteaptă un obiect funcțional care, aplicat la rezultatele dereferențierii a doi iteratori sau a unui iterator și a unui tip `T`, returnează o valoare convertibilă la `bool`. Cu alte cuvinte, dacă algoritmul primește `BinaryPredicate binary_pred` și doi iteratori `first1` și `first2`, trebuie să funcționeze corect în construcția `if (binary_pred(*first1, *first2)) {...}`.

`BinaryPredicate` ia întotdeauna tipul primului iterator ca prim parametru; dacă `T value` face parte din semnătură, trebuie să funcționeze în contextul `if (binary_pred(*first, value)) {...}`. Se presupune că `binary_pred` nu modifică elementele la care fac referire iteratorii.

## Algoritmi care nu modifică datele

Acești algoritmi nu modifică colecțiile cu care lucrează.

### Operații de căutare

Algoritmii de căutare caută elemente în colecții și returnează iteratori către elementele găsite. Dacă elementul nu este găsit, se returnează iteratorul de sfârșit al colecției.

- `find` – caută prima apariție a unui element în colecție.
- `find_if` – caută primul element care satisface predicatul.
- `find_if_not` – caută primul element care nu satisface predicatul.
- `find_end` – caută ultima apariție a unei subsecvențe în colecție.
- `find_first_of` – caută prima apariție a oricărui element dintr-o colecție în alta.
- `adjacent_find` – caută două elemente adiacente egale.
- `search` – caută prima apariție a unei subsecvențe în colecție.
- `all_of` – verifică dacă toate elementele satisfac predicatul.
- `any_of` – verifică dacă cel puțin un element satisface predicatul.
- `none_of` – verifică dacă niciun element nu satisface predicatul.
- `count` – numără elementele care satisfac predicatul.
- `count_if` – numără elementele care satisfac predicatul.
- `mismatch` – caută prima nepotrivire între două colecții.
- `equal` – verifică egalitatea a două colecții.

## Algoritmi care modifică datele

Acești algoritmi modifică colecțiile cu care lucrează, de exemplu, inserând, ștergând sau reordonând elemente.

### Copiere

- `copy` – copiază elemente dintr-o colecție în alta.
- `copy_if` – copiază elementele care satisfac predicatul.
- `copy_n` – copiază primele `n` elemente.
- `copy_backward` – copiază elementele în ordine inversă.
- `move` – mută elemente dintr-o colecție în alta.
- `move_backward` – mută elemente în ordine inversă.

### Umplere

- `fill` – umple colecția cu o valoare.
- `fill_n` – umple primele `n` elemente cu o valoare.
- `generate` – umple colecția cu valori generate de un obiect funcțional.
- `generate_n` – umple primele `n` elemente cu valori generate de un obiect funcțional.

### Transformare

- `transform` – aplică o funcție fiecărui element al colecției.
- `replace` – înlocuiește toate aparițiile unei valori cu alta.
- `replace_if` – înlocuiește toate elementele care satisfac predicatul cu o altă valoare.
- `replace_copy` – copiază elementele, înlocuind toate aparițiile unei valori cu alta.
- `replace_copy_if` – copiază elementele, înlocuind toate elementele care satisfac predicatul cu o altă valoare.

### Ștergere

- `remove` – șterge toate aparițiile unei valori din colecție.
- `remove_if` – șterge toate elementele care satisfac predicatul.
- `remove_copy` – copiază elementele, ștergând toate aparițiile unei valori.
- `remove_copy_if` – copiază elementele, ștergând toate elementele care satisfac predicatul.
- `unique` – șterge duplicatele consecutive.
- `unique_copy` – copiază elementele, ștergând duplicatele consecutive.

### Reordonare

- `reverse` – inversează ordinea elementelor.
- `rotate` – rotește elementele spre stânga; cele care ies din colecție sunt mutate la început.
- `rotate_copy` – copiază elementele, rotindu-le spre stânga.
- `random_shuffle` – amestecă elementele aleatoriu.
- `shuffle` – amestecă elementele aleatoriu, folosind un generator dat.
- `shift_left` – deplasează elementele spre stânga.
- `shift_right` – deplasează elementele spre dreapta.

### Sortare

- `sort` – sortează colecția.
- `stable_sort` – sortează colecția, păstrând ordinea elementelor egale.
- `partial_sort` – sortează parțial colecția.
- `is_sorted` – verifică dacă colecția este sortată.
- `is_sorted_until` – găsește primul element care nu respectă ordinea.
- `nth_element` – mută al n-lea element pe poziția corectă într-o colecție sortată.

## Structura algoritmilor

Algoritmii STL sunt implementați ca funcții șablon care primesc iteratori ca parametri. Implementările sunt de obicei foarte simple și eficiente. Următoarele exemple arată structura unor algoritmi.

### Căutarea unui element într-o colecție

Se parcurg toate elementele de la iteratorul de început la cel de sfârșit. Dacă elementul este găsit, se returnează iteratorul către acesta, altfel iteratorul de sfârșit.

```cpp
template <class InputIterator, class Type>
InputIterator find(InputIterator first, InputIterator last, const Type& value) {
    while(first != last) {
        if(*first == value) {
            return first;
        }
        ++first;
    }
    return last;
}
```

### Căutarea unui element care satisface o condiție

Se parcurg toate elementele de la iteratorul de început la cel de sfârșit. Dacă se găsește un element care satisface predicatul, se returnează iteratorul către acesta, altfel iteratorul de sfârșit.

```cpp
template <class InputIterator, class Predicate>
InputIterator find_if(InputIterator first, InputIterator last, Predicate pred) {
    while(first != last) {
        if(pred(*first)) {
            return first;
        }
        ++first;
    }
    return last;
}
```

### Copierea elementelor care satisfac o condiție

Se parcurg toate elementele de la iteratorul de început la cel de sfârșit. Dacă un element satisface predicatul, acesta este copiat într-o altă colecție.

```cpp
template <class InputIterator, class OutputIterator, class Predicate>
OutputIterator copy_if( InputIterator first1, InputIterator last1,
  OutputIterator first2, Predicate predicate) {
    while(first1 != last1){
        if(predicate(*first1)){
            *first2 = *first1;
            ++ first2;
        }
        ++first1;
    }
    return first2;
}
```

## Exemple de utilizare

### Citirea și afișarea datelor

Citirea unui vector de numere întregi de la intrarea standard și afișarea acestuia pe ecran.

```cpp
/**
 * @file read_write_vector.cpp
 * @brief Exemplu de citire și afișare a datelor
 * @details g++ -std=c++20 -o read_write_vector read_write_vector.cpp
 */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

int main() {
    std::vector<int> v;
    std::copy(
      std::istream_iterator<int>(std::cin),
      std::istream_iterator<int>(),
      std::back_inserter(v));
    
    std::copy(
      v.begin(),
      v.end(),
      std::ostream_iterator<int>(std::cout, " "));
    return 0;
}
```

### Căutarea primului număr par într-un vector

Se dă un vector de numere întregi. Să se găsească primul număr par.

```cpp
/**
 * @file find_even_number.cpp
 * @brief Exemplu de căutare a primului număr par într-un vector
 * @details g++ -std=c++20 -o find_even_number find_even_number.cpp
 */
#include <iostream>
#include <vector>
#include <algorithm>

int main() {
    std::vector<int> v = {1, 3, 5, 7, 9, 2, 4, 6, 8, 10};
    auto it = std::find_if(v.begin(), v.end(), [](int x) { return x % 2 == 0; });
    if(it != v.end()) {
        std::cout << *it << std::endl;
    }
    return 0;
}
```

### Citire, sortare și căutare

Fișierul conține o listă de studenți în următorul format:

- fiecare linie reprezintă un student;
- pe linie se află numele, prenumele și nota la test, separate prin punct și virgulă.

Citiți datele din fișier, selectați toți studenții cu nota mai mare de 5 și afișați-i pe ecran, ordonați descrescător după notă.

```cpp
/**
 * @file read_sort_search.cpp
 * @brief Exemplu de citire, sortare și căutare
 * @details g++ -std=c++20 -o read_sort_search read_sort_search.cpp
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
#include <format>

const std::string_view LINE_FORMAT = "{:<16} {:<16} {:>5}";

struct TestInfo {
    std::string name;
    std::string surname;
    float grade;
};

std::ostream& operator<<(std::ostream& os, const TestInfo& ti) {
    os << std::format(LINE_FORMAT, ti.name, ti.surname, ti.grade);
    return os;
}

std::istream& operator>>(std::istream& is, TestInfo& ti) {
    std::string line;
    ti.name.clear();
    ti.surname.clear();
    ti.grade = 0;
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::getline(iss, ti.name, ';');
        std::getline(iss, ti.surname, ';');
        iss >> std::ws >> ti.grade;
    }
    return is;
}

int main() {
    std::ifstream file("students.txt");
    if (!file.is_open()) {
        std::cerr << "Eroare: fișierul nu a fost găsit\n";
        return 1;
    }

    std::vector<TestInfo> students;
    std::copy(
        std::istream_iterator<TestInfo>(file),
        std::istream_iterator<TestInfo>(),
        std::back_inserter(students));

    std::cout << std::format(LINE_FORMAT, "Nume", "Prenume", "Nota") << '\n';

    std::sort(
        students.begin(),
        students.end(), 
        [](const TestInfo& a, const TestInfo& b) {
            return a.grade > b.grade;
        });

    std::copy_if(
        students.begin(), 
        students.end(), 
        std::ostream_iterator<TestInfo>(std::cout, "\n"), [](const TestInfo& ti) {
            return ti.grade > 5;
        });

    return 0;
}
```

## Bibliografie

1. [cppreference.com](https://en.cppreference.com/w/cpp/algorithm)
2. [Referință pentru biblioteca standard C++ (STL), Microsoft](https://learn.microsoft.com/ro-ro/cpp/standard-library/cpp-standard-library-reference)
3. [Scott Meyers. Effective STL](https://www.google.com/search?q=Scott+Meyers+Effective+STL)
