# Proiect. Sisteme de asamblare a proiectelor

- [Proiect. Sisteme de asamblare a proiectelor](#proiect-sisteme-de-asamblare-a-proiectelor)
  - [Organizarea proiectului](#organizarea-proiectului)
  - [Noțiune de compilare](#noțiune-de-compilare)
  - [Compilarea din linia de comandă](#compilarea-din-linia-de-comandă)
  - [Sisteme de asamblare a proiectelor](#sisteme-de-asamblare-a-proiectelor)
    - [make](#make)
    - [Ninja](#ninja)
    - [Autotools](#autotools)
    - [CMake](#cmake)
  - [Arhitectura fișierului Makefile](#arhitectura-fișierului-makefile)
  - [Exemplu de `Makefile` universal](#exemplu-de-makefile-universal)
  - [Bibliografie](#bibliografie)

## Organizarea proiectului

Proiectul este un ansamblu de fișiere sursă, distribuite într-un anumit mod în directoarele proiectului.

Proiectul poate conține un singur fișier de proiect sau mai multe, pentru construirea unui artefact, numit ținta proiectului, din fișierele sursă. Ținta proiectului poate fi o bibliotecă statică, o bibliotecă dinamică, un fișier executabil sau un ansamblu de biblioteci și fișiere executabile.

Proiectul poate conține mai multe subproiecte. Un subproiect este un ansamblu de fișiere sursă ale altui proiect, adăugate în structura de directoare a proiectului.

Totoadă, proiectul poate conține și module terțe: dependențe externe (de exemplu, biblioteci).

Organizarea codului sursă în proiect poate fi foarte diversă, dar ideea principală este împărțirea:

- codului sursă al proiectului
- subproiectelor
- resurselor proiectului
- modulelor
- rezultatului compilării
- fișierelor temporare
- documentației

cu scopul de a simplifica lucrul cu proiectul.

O structură posibilă a proiectului în stilul UNIX-like:

- `bin` - conține rezultatul compilării proiectului
- `include` - fișierele antet
- `src` - fișierele `cpp`
- `lib` - dependențele externe (biblioteci)
- `obj` - fișiere temporare create în timpul compilării proiectului
- `resources` - resursele utilizate de aplicație (imagini, audio, video, etc.)

Fiecare IDE are propria structură a proiectului.

## Noțiune de compilare

__Compilarea aplicatiei__ - este procesul de transformare a codului sursa al programului in fisierul executabil. In procesul de compilare codul sursa al programului este transformat in fisiere obiect, care sunt apoi legate intr-un fisier executabil.

__Compilatorul__ - este programul care efectueaza transformarea codului sursa al programului în cod masina.

__Fișierul obiect__ - este fișierul care conține codul mașină, derivat de la codul sursă al programului.

Proces de compilare a programului include următoarele etape:

- `prepocesarea` - prelucrarea preliminară a codului sursă al programului, inclusiv directivele preprocesorului. În urma preprocesării în codul sursă al programului pot fi inserate conținutul fișierelor, declarate cu directiva `#include`, de asemenea pot fi eliminate comentariile și procesate directivele preprocesorului;
- `compilarea` - transformarea codului sursă al programului în fișiere obiect. În urma compilării codul sursă al programului este transformat în fișiere obiect, care conțin codul mașină, care va fi executat de procesor;
- `link-editarea` - unirea fișierelor obiect într-un fișier executabil.

## Compilarea din linia de comandă

In realitate nu este necesar să știi cum să compilezi o aplicație din linia de comandă, deoarece mediile de programare moderne vin cu un compilator, iar întregul proces de compilare a aplicației este redus la selectarea unui element de meniu sau apăsarea unei combinații de taste. Cu toate acestea, pentru dezvoltarea generală, este util să știi cum se face acest lucru - cum se compilează o aplicație din fișiere sursă, mai ales că aceasta nu este o situație rară pentru utilizatorii sistemului de operare UNIX-like.

Orice aplicație de tip consolă poate fi pornită cu un set de chei (parametri). Pentru a ști ce chei poate accepta această aplica ție, trebuie să o porniți cu cheia `--help` sau `-h`, în funcție de implementarea aplicației. De exemplu, despre utilizarea compilatorului `GNU C++` puteți afla rulând următoarea comandă:

```shell
g++ --help
```

Pentru a compila un fișier sursă, trebuie să utilizați următoarea comandă:

```shell
g++ main.cpp -o file -l filename
```

În realitate pentru compilarea codului sursă în fișier executabil, la compilator poate fi transmis numai numele fișierului sursă, dar în acest caz compilarea va fi reușită numai dacă programul folosește doar biblioteca standard C/C++, iar fișierul executabil va fi numit `a[.exe]`. Prin urmare, cheia `-o` indică numele fișierului executabil, adică `file`. Cheia `-l` indică că la compilare trebuie să fie adăugată biblioteca de programare. Conform regulilor de conectare a bibliotecilor de programare în sistemul de operare UNIX-like, dacă numele fișierului bibliotecii este `libfilename.a`, atunci pentru a o conecta este suficient să scrieți `-l filename`, sau să specificați numele complet al bibliotecii.

Dacă proiectul aplicației constă din mai multe fișiere sursă, atunci pentru pentru compilarea aplicației trebuie să specificați toate fișierele sursă.

```shell
g++ first.cpp second.cpp main.cpp -o file
```

> [!TIP]
> Fișierele antet nu trebuie să fie specificate la compilare. Compilatorul le va găsi singur.

De obicei în proiectele complexe fiecare fișier sursă se compilează în fișier obiect, iar apoi fișierele obiect se conectează într-un singur fișier executabil. În acest caz, procesul de compilare va fi următorul:

```shell
g++ first.cpp -o first.o -O2 -c -std=c++14
g++ second.cpp -o second.o -O2 -c -std=c++14
g++ main.cpp -o main.o -O2 -c -std=c++14
g++ first.o second.o main.o -o file
```

> [!TIP]
> Enumerarea bibliotecilor utilizate de aplicație se face la etapa de construire a fișierului executabil.

Cele mai des utilizate chei de compilare sunt prezentate în tabel:

| __Cheie__ | __Descriere__ |
| -------- | ------------ |
| `-o`     | specificarea numelui fișierului executabil |
| `-E`     | preprocesarea fișierului sursă |
| `-S`     | compilarea fișierului sursă în fișier asamblor |
| `-c`     | compilarea fișierului sursă în fișier obiect |
| `-g`     | generarea informațiilor de depanare |
| `-O<N>`    | nivelul de optimizare, unde N obține valori de la 0 la 4 |
| `-std=<standard>` | specificarea standardului limbajului C++. Valorile posibile: `c++11`, `c++14`, `c++17`, `c++20`, `c++23` |
| `-l`     | conectarea bibliotecii |
| `-I`     | specificarea căii către fișierele antet |
| `-L`     | specificarea căii către biblioteci |

Compilarea fișierelor sursă în fișiere obiect și link-editarea lor într-un singur fișier executabil devine un proces destul de complicat. Din acest motiv, pentru a simplifica acest proces, se folosesc sisteme de asamblare a proiectelor.

## Sisteme de asamblare a proiectelor

Automatizarea asamblării - este o etapă a procesului de dezvoltare a software-ului, care constă în automatizarea unui set larg de sarcini rezolvate de programatori în activitatea lor de zi cu zi. Acest proces include acțiuni precum:

- compilarea codului sursă în fișiere obiect,
- legarea fișierelor obiect într-un fișier executabil,
- executarea testelor,
- desfășurarea programului în mediul țintă,
- generarea documentației sau descrierea modificărilor noii versiuni,
- configurarea și pregătirea fișierelor pentru asamblare,
- colectarea și transmiterea informației către programul final (versiunea programului, sistemul, compilatorul, informația hardware, informația de sistem, licența programului, numele autorului etc.).

Instrument de bază pentru automatizarea asamblării este `make`, care a definit stilul și metodele pentru instrumentele care au apărut mai târziu. `Make` lucrează cu fișiere `Makefile`. Acest format este acceptat de majoritatea instrumentelor larg utilizate (`Automake`, `CMake`, `imake`, `qmake`, `nmake`, `wmake`, `Apache Ant`, `Apache Maven`, `OpenMake Meister`, `Gradle`).

Cerințele cheie pentru instrumentele de automatizare sunt:

- suportul pentru tehnologiile de integrare continuă, în special pentru compilațiile nocturne,
- gestionarea dependențelor codului sursă,
- asamblarea diferențială,
- notificarea în cazul în care codul sursă (după asamblare) se potrivește cu fișierele binare existente,
- furnizarea de rapoarte convenabile despre rezultatele compilă
- executarea automată a testelor și executarea condiționată în funcție de rezultatele trecerii.

Variantele de automatizare utilizate în diferite instrumente:

- automatizare pe cerere (on-demand automation): rularea unui scenariu de comandă de către utilizator,
- automatizare programată (scheduled automation): integrare continuă care se desfășoară sub formă de compilații nocturne,
- automatizare condiționată (triggered automation): integrare continuă care efectuează o compilație la fiecare confirmare a modificării codului (commit) în sistemul de control al versiunilor.

### make

`make` - este un instrument de automatizare a procesului de compilare a programelor. Cel mai des este folosit pentru compilarea codului sursă în fișiere obiect și legarea lor într-un fișier executabil sau bibliotecă.

`make` utilizează fișierele speciale, de obicei numite `Makefile`, în care sunt definite dependențele între fișiere și regulile de compilare a acestora.

### Ninja

`Ninja` este o utilitate de linie de comandă, un sistem de construire a proiectelor din fișiere sursă. Instrumentul Ninja a fost elaborat de Evan Martin, un angajat al companiei Google.

Ninja prezintă o versiune îmbunătățită și optimizată a utilității `make`. Scopul principal al Ninja este automatizarea și accelerarea procesului de construire a proiectelor, precum și accelerarea recompilării ulterioare, pe baza fișierelor generate de utilitar și soluționarea problemelor tipice în dezvoltarea cross-platform.

### Autotools

`Autotools` este un sistem de construire a proiectelor software GNU, un set de instrumente software destinate suportului portabilității codului sursă între sistemele UNIX-like.

Migrarea codului de pe un sistem pe altul poate fi o sarcină dificilă. Diferite realizări ale compilatorului limbajului C pot diferi semnificativ: anumite funcții ale limbajului pot lipsi, pot avea un alt nume sau pot fi în biblioteci diferite. Programatorul poate rezolva această problemă folosind macro-uri și directive de preprocesor, cum ar fi `#if`, `#ifdef` și altele. Dar în acest caz, utilizatorul care compilează programul pe propriul sistem va trebui să definească toate aceste macro-uri, ceea ce nu este atât de simplu, deoarece există multe distribuții și variații ale sistemelor. Autotools sunt apelate printr-o secvență de comenzi `./configure && make && make install` și rezolvă aceste probleme automat.

Sistem de construire `GNU Autotools` se utilizează larg în multe proiecte cu sursă deschisă. `GNU Autotools` include:

- `Autoconf` - un istrument pentru generarea scripturilor de configurare `configure` pe baza fișierelor `configure.ac` (sau `configure.in`). Scriptul generat este apoi rulat de utilizator, iar scriptul verifică caracteristicile sistemului și creează un `Makefile`.
- `Automake` - citeste fișierele `Makefile.am` și creează un `Makefile` portabil, adică `Makefile.in`, care apoi, după procesarea scriptului de configurare, devine `Makefile` și este utilizat de utilitarul `make`.
- `Libtool` - gestionează crearea bibliotecilor în sistemele de operare similare Unix.

### CMake

`CMake` - este un sistem cross-platform de automatizare a procesului de construire a proiectelor software. Acest instrument de nivel înalt permite utilizatorilor să scrie fișiere de configurare `CMakeLists.txt` independente de platformă, care sunt apoi transformate în fișiere de configurare specifice platformei. Totorodată, `CMake` poate automatiza proces de instalare și configurarea a pachetelor software.

`CMake` se consideră o alternativă mai modernă și mai ușor de utilizat decât `Autotools`, utilizat în comuniteatea GNU.

## Arhitectura fișierului Makefile

Pentru a utiliza sistemul de asamblare `make` este necesar să creați un fișier `Makefile`.

Reguli de creare a fișierului `Makefile` sunt următoarele:

- în fișierul `Makefile` pot fi definite variabile, comenzi și comentarii.
- variabilele sunt de obicei definite la începutul fișierului și sunt definite ca `<nume> = <valoare>`. Variabilele pot fi utilizate în fișierul `Makefile` ca `$(<nume>)`.
- comentariile încep cu simbolul `#` și continuă până la sfârșitul liniei.
- fiecare regulă a fișierului este structurată după modelul

```makefile
<regula> : [<dependența> [...]]
    [<comanda>]
```

- regula poate avea mai multe dependențe sau deloc să nu aibă. Dacă regula are dependențe, atunci mai întâi acestea sunt executate, în ordinea în care sunt enumerate, iar apoi comanda / comenzile regulei.
- fiecare dependență este un alt regulă definită în fișierul `Makefile`.
- comenzile încep cu un tabulator.

Există o practică larg răspândită de a numi regulile din `Makefile` în conformitate cu numele fișierelor pe care le creează. De exemplu, regula pentru crearea fișierului `file` va fi numită `file`.

Un exemplu `Makefile` pentru asamblarea proiectului din trei fișiere `first.cpp`, `second.cpp` și `main.cpp`:

```makefile
all: file

file: first.o second.o main.o
    g++ first.o second.o main.o -o file -love
    
first.o: first.cpp
    g++ -c first.cpp -O2 -std=c++14 -o first.o

second.o: second.cpp
    g++ -c second.cpp -O2 -std=c++14 -o second.o

main.o: main.cpp
    g++ -c main.cpp -O2 -std=c++14 -o main.o
```

Definirea variabilelor în fișierul `Makefile` permite crearea unui `Makefile` mai flexibil. De exemplu, în următorul exemplu, variabilele `CC`, `CXXFLAGS`, `LDFLAGS` și `OUT` sunt definite la începutul fișierului. Variabila `CC` conține numele compilatorului, `CXXFLAGS` - opțiunile de compilare, `LDFLAGS` - opțiunile de legare, `OUT` - numele fișierului executabil.

```makefile
CC = gcc
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++ -love
OUT = file

all: file

file: first.o second.o main.o
    $(CC) first.o second.o main.o -o $(OUT) $(LDFLAGS)
    
first.o: first.cpp
    $(CC) -c first.cpp $(CXXFLAGS) -o first.o

second.o: second.cpp
    $(CC) -c second.cpp $(CXXFLAGS) -o second.o

main.o: main.cpp
    $(CC) -c main.cpp $(CXXFLAGS) -o main.o
```

Exemplu de `Makefile` cu reguli suplimentare:

```makefile
CC = gcc
CXXFLAGS = -O2 -std=c++14
LDFLAGS = -lstdc++ -love
OUT = file

BINDIR = bin
SRCDIR = src
OBJDIR = obj

all: prepare $(OUT)

prepare:
   mkdir -p $(OBJDIR) $(BINDIR)

clean:
   rm -f $(OBJDIR)/*.o $(BINDIR)/*

help:
   @echo Usage:
   echo make - build application
   echo make clean - remove build artifacts
   echo make help - show help

$(OUT): $(OBJDIR)/first.o $(OBJDIR)/second.o $(OBJDIR)/main.o
    $(CC) $(OBJDIR)/first.o $(OBJDIR)/second.o $(OBJDIR)/main.o -o $(BINDIR)/$(OUT) $(LDFLAGS)
    
$(OBJDIR)/first.o:
    $(CC) -c $(SRCDIR)/first.cpp $(CXXFLAGS) -o $(OBJDIR)/first.o

$(OBJDIR)/second.o:
    $(CC) -c $(SRCDIR)/second.cpp $(CXXFLAGS) -o $(OBJDIR)/second.o

$(OBJDIR)/main.o:
    $(CC) -c $(SRCDIR)/main.cpp $(CXXFLAGS) -o $(OBJDIR)/main.o
```

Construirea proiectului se face prin rularea comenzii `make`. În acest caz, prima regulă definită în fișierul `Makefile` va fi executată. Totodata, se poate rula o regulă specifică, specificând numele acesteia ca parametru pentru comanda `make`. De exemplu, pentru a curăța proiectul de fișiere temporare și fișierul executabil, se poate rula comanda `make clean`.

## Exemplu de `Makefile` universal

Presupunem că proiectul constă din mai multe fișiere sursă, distribuite în directoarele proiectului:

- `bin` - conține rezultatul compilării proiectului
- `include` - fișierele antet
- `src` - fișierele `cpp`
- `lib` - dependențele externe (biblioteci)
- `obj` - fișiere temporare create în timpul compilării proiectului

În acest caz, `Makefile` va arăta astfel:

```makefile
CC = g++
CXXFLAGS = -O2 -std=c++20 -I include
LDFLAGS = -L lib

BINDIR = bin
SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

APP = app

all: prepare $(APP)

prepare:
    mkdir -p $(OBJDIR) $(BINDIR)

clean:
    rm -f $(OBJDIR)/*.o $(BINDIR)/*

help:
    @echo Usage:
    echo make - build application
    echo make clean - remove build artifacts
    echo make help - show help

$(APP): $(OBJ)
    $(CC) $(OBJ) -o $(BINDIR)/$(APP) $(LDFLAGS)

$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
    $(CC) -c $< $(CXXFLAGS) -o $@
```

## Bibliografie

1. [GNU make](https://www.gnu.org/software/make/)
2. [Ninja](https://ninja-build.org/)
3. [Autoconf](https://www.gnu.org/savannah-checkouts/gnu/autoconf/manual/autoconf-2.71/autoconf.html)
4. [CMake](https://cmake.org)
