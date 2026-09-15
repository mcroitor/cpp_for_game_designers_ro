# Intrebari la tema Utilizarea bibliotecilor terțe

## Cunostinte

Intrebari legate de cunostintele necesare pentru implementarea temei. Sunt de tip Single Choice, alegerea unei singure variante corecte din patru posibile. Total 20 intrebari.

1. Câte fișiere conțin de obicei o bibliotecă statică?
   - [x] două (header și fișier binar)
   - [ ] unul (doar header)
   - [ ] trei (header, dll și lib)
   - [ ] patru (header, lib, dll și so)

2. Ce extensie are o bibliotecă statică în sistemele Unix?
   - [x] .a
   - [ ] .lib
   - [ ] .so
   - [ ] .dll

3. Ce extensie are o bibliotecă dinamică în Windows?
   - [x] .dll
   - [ ] .so
   - [ ] .lib
   - [ ] .a

4. Câte fișiere conțin de obicei o bibliotecă dinamică în Windows?
   - [x] trei (header, dll și lib de import)
   - [ ] două (header și dll)
   - [ ] unul (doar dll)
   - [ ] patru (header, dll, lib și so)

5. Unde se găsesc de obicei fișierele header ale bibliotecilor?
   - [x] în folderul INCLUDE al compilatorului
   - [ ] în folderul LIB al compilatorului
   - [ ] în c:\Windows\System32
   - [ ] în directorul de lucru

6. Ce tip de legare are loc când biblioteca este încărcată în memorie înainte de lansarea aplicației?
   - [x] legare implicită
   - [ ] legare explicită
   - [ ] legare statică
   - [ ] legare dinamică

7. Ce funcție Windows încarcă o bibliotecă dinamică în memorie?
   - [x] LoadLibrary
   - [ ] GetProcAddress
   - [ ] FreeLibrary
   - [ ] LoadDLL

8. Ce funcție Unix încarcă o bibliotecă dinamică în memorie?
   - [x] dlopen
   - [ ] dlsym
   - [ ] dlclose
   - [ ] loadlib

9. Ce parametru compilatorului g++ specifică calea către fișierele header?
   - [x] -I
   - [ ] -L
   - [ ] -l
   - [ ] -H

10. Ce parametru compilatorului g++ specifică calea către biblioteci?
    - [x] -L
    - [ ] -I
    - [ ] -l
    - [ ] -P

11. Ce parametru compilatorului g++ specifică numele bibliotecii de legat?
    - [x] -l
    - [ ] -L
    - [ ] -I
    - [ ] -lib

12. Ce funcție Windows obține adresa unei funcții din bibliotecă?
    - [x] GetProcAddress
    - [ ] LoadLibrary
    - [ ] FreeLibrary
    - [ ] GetFunction

13. Ce funcție Unix obține adresa unei funcții din bibliotecă?
    - [x] dlsym
    - [ ] dlopen
    - [ ] dlclose
    - [ ] getproc

14. Ce avantaj au bibliotecile statice?
    - [x] portabilitate mare, fără dependențe externe
    - [ ] dimensiune executabil mai mică
    - [ ] memorie mai puțin ocupată
    - [ ] actualizare mai ușoară

15. Ce avantaj au bibliotecile dinamice?
    - [x] dimensiune executabil mai mică
    - [ ] portabilitate mai mare
    - [ ] viteză de execuție mai mare
    - [ ] fără dependențe externe

16. În ce folder se găsesc de obicei bibliotecile dinamice în Windows?
    - [x] c:\Windows\System32
    - [ ] c:\Program Files
    - [ ] c:\Windows
    - [ ] c:\Libs

17. Ce se întâmplă dacă lipsește o bibliotecă dinamică legată implicit la pornirea aplicației?
    - [x] aplicația se oprește cu eroare
    - [ ] aplicația pornește normal
    - [ ] aplicația folosește o bibliotecă alternativă
    - [ ] se afișează un avertisment

18. Ce antet trebuie inclus pentru legarea explicită în Windows?
    - [x] windows.h
    - [ ] dll.h
    - [ ] library.h
    - [ ] loadlib.h

19. Ce antet trebuie inclus pentru legarea explicită în Unix?
    - [x] dlfcn.h
    - [ ] dl.h
    - [ ] unix.h
    - [ ] library.h

20. Ce funcție Windows eliberează o bibliotecă din memorie?
    - [x] FreeLibrary
    - [ ] UnloadLibrary
    - [ ] CloseLibrary
    - [ ] ReleaseLibrary

## Utilizare

Intrebari legate de utilizarea corecta a temei. Sunt de tip Short Answer, unde studentul trebuie sa scrie un raspuns scurt. Total 10 intrebari.

1. Scrieți numele complet al unui fișier bibliotecă statică pentru biblioteca `Math` în Unix (folosind convenția Gnu C++):
   - libMath.a

2. Scrieți comanda g++ pentru a compila `main.cpp` cu biblioteca statică `MyLib` aflată în folderul `/usr/local/lib`:
   - g++ -o main main.cpp -L/usr/local/lib -lMyLib

3. Scrieți directiva de preprocesare pentru a include header-ul `MyLib.h`:
   - #include "MyLib.h"
   - #include <MyLib.h>

4. Scrieți apelul funcției Windows pentru a încărca biblioteca `MyLib.dll`:
   - LoadLibrary("MyLib.dll")

5. Scrieți apelul funcției Unix pentru a încărca biblioteca `libMyLib.so`:
   - dlopen("libMyLib.so", RTLD_LAZY)
   - dlopen("libMyLib.so", RTLD_NOW)

6. Scrieți declarația unui pointer la funcție care returnează `int` și primește doi parametri `int`:
   - int (*funcPtr)(int, int);

7. Scrieți apelul funcției Windows pentru a obține adresa funcției `Add` din biblioteca încărcată `hLib`:
   - GetProcAddress(hLib, "Add")

8. Scrieți apelul funcției Unix pentru a obține adresa funcției `Add` din biblioteca încărcată `hLib`:
   - dlsym(hLib, "Add")

9. Scrieți apelul funcției Windows pentru a elibera biblioteca `hLib`:
   - FreeLibrary(hLib)

10. Scrieți apelul funcției Unix pentru a elibera biblioteca `hLib`:
    - dlclose(hLib)

## Integrare

Intrebari legate de integrarea temei cu alte teme. Sunt de tip Long Answer (Essay) unde studentul trebuie sa scrie un cod (program sau implementare functie, clasa etc). Total 5 intrebari.

1. Scrieți un program C++ care încarcă explicit o bibliotecă dinamică în Windows (`MyMath.dll`) și apelează funcția `int Multiply(int, int)` pentru a calcula 5 * 7.
   - ```cpp
     #include <windows.h>
     #include <iostream>

     typedef int (*pOperation)(int, int);

     int main() {
         HINSTANCE hLib = LoadLibrary("MyMath.dll");
         if (hLib == nullptr) {
             std::cerr << "Eroare la încărcarea bibliotecii" << std::endl;
             return 1;
         }

         pOperation Multiply = (pOperation)GetProcAddress(hLib, "Multiply");
         if (Multiply == nullptr) {
             std::cerr << "Eroare la încărcarea funcției" << std::endl;
             FreeLibrary(hLib);
             return 1;
         }

         std::cout << "5 * 7 = " << Multiply(5, 7) << std::endl;

         FreeLibrary(hLib);
         return 0;
     }
     ```

2. Scrieți un program C++ care încarcă explicit o bibliotecă dinamică în Unix (`libMyMath.so`) și apelează funcția `double Divide(double, double)` pentru a calcula 10.0 / 3.0.
   - ```cpp
     #include <dlfcn.h>
     #include <iostream>

     typedef double (*pOperation)(double, double);

     int main() {
         void* hLib = dlopen("libMyMath.so", RTLD_LAZY);
         if (hLib == nullptr) {
             std::cerr << "Eroare: " << dlerror() << std::endl;
             return 1;
         }

         pOperation Divide = (pOperation)dlsym(hLib, "Divide");
         char* error = dlerror();
         if (error != nullptr) {
             std::cerr << "Eroare: " << error << std::endl;
             dlclose(hLib);
             return 1;
         }

         std::cout << "10.0 / 3.0 = " << Divide(10.0, 3.0) << std::endl;

         dlclose(hLib);
         return 0;
     }
     ```

3. Scrieți un Makefile simplu pentru a compila un program `main.cpp` care folosește biblioteca statică `libUtils.a` aflată în folderul curent.
   - ```makefile
     CXX = g++
     CXXFLAGS = -std=c++17 -Wall
     LDFLAGS = -L. -lUtils

     main: main.cpp
     	$(CXX) $(CXXFLAGS) -o main main.cpp $(LDFLAGS)

     clean:
     	rm -f main
     ```

4. Scrieți un program C++ care verifică dacă o bibliotecă dinamică `MyLib.dll` (Windows) poate fi încărcată. Dacă da, afișați mesaj de succes și eliberați biblioteca. Dacă nu, afișați mesaj de eroare.
   - ```cpp
     #include <windows.h>
     #include <iostream>

     int main() {
         HINSTANCE hLib = LoadLibrary("MyLib.dll");
         
         if (hLib != nullptr) {
             std::cout << "Biblioteca MyLib.dll a fost încărcată cu succes" << std::endl;
             FreeLibrary(hLib);
             return 0;
         } else {
             std::cerr << "Eroare: Nu s-a putut încărca biblioteca MyLib.dll" << std::endl;
             std::cerr << "Cod eroare: " << GetLastError() << std::endl;
             return 1;
         }
     }
     ```

5. Scrieți un program C++ care încarcă explicit biblioteca `libGame.so` (Unix) și încearcă să apeleze funcția `void InitGame()`. Dacă biblioteca sau funcția nu pot fi încărcate, afișați mesaje de eroare detaliate folosind `dlerror()`.
   - ```cpp
     #include <dlfcn.h>
     #include <iostream>

     typedef void (*pInitFunc)();

     int main() {
         // Resetăm eventualele erori anterioare
         dlerror();
         
         void* hLib = dlopen("libGame.so", RTLD_LAZY);
         if (hLib == nullptr) {
             std::cerr << "Eroare la încărcarea bibliotecii: " << dlerror() << std::endl;
             return 1;
         }

         std::cout << "Biblioteca încărcată cu succes" << std::endl;

         // Resetăm eroarea înainte de dlsym
         dlerror();
         
         pInitFunc InitGame = (pInitFunc)dlsym(hLib, "InitGame");
         char* error = dlerror();
         if (error != nullptr) {
             std::cerr << "Eroare la încărcarea funcției: " << error << std::endl;
             dlclose(hLib);
             return 1;
         }

         std::cout << "Funcția InitGame încărcată cu succes" << std::endl;
         InitGame();
         std::cout << "InitGame() executată" << std::endl;

         dlclose(hLib);
         return 0;
     }
     ```
