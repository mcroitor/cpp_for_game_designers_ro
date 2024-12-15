# Practici bune de programare

- [Practici bune de programare](#practici-bune-de-programare)
  - [Stil de programare](#stil-de-programare)
    - [Utilizați nume de variabile, funcții și clase clare și descriptive](#utilizați-nume-de-variabile-funcții-și-clase-clare-și-descriptive)
    - [Utilizați comentarii pentru a explica codul](#utilizați-comentarii-pentru-a-explica-codul)
    - [Utilizați spații pentru a îmbunătăți citirea codului](#utilizați-spații-pentru-a-îmbunătăți-citirea-codului)
    - [Utilizați tab-uri pentru a evidenția blocurile de cod](#utilizați-tab-uri-pentru-a-evidenția-blocurile-de-cod)
    - [Utilizați linii goale pentru a separa blocurile logice de cod](#utilizați-linii-goale-pentru-a-separa-blocurile-logice-de-cod)
    - [Evitați utilizarea numerelor și șirurilor magice](#evitați-utilizarea-numerelor-și-șirurilor-magice)
    - [Evitați utilizarea liniilor de cod prea lungi](#evitați-utilizarea-liniilor-de-cod-prea-lungi)
    - [Evitați funcțiile prea mari](#evitați-funcțiile-prea-mari)
  - [Documentarea codului](#documentarea-codului)
  - [Testarea codului](#testarea-codului)
  - [Idiomuri de programare](#idiomuri-de-programare)
    - [Idiomuri de bază](#idiomuri-de-bază)
      - [Increment și decrement](#increment-și-decrement)
      - [Swap](#swap)
    - [RAII](#raii)
    - [Pimpl](#pimpl)
  - [Bibliografia](#bibliografia)

Practici bune de programare sunt reguli și recomandări care ajută la scrierea codului de calitate, ușor de citit și de întreținut. Practicile bune de programare sunt importante pentru dezvoltarea de software de calitate, care este ușor de înțeles, de testat și de întreținut. În practicile bune de programare sunt incluse următoarele aspecte:

1. Stil de programare.
2. Documentarea codului.
3. Testarea codului.
4. Idiomuri de programare.

## Stil de programare

__Stilul de programare__ se referă la regulile de formatare a codului programului [^1]. Stilul de programare definește

1. cerințele pentru denumirile variabilelor, funcțiilor etc.
2. regulile de formatare a codului;
3. regulile de organizare a codului;
4. regulile de documentare a codului.

Stilul de programare ajută la îmbunătățirea citirii codului, simplifică înțelegerea și întreținerea acestuia. Acest lucru este deosebit de important în dezvoltarea de echipă, când mai mulți programatori lucrează la același proiect sau când un programator transmite proiectul altuia.

Stilul de programare este de obicei definit de standardele interne ale companiei sau comunității de programatori. Cu toate acestea, există standarde care sunt larg utilizate în industria programării. De exemplu, standardele de formatare a codului pentru limbajul `C++` sunt definite în cartea C++ _Coding Standards: 101 Rules, Guidelines, and Best Practices_ [^2] și în standardul _Google C++ Style Guide_ [^3].

În majoritatea mediilor de dezvoltare sunt implementate instrumente care permit verificarea automată a codului pentru conformitatea cu stilul de programare. Este recomandat să utilizați aceste instrumente pentru menținerea unui stil de programare uniform în proiect.

Mai jos sunt enumerate câteva recomandări de bază pentru formatarea codului:

1. Utilizați nume de variabile, funcții și clase clare și descriptive.
2. Utilizați comentarii pentru a explica codul.
3. Utilizați spații pentru a îmbunătăți citirea codului.
4. Utilizați tab-uri pentru a evidenția blocurile de cod.
5. Utilizați linii goale pentru a separa blocurile logice de cod.
6. Evitați utilizarea numerelor și șirurilor magice.
7. Evitați utilizarea liniilor de cod prea lungi.
8. Evitați funcțiile prea mari.

### Utilizați nume de variabile, funcții și clase clare și descriptive

Numele variabilelor, funcțiilor și claselor trebuie să fie clare și descriptive. Numele ar trebui să reflecte scopul variabilei, funcției sau clasei și să fie ușor de înțeles pentru alți programatori. Pentru denumirea se folosește, de obicei, unul dintre următoarele stiluri:

1. `camelCase` - primul cuvânt cu literă mică, fiecare cuvânt următor cu literă mare: `myVariable`, `myFunction`. De obicei, este folosit pentru denumirea variabilelor, funcțiilor și metodelor.
2. `snake_case` - toate cuvintele cu litere mici, separate de caracterul de subliniere: `my_variable`, `my_function`, `my_class`. Acest tip de denumire este de obicei folosit în biblioteca standard a limbajului `C++`.
3. `PascalCase` - fiecare cuvânt cu literă mare: `MyClass`. Acest tip de denumire este de obicei folosit pentru denumirea claselor și structurilor în `C++`.
4. `UPPER_CASE` - toate literele cu majuscule, cuvintele separate de caracterul de subliniere: `MY_CONSTANT`. Este folosit pentru denumirea constantelor.

În alte limbaje de programare pot fi utilizate alte stiluri de denumire.

### Utilizați comentarii pentru a explica codul

Un cod curat și calitativ trebuie să conțină o anumită documentație sub formă de comentarii, care explică codul, caracteristicile și logica sa de lucru. Este important nu numai să explicați codul, ci și să justificați deciziile luate și să furnizați informații suplimentare (de exemplu, autor, dată de creare etc.). Mai detaliat despre comentarii și documentare a codului vom discuta în secțiunea _Documentarea codului_.

### Utilizați spații pentru a îmbunătăți citirea codului

Atunci când scriem un anumit text, îl despărțim cuvintele cu spații pentru a îmbunătăți citirea. Același lucru se aplică și codului programului: plasarea spațiilor între operatori, cuvinte cheie și variabile îmbunătățește citirea codului și îl face mai ușor de înțeles.

Este rău să scriem:

```cpp
int a=5;
```

Cu mult mai bine să scriem:

```cpp
int a = 5;
```

### Utilizați tab-uri pentru a evidenția blocurile de cod

Tab-urile sau indentare cu spații sunt utilizate pentru a evidenția blocurile de cod și a îmbunătăți citirea acestuia. Tab-urile permit ușor de determinat înglobarea blocurilor de cod și de îmbunătățit înțelegerea acestuia.

Este rău să scriem:

```cpp
for (int i = 0; i < 10; i++) {
std::cout << i << std::endl;
}
```

Cu mult mai bine să scriem:

```cpp
for (int i = 0; i < 10; i++) {
    std::cout << i << std::endl;
}
```

În plus, indentarea permite evidențierea blocuri logice de cod, care pot fi candidați pentru extragerea în funcții separate.

### Utilizați linii goale pentru a separa blocurile logice de cod

Un cod complex secvențial de obicei conține mai multe blocuri logice care îndeplinesc diferite sarcini. Pentru a îmbunătăți citirea codului și a înțelege structura acestuia, blocurile logice de cod ar trebui să fie separate cu linii goale.

Este rău să scriem:

```cpp
int a = 5;
int b = 10;
int c = a + b;
std::cout << c << std::endl;
```

Cu mult mai bine să scriem:

```cpp
int a = 5;
int b = 10;
int c = a + b;

std::cout << c << std::endl;
```

### Evitați utilizarea numerelor și șirurilor magice

_Numerele magice_ și _șirurile magice_ sunt numere și șiruri care sunt utilizate direct în codul sursă, fără a fi declarate ca constante. Utilizarea numerelor și șirurilor magice îngreunează înțelegerea codului și întreținerea acestuia, deoarece nu este clar ce înseamnă aceste numere și șiruri. Prin urmare, numerele și șirurile magice ar trebui înlocuite cu constante cu nume clare.

Rău să scriem:

```cpp
if (status == 1) {
    // ...
}
```

Cu mult mai bine să scriem:

```cpp
const int STATUS_OK = 1;

if (status == STATUS_OK) {
    // ...
}
```

### Evitați utilizarea liniilor de cod prea lungi

Liniile de cod prea lungi sunt greu de citit și de înțeles. De asemenea, liniile de cod prea lungi pot fi dificil de citit pe ecranele cu rezoluție mică sau în editorii de text cu lățimea limitată a liniei. Prin urmare, liniile de cod ar trebui să fie suficient de scurte pentru a fi ușor de citit și de înțeles.

Este rău să scriem:

```cpp
std::string longString = "This is a very long string that does not fit on the screen and is hard to read.";
```

Cu mult mai bine să scriem:

```cpp
std::string longString = "This is a very long string that does not fit on the screen "
                         "and is hard to read.";
```

### Evitați funcțiile prea mari

Funcțiile prea mari tot greu de citit și de înțeles. Și mai mult, funcțiile prea mari sunt dificil de testat și de întreținut. De aceea, funcțiile mari să separ în funcții mai mici, fiecare din care să îndeplinească o singură sarcină.

## Documentarea codului

Documentarea codului este un proces de adăugare a comentariilor la codul programului pentru a explica funcționarea și destinația acestuia. Documentarea codului ajută la îmbunătățirea înțelegerii codului, simplificarea întreținerii și dezvoltării acestuia. Pe baza codului documentat, programe speciale pot genera automat documentația programului, iar mediile de dezvoltare pot oferi sugestii și informații suplimentare despre cod.

Documentarea codului de obicei include următoarele tipuri de comentarii:

1. Metadate - informații despre versiune, autor, dată de creare etc.
2. Comentarii pentru clase, funcții și variabile - descriu scopul și caracteristicile clasei, funcției sau variabilei.
3. Comentarii pentru blocuri de cod - explică logica de funcționare a blocului de cod.
4. Comentarii pentru linii de cod - justifică deciziile luate și explică secțiunile de cod complexe.

Documentarea excesivă a codului poate fi, de asemenea, dăunătoare, deoarece complică înțelegerea codului și crește volumul codului. Prin urmare, documentarea codului ar trebui să fie moderată și informativă.

Pentru crearea documentației tehnice a programului de obicei se folosesc instrumente speciale, cum ar fi Doxygen [^4], Javadoc [^5] etc. Aceste instrumente permit generarea automată a documentației programului pe baza comentariilor din cod.

Pentru definirea standardelor de documentare a codului de obicei se folosesc standarde de formatare a codului, cum ar fi Google C++ Style Guide [^3].

Un exemplu de documentare a funcției în `C++`:

```cpp
/**
 * @brief This is a brief description of the function.
 *
 * This is a detailed description of the function.
 *
 * @param[in] a The first parameter.
 * @param[in] b The second parameter.
 * @return The result of the function.
 */
int add(int a, int b) {
    return a + b;
}
```

Exemplu de documentare a clasei în `C++`:

```cpp
/**
 * @brief This is a brief description of the class.
 *
 * This is a detailed description of the class.
 */
class MyClass {
public:
    /**
     * @brief This is a brief description of the function.
     *
     * This is a detailed description of the function.
     *
     * @param[in] a The first parameter.
     * @param[in] b The second parameter.
     * @return The result of the function.
     */
    int add(int a, int b);
};
```

Documentația la cod se face printr-un comentariu de tip bloc, care începe cu `/**` și se termină cu `*/`. În comentariu se pot folosi taguri speciale, care permit generarea automată a documentației programului.

Câteva taguri de bază din documentație:

1. `@brief` - o descriere scurtă.
2. `@param` - descrierea parametrului funcției.
3. `@return` - descrierea valorii returnate de funcție.
4. `@version` - versiunea funcției sau clasei.
5. `@author` - autorul funcției sau clasei.
6. `@date` - data creării funcției sau clasei.

## Testarea codului

Una din problemele informaticii este justificarea corectitudinii programului. Testarea programului este procesul de verificare a conformității programului cu cerințele și detectarea erorilor. Testarea programului permite să ne asigurăm că programul funcționează corect și nu conține erori.

Sunt următoarele tipuri de testare a programului:

1. Testarea unitară (en. _unit testing_) - testarea fiecărui modul al programului în mod separat.
2. Testarea de integrare (en. _integration testing_) - testarea interacțiunii dintre modulele programului.
3. Testarea de sistem (en. _system testing_) - testarea întregului program.
4. Testarea de acceptare (en. _acceptance testing_) - testarea programului de către client.
5. Testarea de regresie (en. _regression testing_) - testarea programului după modificări.
6. Testarea de performanță (en. _performance testing_) - testarea performanței programului.
7. Testarea de securitate (en. _security testing_) - testarea securității programului.

Elaborarea testelor unitare este responsabilitatea programatorului [^6]. Testele unitare permit să ne asigurăm de corectitudinea funcționării modulelor separate ale programului și să detectăm erorile la etapele timpurii ale dezvoltării. Testele unitare de obicei se scriu împreună cu codul programului (sau chiar înainte de scrierea codului) și se execută automat la asamblarea proiectului.

Pentru scrierea testelor unitare de obicei se folosesc biblioteci speciale de testare, cum ar fi Google Test [^7], Catch2 [^8] etc. Aceste biblioteci permit să scriem și să executăm testele în mod automat și să verificăm rezultatele testării.

Totuși, un simplu test unitar poate fi scris și fără utilizarea unui framework. De exemplu, pentru testarea funcției de adunare a două numere se poate scrie următorul test:

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

## Idiomuri de programare

Sub _idiom de programare_ se înțelege un mod standard de a scrie cod, care este cel mai eficient și convenabil pentru rezolvarea unei anumite sarcini. Idiomurile de programare de obicei fac parte din limbajul de programare și includ șabloane, algoritmi și structuri de date standard. Idiomurile de programare pot fi numite _șabloane de proiectare_ la nivel scăzut [^9], care sunt utilizate pentru rezolvarea unor sarcini specifice.

### Idiomuri de bază

#### Increment și decrement

Una din cele probleme standard de programare este numărarea (elementelor, operațiilor efectuate etc.). Soluția standard a acestei probleme constă în introducerea unei variabile - contor și creșterea (scăderea) valorii acesteia cu o unitate. În unele limbaje pentru aceasta se folosește forma:

```basic
i = i + 1
```

În limbajele bazate pe `C` pentru soluționarea acestei probleme se folosește operatorul de incrementare `++`:

```cpp
i++;
```

Respectiv, pentru decrementare se folosește operatorul de decrementare `--`:

```cpp
i--;
```

#### Swap

ALtă problema tipică a programării este schimbul valorilor a două variabile. Soluția standard a acestei probleme constă în utilizarea unei variabile intermediare:

```cpp
template <typename T>
void swap(T& a, T& b) {
    T tmp = a;
    a = b;
    b = tmp;
}
```

Totuși, dacă este necesar să schimbăm conținut a două containere, schimbul valorilor elementelor este ineficient. De obicei, containerul conține un pointer la memoria pe care o gestionează, de aceea schimbul de pointeri este o soluție mai eficientă:

```cpp
template <typename T>
void swap(T* a, T* b) {
    T* tmp = a;
    a = b;
    b = tmp;
}
```

### RAII

_RAII_ (en. Resource Acquisition Is Initialization) - este o idiom de programare care constă în faptul că resursele trebuie să fie alocate în constructorul obiectului și eliberate în destructorul acestuia. Acest lucru permite să garantăm că resursele vor fi eliberate în caz de excepție sau ieșire din bloc.

RAII este utilizat pentru a evita scurgerile de memorie și alocările nereușite de resurse.

Exemplu de realizare a RAII pentru lucru cu fișiere:

```cpp
class File {
public:
    File(const std::string& filename) : file(fopen(filename.c_str(), "r")) {
        if (!file) {
            throw std::runtime_error("Failed to open file");
        }
    }

    ~File() {
        fclose(file);
    }

    void read() {
        // ...
    }

private:
    FILE* file;
};
```

### Pimpl

_Pimpl_ (en. Pointer to Implementation) - este un idiom de programare care constă în faptul că implementarea clasei este separată într-o clasă separată, care este stocată într-un pointer inteligent în clasa principală. Acest lucru permite să ascundem implementarea clasei de client și să reducem dependența dintre interfață și implementare.

Exemplu:

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

## Bibliografia

[^1]: [Kernighan B., Pike R., The Practice of Programming, Addison-Wesley, 1999](https://www.google.com/search?q=kernighan+pike+the+practice+of+programming)
[^2]: [Sutter H., Alexandrescu A., C++ Coding Standards: 101 Rules, Guidelines, and Best Practices, Pearson Education, 2004](https://www.google.com/search?q=C%2B%2B+Coding+Standards%3A+101+Rules%2C+Guidelines%2C+and+Best+Practices)
[^3]: [Google C++ Style Guide, Google, github.io](https://google.github.io/styleguide/cppguide.html)
[^4]: [Doxygen, doxygen.nl](https://www.doxygen.nl)
[^5]: [Javadoc, Oracle](https://www.oracle.com/java/technologies/javase/javadoc.html)
[^6]: [Beck K., Test-Driven Development by Example, Addison-Wesley, 2003](https://www.google.com/search?q=Test-Driven+Development+by+Example)
[^7]: [Google Test, Google, github.com](https://github.com/google/googletest)
[^8]: [Catch2, catchorg, github.com](https://github.com/catchorg/Catch2)
[^9]: [Software design pattern, Wikipedia](https://en.wikipedia.org/wiki/Software_design_pattern)
