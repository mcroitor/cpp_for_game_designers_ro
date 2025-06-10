# Bazele metaprogramării

- [Bazele metaprogramării](#bazele-metaprogramării)
  - [Șabloane de funcții](#șabloane-de-funcții)
  - [Șabloane de clase](#șabloane-de-clase)
  - [Instanțierea șabloanelor](#instanțierea-șabloanelor)
  - [Supraîncărcarea șabloanelor de funcții](#supraîncărcarea-șabloanelor-de-funcții)
  - [Specializarea șabloanelor](#specializarea-șabloanelor)
  - [Bibliografie](#bibliografie)

__Metaprogramarea__ este o paradigmă de dezvoltare software care se bazează pe ideea descrierii modelelor și a transformării acestora în cod sursă (sau în program).  

Principalul mecanism de metaprogramare în C++ este utilizarea șabloanelor de clase, a șabloanelor de funcții și a specializărilor acestora [^1].

## Șabloane de funcții

__Șablonul de funcție__ reprezintă o descriere generală a unei familii de funcții (un algoritm generic).

Să analizăm conceptul de șablon de funcție printr-un exemplu. Să presupunem că am definit o funcție care schimbă valorile a două variabile întregi:

```cpp
void swap(int& a, int& b){
  int tmp = a;
  a = b;
  b = tmp;
}
```

Totuși, pentru a schimba valorile a două variabile reale, ar trebui să adăugăm o altă funcție, folosind supraîncărcarea funcției:

```cpp
void swap(float& a, float& b){
  float tmp = a;
  a = b;
  b = tmp;
}
```

Astfel, pentru fiecare tip trebuie definită o funcție separată.

Observăm însă că pentru fiecare tip de date, funcția arată identic, cu excepția tipului variabilelor. Din acest motiv, limbajul C++ oferă mecanismul șabloanelor, care permite descrierea unei familii de funcții. Un exemplu de șablon care schimbă valorile a două variabile este prezentat mai jos:

```cpp
template<typename TYPE>
void swap(TYPE& a, TYPE& b){
  TYPE tmp = a;
  a = b;
  b = tmp;
}
```

Definirea unui șablon începe cu construcția `template<typename TYPE, ...>`, unde între paranteze unghiulare se specifică parametrii șablonului. Pot exista oricâți parametri de șablon, iar aceștia pot fi tipuri sau valori enumerate (tipuri întregi sau enumerații).

> Pe lângă cuvântul cheie `typename`, pentru declararea parametrilor șablonului se poate folosi și cuvântul cheie `class`.

Atâta timp cât funcția _swap_ nu este apelată în program, la compilare nu va fi generată (nu va fi instanțiată). Dacă însă apelăm funcția cu variabile de tipuri diferite, pentru fiecare tip, compilatorul va genera o implementare separată pe baza șablonului.

De asemenea, ca parametru al unui șablon de funcție poate fi folosit și un tip enumerat (de exemplu, `int`).

Apelul unei funcții șablon este, în general, echivalent cu apelul unei funcții obișnuite. În acest caz, compilatorul va determina ce tip să folosească în loc de `TYPE`, pe baza tipului parametrilor efectivi. Dacă însă parametrii au tipuri diferite, compilatorul nu va putea deduce (instanția șablonul) implementarea funcției:

```cpp
/**
 * @file metaprogramming_01.cpp
 * @brief Exemplu de utilizare a șabloanelor de funcții
 * @details g++ metaprogramming_01.cpp -o metaprogramming_01
 */
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
    std::cout << min(5, 2.1) << std::endl; // Eroare, compilatorul nu poate deduce tipul comun.
    return 0;
}
```

Această problemă poate fi rezolvată prin specificarea explicită a tipului pentru șablon:

```cpp
/**
 * @file metaprogramming_02.cpp
 * @brief Specificarea explicită a tipului pentru șablonul de funcție
 * @details g++ metaprogramming_02.cpp -o metaprogramming_02
 */
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

__Când funcția șablon (nu) va funcționa?__

La compilare, compilatorul înlocuiește tipul potrivit în șablon. Dar va funcționa întotdeauna funcția rezultată? Evident, nu. Orice algoritm poate fi definit independent de tipul de date, dar folosește anumite proprietăți ale acestora. În cazul funcției șablon _min_, este necesar ca tipul să aibă operatorul de comparație `<`.

Orice șablon de funcție presupune existența anumitor proprietăți ale tipului parametrizat, în funcție de implementare (de exemplu, operator de copiere, operator de comparație, anumite metode etc.). În standardul actual C++ acest lucru este reglementat de _concepte_ [^2].

## Șabloane de clase

__Șablonul de clasă__ este o descriere a unei mulțimi de tipuri de date cu același comportament [^3].

Exemplul clasic de șablon de clasă este un container. Totuși, domeniul de aplicare nu se limitează la acestea.

Exemplu de șablon de clasă:

```cpp
template<typename TYPE>
class Box{
    // implementare
    TYPE value_;
public:
    typedef TYPE valueType;

    Box(TYPE value): value_(value) {}
    const TYPE& value() const {
        return value_;
    }
};
```

În practica C++, clasele sunt împărțite în două fișiere: fișierul header (`.h`) și fișierul sursă (`.cpp`). Totuși, particularitatea șabloanelor de clase impune ca declarația și implementarea să fie în același fișier, de obicei în header.

## Instanțierea șabloanelor

Termenul _instanțiere_ (crearea unei instanțe) se poate referi atât la declararea variabilelor, cât și la crearea implementărilor concrete ale șabloanelor de funcții.

_Instanțierea unui șablon_ înseamnă generarea codului funcției sau clasei pe baza șablonului pentru parametri concreți. Există _instanțiere implicită_, care are loc la apelul funcției sau la crearea obiectului, și _instanțiere explicită_ cu cuvântul cheie `template`.

Exemplu de instanțiere a funcției `swap`:

```cpp
/**
 * @file metaprogramming_03.cpp
 * @brief Exemplu de instanțiere a șabloanelor de funcții
 * @details g++ metaprogramming_03.cpp -o metaprogramming_03
 */
#include <iostream>

template<typename TYPE>
void swap(TYPE& p1, TYPE& p2) {
  TYPE tmp = p1;
  p1 = p2;
  p2 = tmp;
}

// instanțiere explicită
template void swap(int&, int&);

int main() {
  double a = 10;
  double b = 12;
  std::cout << "a: " << a << ", b: " << b << std::endl;
  // instanțiere implicită
  swap(a, b);
  std::cout << "a: " << a << ", b: " << b << std::endl;
  return 0;
}
```

În exemplul de mai sus, instanțierea explicită poate fi făcută pentru toate tipurile necesare. În acest caz, fiecare funcție instanțiată va fi adăugată în codul binar la compilare.

## Supraîncărcarea șabloanelor de funcții

Șabloanele de funcții pot fi supraîncărcate, caz în care se deosebesc doar prin parametrii funcției. Un exemplu bun este supraîncărcarea funcției `swap` pentru pointeri:

```cpp
/**
 * @file metaprogramming_04.cpp
 * @brief Exemplu de supraîncărcare a șabloanelor de funcții
 * @details g++ metaprogramming_04.cpp -o metaprogramming_04
 */
#include <iostream>

template<typename TYPE>
void swap(TYPE& p1, TYPE& p2) {
  TYPE tmp = p1;
  p1 = p2;
  p2 = tmp;
}

template<typename TYPE>
void swap(TYPE* p1, TYPE* p2) {
  if (p1 == p2) {
    return;
  }
  TYPE tmp = *p1;
  *p1 = *p2;
  *p2 = tmp;
}

int main() {
  double a = 10;
  double b = 12;

  double* p1 = &a;
  double* p2 = &b;
  std::cout << "*p1: " << *p1 << ", *p2: " << *p2 << std::endl;
  // instanțiere implicită
  swap(p1, p2);
  std::cout << "*p1: " << *p1 << ", *p2: " << *p2 << std::endl;
  return 0;
}
```

> [!NOTE]
> Supraincărcarea șabloanelor de funcții se face doar pe baza semnăturii funcției, nu pe baza tipului parametrului șablonului.

## Specializarea șabloanelor

Se poate _specializa_ implementarea șablonului pentru anumite tipuri de date, fie pentru funcții, fie pentru metode ale unei clase șablon sau pentru întreaga clasă șablon.

Pentru funcții și metode se permite doar specializarea completă. Înaintea definiției specializării se scrie `template <>`, iar după numele funcției sau clasei se adaugă lista de argumente a șablonului de bază între `<>`. Aceeași funcționalitate se poate obține și prin definirea unei funcții obișnuite sau prin supraîncărcarea șablonului. Diferența este că funcția obișnuită este generată la compilarea definiției sale (deci întotdeauna), iar șablonul și specializarea – la prima utilizare (instanțiere).

Exemplu de specializare a șabloanelor:

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

În acest exemplu, șablonul parametrizat `print` va funcționa doar cu tipuri care au metoda `toString()`. Pentru tipurile `int`, `float` și `std::string` sunt definite implementări proprii. Dacă tipul nu are metoda `toString()`, va apărea o eroare de compilare la instanțierea șablonului pentru acel tip.

> [!NOTE]
> Specializarea parțială a șabloanelor este permisă doar pentru clase, nu și pentru funcții.

Un alt exemplu, care arată utilizarea specializării șabloanelor pentru calcule la compilare:

```cpp
/**
 * @file fibonacci.cpp
 * @brief Exemplu de calcul al numerelor Fibonacci la compilare
 * @details g++ fibonacci.cpp -o fibonacci
 */
#include <iostream>

template <size_t index>
size_t fibonacci()
{
    return fibonacci<index - 1>() + fibonacci<index - 2>();
}

template <>
size_t fibonacci<0>()
{
    return 0;
}

template <>
size_t fibonacci<1>()
{
    return 1;
}

int main()
{
    std::cout << fibonacci<10>() << std::endl;
    return 0;
}
```

Pentru valori mari ale indexului, recursivitatea profundă poate duce la depășirea stivei la compilare.

## Bibliografie

[^1]: [David Vandevoorde, Nicolai M. Josuttis. C++ Templates: The Complete Guide](https://www.google.com/search?client=opera&q=David+Vandevoorde%2C+Nicolai+M.+Josuttis.+C%2B%2B+Templates%3A+The+Complete+Guide&sourceid=opera&ie=UTF-8&oe=UTF-8)
[^2]: [Concepts, cppreference.com](https://en.cppreference.com/w/cpp/concepts)
[^3]: [Templates, cppreference.com](https://en.cppreference.com/w/cpp/language/templates)
