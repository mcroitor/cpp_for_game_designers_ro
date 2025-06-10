# Programarea orientată pe obiect

- [Programarea orientată pe obiect](#programarea-orientată-pe-obiect)
  - [Noțiunea de programare orientată pe obiect](#noțiunea-de-programare-orientată-pe-obiect)
    - [Abstracția datelor](#abstracția-datelor)
    - [Încapsularea](#încapsularea)
    - [Moștenirea](#moștenirea)
  - [Crearea și distrugerea obiectelor](#crearea-și-distrugerea-obiectelor)
  - [Funcții virtuale](#funcții-virtuale)
    - [Clase abstracte](#clase-abstracte)
    - [Interfață](#interfață)
  - [Polimorfism](#polimorfism)
  - [Bibliografie](#bibliografie)

## Noțiunea de programare orientată pe obiect

__Programarea orientată pe obiect__ (OOP) este o paradigmă de programare bazată pe utilizarea obiectelor și a claselor. În această paradigmă, totul este un obiect sau o parte a unui obiect, iar programul este privit ca o interacțiune între obiecte.

Principalele concepte ale programării orientate pe obiect sunt:

- __Clasa__ – tip de date definit de utilizator, care reprezintă o abstractizare a obiectelor din lumea reală, incluzând un set de date ce descriu aceste obiecte, precum și funcții ce descriu comportamentul lor;
- __Obiectul__ – variabilă de tip clasă;
- __Interfața__ – (interfața clasei) ansamblul proprietăților publice ale clasei, al metodelor sale, precum și al funcțiilor cu parametri de tipul clasei;

O clasă poate fi privită ca o mulțime de obiecte cu proprietățile descrise de clasă. În acest caz, proprietățile sunt determinate de interfața clasei, iar un obiect al clasei este un element al acestei mulțimi.

Principiile de bază ale OOP:

- _abstracția datelor_ – implementarea doar a acelor caracteristici ale obiectului care sunt necesare pentru rezolvarea problemei;
- _încapsularea_ – izolarea și ascunderea datelor și metodelor clasei;
- _moștenirea_ – posibilitatea de a crea clase noi pe baza celor existente;
- _polimorfismul_ – mecanism ce permite utilizarea datelor de tipuri diferite într-un context comun.

### Abstracția datelor

__Abstracția datelor__ presupune utilizarea doar a acelor caracteristici ale unui obiect care îl reprezintă suficient de precis în cadrul sistemului. Ideea principală este să prezentăm obiectul printr-un set minim de câmpuri și metode, dar suficient pentru rezolvarea sarcinii.

Abstracția stă la baza programării orientate pe obiect și permite lucrul cu obiecte fără a intra în detalii despre implementarea lor.

### Încapsularea

__Încapsularea__ înseamnă izolarea elementelor care definesc structura (datele) și comportamentul (metodele) unui obiect. Încapsularea presupune separarea clasei în interfață și implementare.

Modul de utilizare a unui obiect este determinat de interfața clasei.

```cpp
class vector {
private:
    double x, y;
    void normalize();

public:
    void move(double, double);
    std::string to_string() const;
};

void print(const vector&);
```

În exemplul de mai sus, clasa `vector` încapsulează datele `x`, `y` și metoda `normalize`. Interfața clasei este definită de metodele `move`, `to_string` și funcția `print`.

### Moștenirea

__Moștenirea__ permite ca un tip de date abstract să moștenească datele și funcționalitatea altui tip de date.

Moștenirea facilitează reutilizarea codului.

Clasa care moștenește proprietățile altei clase se numește __clasă derivată__ sau __subclasă__.

Clasa de la care se moștenește se numește __clasă de bază__, __superclasă__ sau __părinte__.

Clasele derivate se formează din clasele de bază prin adăugarea de noi proprietăți și prin redefinirea anumitor metode.

Exemplu de moștenire:

```cpp
class Animal {
    point position;
public:
    Animal();
    virtual ~Animal();

    virtual void eat() const {
        puts("do eat");
    }
    void move(point pt) {
        position = pt;
    }
};

class Cat: public Animal {
public:
    Cat();
    virtual ~Cat();

    virtual void eat() const;
};

class Pig: public Animal {
public:
    Pig();
    virtual ~Pig();

    virtual void eat() const;
};
```

Deoarece o clasă derivată descrie o submulțime de elemente ale clasei de bază, un pointer (sau referință) la un obiect al clasei de bază poate indica și către un obiect al clasei derivate. Invers nu este valabil: un pointer (sau referință) la un obiect al clasei derivate __nu poate__ indica către un obiect al clasei de bază.

Exemplu:

```cpp
class A {};
class B: public A {};

A a1;
B b1;
A& a = b1; // OK!
B& b = a1; // EROARE!
```

## Crearea și distrugerea obiectelor

O funcție specială, care poartă același nume ca și clasa, se numește __constructor__. Această funcție este folosită pentru crearea obiectelor clasei și inițializarea câmpurilor acestora. O clasă poate avea mai mulți constructori, diferențiați prin parametri:

- constructorul fără parametri se numește constructor implicit;
- constructorul care primește ca parametru un obiect de același tip se numește constructor de copiere.

Constructorul nu returnează nicio valoare.

O funcție cu același nume ca și constructorul, dar care începe cu simbolul `~`, se numește __destructor__. Rolul destructorului este de a elibera corect memoria la distrugerea obiectului. O clasă poate avea un singur destructor.

```cpp
class vector {
    double _x, _y, _z;
public:
    // constructor implicit
    vector();
    // constructor cu parametri
    vector(double x, double y, double z);
    // constructor de copiere
    vector(const vector&);
    // destructor
    ~vector();
};
```

Dacă într-o clasă nu sunt definiți constructori, compilatorul creează un constructor implicit. Dacă este definit un constructor de către utilizator, compilatorul nu mai generează constructorul implicit, deci acesta trebuie definit explicit dacă este necesar. Dacă este suficient constructorul generat de compilator, se poate folosi cuvântul cheie `default`. Același lucru este valabil și pentru constructorul de copiere.

```cpp
class vector {
    double _x, _y, _z;
public:
    // constructor implicit
    vector() = default;
    // constructor cu parametri
    vector(double x, double y, double z);
    // constructor de copiere
    vector(const vector&) = default;
    // destructor
    ~vector();
};
```

Dacă într-o clasă nu este definit destructorul, compilatorul creează un destructor implicit.

La implementarea constructorului cu parametri, câmpurile clasei sunt de obicei inițializate cu valorile parametrilor folosind lista de inițializare. Aceasta este o listă de membri, separați prin virgulă, între paranteze acolade și inițializați cu valorile parametrilor.

```cpp
vector::vector(double x, double y, double z): _x(x), _y(y), _z(z) {}
```

## Funcții virtuale

Programatorul poate suprascrie (redefini) o funcție a clasei de bază într-o clasă derivată. De exemplu, în următorul cod este ilustrată această posibilitate:

```cpp
/**
 * @file no_poly.cpp
 * @brief Fără polimorfism
 * @details g++ no_poly.cpp -o no_poly
 */
#include <cstdio>

struct A {
    A() {}
    void print() const { puts("A"); }
};

struct B: public A {
    B(){}
    void print() const { puts("B"); }
};

int main(){
     A* obj = new B;
     obj->print();
     obj = new A;
     obj->print();
     return 0; 
}
```

Totuși, rezultatul nu va fi cel așteptat – pe ecran va fi afișată litera A în ambele cazuri, nu B. Acest lucru se datorează faptului că compilatorul nu poate determina tipul real al obiectului la care face referire variabila obj, astfel încât este apelată funcția obiectului părinte. Această problemă poate fi rezolvată cu ajutorul funcțiilor virtuale. În cazul funcțiilor virtuale, compilatorul garantează apelarea variantei corecte a funcției pentru fiecare obiect din ierarhie.

O metodă este __virtuală__ dacă poate fi suprascrisă în clasa derivată, folosind cuvântul cheie `virtual`. Exemplu de utilizare a funcțiilor virtuale:

```cpp
/**
 * @file poly01.cpp
 * @brief Polimorfism
 * @details g++ poly01.cpp -o poly01
 */
#include <cstdio>

struct A {
     A() {}
     virtual void print() const { puts("A"); }
};

struct B:public A {
     B() {}
     virtual void print() const { puts("B"); }
};

int main(){
     A* obj = new B;
     obj->print();
     obj = new A;
     obj->print();
     return 0;
}
```

În exemplul _poly01.cpp_ vom obține rezultatul dorit: pe ecran va fi afișat "BA".

### Clase abstracte

__Metoda abstractă__ (funcție membră abstractă, funcție virtuală pură) este o funcție virtuală fără implementare.

```cpp
struct Comparable {
    // funcție virtuală pură!
    virtual bool equal(const Comparable&) const = 0; 
};

class Complex: public Comparable {
    double real;
    double imaginary;
public:
    bool equal(const Comparable&) const override; 
};
```

Dacă o clasă are cel puțin o metodă abstractă, aceasta se numește __clasă abstractă__.

### Interfață

O interfață (în sens restrâns) conține doar funcții virtuale pure publice. În acest caz, clasa abstractă este numită uneori interfață, prin analogie cu alte limbaje OOP. Totuși, în C++, o clasă abstractă poate conține și alte metode sau date, nu doar funcții virtuale pure.

## Polimorfism

__Polimorfismul__ este un mecanism care permite utilizarea datelor de tipuri diferite într-un context comun. Exemplu de polimorfism bazat pe conversia implicită a tipurilor:

```cpp
bool less(double x, double y) { return x < y; }

int a = 10, b = 15;
less(a, b);
```

Polimorfismul bazat pe funcții virtuale, numit și polimorfism dinamic, se bazează pe posibilitatea ca un pointer la un obiect al clasei de bază să indice către un obiect al unei clase derivate.

Această proprietate poate fi utilizată pentru a implementa polimorfismul – posibilitatea de a folosi aceeași funcție (același nume de funcție) cu tipuri diferite de parametri. Exemplu de polimorfism dinamic cu clasele prezentate, în listarea _poly02.cpp_:

```cpp
/**
 * @file poly02.cpp
 * @brief Polimorfism
 * @details g++ poly02.cpp -o poly02
 */
#include <cstdio>

struct A{
     A() {}
     virtual void print() const { puts("A"); }
};

struct B: public A{
     B(){}
     virtual void print() const { puts("B"); }
};

void print(const A& a){
     a.print();
}

int main(){
     B b;
     A& obj = b;
     print(obj);
     return 0;
}
```

## Bibliografie

1. [Programarea orientată pe obiect, Wikipedia](https://ro.wikipedia.org/wiki/Programare_orientat%C4%83_pe_obiect)
2. [Bjarne Stroustrup, Limbajul de programare C++.](https://www.google.com/search?q=stroustrup+limbajul+de+programare+c%2B%2B)
3. [Classes, cppreference.com](https://en.cppreference.com/w/cpp/language/classes)
