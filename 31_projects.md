# Proiect. Sisteme de build pentru proiecte

- [Proiect. Sisteme de build pentru proiecte](#proiect-sisteme-de-build-pentru-proiecte)
  - [Organizarea proiectului](#organizarea-proiectului)
  - [Noțiunea de compilare](#noțiunea-de-compilare)
  - [Compilare din linia de comandă](#compilare-din-linia-de-comandă)
  - [Sisteme de build pentru proiecte](#sisteme-de-build-pentru-proiecte)
    - [make](#make)
    - [Ninja](#ninja)
    - [Autotools](#autotools)
    - [CMake](#cmake)
  - [Bibliografie](#bibliografie)

## Organizarea proiectului

Un proiect reprezintă ansamblul fișierelor sursă, organizate într-o anumită structură de directoare.

Proiectul poate conține unul sau mai multe fișiere de proiect, pentru a construi din surse un rezultat care poate fi considerat ținta proiectului. Ținta poate fi o bibliotecă statică, o bibliotecă dinamică, un executabil sau o combinație de biblioteci și executabile.

Un proiect poate fi compus din mai multe subproiecte. Un subproiect este un set de surse (și nu numai) ale unui alt proiect, adăugat în structura de directoare a proiectului principal.

De asemenea, proiectul poate include module externe: dependențe externe (de exemplu, biblioteci).

Organizarea codului sursă într-un proiect poate fi foarte variată, însă ideea principală este separarea:

- codului sursă al proiectului
- subproiectelor
- resurselor proiectului
- modulelor
- rezultatului build-ului
- fișierelor temporare
- documentației

pentru a ușura lucrul cu proiectul.

O variantă de structură în stil Linux:

- `bin` - conține rezultatul build-ului proiectului
- `include` - fișiere header
- `src` - fișiere `cpp`
- `lib` - dependențe externe (biblioteci)
- `obj` - fișiere temporare generate în timpul build-ului
- `resources` - resurse folosite de aplicație (imagini, audio, video etc.)

Fiecare IDE poate propune propria structură de proiect.

## Noțiunea de compilare

__Compilarea aplicației__ este procesul de transformare a codului sursă într-un fișier executabil. În timpul compilării, codul sursă este transformat în fișiere obiect, care apoi sunt legate într-un executabil.

__Compilatorul__ este programul care realizează compilarea codului sursă. El transformă codul sursă în fișiere obiect.

__Fișierul obiect__ este un fișier care conține cod mașină echivalent cu codul sursă.

Procesul de compilare include următoarele etape:

- `preprocesare` – prelucrarea inițială a codului sursă, inclusiv directivele preprocesorului. În urma acestei etape, pot fi inserate conținuturi din fișierele incluse cu `#include`, pot fi eliminate comentariile și procesate directivele preprocesorului;
- `compilare` – transformarea codului sursă în fișiere obiect. Rezultatul este cod mașină care va fi executat de procesor;
- `linkare` – combinarea fișierelor obiect într-un executabil.

## Compilare din linia de comandă

Astăzi nu este obligatoriu să știi să compilezi din linia de comandă, deoarece majoritatea mediilor de dezvoltare includ compilatorul și tot procesul de build se rezumă la un click sau o combinație de taste. Totuși, pentru cultura generală este util să știi cum se realizează build-ul unei aplicații din surse, mai ales că această situație nu este rară pentru utilizatorii de Linux.

Orice aplicație de tip consolă poate fi pornită cu o serie de opțiuni (parametri). Pentru a afla ce opțiuni acceptă, se poate apela cu `--help` sau `-h`, în funcție de implementare. De exemplu, pentru a afla opțiunile compilatorului `GNU C++`:

```shell
g++ --help
```

Pentru a compila fișierul `main.cpp` într-un executabil `file[.exe]` este suficient să scrii:

```shell
g++ main.cpp -o file -lfilename
```

Poți încerca să compilezi doar cu numele fișierului, dar compilarea va reuși doar dacă programul folosește doar biblioteca standard C, iar executabilul se va numi `a[.exe]`. Opțiunea `-o` setează numele fișierului rezultat, iar `-l` adaugă o bibliotecă la linkare. În Linux, dacă biblioteca se numește `libfilename.a`, este suficient să scrii `-l filename` sau să indici calea completă.

Poți scrie opțiunea fără spațiu între cheie și valoare:

```shell
g++ main.cpp -ofile
```

Dacă proiectul are mai multe fișiere, poți specifica toate sursele la compilare:

```shell
g++ first.cpp second.cpp main.cpp -o file
```

> [!TIP]
> Fișierele header nu se indică la compilare, deoarece compilatorul le caută automat în directorul proiectului.

Poți compila fiecare fișier separat în obiect, apoi să le legi într-un executabil:

```shell
g++ first.cpp -o first.o -O2 -c -std=c++14
g++ second.cpp -o second.o -O2 -c -std=c++14
g++ main.cpp -o main.o -O2 -c -std=c++14
g++ first.o second.o main.o -o file -love
```

> [!TIP]
> Bibliotecile se specifică la etapa de linkare, nu la compilarea fișierelor sursă.

Cele mai folosite opțiuni de compilare sunt prezentate în tabelul de mai jos:

| __Opțiune__ | __Descriere__ |
| ----------- | ------------- |
| `-o`        | numele fișierului rezultat |
| `-E`        | doar preprocesare |
| `-S`        | compilare în fișier de asamblare |
| `-c`        | compilare în fișier obiect |
| `-g`        | generare de informații de depanare |
| `-O<N>`     | nivel de optimizare, N între 0 și 4 |
| `-std=<standard>` | standardul C++: `c++11`, `c++14`, `c++17`, `c++20`, `c++23` |
| `-l`        | adăugare bibliotecă la linkare |
| `-I`        | cale către fișiere header |
| `-L`        | cale către biblioteci |

Compilarea manuală a fiecărui fișier și linkarea devin rapid obositoare. Pentru automatizare se folosesc sisteme de build.

## Sisteme de build pentru proiecte

Automatizarea build-ului este etapa din dezvoltarea software care presupune automatizarea unui spectru larg de sarcini zilnice ale programatorului.

Include:

- compilarea codului sursă în obiecte,
- linkarea codului binar într-un executabil,
- rularea testelor,
- instalarea aplicației în mediul țintă,
- generarea documentației sau a jurnalului de modificări,
- configurarea și pregătirea fișierelor pentru build,
- colectarea și transmiterea informațiilor către aplicația finală (versiune, sistem, compilator, hardware, licență, autor etc.).

Principalul instrument de automatizare este utilitarul `make`, care a definit stilul și metodele pentru multe alte instrumente apărute ulterior. `make` folosește fișiere `Makefile`. Acest format este suportat de majoritatea instrumentelor moderne (`Automake`, `CMake`, `imake`, `qmake`, `nmake`, `wmake`, `Apache Ant`, `Maven`, `OpenMake Meister`, `Gradle`).

Cerințe cheie pentru instrumentele de automatizare: suport pentru integrare continuă (build-uri de noapte), managementul dependențelor, build incremental, notificări la coincidența codului sursă cu binarele existente, rapoarte clare despre build, rulare automată a testelor și execuție condiționată de rezultatele acestora.

Tipuri de automatizare:

- la cerere (on-demand): rularea manuală a scriptului din linia de comandă,
- programată (scheduled): integrare continuă, de obicei build-uri de noapte,
- condiționată (triggered): build la fiecare commit în sistemul de versionare.

### make

`make` este un utilitar care automatizează transformarea fișierelor dintr-o formă în alta. Cel mai des, compilarea surselor în obiecte și linkarea în executabile sau biblioteci.

Utilitarul folosește fișiere speciale, de obicei numite `Makefile`, unde sunt descrise dependențele și comenzile pentru fiecare transformare.

### Ninja

`Ninja` este un utilitar cross-platform pentru build din linia de comandă, dezvoltat de Evan Martin (Google).

Ninja este o versiune îmbunătățită a lui Make, cu accent pe viteză și build-uri incrementale rapide, utilă în dezvoltarea cross-platform.

### Autotools

`Autotools` este sistemul de build GNU, un set de instrumente pentru portabilitatea codului între sisteme UNIX-like.

Portarea codului poate fi dificilă din cauza diferențelor între compilatoare și biblioteci. Autotools rezolvă aceste probleme automat, fiind apelat cu `./configure && make && make install`.

Autotools include:

- `Autoconf` – generează scriptul `configure` pe baza fișierului `configure.ac` sau `configure.in`, care detectează particularitățile sistemului și creează `Makefile`.
- `Automake` – citește `Makefile.am` și creează un `Makefile.in` portabil, care devine `Makefile` după rularea scriptului de configurare.
- `Libtool` – gestionează crearea bibliotecilor pe sisteme Unix-like.

### CMake

`CMake` este un sistem de build cross-platform care generează fișiere de build pentru diverse platforme și compilatoare, pe baza unui fișier `CMakeLists.txt` unde sunt descrise dependențele și regulile de build.

CMake permite gestionarea ușoară a dependențelor și suportă diverse configurații (Debug, Release).

Dacă proiectul `MyProject` are structura:

- `bin` – rezultatul build-ului
- `include` – fișiere header
- `src` – fișiere cpp
- `lib` – biblioteci externe
- `obj` – fișiere temporare

și următoarele cerințe:

- standard C++20
- folosește biblioteca `liblove`
- folosește biblioteca `libmath`
- executabilul se numește `app`

atunci `CMakeLists.txt` va arăta astfel:

```cmake
cmake_minimum_required(VERSION 3.10)
project(MyProject)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include) # Calea către fișierele header
link_directories(lib)        # Calea către biblioteci externe (doar dacă este necesar)

file(GLOB SOURCES "src/*.cpp") # Adună automat toate fișierele .cpp din src
add_executable(app ${SOURCES})

target_link_libraries(app love math) # Leagă bibliotecile
```

> [!TIP]
> Dacă vrei ca executabilul să fie plasat în folderul `bin`, adaugă linia:
>
> ```cmake
> set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
> ```

Build-ul proiectului cu `CMake` se face astfel:

```bash
# Creează directorul de build
mkdir build
# Intră în directorul de build
cd build
# Generează fișierele de build
cmake ..
# Compilează proiectul
cmake --build .
```

## Bibliografie

1. [GNU make](https://www.gnu.org/software/make/)
2. [Ninja](https://ninja-build.org/)
3. [Autoconf](https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.71/autoconf.html)
4. [CMake](https://cmake.org)
