# Cele mai bune practici de programare

- [Cele mai bune practici de programare](#cele-mai-bune-practici-de-programare)
  - [Stilul de programare](#stilul-de-programare)
    - [Folosiți denumiri clare pentru variabile, funcții și clase](#folosiți-denumiri-clare-pentru-variabile-funcții-și-clase)
    - [Folosiți comentarii pentru clarificarea codului](#folosiți-comentarii-pentru-clarificarea-codului)
    - [Folosiți spații pentru lizibilitate](#folosiți-spații-pentru-lizibilitate)
    - [Folosiți indentarea pentru blocuri de cod](#folosiți-indentarea-pentru-blocuri-de-cod)
    - [Folosiți linii goale pentru separarea logică a codului](#folosiți-linii-goale-pentru-separarea-logică-a-codului)
    - [Evitați numerele și șirurile „magice”](#evitați-numerele-și-șirurile-magice)
    - [Evitați liniile de cod prea lungi](#evitați-liniile-de-cod-prea-lungi)
    - [Evitați funcțiile prea mari](#evitați-funcțiile-prea-mari)
  - [Documentarea codului](#documentarea-codului)
  - [Testarea](#testarea)
  - [Idiome de programare](#idiome-de-programare)
    - [Idiome de bază](#idiome-de-bază)
      - [Increment și decrement](#increment-și-decrement)
      - [Swap](#swap)
    - [RAII](#raii)
    - [Pimpl](#pimpl)
  - [Bibliografie](#bibliografie)

Cele mai bune practici de programare reprezintă un set de reguli și recomandări care ajută la îmbunătățirea calității codului, la ușurarea înțelegerii și mentenanței acestuia. Acestea includ reguli de stil, documentare, testare și utilizarea idiomelor de programare.

Aspecte esențiale ale bunelor practici:

1. Stilul de programare — reguli de formatare și organizare a codului.
2. Documentarea codului — adăugarea de comentarii explicative.
3. Testarea — verificarea codului pentru a corespunde cerințelor.
4. Idiome de programare — soluții standardizate pentru probleme frecvente.

## Stilul de programare

__Stilul de programare__ reprezintă ansamblul regulilor de formatare a codului. Acesta stabilește:

1. reguli pentru denumirea variabilelor, funcțiilor etc.;
2. reguli de formatare și organizare a codului;
3. reguli de documentare.

Un stil coerent îmbunătățește lizibilitatea și facilitează colaborarea în echipă[^1]. În proiectele de echipă sau la predarea unui proiect, un stil unitar este esențial.

Stilul de programare poate fi dictat de standardele interne ale unei companii sau de comunitate. Există însă și standarde larg acceptate, precum "C++ Coding Standards: 101 Rules, Guidelines, and Best Practices"[^2] sau "Google C++ Style Guide"[^3].

Majoritatea mediilor de dezvoltare oferă instrumente pentru verificarea automată a stilului. Se recomandă utilizarea acestor instrumente pentru a menține un stil unitar.

Câteva reguli de bază:

1. Folosiți denumiri clare pentru variabile, funcții și clase.
2. Folosiți comentarii pentru clarificarea codului.
3. Folosiți spații pentru lizibilitate.
4. Folosiți indentarea pentru blocuri de cod.
5. Folosiți linii goale pentru separarea logică a codului.
6. Evitați numerele și șirurile „magice”.
7. Evitați liniile de cod prea lungi.
8. Evitați funcțiile prea mari.

### Folosiți denumiri clare pentru variabile, funcții și clase

Denumirile trebuie să fie descriptive și să reflecte scopul variabilei, funcției sau clasei. Exemple de stiluri de denumire:

1. `camelCase` — primul cuvânt cu literă mică, următoarele cu majusculă: `myVariable`, `myFunction`. Folosit pentru variabile, funcții, metode.
2. `snake_case` — toate cuvintele cu litere mici, separate prin underscore: `my_variable`, `my_function`, `my_class`. Folosit frecvent în STL.
3. `PascalCase` — fiecare cuvânt cu majusculă: `MyClass`. Folosit pentru clase și structuri.
4. `UPPER_CASE` — toate literele mari, cuvintele separate prin underscore: `MY_CONSTANT`. Folosit pentru constante.

### Folosiți comentarii pentru clarificarea codului

Comentariile ajută la înțelegerea scopului și logicii codului. Este important să explicați nu doar ce face codul, ci și de ce a fost ales acel mod de implementare. Comentariile pot conține și informații suplimentare (autor, dată etc.).

### Folosiți spații pentru lizibilitate

Spațiile între operatori, cuvinte cheie și variabile cresc lizibilitatea codului.

Greșit:

```cpp
int a=5;
```

Corect:

```cpp
int a = 5;
```

### Folosiți indentarea pentru blocuri de cod

Indentarea (prin spații sau taburi) evidențiază blocurile de cod și ajută la înțelegerea structurii.

Greșit:

```cpp
for (int i = 0; i < 10; i++) {
std::cout << i << std::endl;
}
```

Corect:

```cpp
for (int i = 0; i < 10; i++) {
    std::cout << i << std::endl;
}
```

### Folosiți linii goale pentru separarea logică a codului

Liniile goale separă blocuri logice, crescând lizibilitatea.

Greșit:

```cpp
int a = 5;
int b = 10;
int c = a + b;
std::cout << c << std::endl;
```

Corect:

```cpp
int a = 5;
int b = 10;
int c = a + b;

std::cout << c << std::endl;
```

### Evitați numerele și șirurile „magice”

Numerele sau șirurile „magice” sunt valori folosite direct în cod, fără a fi declarate ca constante. Acestea îngreunează mentenanța și înțelegerea codului.

Greșit:

```cpp
if (status == 1) {
    // ...
}
```

Corect:

```cpp
constexpr int STATUS_OK = 1;

if (status == STATUS_OK) {
    // ...
}
```

### Evitați liniile de cod prea lungi

Liniile lungi sunt greu de citit și de urmărit. Împărțiți-le pe mai multe linii.

Greșit:

```cpp
std::string longString = "This is a very long string that does not fit on the screen and is hard to read.";
```

Corect:

```cpp
std::string longString = "This is a very long string that does not fit on the screen "
                         "and is hard to read.";
```

### Evitați funcțiile prea mari

Funcțiile lungi sunt greu de citit, testat și întreținut. Împărțiți funcțiile complexe în funcții mai mici, fiecare cu o singură responsabilitate.

## Documentarea codului

Documentarea codului presupune adăugarea de comentarii explicative pentru a clarifica funcționarea și scopul acestuia. O documentare bună facilitează mentenanța și dezvoltarea ulterioară. Pe baza comentariilor, instrumente precum Doxygen[^4] sau Javadoc[^5] pot genera automat documentație tehnică.

Tipuri de comentarii utile:

1. Comentarii la clase, funcții și variabile — explică scopul și particularitățile acestora.
2. Comentarii la blocuri de cod — explică logica unui bloc.
3. Comentarii la linii de cod — justifică decizii sau explică fragmente complexe.
4. Metadate — informații despre versiune, autor, dată etc.

Documentarea excesivă poate dăuna, îngreunând citirea codului. Comentariile trebuie să fie concise și relevante.

Exemplu de documentare a unei funcții în C++:

```cpp
/**
 * @brief Descriere succintă a funcției.
 *
 * Descriere detaliată a funcției.
 *
 * @param[in] a Primul parametru.
 * @param[in] b Al doilea parametru.
 * @return Rezultatul funcției.
 */
int add(int a, int b) {
    return a + b;
}
```

Exemplu de documentare a unei clase:

```cpp
/**
 * @brief Descriere succintă a clasei.
 *
 * Descriere detaliată a clasei.
 */
class MyClass {
public:
    /**
     * @brief Descriere succintă a funcției.
     *
     * Descriere detaliată a funcției.
     *
     * @param[in] a Primul parametru.
     * @param[in] b Al doilea parametru.
     * @return Rezultatul funcției.
     */
    int add(int a, int b);
};
```

Comentariile pentru documentație folosesc blocul `/** ... */` și pot conține tag-uri speciale pentru generarea automată a documentației.

Tag-uri frecvente:

1. `@brief` — descriere scurtă.
2. `@param` — descrierea parametrului.
3. `@return` — descrierea valorii returnate.
4. `@version` — versiunea funcției sau clasei.
5. `@author` — autorul.
6. `@date` — data creării.

## Testarea

Testarea codului este procesul de verificare a corectitudinii și identificare a erorilor. Testarea asigură că programul funcționează conform cerințelor.

Tipuri de testare:

1. Testare unitară (unit testing) — testarea modulelor individuale (funcții, clase).
2. Testare de integrare — testarea interacțiunii dintre module.
3. Testare de sistem — testarea întregului program.
4. Testare de acceptanță — validarea de către client.
5. Testare de regresie — testarea după modificări.
6. Testare de performanță — evaluarea performanței.
7. Testare de securitate — evaluarea siguranței aplicației.

Kent Beck[^6] recomandă ca dezvoltatorii să scrie teste unitare pentru a verifica corectitudinea modulelor și a depista erorile devreme. Testele unitare se scriu împreună cu codul și se rulează automat la fiecare build.

Framework-uri populare pentru teste unitare: Google Test[^7], Catch2[^8] etc.

Exemplu simplu de test fără framework:

```cpp
#include <cassert>

int add(int a, int b) {
    return a + b;
}

int main() {
    assert(add(2, 3) == 5);
    assert(add(-2, 3) == 1);
    assert(add(0, 0) == 0);

    return 0;
}
```

## Idiome de programare

O idiomă de programare este o soluție standardizată pentru o problemă frecventă. Idiomele sunt parte a limbajului și includ șabloane, algoritmi și structuri de date uzuale. Ele pot fi considerate „șabloane de proiectare de nivel scăzut”[^9].

### Idiome de bază

#### Increment și decrement

Pentru numărare se folosește o variabilă-contor și operatorii de incrementare/decrementare:

```cpp
i++;
i--;
```

#### Swap

Pentru schimbul valorilor a două variabile:

```cpp
template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
```

Pentru containere sau pointeri, schimbul direct al adreselor este mai eficient:

```cpp
template <typename T>
void swap(T*& a, T*& b) {
    T* tmp = a;
    a = b;
    b = tmp;
}
```

### RAII

_RAII_ (Resource Acquisition Is Initialization) presupune ca resursele să fie alocate în constructor și eliberate în destructor. Astfel, resursele sunt eliberate automat la ieșirea din bloc sau la apariția unei excepții.

Exemplu pentru fișiere:

```cpp
class File {
public:
    File(const std::string& filename) : file(fopen(filename.c_str(), "r")) {
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~File() {
        if (file) {
            fclose(file);
        }
    }

    void read() {
        // ...
    }

private:
    FILE* file;
};
```

### Pimpl

_Pimpl_ (Pointer to Implementation) presupune separarea implementării de interfață, ascunzând detaliile într-o clasă internă gestionată prin pointer. Astfel, dependențele și timpul de compilare scad, iar interfața rămâne stabilă.

```cpp
class Widget {
public:
    Widget();
    ~Widget();

    void doSomething();

private:
    class Impl;
    std::unique_ptr<Impl> impl;
};

class Widget::Impl {
public:
    void doSomething() {
        // ...
    }
};

Widget::Widget() : impl(std::make_unique<Impl>()) {}

Widget::~Widget() = default;

void Widget::doSomething() {
    impl->doSomething();
}
```

## Bibliografie

[^1]: [Kernighan B., Pike R., The Practice of Programming, Williams, 2019](https://www.google.com/search?q=Керниган+Пайк+Практика+программирования)
[^2]: [Sutter H., Alexandrescu A., C++ Coding Standards: 101 Rules, Guidelines, and Best Practices, Pearson Education, 2004](https://www.google.com/search?q=C%2B%2B+Coding+Standards%3A+101+Rules%2C+Guidelines%2C+and+Best+Practices)
[^3]: [Google C++ Style Guide, Google, github.io](https://google.github.io/styleguide/cppguide.html)
[^4]: [Doxygen, doxygen.nl](https://www.doxygen.nl)
[^5]: [Javadoc, Oracle](https://www.oracle.com/java/technologies/javase/javadoc.html)
[^6]: [Beck Kent, Extreme Programming Explained, Piter, 2020](https://www.google.com/search?q=Бек+Кент+Экстремальное+программирование.+Разработка+через+тестирование)
[^7]: [Google Test, Google, github.com](https://github.com/google/googletest)
[^8]: [Catch2, catchorg, github.com](https://github.com/catchorg/Catch2)
[^9]: [Design Patterns, Wikipedia](https://ru.wikipedia.org/wiki/Шаблон_проектирования)
