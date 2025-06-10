# Programare multithreading

- [Programare multithreading](#programare-multithreading)
  - [Noțiuni de bază](#noțiuni-de-bază)
  - [Fire de execuție](#fire-de-execuție)
  - [Lucrul cu sistemul și firele](#lucrul-cu-sistemul-și-firele)
  - [Problema partajării datelor între fire](#problema-partajării-datelor-între-fire)
    - [Mutex](#mutex)
    - [Variabile și operații atomice](#variabile-și-operații-atomice)
  - [Programare asincronă](#programare-asincronă)
  - [Algoritmi paraleli](#algoritmi-paraleli)
  - [Bibliografie](#bibliografie)

## Noțiuni de bază

__Programul__ este o succesiune de instrucțiuni stocate într-un fișier executabil sau interpretat. __Procesul__ reprezintă execuția efectivă a unui program (instrucțiunile sale). Uneori, procesul este definit ca ansamblul programului executat împreună cu resursele asociate: spațiu de adrese, variabile globale, fișiere deschise etc. În cadrul unui proces pot exista unul sau mai multe __fire de execuție__ (en. _threads_).

__Firul de execuție__ (sau __thread__) este cea mai mică unitate de execuție gestionată de sistemul de operare. Implementarea firelor și a proceselor diferă între sistemele de operare, dar, de regulă, un fir există în interiorul unui proces. Mai multe fire pot coexista în același proces și pot partaja resurse precum memoria, în timp ce procesele nu partajează aceste resurse. Firele partajează codul procesului și contextul acestuia – valorile variabilelor (registrele procesorului și stiva de apeluri) pe care le au la un moment dat.

Capacitatea sistemului de operare (și a procesorului) de a executa mai multe fire simultan se numește __multithreading__. Calculatoarele moderne permit rularea mai multor operații în paralel datorită existenței mai multor nuclee de procesare.

__Algoritmul paralel__ este un algoritm care poate fi implementat pe mai multe dispozitive de calcul, cu reunirea rezultatelor pentru a obține rezultatul corect. Un exemplu de algoritm paralel este adunarea sau înmulțirea matricelor.

Termenul _paralel_ nu înseamnă neapărat simultan în sens strict. Două sarcini se execută _paralel_ dacă au loc în același interval de timp.

__Programarea paralelă__ (sau __programarea multithreading__) este metoda de scriere a programelor în care o problemă este împărțită în mai multe subprobleme independente, fiecare fiind executată simultan cu celelalte, pe procesoare (nuclee) diferite, în cadrul aceluiași calculator fizic sau virtual.

__Programarea distribuită__ presupune împărțirea unei probleme în subprobleme independente, fiecare fiind executată pe calculatoare diferite, fizice sau virtuale.

La proiectarea algoritmilor paraleli trebuie urmați pașii:

- __decompoziție__ – împărțirea problemei și a soluției în părți;
- __comunicare__ – definirea interacțiunilor dintre părți;
- __sincronizare__ – coordonarea ordinii de execuție a părților.

Firele care rulează în paralel pot avea memorie proprie, dar pot accesa și memorie partajată, numită __memorie partajată__ (en. shared memory).

Începând cu standardul __C++11__, limbajul oferă suport pentru programare multithreading. C++ suportă următoarele elemente de programare paralelă (clasificare după standard):

- __C++11__
  - model de memorie
  - variabile atomice
  - fire de execuție
  - mutexe și lock-uri
  - date locale firului
  - task-uri
- __C++14__
  - lock-uri pentru citire/scriere
- __C++17__
  - algoritmi paraleli
- __C++20__
  - pointeri inteligenți atomici
  - fire cu așteptare
  - latch-uri și bariere
  - semafoare generice
  - corutine

## Fire de execuție

Lucrul cu firele în C++ este definit în antetul `<thread>`. Crearea unui fir se face prin declararea unui obiect al clasei `std::thread`, constructorul primind funcția ce va fi executată în firul nou creat, precum și eventual parametrii acesteia.

Exemplu simplu de creare a unui fir:

```cpp
/**
  * @file thread_example.cpp
  * @brief Exemplu de creare a unui fir
  * @details g++ -std=c++11 thread_example.cpp -o thread_example
  */
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

În acest exemplu se creează un fir care execută funcția `hello`, iar programul principal așteaptă finalizarea firului (`t.join();`). Dacă nu se așteaptă finalizarea firului, comportamentul programului nu este definit (de obicei firul se închide cu eroare).

Începând cu __C++20__ se pot crea fire care se atașează automat, folosind clasa `std::jthread`.

```cpp
/**
  * @file jthread_example.cpp
  * @brief Exemplu de creare a unui fir
  * @details g++ -std=c++20 jthread_example.cpp -o jthread_example
  */
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

## Lucrul cu sistemul și firele

Pentru a lucra eficient cu sistemul de operare, este util să cunoaștem configurația acestuia. De exemplu, la lucrul cu firele, este util să știm câte nuclee sunt disponibile. Biblioteca standard C++ oferă funcția:

```cpp
std::thread::hardware_concurrency();
```

Aceasta returnează numărul de nuclee disponibile. Dacă nu se poate determina, funcția returnează 0.

Alte funcții utile pentru fire:

- `std::this_thread::get_id()` – identificatorul firului curent;
- `std::this_thread::sleep_for(<durată>)` – suspendă firul curent pentru `<durată>` (obiect de tip `std::chrono::duration`);
- `std::this_thread::sleep_until(<moment>)` – suspendă firul curent până la `<moment>` (obiect de tip `std::chrono::time_point`);

Exemplu de utilizare:

```cpp
/**
  * @file 23_threads_01.cpp
  * @brief Exemplu de lucru cu fire
  * @details g++ -std=c++11 23_threads_01.cpp -o 23_threads_01
  */
#include <iostream>
#include <vector>
#include <thread>
#include <chrono>

int main() {
    unsigned int total_threads = std::thread::hardware_concurrency();
    std::cout << "threads: " << total_threads << std::endl;
    if(total_threads == 0) {
        std::cout << "unknown number of threads, exit" << std::endl;
        return 1;
    }

    std::cout << "main thread id: " << std::this_thread::get_id() << std::endl;

    std::vector<std::thread> threads;

    for(unsigned int i = 0; i < total_threads; ++i) {
        threads.push_back(std::thread([i]() {
            std::cout << "thread id: " << std::this_thread::get_id() << " started" << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(i));
            std::cout << "thread id: " << std::this_thread::get_id() << " finished" << std::endl;
        }));
    }
    for(unsigned int i = 0; i < total_threads; ++i) {
        threads[i].join();
    }
    return 0;
}
```

## Problema partajării datelor între fire

Una dintre problemele programării paralele este accesul concurent la memorie. Dacă două fire accesează aceeași zonă de memorie, pot apărea conflicte, modificând valorile stocate. Situația în care rezultatul depinde de ordinea execuției firelor se numește __condiție de cursă__ (race condition).

Soluții pentru această problemă:

- protejarea structurii de date cu un mecanism care garantează accesul exclusiv;
- rescrierea structurii de date pentru a elimina nevoia de blocare (programare lock-free).

### Mutex

__Mutexul__ (din engleză mutual exclusion) este un obiect simplu (primitiv de sincronizare) care marchează secțiuni de cod pentru a preveni condițiile de cursă.

Mutexul este declarat în `<mutex>` ca `std::mutex`. Blocarea/deblocarea se face cu `lock`/`unlock`, dar se recomandă folosirea clasei `std::lock_guard`, care blochează mutexul la creare și îl deblochează la distrugere.

```cpp
/**
  * @file mutex_example.cpp
  * @brief Exemplu de utilizare a unui mutex
  * @details g++ -std=c++11 mutex_example.cpp -o mutex_example
  */
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

> [!NOTE]
> `std::lock_guard` folosește principiul RAII și deblochează mutexul automat la ieșirea din blocul de cod.

### Variabile și operații atomice

O operație este __atomică__ dacă nu poate fi întreruptă: se execută complet sau deloc. O operație atomică poate fi efectuată de un singur fir la un moment dat.

Atomicitatea poate fi asigurată hardware (prin instrucțiuni speciale garantate de procesor) sau software (prin mecanisme de sincronizare care blochează resursa). _Blocarea este o operație atomică_.

__Tipul atomic__ este un tip de date pentru care operațiile sunt atomice.

Tipurile atomice standard sunt definite în `<atomic>`.

Exemplu de utilizare a unui tip atomic:

```cpp
#include <atomic>
#include <thread>
#include <iostream>

std::atomic<int> counter{0};

void increment() {
    for (int i = 0; i < 1000; ++i) {
        ++counter;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);
    t1.join();
    t2.join();
    std::cout << counter << std::endl;
    return 0;
}
```

## Programare asincronă

__Programarea asincronă__ este o metodă de organizare a programului în care unele operații nu se execută în ordinea apelării. În loc să aștepte finalizarea unei operații, programul continuă execuția, iar operația se finalizează în fundal.

În C++11 a fost introdusă clasa `std::future`, care permite obținerea rezultatului unei operații asincrone. Clasa `std::future` reprezintă un obiect ce stochează rezultatul unei operații asincrone și oferă metode pentru verificarea finalizării și obținerea rezultatului. Operația asincronă se realizează cu funcția `std::async`, care primește ca parametrii funcția de executat și argumentele acesteia.

```cpp
/**
  * @file async_example.cpp
  * @brief Exemplu de programare asincronă
  * @details g++ -std=c++11 async_example.cpp -o async_example
  */
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

În C++17 au fost adăugate versiuni paralele ale unor algoritmi. Acestea sunt funcții care acceptă ca prim parametru o politică de execuție, de exemplu `std::find`, `std::transform` sau `std::reduce`. Semnătura este aceeași ca la versiunile obișnuite, cu un parametru suplimentar pentru politică.

```cpp
std::vector<int> my_data;
std::sort(std::execution::par, my_data.begin(), my_data.end());
```

Politica `std::execution::par` permite bibliotecii să execute algoritmul în paralel, folosind mai multe fire. Este doar o permisiune, nu o obligație – implementarea poate alege să ruleze tot secvențial.

Politicile de execuție sunt declarate în `<execution>`.

Standardul definește următoarele politici:

- `std::execution::sequenced_policy` cu obiectul `std::execution::seq` – execuție secvențială (fără paralelism).
- `std::execution::parallel_policy` cu obiectul `std::execution::par` – execuție paralelă pe mai multe fire.
- `std::execution::parallel_unsequenced_policy` cu obiectul `std::execution::par_unseq` – execuție paralelă și vectorizată.
- `std::execution::unsequenced_policy` cu obiectul `std::execution::unseq` – execuție neordonată, vectorizată.

Exemplu de utilizare:

```cpp
std::vector<int> vec = {3, 2, 1, 4, 5, 6, 10, 8, 9, 4};

std::sort(vec.begin(), vec.end());                            // secvențial, ca înainte
std::sort(std::execution::seq, vec.begin(), vec.end());       // secvențial
std::sort(std::execution::par, vec.begin(), vec.end());       // paralel
std::sort(std::execution::par_unseq, vec.begin(), vec.end()); // paralel și vectorizat
```

> [!NOTE]
> Suportul pentru politicile de execuție din `<execution>` depinde de implementarea STL și poate fi limitat în unele compilatoare.

## Bibliografie

1. [Concurrency support library, cppreference.com](https://en.cppreference.com/w/cpp/thread)
2. [About Processes and Threads, Microsoft](https://learn.microsoft.com/en-us/windows/win32/procthread/about-processes-and-threads)
3. [MaxRokatansky, Multithreading, habr.com](https://habr.com/ru/companies/otus/articles/549814/)
4. [Multithreading, https://cpp-kt.github.io](https://cpp-kt.github.io/cpp-notes/26_multithreading.html)
5. [Rainer Grimm, Multithreading with C++17 and C++20, moderncpp.com](https://www.modernescpp.com/index.php/multithreading-in-c-17-and-c-20/)
