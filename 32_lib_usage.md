# Utilizarea bibliotecilor externe

- [Utilizarea bibliotecilor externe](#utilizarea-bibliotecilor-externe)
  - [Biblioteci de programare](#biblioteci-de-programare)
  - [Utilizarea bibliotecilor statice](#utilizarea-bibliotecilor-statice)
    - [Exemplu de utilizare a bibliotecii statice](#exemplu-de-utilizare-a-bibliotecii-statice)
  - [Utilizarea bibliotecilor dinamice](#utilizarea-bibliotecilor-dinamice)
    - [Dynamic linking](#dynamic-linking)
    - [Dynamic loading](#dynamic-loading)
  - [Bibliografie](#bibliografie)

## Biblioteci de programare

__Biblioteca de programare__ este un set de resurse de programare așa cum sunt funcții, clase, obiecte, constante și variabile. În special, constantele pot fi date grafice sau multimedia. Bibliotecile de programare sunt împărțite în trei tipuri: __biblioteci statice__, __biblioteci dinamice__ și __biblioteci de șabloane__.

Bibliotecile de programare statice sunt prezentate prin două fișiere:

1. Fișierul antet cu extensia `h` (`hxx`, `hpp`), care descrie interfața bibliotecii;
2. Arhiva binară cu extensia `lib` (în Windows) sau `a` (în sistemele compatibile Unix), care stochează toate resursele de programare sub formă de cod obiect.

Bibliotecile de programare dinamice sunt prezentate prin trei fișiere:

1. Fișierul antet cu extensia `h` (`hxx`, `hpp`), care descrie interfața bibliotecii;
2. Arhiva binară cu extensia `dll` (în Windows) sau `so` (în sistemele compatibile Unix), numită bibliotecă dinamică (în sistemele Unix - partajată), care stochează toate resursele de programare sub formă de cod binar;
3. Fișierul cu extensia `lib` (în Windows) sau `a` (în sistemele compatibile Unix), numit bibliotecă de import, care stochează locațiile resurselor de programare în biblioteca dinamică. În sistemele Unix, biblioteca de import nu este utilizată.

Există și biblioteci de programare care nu pot fi reprezentate altfel decât sub formă de cod sursă - acestea sunt bibliotecile care conțin șabloane de clase și funcții. Aceste biblioteci sunt furnizate în fișiere antet.

Numirea bibliotecilor de programare pentru compilatorul Gnu C++ (g++) are următoarea formă:

- fișierul antet: `<nume bibliotecă>.h` sau `<nume bibliotecă>.hpp`;
- biblioteca statică: `lib<nume bibliotecă>.a` (în sistemele Unix) sau `<nume bibliotecă>.lib` (în Windows);
- biblioteca dinamică: `<nume bibliotecă>.so` (în sistemele Unix) sau `<nume bibliotecă>.dll` (în Windows).

Fișierele antet de obicei sunt plăsate în directorul `include` a compilatorului, bibliotecile statice și de import - în directorul `lib`, iar bibliotecile dinamice sunt plasate în directoarele sistemului (`C:\Windows\System32` sau `/usr/bin`). Aceste căi pot fi redefinite în program sau în timpul compilării.

Fiecare tip de bibliotecă de programare are avantaje și dezavantaje. De exemplu, utilizarea bibliotecilor statice crește portabilitatea programelor datorită faptului că acestea nu depind de niciun modul (biblioteci dinamice), dar codul programului crește. Utilizarea bibliotecilor dinamice permite crearea de programe mici ca dimensiune, dar în timpul execuției acestea vor ocupa în memorie locul bibliotecii dinamice.

## Utilizarea bibliotecilor statice

La utilizarea funcțiilor (claselor sau altor resurse programatice) din bibliotecile statice, la etapa de compilare a programului din bibliotecă compilatorul ia doar codurile obiect ale resurselor utilizate. Prin urmare, la dimensiunea bibliotecii statice de câteva megaocteți, programul crește în dimensiune cu câteva zeci de kiloocteți (în funcție de dimensiunea funcțiilor utilizate).

Pentru utilizarea bibliotecilor statice în program este necesar să se execute următoarele acțiuni:

1. De a conecta fișierul antet al bibliotecii în program;
2. La compilarea programului să se specifice calea către bibliotecă în parametrii de compilare.

În acest caz, compilatorul ia doar codurile obiect ale funcțiilor utilizate din bibliotecă și le include în codul programului. Această includere a codului se numește __asamblarea statică__.

### Exemplu de utilizare a bibliotecii statice

Fie dată o bibliotecă statică __MyMath__, care este caracterizată de următoarele fișiere:

1. `MyMath.h` - fișierul antet al bibliotecii;
2. `libMyMath.a` - arhiva binară a bibliotecii.

Fie această bibliotecă plasată în directorul `C:\MyLibs\MyMath`. Pentru a utiliza biblioteca în program, este necesar să se execute următoarele acțiuni:

1. De a conecta fișierul antet al bibliotecii în program:

```cpp
#include "MyMath.h"
```

2. La compilarea programului să se specifice calea către bibliotecă în parametrii de compilare:

```bash
g++ -o MyProgram.exe MyProgram.cpp -IC:\\MyLibs\\MyMath -LC:\\MyLibs\\MyMath -lMyMath
```

În acest caz, cheia de compilare `-I` indică calea către fișierul antet al bibliotecii, cheia `-L` indică calea către biblioteca de programare, iar cheia `-l` indică numele bibliotecii. Cărțile pot fi atât absolute, cât și relative.

## Utilizarea bibliotecilor dinamice

Bibliotecile dinamice pot fi utilizate în două moduri diferite:

- legare la timpul de încărcare a programului - __legare dinamică__ (en. __dynamic linking__);
- legare la timpul de execuție a programului - __încărcare dinamică__ (en. __dynamic loading__).

### Dynamic linking

__Legarea dinamică a bibliotecii__ cu aplicația se realizează la momentul conectării fișierului antet al bibliotecii, precum și la indicarea în proprietățile proiectului utilizarea bibliotecii. În acest caz, biblioteca va fi încărcată în memoria operațională înainte de pornirea aplicației. La pornirea aplicației, sistemul de operare verifică existența bibliotecilor dinamice legate de program, pe căile sistemului, în directorul curent sau în memoria operațională. Numai după aceea programul este executat. Dacă cel puțin o bibliotecă nu a fost găsită, aplicația se încheie cu o eroare corespunzătoare.

În timpul compilării a programului care utilizează biblioteca dinamică codul binar al aplicației crește cu câteva byte, deoarece în locul codului binar al funcțiilor din bibliotecă este inclusă doar o instrucțiune de apel a funcției din bibliotecă, care este definită în biblioteca de import.

### Dynamic loading

Totodată bibliotecile dinamice pot fi încărcate și utilizate nu numai la pornirea aplicației, ci și, după necesitate, în timpul execuției acesteia.

__Încărcarea dinamică a bibliotecii__ se realizează prin intermediul funcției `LoadLibrary` (sau `dlopen` în Unix), care încarcă biblioteca în memorie în momentul apelării funcției. În acest caz, aplicația poate funcționa fără bibliotecă până în momentul încărcării acesteia cu funcția `LoadLibrary`.

În SO Windows pentru încărcarea dinamică a bibliotecii se utilizează următoarele funcții, definite în fișierul antet `windows.h`:

- `LoadLibrary` - încarcă biblioteca dinamică în memorie operativă;
- `GetProcAddress` - obține adresa funcției din biblioteca dinamică;
- `FreeLibrary` - descarcă biblioteca dinamică din memorie operativă;
- `GetModuleHandle` - obține descriptorul bibliotecii dinamice.

În Unix pentru încărcarea dinamică a bibliotecii se utilizează următoarele funcții, definite în fișierul antet `dlfcn.h`:

- `dlopen` - încarcă biblioteca dinamică în memorie operativă;
- `dlsym` - obține adresa funcției din biblioteca dinamică;
- `dlclose` - descarcă biblioteca dinamică din memorie operativă;

Dacă există o bibliotecă dinamică `MyMath.dll`, iar în ea este definită funcția `int Add(int, int)`, atunci în SO Windows pentru legarea explicită a bibliotecii cu programul este necesar să se execute următoarele acțiuni:

```cpp
#include <windows.h>
#include <iostream>

typedef int (*pOperation)(int, int);

int main()
{
    HINSTANCE hLib = LoadLibrary("MyMath.dll");
    if (hLib == NULL)
    {
        std::cerr << "Error loading library" << std::endl;
        return 1;
    }

    pOperation Add = (pOperation)GetProcAddress(hLib, "Add");
    if (Add == NULL)
    {
        std::cerr << "Error loading function" << std::endl;
        return 1;
    }

    std::cout << Add(2, 3) << std::endl;

    FreeLibrary(hLib);
    return 0;
}
```

În sistemul de operare Unix pentru legarea explicită a bibliotecii cu programul este necesar să se execute următoarele acțiuni:

```cpp
#include <dlfcn.h>
#include <iostream>

typedef int (*pOperation)(int, int);

int main()
{
    void* hLib = dlopen("MyMath.so", RTLD_LAZY);
    if (hLib == NULL)
    {
        std::cerr << "Error loading library" << std::endl;
        return 1;
    }

    pOperation Add = (pOperation)dlsym(hLib, "Add");
    if (Add == NULL)
    {
        std::cerr << "Error loading function" << std::endl;
        return 1;
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
4. [Wheeler David, Dynamically Loaded (DL) Libraries](dwheeler.com/program-library/Program-Library-HOWTO/)
