# Algoritmi

- [Algoritmi](#algoritmi)
  - [Noțiune de algoritm](#noțiune-de-algoritm)
    - [Functor](#functor)
    - [Predicat](#predicat)
    - [Reguli de denumire a algoritmilor din STL](#reguli-de-denumire-a-algoritmilor-din-stl)
  - [Algoritmi care nu modifică containerul](#algoritmi-care-nu-modifică-containerul)
    - [Cautare](#cautare)
    - [Verificare](#verificare)
  - [Algoritmi care modifică containerul](#algoritmi-care-modifică-containerul)
    - [Copiere](#copiere)
    - [Completare](#completare)
    - [Transformare](#transformare)
    - [Eliminare](#eliminare)
    - [Ordonare](#ordonare)
    - [Sortare](#sortare)
  - [Construcția algoritmilor](#construcția-algoritmilor)
    - [Căutarea elementului în colecție](#căutarea-elementului-în-colecție)
    - [Căutarea elementului care satisface un predicat](#căutarea-elementului-care-satisface-un-predicat)
    - [Copierea elementelor care satisfac unui predicat](#copierea-elementelor-care-satisfac-unui-predicat)
  - [Exemple de utilizare a algoritmilor](#exemple-de-utilizare-a-algoritmilor)
    - [Citirea și afișarea a datelor](#citirea-și-afișarea-a-datelor)
    - [Căutarea primului element par în vector](#căutarea-primului-element-par-în-vector)
    - [Citirea, sortarea și căutarea](#citirea-sortarea-și-căutarea)
  - [Bibliografie](#bibliografie)

## Noțiune de algoritm

> [!TIP]
> __Algoritmul__ este o secvență finită de instrucțiuni care aduce la un rezultat dorit într-un număr finit de pași.

Realizările algoritmice din biblioteca standard C++ sunt foarte simple și eficiente. De aceea ar fi util să alocați timp pentru a citi codul sursă.

Toate algoritmii din biblioteca standard C++ sunt separate de la detalii de implementare a structurilor de date și utilizează iteratori ca parametri. De aceea aceștia pot lucra cu structuri de date definite de utilizator, atunci când aceste structuri de date au tipuri de iteratori care satisfac condițiilor presupuse în algoritmi.

Algoritmii STL de obicei lucrează cu containere STL și folosesc iteratori pentru a accesa elementele acestora.

Toate algoritmii din biblioteca standard C++ sunt definite în fișierul de antet `<algorithm>`.

### Functor

> [!TIP]
> __Functor__ este un obiect al unei clase care are definit operatorul `()`.

În cadrul unei clase poate fi redefinit operatorul `()`. Dacă acest operator este redefinit, atunci obiectele acestei clase pot fi folosite ca funcții. Aceste obiecte se numesc __obiecte funcționale__ sau functori. Functori sunt utile atunci când o funcție trebuie să aibă "memorie", precum și ca înlocuirea pointerilor la funcții.

> În unele cazuri pointer la funcție tot poate fi numit obiect funcțional.

Exemplu de functor care schimbă valorile a două variabile întregi și numără apelurile:

```cpp
class _swap{
    static size_t counter = 0;
    static void increment() { ++counter; }
public:
    _swap(){}
    void operator ()(int& a, int& b){
        int tmp = a;
        a = b;
        b = tmp;
        increment();
    }
    int getNrCalls() {return counter; }
};

int main() {
    _swap swap;
    int a = 3, b = 5;
    swap(a, b);
    return 0;
}
```

### Predicat

> [!TIP]
> Un predicat este o funcție care întoarce o valoare logică.

Algoritmii STL folosesc predicat pentru a determina dacă un element îndeplinește o anumită condiție. Algoritmii operează cu predicate binare și unare.

Exemplu de predicat care determină dacă un număr este par:

```cpp
bool isOdd(int value) {
   return value % 2 == 0;
}
```

### Reguli de denumire a algoritmilor din STL

Unele algoritmi au cât versiuni operative (rezultatul algoritmului se păstrează în segmentul indicat de iterații), cât și versiuni de copiere. Decizia de a include sau nu o versiune de copiere a algoritmului în bibliotecă a fost luată pe baza eficienței algoritmului. Atunci când costul efectuării operației domină costul copierii, versiunea de copiere nu este inclusă. De exemplu, `sort_copy` nu este inclus, deoarece costul sortării este mult mai semnificativ și utilizatorii ar putea face `copy` înainte de `sort`.

Versiunea de copiere a algoritmului `algorithm` se numește `algorithm_copy` (adică se adaugă sufixul `_copy`). În algoritmii de copiere nu se specifică sfârșitul celui de-al doilea interval, deoarece acesta poate fi calculat pe baza lungimii primului interval.

Totodată, o parte de algoritmi are versiuni care lucrează cu predicat. Algoritmii care iau predicat ca parametru se termină cu sufixul `_if` (care urmează după sufixul `_copy` în cazul algoritmului de copiere).

Parametrul șablonului `Predicate` se utilizează fiecare dată când algoritmul așteaptă un obiect funcțional, care, aplicat la rezultatul dereferențierii iteratorului corespunzător, întoarce o valoare convertibilă la `bool`. Cu alte cuvinte, dacă algoritmul ia `Predicate pred` ca parametru și `first` ca parametru al iteratorului, el trebuie să funcționeze corect în construcția `if (pred(*first)) {...}`. Se presupune că obiectul funcțional `pred` nu aplică nicio funcție non-const la iteratorul dereferențiat.

Parametrul șablonului `BinaryPredicate` se utilizează de fiecare dată când algoritmul așteaptă un obiect funcțional care, aplicat la rezultatul dereferențierii a două iteratori corespunzători sau la dereferențierea unui iterator și a unui tip `T`, când `T` este parte a semnăturii, întoarce o valoare convertibilă la `bool`. Cu alte cuvinte, dacă algoritmul ia `BinaryPredicate binary_pred` ca parametru și `first1` și `first2` ca parametri ai iteratorilor, el trebuie să funcționeze corect în construcția `if (binary_pred(*first1, *first2)) {...}`.

## Algoritmi care nu modifică containerul

Acest tip de algoritmi nu modifică containerul cu care lucrează.

### Cautare

Acestea algoritmi sunt folosiți pentru a căuta elemente într-o colecție.

- `find` - găsește prima apariție a unui element într-o colecție.
- `find_if` - găsește prima apariție a unui element care satisface un predicat.
- `find_if_not` - găsește prima apariție a unui element care nu satisface un predicat.
- `find_end` - găsește ultima apariție a unei subsecvențe într-o colecție.
- `find_first_of` - găsește prima apariție a unui element dintr-o colecție într-o altă colecție.
- `adjacent_find` - găsește două elemente consecutive egale.
- `search` - găsește prima apariție a unei subsecvențe într-o colecție.

### Verificare

- `all_of` - verifică dacă toate elementele dintr-o colecție satisfac un predicat.
- `any_of` - verifică dacă cel puțin un element dintr-o colecție satisface un predicat.
- `none_of` - verifică dacă niciun element dintr-o colecție nu satisface un predicat.
- `count` - numără elementele dintr-o colecție care satisfac un predicat.
- `count_if` - numără elementele dintr-o colecție care satisfac un predicat.
- `mismatch` - găsește prima pereche de elemente care nu sunt egale.
- `equal` - verifică dacă două colecții sunt egale.

## Algoritmi care modifică containerul

Acești algoritmi modifică colecțiile cu care lucrează într-un fel sau altul, de exemplu, adaugă elemente, elimină, schimbă locul.

### Copiere

- `copy` - copiază elementele dintr-o colecție în alta.
- `copy_if` - copiază elementele care satisfac un predicat.
- `copy_n` - copiază primele `n` elemente.
- `copy_backward` - copiază elementele dintr-o colecție în alta în ordine inversă.
- `move` - mută elementele dintr-o colecție în alta.
- `move_backward` - mută elementele dintr-o colecție în alta în ordine inversă.

### Completare

- `fill` - umple colecția cu un singur element.
- `fill_n` - umple primele `n` elemente cu un singur element.
- `generate` - umple colecția cu valori returnate de un obiect funcțional.
- `generate_n` - umple primele `n` elemente cu valori returnate de un obiect funcțional.

### Transformare

- `transform` - aplică o funcție la fiecare element al colecției.
- `replace` - înlocuiește toate aparițiile unei valori cu alta.
- `replace_if` - înlocuiește toate aparițiile elementelor care satisfac un predicat cu alta valoare.
- `replace_copy` - copiază elementele dintr-o colecție în alta, înlocuind toate aparițiile unei valori cu alta.
- `replace_copy_if` - copiază elementele dintr-o colecție în alta, înlocuind toate aparițiile elementelor care satisfac un predicat cu alta valoare.

### Eliminare

- `remove` - șterge toate aparițiile unui element din colecție.
- `remove_if` - șterge toate aparițiile elementelor care satisfac un predicat.
- `remove_copy` - copiază elementele dintr-o colecție în alta, ștergând toate aparițiile unui element.
- `remove_copy_if` - copiază elementele dintr-o colecție în alta, ștergând toate aparițiile elementelor care satisfac un predicat.
- `unique` - șterge toate aparițiile duplicate ale unui element.
- `unique_copy` - copiază elementele dintr-o colecție în alta, ștergând toate aparițiile duplicate ale unui element.

### Ordonare

- `reverse` - inversează ordinea elementelor.
- `rotate` - deplasează elementele colecției din stânga în dreapta. Elementele care ies din colecție sunt mutate la început.
- `rotate_copy` - copiază elementele dintr-o colecție în alta, deplasându-le din stânga în dreapta. Elementele care ies din colecție sunt mutate la început.
- `random_shuffle` - amestecă elementele colecției în mod aleatoriu.
- `shuffle` - amestecă elementele colecției în mod aleatoriu, folosind un generator de numere aleatorii specificat.
- `shift_left` - deplasează elementele colecției la stânga.
- `shift_right` - deplasează elementele colecției la dreapta.

### Sortare

- `sort` - sortează colecția.
- `stable_sort` - sortează colecția, păstrând ordinea elementelor egale.
- `partial_sort` - sortează primele `n` elemente.
- `is_sorted` - verifică dacă colecția este sortată.
- `is_sorted_until` - găsește primul element care nu respectă ordinea sortării.
- `nth_element` - mută elementul `n` pe poziția sa într-o colecție sortată.

## Construcția algoritmilor

Algoritmii STL sunt realizate ca funcții generice, care primesc iteratori ca parametri. Realizarea algoritmilor STL este simplă și eficientă. Următoarele exemple arată structura unor algoritmi.

### Căutarea elementului în colecție

Se parcurg elementele colecției de la primul la ultimul element. Dacă elementul este găsit, se returnează iteratorul pe acest element, altfel se returnează iteratorul pe ultimul element.

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

### Căutarea elementului care satisface un predicat

Se parcurg elementele colecției de la primul la ultimul element. Dacă elementul care satisface predicatului specificat este găsit, se returnează iteratorul pe acest element, altfel se returnează iteratorul pe ultimul element.

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

### Copierea elementelor care satisfac unui predicat

Se parcurg elementele colecției de la primul la ultimul element. Dacă elementul care satisface predicatului specificat este găsit, el se copie într-o altă colecție.

```cpp
template <class InputIterator, class OutputIterator, class Predicate>
void copy_if( InputIterator first1, InputIterator last1,
  OutputIterator first2, Predicate predicate) {
    while(first1 != last1){
      if(predicate(*first1)){
        *first2 = *first1;
        ++ first2;
      }
      ++first1;
    }
  }
```

## Exemple de utilizare a algoritmilor

### Citirea și afișarea a datelor

Citirea unui vector de numere întregi din fluxul de intrare standard și afișarea acestora pe ecran.

```cpp
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

### Căutarea primului element par în vector

Este dat un vector de numere întregi. Găsiți primul element par.

```cpp
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

### Citirea, sortarea și căutarea

În fișierul `students.txt` sunt stocate date despre studenți în următorul format:

- fiecare linie reprezintă un student;
- în linie, separate de punct și virgulă, sunt stocate numele studentului, prenumele studentului, nota pentru test.

Citiți datele din fișier, selectați toți studenții care au trecut testul (nota mai mare de `5`) și afișați-le pe ecran într-un format tabular, în ordinea descrescătoare a notei.

```cpp
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
    if (std::getline(is, line)) {
        std::istringstream iss(line);
        std::getline(iss, ti.name, ';');
        std::getline(iss, ti.surname, ';');
        iss >> ti.grade;
    }
    return is;
}

int main() {
    std::ifstream file("students.txt");
    if (!file.is_open()) {
        std::cerr << "Error: file not found\n";
        return 1;
    }

    std::vector<TestInfo> students;
    std::copy(
        std::istream_iterator<TestInfo>(file),
        std::istream_iterator<TestInfo>(),
        std::back_inserter(students));

    std::cout << std::format(LINE_FORMAT, "Name", "Surname", "Grade") << '\n';

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

1. [Algorithms library, cppreference.com](https://en.cppreference.com/w/cpp/algorithm)
2. [C++ Standard Library reference (STL), Microsoft](https://learn.microsoft.com/en-us/cpp/standard-library/cpp-standard-library-reference)
3. [Scott Meyers. Effective STL](https://www.google.com/search?q=Scott+Meyers+effective+stl)
