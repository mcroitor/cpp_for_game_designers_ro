# Bazele metaprogramării

- [Bazele metaprogramării](#bazele-metaprogramării)
  - [Șabloane de funcții](#șabloane-de-funcții)
  - [Șabloane de clase](#șabloane-de-clase)
  - [Instanțierea șabloanelor](#instanțierea-șabloanelor)
  - [Supraincarcarea funcțiilor șablon](#supraincarcarea-funcțiilor-șablon)
  - [Specializarea șabloanelor](#specializarea-șabloanelor)
  - [Bibliografie](#bibliografie)

__Programarea generativă__ (sau __metaprogramarea__) este o paradigmă de dezvoltare a software-ului, care se bazează pe ideea de a descrie modele și de a transforma aceste modele în cod sursă (sau program) [^1].

Mecanismul de bază a programării generative în limbajul C++ este utilizarea șabloanelor de clase, șabloanelor de funcții și a specializărilor acestora.

## Șabloane de funcții

__Șablonul de funcție__ este o descriere de bază a unei familii de funcții (algoritm generalizat).

O sa vedem un exemplu de șablon de funcție pentru schimbarea valorilor a două variabile întregi:

```cpp
void swap(int& a, int& b){
  int tmp = a;
  a = b;
  b = tmp;
}
```

Pentru a schimba valori dintre două variabile de tip `float` va trebui să adăugăm în programă următoarea funcție, folosind supraincarcarea funcției:

```cpp
void swap(float& a, float& b){
  float tmp = a;
  a = b;
  b = tmp;
}
```

Pentru fiecare tip nou de date, va trebui să adăugăm o nouă funcție.

Totuși, pentru fiecare tip de date funcția arată la fel, cu excepția tipurilor de variabile. Din acest motiv, limbajul C++ oferă mecanismul de șabloane, care permite să descriem o familie de funcții. Un exemplu de șablon corespunzător, care schimbă valorile a două variabile, este prezentat mai jos:

```cpp
template<typename TYPE>
void swap(TYPE& a, TYPE& b){
  TYPE tmp = a;
  a = b;
  b = tmp;
}
```

Definirea unui șablon se începe cu construcția cheie `template<typename TYPE, ...>`, unde în parantezele unghiulare sunt specificate parametrii șablonului. Numărul de parametrii șablonului poate fi orice.

> La definirea parametrilor tip ale sablonului, în loc de cuvântul cheie `typename` se poate folosi cuvântul cheie `class`.

Până când nu este apelată funcția `_swap_` în program, la compilare ea nu este creată în codul binar (_nu este instanțiată_). Dacă se declară un grup de apeluri a funcției cu variabile de tipuri diferite, atunci pentru fiecare apel compilatorul va crea propria implementare pe baza șablonului.

Parametrul șablonului de funcție poate fi orice tip de date, inclusiv unul definit de utilizator, sau o valoare de tip enumerabil (de exemplu, `int`, `char` sau enumerare).

Apelul unei funcții șablon, în general, este similar cu apelul unei funcții obișnuite. În acest caz, compilatorul va deduce tipul `TYPE` parametrilor funcției din tipul argumentelor efective. În cazul în care tipurile argumentelor efective sunt diferite, compilatorul nu va putea deduce tipul parametrilor funcției și va genera o eroare, de exemplu:

```cpp
#include <iostream>
template<class TYPE>
TYPE min(TYPE a, TYPE b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main(int argc, char** argv) {
    std::cout << min(1, 2) << std::endl; // OK
    std::cout << min(3.1, 1.2) << std::endl; // OK
    std::cout << min(5, 2.1) << std::endl; // error! can`t deduce from template!
    return 0;
}
```

Aceasta problema poate fi rezolvată prin specificarea tipului efectiv al argumentelor:

```cpp
#include <iostream>
template<class TYPE>
TYPE min(TYPE a, TYPE b) {
    if (a < b) {
        return a;
    }
    return b;
}

int main(int argc, char** argv) {
    std::cout << min(1, 2) << std::endl; // OK
    std::cout << min(3.1, 1.2) << std::endl; // OK
    std::cout << min<double>(5, 2.1) << std::endl; // OK
    return 0;
}
```

__Când șablonul de funcție nu va funcționa?__

La etapa de compilare a programului, compilatorul va înlocui tipul `TYPE` cu tipul efectiv al argumentelor. Dar întotdeauna funcția va funcționa corect? Evident, nu. Orice algoritm poate fi definit independent de tipul de date, dar el folosește proprietățile acestor date. În cazul funcției șablon _min_ este necesară definirea operatorului de ordonare (`<`).

Fiecare șablon de funcție presupune existența unor anumite proprietăți ale tipului de date parametrizat, în dependența de realizare (de exemplu, operatorul de copiere, operatorul de comparare, existența unui anumit metoda etc.). În standardul C++20, pentru aceasta sunt responsabile _conceptele_ [^2].

## Șabloane de clase

__Șablonul de clasă__ este o descriere a mulțimii de tipuri de date cu un anumit comportament.

Un exemplu standard de șabloane de clase sunt containerele STL. Totuși sfera de aplicare a șabloanelor de clase nu se limitează la aceasta.

Un exemplu de declarație a șablonului de clasă:

```cpp
template<typename TYPE>
class Box{
    // implementation
    TYPE value_;
public:
    typedef TYPE valueType;

    Box(TYPE value): value_(value) {}
    const TYPE& value() const {
        return value_;
    }
};
```

## Instanțierea șabloanelor

Terminul _instanțierea_ ( crearea unei instanțe) poate fi aplicat atât la declararea variabilelor, cât și la crearea implementărilor concrete ale funcțiilor sau claselor șablonice.

_Instanțierea unui șablon_ este procesul de creare a unei clase sau a unei funcții concrete dintr-un șablon de clasă sau de funcție. Se diferențiază _instanțierea implicită_ care se produce automat la apelul funcției sau crearea obiectului clasei, și _instanțierea explicită_ care se produce prin specificarea tipului cu ajutorul cuvântului cheie `template`.

Exemplu de instanțiere a funcției `swap`:

```cpp
#include <iostream>

template<typename TYPE>
void swap(TYPE& p1, TYPE& p2) {
  TYPE tmp = p1;
  p1 = p2;
  p2 = tmp;
}

// instanțierea explicită
template void swap(int&, int&);

int main() {
  double a = 10;
  double b = 12;
  std::cout << "a: " << a << ", b: " << b << std::endl;
// instanțierea implicită
  swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;
  return 0;
}
```

În exemplul dat instanțierea explicită a funcției `swap` poate fi realizată pentru toate tipurile de date, care sunt necesare în program. În acest caz, fiecare instanțiere a funcției va fi adăugată în codul binar al programului la etapa de compilare.

## Supraincarcarea funcțiilor șablon

Șabloane de funcții pot fi supraincarcate. În acest caz șabloane de funcții vor diferi prin numărul și tipul parametrilor. Un exemplu bun de supraincarcare este funcția `swap` pentru pointeri:

```cpp
#include <iostream>

template<typename TYPE>
void swap(TYPE& p1, TYPE& p2) {
  TYPE tmp = p1;
  p1 = p2;
  p2 = tmp;
}

template<typename TYPE>
void swap(TYPE* p1, TYPE* p2) {
  TYPE tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

int main() {
  double a = 10;
  double b = 12;

  double* p1 = &a;
  double* p2 = &b;
  std::cout << "*p1: " << *p1 << ", *p2: " << p2 << std::endl;
// instanțierea implicită
  swap(p1, p2);
  std::cout << "*p1: " << *p1 << ", *p2: " << p2 << std::endl;
  return 0;
}
```

## Specializarea șabloanelor

Șablonul funcției, metodei șablonului clasei sau șablonului clasei în întregime poate fi _specializat_, adică modificat pentru anumite tipuri de date.

La specializarea șabloanelor de funcții, sau a metodelor șabloanelor de clase se acceptă doar specializarea completă. Înainte de definirea specializării se scrie `template <>`, iar după numele funcției sau clasei se adaugă lista de argumente a șablonului principal în `<>`. O funcționalitate similară poate fi obținută, dacă se definește o funcție obișnuită sau se supraincarcă funcția șablonului. Diferența constă în faptul că generarea codului pentru funcția obișnuită se va produce la compilarea definiției ei (adică întotdeauna), iar pentru șablon și specializare – la prima utilizare (instantiere).

Exemplu de specializare a șablonului:

```cpp
template<typename TYPE>
void print(TYPE p) {
  std::cout << p.toString() << std::endl;
}
template<>
void print(int p) {
  std::cout << p << std::endl;
}
template<>
void print(float p) {
  std::cout << p << std::endl;
}
template<>
void print(std::string p) {
  std::cout << p << std::endl;
}
```

Exemplu de utilizare a specializării șabloanelor pentru calculul la etapa de compilare:

```cpp
#include <iostream>

template <size_t index>
size_t fibbonacci()
{
    return fibbonacci<index - 1>() + fibbonacci<index - 2>();
}

template <>
size_t fibbonacci<0>()
{
    return 0;
}

template <>
size_t fibbonacci<1>()
{
    return 1;
}

int main()
{
    std::cout << fibbonacci<10>() << std::endl;
    return 0;
}
```

## Bibliografie

[^1]: [Дэвид Вандевурд, Николай М. Джосаттис. Шаблоны C++: справочник разработчика](https://www.google.com/search?client=opera&q=Дэвид+Вандевурд%2C+Николай+М.+Джосаттис.+Шаблоны+C%2B%2B%3A+справочник+разработчика&sourceid=opera&ie=UTF-8&oe=UTF-8)
[^2]: [Concepts, cppreference.com](https://en.cppreference.com/w/cpp/concepts)
