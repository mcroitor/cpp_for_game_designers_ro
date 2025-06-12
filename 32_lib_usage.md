# Utilizarea bibliotecilor terțe

- [Utilizarea bibliotecilor terțe](#utilizarea-bibliotecilor-terțe)
  - [Biblioteca de programare](#biblioteca-de-programare)
  - [Utilizarea bibliotecilor statice](#utilizarea-bibliotecilor-statice)
    - [Exemplu de utilizare a unei biblioteci statice](#exemplu-de-utilizare-a-unei-biblioteci-statice)
  - [Utilizarea bibliotecilor dinamice](#utilizarea-bibliotecilor-dinamice)
    - [Legare implicită](#legare-implicită)
    - [Legare explicită](#legare-explicită)
  - [Bibliografie](#bibliografie)

## Biblioteca de programare

Prin __bibliotecă de programare__ se înțelege un ansamblu de resurse software, precum funcții, clase, obiecte, constante și diverse variabile. De exemplu, constantele pot reprezenta date grafice sau multimedia. Bibliotecile de programare se împart în trei tipuri: __statice__, __dinamice__ și __biblioteci de șabloane__.

Bibliotecile statice sunt reprezentate de două fișiere:

1. Un fișier header cu extensia `h` (`hxx`, `hpp`), care descrie interfața bibliotecii;
2. Un fișier binar cu extensia `lib` (în Windows) sau `a` (în sistemele Unix), care conține toate resursele software sub formă de cod obiect.

Bibliotecile dinamice sunt reprezentate de trei fișiere:

1. Un fișier header cu extensia `h` (`hxx`, `hpp`), care descrie interfața bibliotecii;
2. Un fișier binar cu extensia `dll` (în Windows) sau `so` (în sistemele Unix), numit bibliotecă dinamică (sau partajată în Unix), care conține toate resursele software sub formă de cod binar;
3. Un fișier cu extensia `lib` (în Windows) sau `a` (în Unix), numit bibliotecă de import, care conține informații despre locația resurselor din biblioteca dinamică. În Unix, biblioteca de import nu este folosită.

Există și un tip special de biblioteci care nu pot fi distribuite decât sub formă de cod sursă – biblioteci ce conțin șabloane de clase și funcții. Acestea sunt livrate sub formă de fișiere header.

Denumirea fișierelor pentru bibliotecile de programare în Gnu C++ (g++) este:

- fișier header: `<nume_bibliotecă>.h` sau `<nume_bibliotecă>.hpp`;
- bibliotecă statică: `lib<nume_bibliotecă>.a` (Unix) sau `<nume_bibliotecă>.lib` (Windows);
- bibliotecă dinamică: `<nume_bibliotecă>.so` (Unix) sau `<nume_bibliotecă>.dll` (Windows).

Fișierele header se găsesc de obicei în folderul `INCLUDE` al compilatorului, bibliotecile statice și de import – în folderul `LIB`, iar bibliotecile dinamice – în folderele de sistem (`c:\Windows\System32` sau `/usr/bin`). Aceste căi pot fi suprascrise în program sau la compilare.

Fiecare tip de bibliotecă are avantaje și dezavantaje. De exemplu, utilizarea bibliotecilor statice crește portabilitatea programelor, deoarece nu depind de module externe, însă dimensiunea executabilului crește. Utilizarea bibliotecilor dinamice permite crearea unor programe mai mici, dar la rulare acestea ocupă memorie suplimentară pentru biblioteca dinamică.

## Utilizarea bibliotecilor statice

La utilizarea funcțiilor (claselor sau altor resurse) din biblioteci statice, la compilare, compilatorul include doar codul obiect al resurselor folosite. Astfel, chiar dacă biblioteca are câțiva megabytes, programul rezultat crește doar cu câteva zeci de kilobytes (în funcție de funcțiile folosite).

Pentru a utiliza o bibliotecă statică într-un program, trebuie să:

1. Includeți fișierul header al bibliotecii în program;
2. La compilare, specificați calea către bibliotecă în parametrii compilatorului.

În acest caz, compilatorul include doar codul obiect al funcțiilor folosite, proces numit __legare statică__.

### Exemplu de utilizare a unei biblioteci statice

Presupunem că avem biblioteca statică __MyMath__, cu următoarele fișiere:

1. `MyMath.h` – fișierul header;
2. `libMyMath.a` – arhiva binară a bibliotecii.

Biblioteca se află în folderul `C:\MyLibs\MyMath`. Pentru a o folosi:

1. Includeți fișierul header în program:

   ```cpp
   #include "MyMath.h"
   ```

2. La compilare, specificați calea către bibliotecă:

   ```bash
   g++ -o MyProgram.exe MyProgram.cpp -IC:\\MyLibs\\MyMath -LC:\\MyLibs\\MyMath -lMyMath
   ```

Aici, `-I` indică calea către fișierele header, `-L` către biblioteci, iar `-l` numele bibliotecii. Căile pot fi absolute sau relative.

## Utilizarea bibliotecilor dinamice

Bibliotecile dinamice pot fi folosite în două moduri:

- Legare implicită;
- Legare explicită.

### Legare implicită

__Legarea implicită__ a unei biblioteci cu aplicația are loc la includerea header-ului și la specificarea bibliotecii în proprietățile proiectului. Biblioteca este încărcată în memorie înainte de lansarea aplicației. La pornire, sistemul de operare caută bibliotecile dinamice asociate programului în căile de sistem, în directorul curent sau în memorie. Dacă lipsește o bibliotecă, aplicația se oprește cu eroare.

La compilare, codul executabil crește cu câțiva bytes, deoarece în locul codului funcției din biblioteca dinamică se inserează un apel către acea funcție, declarat în biblioteca de import.

### Legare explicită

Bibliotecile dinamice pot fi încărcate și la cerere, în timpul execuției programului.

__Legarea explicită__ se face cu funcția `LoadLibrary` (`dlopen` în Unix), care încarcă biblioteca la momentul apelului. Astfel, aplicația poate funcționa fără bibliotecă până la momentul încărcării acesteia.

În Windows, pentru legare explicită se folosesc funcțiile din `windows.h`:

- `LoadLibrary` — încarcă biblioteca dinamică în memorie;
- `GetProcAddress` — obține adresa unei funcții din bibliotecă;
- `FreeLibrary` — eliberează biblioteca din memorie;
- `GetModuleHandle` — obține descriptorul bibliotecii.

În Unix, pentru legare explicită se folosesc funcțiile din `dlfcn.h`:

- `dlopen` — încarcă biblioteca dinamică în memorie;
- `dlsym` — obține adresa unei funcții din bibliotecă;
- `dlclose` — eliberează biblioteca din memorie.

Dacă există biblioteca dinamică `MyMath.dll` cu funcția `int Add(int, int)`, în Windows legarea explicită se face astfel:

```cpp
/**
 * @file dll_load_example.cpp
 * @brief Exemplu de legare explicită a unei biblioteci dinamice, Windows
 * @details g++ dll_load_example.cpp -o dll_load_example.exe
 */
#include <windows.h>
#include <iostream>

typedef int (*pOperation)(int, int);

int main()
{
    HINSTANCE hLib = LoadLibrary("MyMath.dll");
    if (hLib == nullptr)
    {
        std::cerr << "Eroare la încărcarea bibliotecii" << std::endl;
        return 1;
    }

    pOperation Add = (pOperation)GetProcAddress(hLib, "Add");
    if (Add == nullptr)
    {
        std::cerr << "Eroare la încărcarea funcției" << std::endl;
        return 1;
    }

    std::cout << Add(2, 3) << std::endl;

    FreeLibrary(hLib);
    return 0;
}
```

În Unix, legarea explicită se face astfel:

```cpp
/**
 * @file dl_load_example.cpp
 * @brief Exemplu de legare explicită a unei biblioteci dinamice, Unix
 * @details g++ dl_load_example.cpp -o dl_load_example -ldl
 */
#include <dlfcn.h>
#include <iostream>

typedef int (*pOperation)(int, int);

int main()
{
    void* hLib = dlopen("MyMath.so", RTLD_LAZY);
    if (hLib == nullptr)
    {
        std::cerr << "Eroare la încărcarea bibliotecii" << std::endl;
        return 1;
    }

    pOperation Add = (pOperation)dlsym(hLib, "Add");
    if (Add == nullptr)
    {
        char* error = dlerror();
        if (error != nullptr) {
            std::cerr << "Eroare la dlsym: " << error << std::endl;
            dlclose(hLib);
            return 1;
        }
    }

    std::cout << Add(2, 3) << std::endl;

    dlclose(hLib);
    return 0;
}
```

## Bibliografie

1. [Library (computing), Wikipedia](https://en.wikipedia.org/wiki/Library_(computing))
2. [Create C/C++ DLLs in Visual Studio, microsoft.com](https://learn.microsoft.com/en-us/cpp/build/dlls-in-visual-cpp?view=msvc-170)
3. [dlopen, Linux Manual page](https://www.man7.org/linux/man-pages/man3/dlopen.3.html)
4. [Wheeler David, Dynamically Loaded (DL) Libraries](https://dwheeler.com/program-library/Program-Library-HOWTO/)
