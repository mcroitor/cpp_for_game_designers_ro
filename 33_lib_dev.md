# Crearea bibliotecilor

- [Crearea bibliotecilor](#crearea-bibliotecilor)
  - [Particularități ale creării bibliotecilor](#particularități-ale-creării-bibliotecilor)
  - [Import / export](#import--export)
  - [Construirea bibliotecilor](#construirea-bibliotecilor)
  - [Bibliografie](#bibliografie)

## Particularități ale creării bibliotecilor

Crearea bibliotecilor de programare, în general, seamănă cu dezvoltarea aplicațiilor obișnuite, însă există anumite particularități.

În fișierul header al bibliotecii sunt descrise resursele destinate exportului (adică pentru a fi utilizate de alte programe). Aceste resurse formează interfața bibliotecii (sau API — Application Programming Interface).

Exemplu de fișier header pentru o bibliotecă statică ce lucrează cu numere complexe:

```cpp
#ifndef COMPLEX_H
#define COMPLEX_H

#include <iostream>
#include <string>

class complex {
    double _real, _imaginary;
public:
    complex(double = 0, double = 0);
    complex(const complex&);
    ~complex();

    void operator +=(const complex&);
    void operator -=(const complex&);
    void operator *=(const complex&);
    void operator /=(const complex&);

    complex& operator = (const complex&);
    complex& operator = (const double&);

    const double& real() const;
    const double& imaginary() const;
    void swap(complex&);
    std::string toString() const;
    double mod() const;
    complex conjugate() const;
};

complex operator + (const complex&, const complex&);
complex operator - (const complex&, const complex&);
complex operator * (const complex&, const complex&);
complex operator / (const complex&, const complex&);

std::ostream& operator << (std::ostream&, const complex&);
bool operator == (const complex&, const complex&);

complex pow(const complex&, const complex&);
double abs(const complex&);

#endif /* COMPLEX_H */
```

După cum se poate observa, este o declarație obișnuită de clasă.

Fișierele header pot fi incluse de mai multe ori într-un proiect. Acest lucru poate duce la redefinirea tipurilor de date și variabilelor, ceea ce va genera erori la compilare. De aceea, resursele din fișierele header sunt încadrate între directivele preprocesorului:

```cpp
#ifndef CONSTANT_NAME
#define CONSTANT_NAME

//...

#endif
```

Aceste directive asigură includerea definițiilor o singură dată la preprocesare.

Compilatoarele moderne permit folosirea directivei:

```cpp
#pragma once
```

Aceasta indică compilatorului să includă fișierul o singură dată.

Implementarea resurselor declarate în header se face, ca de obicei, într-un fișier `.cpp`.

```cpp
#include "complex.h"
#include <sstream>
#include <cmath>

complex::complex(double r, double im): _real(r), _imaginary(im) {}
complex::complex(const complex& c): _real(c._real), _imaginary(c._imaginary) {}
complex::~complex() {}

void complex::operator +=(const complex& c) {
    _real += c._real;
    _imaginary += c._imaginary;
}
void complex::operator -=(const complex& c) {
    _real -= c._real;
    _imaginary -= c._imaginary;
}
void complex::operator *=(const complex& c) {
    double real = _real * c._real - _imaginary * c._imaginary;
    double imaginary = _real * c._imaginary + _imaginary * c._real;
    _real = real;
    _imaginary = imaginary;
}
void complex::operator /=(const complex& c) {
    double denominator = c._real * c._real + c._imaginary * c._imaginary;
    double real = (_real * c._real + _imaginary * c._imaginary) / denominator;
    double imaginary = (_imaginary * c._real - _real * c._imaginary) / denominator;
    _real = real;
    _imaginary = imaginary;
}

complex& complex::operator =(const complex& c) {
    _real = c._real;
    _imaginary = c._imaginary;
    return *this;
}
complex& complex::operator =(const double& d) {
    _real = d;
    _imaginary = 0;
    return *this;
}

const double& complex::real() const { return _real; }
const double& complex::imaginary() const { return _imaginary; }
void complex::swap(complex& c) {
    std::swap(_real, c._real);
    std::swap(_imaginary, c._imaginary);
}
std::string complex::toString() const {
    std::ostringstream strcout;
    strcout << _real << " + i*( " << _imaginary << " )";
    return strcout.str();
}
double complex::mod() const {
    return std::sqrt(_real * _real + _imaginary * _imaginary);
}
complex complex::conjugate() const {
    return complex(_real, -_imaginary);
}

// extern class interface
complex operator + (const complex& c1, const complex& c2) {
    complex tmp(c1);
    tmp += c2;
    return tmp;
}
complex operator - (const complex& c1, const complex& c2) {
    complex tmp(c1);
    tmp -= c2;
    return tmp;
}
complex operator * (const complex& c1, const complex& c2) {
    complex tmp(c1);
    tmp *= c2;
    return tmp;
}
complex operator / (const complex& c1, const complex& c2) {
    complex tmp(c1);
    tmp /= c2;
    return tmp;
}

std::ostream& operator << (std::ostream& os, const complex& c) {
    os << c.toString();
    return os;
}
bool operator == (const complex& c1, const complex& c2) {
    return ((c1.real() == c2.real()) && (c1.imaginary() == c2.imaginary()));
}

complex pow(const complex&, const complex&) {
    complex result;
    return result;
}
double abs(const complex& c) {
    return c.mod();
}
```

## Import / export

La dezvoltarea bibliotecilor dinamice, procesul este similar cu cel al bibliotecilor statice, diferența fiind doar la tipul proiectului. Biblioteca poate fi folosită implicit (prin includerea header-ului și specificarea fișierului de import) sau explicit. Pentru a indica ce funcții pot fi accesate din afara bibliotecii, se folosește construcția `__declspec(dllexport)`, care marchează funcția sau clasa ca fiind exportată. Mai jos este un exemplu de fișier header pentru exportul unei clase de numere complexe:

```cpp
#pragma once
#include <iostream>
#include <string>

#define DLLEXPORT __declspec(dllexport)

class DLLEXPORT complex
{
    double _real, _imaginary;
public:
    complex(double = 0, double = 0);
    complex(const complex&);
    ~complex(void);

    complex& operator = (const complex&);
    const double& real() const;
    const double& imaginary() const;
    std::string toString() const;

    void operator += (const complex&);
};

DLLEXPORT bool operator == (const complex&, const complex&);
DLLEXPORT complex operator + (const complex&, const complex&);
DLLEXPORT std::ostream& operator << (std::ostream&, const complex&);
DLLEXPORT int min(int, int);
```

Fișierul de implementare nu necesită modificări.

Clasa astfel exportată poate fi folosită doar în proiecte C++. Pentru a crea biblioteci compatibile cu C, fișierele header trebuie scrise în stil C (fără clase, șabloane sau alte elemente specifice C++). De asemenea, este recomandat să se adauge `extern "C"` în macro-ul `DLLEXPORT` pentru a păstra numele originale ale funcțiilor la compilare (unele compilatoare "manglează" numele funcțiilor și claselor).

Utilizarea unei astfel de biblioteci dinamice nu va fi posibilă în alte limbaje decât C/C++. Acest lucru se datorează faptului că, în Pascal, Basic etc., parametrii funcțiilor sunt transmiși de la stânga la dreapta, pe când în C/C++ — de la dreapta la stânga. Pentru compatibilitate cu aceste limbaje, se folosește modificatorul `__stdcall` (sau echivalentul `__pascal`), care schimbă ordinea transmiterii parametrilor.

În Windows, bibliotecile dinamice pot avea un punct de intrare — funcția `DllMain`:

```cpp
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD  ul_reason_for_call,
                      LPVOID lpReserved)
{
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            // Un proces încarcă DLL-ul.
            break;
        case DLL_THREAD_ATTACH:
            // Un proces creează un nou fir.
            break;
        case DLL_THREAD_DETACH:
            // Un fir se termină normal.
            break;
        case DLL_PROCESS_DETACH:
            // Un proces descarcă DLL-ul.
            break;
    }
    return TRUE;
}
```

## Construirea bibliotecilor

Cel mai simplu mod de a crea o bibliotecă este să alegi tipul de proiect corespunzător în mediul de dezvoltare. Toate IDE-urile moderne oferă proiecte pentru biblioteci statice și dinamice.

Construirea bibliotecilor cu `GNU GCC` se face în două etape:

1. Compilarea fișierelor sursă în fișiere obiect;
2. Legarea fișierelor obiect într-o bibliotecă.

Exemplu de Makefile pentru crearea unei biblioteci:

```makefile
BINDIR = bin # director pentru fișiere binare
SRCDIR = src # director pentru fișiere sursă
OBJDIR = obj # director pentru fișiere obiect
INCDIR = include # director pentru fișiere header
LIBDIR = lib # director pentru biblioteci, inclusiv terțe

# compilator
CC = g++
# opțiuni de compilare
CXXFLAGS = -O2 -std=c++20 -I $(INCDIR)
# opțiuni de linkare
LDFLAGS = -L $(LIBDIR)

# fișiere sursă
SRC = $(wildcard $(SRCDIR)/*.cpp)
# fișiere obiect
OBJ = $(patsubst $(SRCDIR)/%.cpp, $(OBJDIR)/%.o, $(SRC))

# numele bibliotecii
LIB = library

all: prepare $(LIB)-static $(LIB)-shared

static: prepare $(LIB)-static

shared: prepare $(LIB)-shared

prepare:
    mkdir -p $(OBJDIR) $(BINDIR)

clean:
    rm -f $(OBJDIR)/*.o $(BINDIR)/*

help:
    @echo "Usage:"
    @echo "make        - build library"
    @echo "make static - build static library"
    @echo "make shared - build shared library"
    @echo "make clean  - remove build artifacts"
    @echo "make help   - show help"

$(LIB)-shared: $(OBJ)
    $(CC) -shared $(OBJ) -o $(BINDIR)/lib$(LIB).so $(LDFLAGS)

$(LIB)-static: $(OBJ)
    ar rcs $(BINDIR)/lib$(LIB).a $(OBJ)

# compilarea fișierelor sursă
$(OBJDIR)/%.o: $(SRCDIR)/%.cpp
    $(CC) -c $< $(CXXFLAGS) -o $@
```

## Bibliografie

1. [Bibliotecă (programare), Wikipedia](https://ro.wikipedia.org/wiki/Bibliotec%C4%83_(programare))
2. [Crearea bibliotecilor DLL în C și C++ cu Visual Studio, microsoft.com](https://learn.microsoft.com/ro-ro/cpp/build/dlls-in-visual-cpp?view=msvc-170)
3. [dlopen, Linux Manual page](https://www.man7.org/linux/man-pages/man3/dlopen.3.html)
4. [Wheeler David, Dynamically Loaded (DL) Libraries](https://dwheeler.com/program-library/Program-Library-HOWTO/)
