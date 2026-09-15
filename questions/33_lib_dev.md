# Intrebari la tema Crearea bibliotecilor

## Cunostinte

Intrebari legate de cunostintele necesare pentru implementarea temei. Sunt de tip Single Choice, alegerea unei singure variante corecte din patru posibile. Total 20 intrebari.

1. Ce reprezintă API-ul unei biblioteci?
   - [x] interfața bibliotecii cu resursele destinate exportului
   - [ ] codul sursă al bibliotecii
   - [ ] fișierele obiect ale bibliotecii
   - [ ] documentația bibliotecii

2. Ce directivă modernă permite includerea unui header o singură dată?
   - [x] #pragma once
   - [ ] #ifndef
   - [ ] #include_once
   - [ ] #define_once

3. Ce construcție se folosește pentru a marca o funcție ca fiind exportată într-o DLL Windows?
   - [x] __declspec(dllexport)
   - [ ] __export
   - [ ] dllexport
   - [ ] export

4. În ce ordine sunt transmiși parametrii funcțiilor în C/C++?
   - [x] de la dreapta la stânga
   - [ ] de la stânga la dreapta
   - [ ] aleatoriu
   - [ ] depinde de compilator

5. Ce modificator se folosește pentru compatibilitate cu Pascal și Basic?
   - [x] __stdcall
   - [ ] __cdecl
   - [ ] __fastcall
   - [ ] __thiscall

6. Cum se numește funcția punct de intrare a unei DLL Windows?
   - [x] DllMain
   - [ ] main
   - [ ] WinMain
   - [ ] DllEntry

7. Ce parametru primește funcția `DllMain` care indică motivul apelului?
   - [x] ul_reason_for_call
   - [ ] reason
   - [ ] call_type
   - [ ] event_type

8. Ce constantă indică că un proces încarcă DLL-ul?
   - [x] DLL_PROCESS_ATTACH
   - [ ] DLL_LOAD
   - [ ] DLL_ATTACH
   - [ ] PROCESS_ATTACH

9. Ce constantă indică că un proces descarcă DLL-ul?
   - [x] DLL_PROCESS_DETACH
   - [ ] DLL_UNLOAD
   - [ ] DLL_DETACH
   - [ ] PROCESS_DETACH

10. Ce comandă Unix/Linux se folosește pentru a crea o bibliotecă statică?
    - [x] ar
    - [ ] ld
    - [ ] gcc
    - [ ] make

11. Ce opțiune g++ se folosește pentru a crea o bibliotecă dinamică?
    - [x] -shared
    - [ ] -dynamic
    - [ ] -dll
    - [ ] -so

12. Ce prefix este standard pentru bibliotecile Unix/Linux?
    - [x] lib
    - [ ] dll
    - [ ] so
    - [ ] bin

13. De ce sunt necesare directivele `#ifndef` și `#define` în fișierele header?
    - [x] pentru a preveni includerea multiplă și redefinirea tipurilor
    - [ ] pentru a optimiza codul
    - [ ] pentru a crea macro-uri
    - [ ] pentru compatibilitate cu C

14. Ce tip de proiect trebuie ales în IDE pentru a crea o bibliotecă dinamică?
    - [x] Dynamic Library sau DLL
    - [ ] Console Application
    - [ ] Static Library
    - [ ] Windows Application

15. Ce comandă ar (archiver) creează o bibliotecă statică?
    - [x] ar rcs
    - [ ] ar create
    - [ ] ar make
    - [ ] ar build

16. În ce fișier se descriu resursele destinate exportului?
    - [x] în fișierul header
    - [ ] în fișierul cpp
    - [ ] în Makefile
    - [ ] în fișierul de configurare

17. Ce specificator se poate adăuga la `extern "C"` pentru a păstra numele originale ale funcțiilor?
    - [x] acest lucru este făcut automat de extern "C"
    - [ ] __keepname
    - [ ] __original
    - [ ] __noMangle

18. Câte etape are construirea unei biblioteci cu GNU GCC?
    - [x] două (compilare și legare)
    - [ ] una (doar compilare)
    - [ ] trei (compilare, legare și arhivare)
    - [ ] patru (preprocesare, compilare, legare, arhivare)

19. Ce extensie au fișierele obiect în Unix/Linux?
    - [x] .o
    - [ ] .obj
    - [ ] .a
    - [ ] .so

20. Unde se plasează de obicei fișierele header ale bibliotecii în proiect?
    - [x] în directorul include sau un subdirector dedicat
    - [ ] în directorul src
    - [ ] în directorul bin
    - [ ] în directorul lib

## Utilizare

Intrebari legate de utilizarea corecta a temei. Sunt de tip Short Answer, unde studentul trebuie sa scrie un raspuns scurt. Total 10 intrebari.

1. Scrieți directiva preprocesor pentru a preveni includerea multiplă a unui header (folosind convenția cu MYHEADER_H):
   - #ifndef MYHEADER_H
   - #define MYHEADER_H
   - ...
   - #endif

2. Scrieți directiva modernă pentru a preveni includerea multiplă:
   - #pragma once

3. Scrieți macro-ul pentru a exporta o funcție dintr-o DLL Windows:
   - #define DLLEXPORT __declspec(dllexport)

4. Scrieți declarația unei funcții exportate `int Add(int, int)` folosind macro-ul DLLEXPORT:
   - DLLEXPORT int Add(int, int);

5. Scrieți comanda g++ pentru a compila `mylib.cpp` în fișier obiect `mylib.o`:
   - g++ -c mylib.cpp -o mylib.o

6. Scrieți comanda pentru a crea biblioteca statică `libmylib.a` din fișierele obiect `file1.o` și `file2.o`:
   - ar rcs libmylib.a file1.o file2.o

7. Scrieți comanda g++ pentru a crea biblioteca dinamică `libmylib.so` din fișierul obiect `mylib.o`:
   - g++ -shared mylib.o -o libmylib.so

8. Scrieți semnătura funcției `DllMain`:
   - BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)

9. Scrieți directiva pentru a declara o funcție cu legare C (pentru evitarea name mangling):
   - extern "C"

10. Scrieți declarația unei funcții exportate compatibile cu C: `int Calculate(int a, int b)`:
    - extern "C" DLLEXPORT int Calculate(int a, int b);
    - extern "C" __declspec(dllexport) int Calculate(int a, int b);

## Integrare

Intrebari legate de integrarea temei cu alte teme. Sunt de tip Long Answer (Essay) unde studentul trebuie sa scrie un cod (program sau implementare functie, clasa etc). Total 5 intrebari.

1. Scrieți un fișier header `mathlib.h` pentru o bibliotecă care exportă funcțiile `int Add(int, int)` și `int Multiply(int, int)`. Folosiți protecție împotriva includerii multiple cu `#ifndef`.
   - ```cpp
     #ifndef MATHLIB_H
     #define MATHLIB_H

     int Add(int a, int b);
     int Multiply(int a, int b);

     #endif /* MATHLIB_H */
     ```

2. Scrieți fișierul de implementare `mathlib.cpp` pentru biblioteca de la întrebarea anterioară.
   - ```cpp
     #include "mathlib.h"

     int Add(int a, int b) {
         return a + b;
     }

     int Multiply(int a, int b) {
         return a * b;
     }
     ```

3. Scrieți un Makefile simplu pentru a crea biblioteca statică `libmathlib.a` din fișierul `mathlib.cpp`. Includeți și o țintă `clean`.
   - ```makefile
     CC = g++
     CXXFLAGS = -std=c++17 -O2

     all: libmathlib.a

     mathlib.o: mathlib.cpp mathlib.h
     	$(CC) $(CXXFLAGS) -c mathlib.cpp -o mathlib.o

     libmathlib.a: mathlib.o
     	ar rcs libmathlib.a mathlib.o

     clean:
     	rm -f mathlib.o libmathlib.a
     ```

4. Scrieți un fișier header `calculator.h` pentru o DLL Windows care exportă o clasă `Calculator` cu metodele `int add(int, int)` și `int subtract(int, int)`. Folosiți macro DLLEXPORT.
   - ```cpp
     #pragma once

     #define DLLEXPORT __declspec(dllexport)

     class DLLEXPORT Calculator {
     public:
         Calculator();
         ~Calculator();
         
         int add(int a, int b);
         int subtract(int a, int b);
     };
     ```

5. Scrieți implementarea funcției `DllMain` care afișează mesaje la consolă pentru fiecare tip de eveniment (PROCESS_ATTACH, PROCESS_DETACH, THREAD_ATTACH, THREAD_DETACH).
   - ```cpp
     #include <windows.h>
     #include <iostream>

     BOOL APIENTRY DllMain(HMODULE hModule,
                           DWORD ul_reason_for_call,
                           LPVOID lpReserved)
     {
         switch (ul_reason_for_call) {
             case DLL_PROCESS_ATTACH:
                 std::cout << "DLL: Process attaching" << std::endl;
                 break;
             case DLL_THREAD_ATTACH:
                 std::cout << "DLL: Thread attaching" << std::endl;
                 break;
             case DLL_THREAD_DETACH:
                 std::cout << "DLL: Thread detaching" << std::endl;
                 break;
             case DLL_PROCESS_DETACH:
                 std::cout << "DLL: Process detaching" << std::endl;
                 break;
         }
         return TRUE;
     }
     ```
