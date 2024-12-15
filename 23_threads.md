# Programare multi-threading

- [Programare multi-threading](#programare-multi-threading)
  - [Noțiuni de bază ale programării multi-threading](#noțiuni-de-bază-ale-programării-multi-threading)
  - [Fire de execuție](#fire-de-execuție)
  - [Lucrul cu sistem și fire de execuție](#lucrul-cu-sistem-și-fire-de-execuție)
  - [Problema partajării resurselor dintre firele de execuție](#problema-partajării-resurselor-dintre-firele-de-execuție)
    - [Mutex](#mutex)
    - [Variabile și operații atomice](#variabile-și-operații-atomice)
  - [Programare asincronă](#programare-asincronă)
  - [Algoritmi paraleli](#algoritmi-paraleli)
  - [Bibliografie](#bibliografie)

## Noțiuni de bază ale programării multi-threading

Un __program__ este o secvență de instrucțiuni salvate într-un fișier, executabil sau interpretabil. Un __proces__ este executarea efectivă a unui program (a instrucțiunilor sale). De asemenea, un proces poate fi definit ca fiind programul împreună cu resursele sale asociate: spațiul de adresare, variabilele globale, fișierele deschise etc. În cadrul unui proces poate funcționa unul sau mai multe _fire de execuție_.

__Fir de execuție__ (en. __thread__) este o unitate minimă care poate fi executată de sistem de operare. Realizarea firelor de execuție și proceselor este diferită în funcție de sistemul de operare, dar în general un fir de execuție se află în cadrul unui proces. Mai multe fire de execuție pot exista în cadrul aceluiași proces și pot partaja resurse, cum ar fi memoria, în timp ce procesele nu partajează aceste resurse. În special, firele de execuție partajează secvența de instrucțiuni a procesului (codul său) și contextul său - valorile variabilelor (registrele procesorului și stiva de apeluri) pe care le au în orice moment.

Posibilitatea sistemei de operare (și a procesorului) de a executa mai multe fire de execuție în același timp se numește __multithreading__. Calculatoarele moderne permit executarea mai multor operații simultan datorită mai multor nuclee ale procesorului.

Un __algoritm paralel__ este un algoritm care poate realizat în bucăți pe mai multe dispozitive de calcul, cu rezultatele obținute ulterior combinate pentru a obține rezultatul corect. Un exemplu de algoritm paralel este adunarea și înmulțirea matricelor.

Terminul _paralel_ nu înseamnă _fix în același moment_. Două sarcini distincte sunt _paralele_ dacă se întâmplă în același interval de timp.

__Programare paralelă__ (sau __programare concurentă__) este o metoda de elaborare a programelor în care problema este împărțită în mai multe sarcini independente, soluțiile cărora sunt executate simultan, fie pe același procesor, fie pe mai multe procesoare în cadrul aceluiași sistem de calcul fizic sau virtual.

__Programare distribuită__ este o metodă de elaborare a programelor în care problema este împărțită în mai multe sarcini independente, soluțiile cărora sunt executate simultan pe mai multe calculatoare fizice sau virtuale, conectate în rețea.

Proiectând un algoritm paralel, este necesar să se efectueze următorii pași:

- __decompoziție__ - proces de împărțire a sarcinii și a soluției sale în părți;
- __relația__ - definirea relațiilor între părțile soluției;
- __sincronizare__ - coordonarea ordinii de execuție a părților soluției.

Firele de execuție care se execută simultan pot avea memorie proprie, dar pot avea și acces la o memorie comună, numită __memorie partajată__ (en. __shared memory__).

Începând cu standardul limbajului __C++11__, limbajul oferă suport pentru programare paralelă. C++ oferă următoarele elemente de programare paralelă (clasificare după standarde):

- __С++11__
  - modelul de memorie
  - variabile atomice
  - fire de execuție
  - mutex-uri (semafoare binare) și blocante
  - date locale ale firului de execuție
  - sarcini
- __С++14__
  - blocante de citire / scriere
- __С++17__
  - algoritmi paraleli
- __С++20__
  - smart pointers atomici
  - fire de execuție cu așteptare
  - bariere (barrier) și clanțe (latch)
  - semafoare generale
  - corutine

## Fire de execuție

În limbajul C++ lucrul cu fire de execuție este definit în antetul `<thread>`. Crearea unui fir de execuție se realizează prin declararea unui obiect de tip `std::thread`, care primește ca argument o funcție care va fi îndeplinită în firul de execuție și, opțional, argumentele acestei funcții.

Un exemplu simplu de creare a unui fir de execuție este prezentat mai jos:

```cpp
#include <thread>
#include <iostream>

void hello() {
    std::cout << "hello!";
}
int main() {
    std::thread t(hello);
    t.join();
    return 0;
}
```

În acest exemplu se creează un fir de execuție care îndeplinește funcția `hello`, iar programul principal așteaptă terminarea firului de execuție (`t.join();`). Dacă nu așteptați terminarea firului de execuție, atunci comportamentul programului nu este definit (și de obicei se termină cu o eroare a firului de execuție).

Începând cu standardul _C++20_ este posibil să se creeze fire de execuție care se prind automat, folosind clasa `std::jthread`.

```cpp
#include <thread>
#include <iostream>

void hello() {
    std::cout << "hello from " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::jthread t(hello);
    return 0;
}
```

## Lucrul cu sistem și fire de execuție

Pentru lucrul efectiv cu sistem de operare este necesară cunoașterea configurației sistemului și a resurselor disponibile. În caz particular este necesar să se cunoască numărul de nuclee ale procesorului, care determină numărul de fire de execuție care efectiv pot fi create. Biblioteca standard C++ pentru obținerea informației despre sistem și firele de execuție oferă funcția:

```cpp
`std::thread::hardware_concurrency();
```

Aceasta funcție returnează numărul fizic de fire de execuție ale procesorului. Dacă numărul actual de fire nu este cunoscut, atunci funcția returnează 0.

Totodată pentru gestionarea firelor de execuție în C++ sunt utilizate următoarele metode:

- `std::this_thread::get_id()` returnează identificatorul firului de execuție curent;
- `std::this_thread::sleep_for(<time duration>)` suspendă execuția firului de execuție curent pentru `<time duration>` timp. Timpul este specificat sub formă de obiect al clasei `std::chrono::duration`;
- `std::this_thread::sleep_until(<time point>)` suspendă execuția firului de execuție curent până la momentul `<time point>`. Timpul este specificat sub formă de obiect al clasei `std::chrono::time_point`.

Un exemplu de utilizare a metodelor este prezentat mai jos:

```cpp
#include <iostream>
#include <thread>
#include <chrono>

int main() {
    int threads = std::thread::hardware_concurrency();
    std::cout << "threads: " << threads << std::endl;
    if(threads == 0) {
        std::cout << "unknown number of threads, exit" << std::endl;
        return 1;
    }

    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

    for(int i = 0; i < threads; ++i) {
        std::thread t([i]() {
            std::cout << "thread id: " << std::this_thread::get_id() 
                    << " started" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(i));
            std::cout << "thread id: " << std::this_thread::get_id() 
                    << " finished" << std::endl;
        });
        t.join();
    }
    return 0;
}
```

## Problema partajării resurselor dintre firele de execuție

Una din problemele programării paralele este interacțiunea firelor de execuție cu memoria comună. Dacă două fire de execuție au acces la aceeași zonă de memorie, atunci ele pot interfera unul cu celălalt, schimbând valoarea stocată în acea zonă de memorie. Problema când rezultatul operațiilor executate în două sau mai multe fire de execuție depinde de ordinea lor de execuție se numește __stare de cursă__ (en. race condition) sau __concurența__.

Soluții posibile ale problemei stării de cursă:

- includerea structurii de date într-un mecanism de protecție care garantează modificarea obiectului de către firul care l-a capturat;
- rescrierea structurii de date pentru a elimina cursa (programare fără blocare), de exemplu, creând o copie a structurii de date pentru fiecare fir de execuție sau folosind variabile atomice.

### Mutex

__Mutex__ (de la en. __mutual exclusion__ - excludere reciprocă) este un obiect simplu (primitiv de sincronizare) care permite marcarea tuturor fragmentelor de cod care accesează aceeași structură de date pentru a preveni starea de cursă.

Mutex-ul este definit în fișier anterior `<mutex>`, se numește `std::mutex`. Blocarea și deblocarea structurii se realizează prin apelarea metodelor `lock` și `unlock`. Totuși, utilizarea directă a acestora nu este recomandată. În schimb, este mai bine să utilizați un obiect de tip `std::lock_guard`, care blochează mutex-ul la crearea sa și deblochează la distrugerea sa.

```cpp
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>

using vector = std::vector<int>;

std::mutex locker;

void populate_vector(vector& v, size_t size) {
    std::lock_guard<std::mutex> lg(locker);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    while(size > 0) {
        v.push_back(size);
        --size;
    }
}

void find_value(const vector& v, size_t value) {
    std::lock_guard<std::mutex> lg(locker);
    auto it = std::find(v.begin(), v.end(), value);
    it == v.end()
        ? std::cout << "not found!" << std::endl
        : std::cout << "found!" << std::endl;
}

int main() {
    vector v;
    std::jthread t_populate(populate_vector, std::ref(v), 10);
    std::jthread t_find2(find_value, std::cref(v), 7);
    return 0;
}
```

### Variabile și operații atomice

O operație este __atomică__ dacă nu poate fi îndeplinită parțial: fie se realizează complet, fie nu se realizează deloc. Operația atomică este realizată de un singur fir de execuție.

Atomicitatea poate fi realizată sau prin hardware sau prin software. În primul caz, sunt utilizate instrucțiuni speciale ale procesorului, iar în al doilea caz, sunt utilizate mecanisme de sincronizare care blochează resursa partajată pentru a efectua operația asupra acesteia. _Blocarea este o operație atomică_.

Tip de date se numește __atomic__ dacă operațiile cu acest tip de date sunt atomice.

Definiția tipului atomic este dată în antetul `<atomic>`.

## Programare asincronă

__Programare asincronă__ este o metoda de organizare a programei în care unele operații se îndeplinesc nu în ordinea în care au fost apelate. În loc să aștepte terminarea operației, programul continuă să funcționeze, iar operația se termină în fundal.

Începând cu standardul `C++11` a fost introdusă clasa `std::future`, care permite obținerea rezultatului unei operații asincrone. Clasa `std::future` reprezintă un obiect care stochează rezultatul unei operații asincrone. Ea oferă metode pentru verificarea terminării operației și obținerea rezultatului. Operația asincronă este realizată cu ajutorul funcției `std::async`, care primește ca argument o funcție și argumentele acesteia.

```cpp
#include <iostream>
#include <future>
#include <thread>
#include <chrono>

int main() {
    std::future<int> f = std::async([]() {
        std::this_thread::sleep_for(std::chrono::seconds(3));
        return 8;
    });
    std::cout << "waiting..." << std::endl;
    std::cout << f.get() << std::endl;
    return 0;
}
```

## Algoritmi paraleli

Începând cu standardul `C++17` în standardul limbajului C++ au fost introduse versiuni paralele ale unor algoritmi standard. Aceste versiuni sunt prezentate ca redeclarări ale multor funcții care lucrează cu diapazoane, cum ar fi `std::find`, `std::transform` sau `std::reduce`. Versiunile paralele au aceeași semnătură ca și cele "obișnuite" unifilare, cu excepția adăugării unui nou prim parametru care specifică politica de execuție.

```cpp
std::vector<int> my_data;
std::sort(std::execution::par,my_data.begin(),my_data.end());
```

Politica de execuție `std::execution::par` specifică că acest apel poate fi executat ca un algoritm de calcul paralel care utilizează mai multe fire de execuție simultan. Este important de menționat că aceasta este o permisiune, nu o cerință - biblioteca este liberă să execute în continuare codul într-un singur fir de execuție.

Politici de execuție sunt clase definite în antetul `<execution>`. Ele sunt folosite pentru a specifica modul în care algoritmii paraleli trebuie să se comporte.

Standardul declară următoarele politici de execuție:

- `std::execution::sequenced_policy` cu obiectul declarat `std::execution::seq` - _politică secvențială_ (sequenced policy) nu este o politică de paralelism: ea forțează implementarea să execute toate operațiile în firul de execuție care a apelat funcția, fără paralelism. Cu toate acestea, este o politică de execuție, ceea ce înseamnă că are același impact asupra complexității algoritmice și a lansării excepțiilor ca și celelalte politici standard.
- `std::execution::parallel_policy` cu obiectul declarat `std::execution::par` - _politică paralelă_ (parallel policy) oferă execuție paralelă de bază, cu operațiile care pot fi executate fie în firul de execuție care a apelat algoritmul, fie în fire de execuție create de bibliotecă. Operațiile care se execută într-un fir de execuție trebuie să se execute într-o anumită ordine și să nu se amestece, dar ordinea exactă nu este specificată și poate varia de la apel la apel. O anumită operație va fi executată în același fir de execuție pe toată durata de viață.
- `std::execution::parallel_unsequenced_policy` cu obiectul declarat `std::execution::par_unseq` - _politică paralelă neordonată_ (parallel unsequenced policy) oferă bibliotecii cea mai mare scalabilitate a algoritmului în schimbul unor cerințe stricte pentru iteratori, valori și obiecte apelate utilizate cu algoritmul.
- `std::execution::unsequenced_policy` cu obiectul declarat `std::execution::unseq` - _politică neordonată_ (unsequenced policy) oferă bibliotecii cea mai mare scalabilitate a algoritmului în schimbul unor cerințe stricte pentru iteratori, valori și obiecte apelate utilizate cu algoritmul.

Exemple de utilizare:

```cpp
std::vector<int> vec ={3, 2, 1, 4, 5, 6, 10, 8, 9, 4};

std::sort(vec.begin(), vec.end());                            // sequential as ever
std::sort(std::execution::seq, vec.begin(), vec.end());       // sequential
std::sort(std::execution::par, vec.begin(), vec.end());       // parallel
std::sort(std::execution::par_unseq, vec.begin(), vec.end()); // parallel and vectorized
```

## Bibliografie

1. [Concurrency support library, cppreference.com](https://en.cppreference.com/w/cpp/thread)
2. [About Processes and Threads, Microsoft](https://learn.microsoft.com/en-us/windows/win32/procthread/about-processes-and-threads)
3. [MaxRokatansky, Multithreading, habr.com](https://habr.com/ru/companies/otus/articles/549814/)
4. [Многопоточность, https://cpp-kt.github.io](https://cpp-kt.github.io/cpp-notes/26_multithreading.html)
5. [Rainer Grimm, Multithreading with C++17 and C++20, moderncpp.com](https://www.modernescpp.com/index.php/multithreading-in-c-17-and-c-20/)
