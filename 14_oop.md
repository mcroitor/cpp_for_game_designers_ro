# programare orientată pe obiecte

- [programare orientată pe obiecte](#programare-orientată-pe-obiecte)
  - [Noțiuni de bază ale programării orientate pe obiecte](#noțiuni-de-bază-ale-programării-orientate-pe-obiecte)
    - [Abstracția datelor](#abstracția-datelor)
    - [Incapsularea](#incapsularea)
    - [Crearea și distrugerea obiectelor](#crearea-și-distrugerea-obiectelor)
    - [Moștenirea](#moștenirea)
  - [Functii virtuale](#functii-virtuale)
    - [Clase abstracte](#clase-abstracte)
    - [Interfață](#interfață)
    - [Polimorfism](#polimorfism)

Programare orientată pe obiecte (POO) este o paradigma de programare bazată pe utilizarea obiectelor și a claselor. În această paradigmă, totul este un obiect sau o parte a acestuia, iar în cadrul POO programul este considerat ca o interacțiune a obiectelor.

Principii de bază ale POO sunt:

- __incapsularea__ - ascunderea datelor și a metodelor de manipulare a acestora;
- __moștenirea__ - posibilitatea de a crea clase noi pe baza claselor existente;
- __polimorfismul__ - capacitatea de a utiliza aceeași interfață pentru obiecte de diferite tipuri.

## Noțiuni de bază ale programării orientate pe obiecte

Noțiunile de bază ale programării orientate pe obiecte sunt:

- __clasa__ - tip de date personalizat, care reprezintă o abstracție a obiectelor din lumea reală și include un set de date care descriu aceste obiecte, precum și funcții care descriu comportamentul acestora;
- __obiect__ - variabilă a clasei;
- __interfață__ - (interfața clasei) un set de proprietăți ale clasei, metodele sale, precum și funcțiile cu parametri de tipul clasei.

Clasa poate fi considerată ca o mulțime de obiecte cu proprietățile descrise de clasă. În acest caz, proprietățile sunt definite de interfața clasei, iar obiectul clasei este un element al acestei mulțimi.

### Abstracția datelor

__Abstracția datelor__ - utilizarea doar a caracteristicilor obiectului, care reprezintă obiectul în această sistemă cu suficientă precizie. Ideea principală este de a reprezenta obiectul cu un set minim de câmpuri și metode, dar cu suficientă precizie pentru sarcina dată.

Abstracția este baza programării orientate pe obiecte și permite lucrul cu obiecte fără a intra în detaliile implementării acestora.

### Incapsularea

__Incapsularea__ - izolarea elementelor care definesc structura (datele) și comportamentul (metodele). Incapsularea presupune împărțirea clasei în interfață și implementare.

Metoda de utilizare a obiectului depinde de interfața clasei.

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

În exemplul dat, clasa `vector` încapsulează datele `x`, `y` și metoda `normalize`. Interfața clasei este definită de metodele `move`, `to_string` și funcția `print`.

### Crearea și distrugerea obiectelor

Funcția specială denumirea căreia coincide cu numele clasei, se numește __constructor__. Această funcție este utilizată pentru crearea obiectelor clasei și inițializarea câmpurilor acestora. O clasă poate conține mai multe constructori, care se deosebesc prin numărul și tipul parametrilor:

- constructorul fără parametri se numește _constructor implicit_;
- constructorul care primește un obiect de același tip ca parametru se numește _constructor de copiere_.

Constructorul nu returnează valoare.

Funcția, care are același nume cu constructorul, dar începe cu simbolul `~`, se numește __destructor__. Rolul destructorului este eliberarea corectă a memoriei la distrugerea obiectului. O clasă poate avea un singur destructor.

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
}
```

### Moștenirea

Un tip de date personalizat poate fi creat pe baza altui tip de date personalizat. Acest mecanism se numește __moștenire__. Moștenirea stimulează reutilizarea codului.

O clasă, care moștenește proprietățile altei clase, se numește __clasă derivată__ sau __subclasă__. Clasa, care este moștenită, se numește __clasă de bază__ sau __superclasă__.

Clase derivate se formează din clase de bază prin adăugarea unor noi proprietăți și metode, precum și prin modificarea sau extinderea metodelor existente.

Un exemplu de moștenire este prezentat în următorul cod:

```cpp
class Animal {
    point position;
public:
    Animal();
    virtual ~Animal();

    virtual void eat() const {
        std::cout << "do eat" << std::endl;
    }
    void move(point pt) {
        position = pt;
    }
};

class Cat: Animal {
public:
    Cat();
    virtual ~Cat();

    virtual void eat() const;
};

class Pig: Animal {
public:
    Pig();
    virtual ~Pig();

    virtual void eat() const;
}
```

Avand in vedere faptul ca clasa derivata descrie o submulțime a elementelor clasei de bază, pointerul (sau referința) la obiectul clasei de bază poate referi și la obiectul clasei derivate, dar nu vice versa. Pointerul (sau referința) la obiectul clasei derivate __nu poate__ referi la obiectul clasei de bază.

Exemplu:

```cpp
class A {};
class B: public A {};

A a1;
B b1;
A& a = b1; // OK!
B& b = a1; // ERROR!
```

## Functii virtuale

Un programator poate redefini o funcție a clasei de bază în clasa derivată. De exemplu, în următorul cod este prezentată această posibilitate:

```cpp
// nopoly.cpp
#include <iostream>

struct A {
    A() {}
    void print() const { std::cout << "A"; }
};

struct B: public A {
    B(){}
    void print() const { std::cout << "B"; }
};

int main(){
     A* obj = new B;
     obj->print();
     obj = new A;
     obj->print();
     return 0; 
}
```

Doar ca rezultatul așteptat nu va fi obținut - pe ecran în ambele cazuri va fi afișată litera A, nu B. Acest lucru se datorează faptului că compilatorul nu poate determina tipul obiectului aflat în variabila `obj`, astfel că se apelează funcția obiectului părinte. Această problemă poate fi rezolvată cu ajutorul funcțiilor virtuale. În cazul utilizării funcțiilor virtuale, compilatorul garantează apelarea propriei versiuni a funcției pentru fiecare obiect al clasei din ierarhie.

O metodă se numește __virtuală__ dacă poate fi redefinită într-o clasă derivată. Exemplu de utilizare a funcțiilor virtuale:

```cpp
// poly01.cpp
#include <iostream>

struct A {
     A() {}
     virtual void print() const { puts("A"); }
};

struct B:public A {
     B() {}
     virtual void print() const { std::cout << "B"; }
};

int main(){
     A* obj = new B;
     obj->print();
     obj = new A;
     obj->print();
     return 0;
}
```

In exemplul dat va fi obținut rezultatul dorit: pe ecran va fi afișat `BA`.

### Clase abstracte

O metoda se numește __pur virtuală__ (sau __abstractă__) dacă nu are implementare.

```cpp
struct Comparable {
    // funcție pur virtuală
    virtual bool equal(const Comparable&) = 0; 
};

class Complex: Comparable {
    double real;
    double imaginary;
public:
    virtual bool equal(const Comparable&); 
};
```

Dacă o clasă conține cel puțin o funcție pur virtuală, atunci această clasă se numește __clasă abstractă__. Un obiect al unei clase abstracte nu poate fi creat.

### Interfață

Class abstractă poate conține doar funcții pur virtuale publice. În acest caz, uneori (analogic cu alte limbaje OO) această clasă se numește interfață.

### Polimorfism

__Polimorfismul__ este un mecanism care permite utilizarea unui obiect de orice tip într-un context general. Exemplu de polimorfism bazat pe conversia implicită a tipurilor:

```cpp
bool less(double x, double y) { return x < y; }

int a = 10, b = 15;
less(a, b);
```

Polimorfismul pe baza funcțiilor virtuale, numit și __polimorfism dinamic__, se bazează pe capacitatea unui pointer (sau referinta) la un obiect de clasă de bază de a include un pointer (referinta) la un obiect de clasă derivată.

Această proprietate poate fi utilizată pentru implementarea polimorfismului - capacitatea de a utiliza aceeași funcție (același nume de funcție) cu diferite tipuri de parametri. Exemplu de polimorfism dinamic cu clasele din exemplul dat este prezentat în listarea _poly02.cpp_

```cpp
// poly02.cpp
#include <iostream>
​
struct A{
     A() {}
     virtual void print() const { puts("A"); }
};
​
struct B:public A{
     B(){}
     virtual void print() const { std::cout << "B"; }
};

void print(const A& a){
     a->Print();
}

int main(){
     B b;
     A& obj = b;
     print(obj);
     return 0;
}
```
