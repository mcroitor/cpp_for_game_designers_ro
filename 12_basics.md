# Bazele limbajului C++

- [Bazele limbajului C++](#bazele-limbajului-c)
  - [Elementele limbajului](#elementele-limbajului)
    - [Constante](#constante)
    - [Identificatori](#identificatori)
    - [Cuvinte cheie](#cuvinte-cheie)
    - [Simboluri speciale](#simboluri-speciale)
    - [Comentarii](#comentarii)
  - [Tipuri de bază și variabile](#tipuri-de-bază-și-variabile)
    - [Numere întregi](#numere-întregi)
    - [Numere reale](#numere-reale)
    - [Tipul logic](#tipul-logic)
    - [Variabile](#variabile)
  - [Structuri de bază](#structuri-de-bază)
    - [Ramificări](#ramificări)
    - [Selecție](#selecție)
    - [Bucle](#bucle)
      - [Buclă cu contor](#buclă-cu-contor)
      - [Buclă cu precondiție](#buclă-cu-precondiție)
      - [Buclă cu postcondiție](#buclă-cu-postcondiție)
    - [Funcții](#funcții)
  - [Gestionarea memoriei](#gestionarea-memoriei)
    - [Pointeri](#pointeri)
    - [Referințe](#referințe)
    - [Alocare și eliberare de memorie](#alocare-și-eliberare-de-memorie)
    - [Tablouri](#tablouri)
  - [Bibliografie](#bibliografie)

## Elementele limbajului

Limbajul C++ (ca orice alt limbaj) este definit prin următoarele elemente:

- __constante__ – definesc datele programului;
- __identificatori__ – permit denumirea spațiilor de stocare a datelor și a algoritmilor pentru utilizarea acestora;
- __cuvinte cheie__ – cuvinte rezervate de limbaj, folosite pentru descrierea programelor;
- __simboluri speciale__ – semne de punctuație cu semnificație specială, în funcție de context;
- __comentarii__ – blocuri de text ignorate la compilare, destinate explicării codului sursă.

### Constante

Constantele sunt valori neschimbabile și pot fi reprezentate printr-un număr (întreg sau real), un caracter sau un șir de caractere.

Exemple de constante:

- `1`, `-12l`, `0b0010011`, `01237`, `0xab` – numere întregi
- `1.0`, `-2.32e+05`, `1.0e-5` – numere reale
- `'a'`, `'U'`, `'\n'`, `'\0xa3'`, `'\200'` – caractere
- `"this is a string"`, `""`, `"\13\255\32\32"` – șiruri de caractere

### Identificatori

Identificatorii sunt nume pentru variabile, funcții, constante și tipuri de date definite de utilizator.

Un identificator este o secvență de caractere folosită pentru denumirea:

- Un identificator conține unul sau mai multe caractere;
- Poate începe cu o literă sau cu caracterul de subliniere (`_`);
- După primul caracter pot urma litere, cifre sau caractere de subliniere;
- Nu se pot folosi cuvinte cheie ca identificatori.

Literele mari și mici sunt considerate diferite (`sample` ≠ `Sample`).

Exemple:

- `sample`
- `_my_variable`
- `THIS_IS_A_CONSTANT`
- `MyVariable10`

### Cuvinte cheie

În versiunea C89 sunt definite 32 de cuvinte cheie.

- __auto__ – permite compilatorului să deducă tipul variabilei pe baza valorii atribuite
- __break__ – instrucțiune de ieșire din buclă
- __case__ – instrucțiune pentru alegerea unei ramuri (folosită cu _switch_)
- __char__ – tip de date caracter
- __const__ – obiectele de tip _const_ nu pot fi modificate în timpul execuției
- __continue__ – instrucțiune pentru a continua bucla, sărind peste restul instrucțiunilor din bloc
- __default__ – ramură implicită în instrucțiunea _switch_
- __do__ – buclă cu postcondiție
- __double__ – tip de date real cu dublă precizie
- __else__ – ramură alternativă în instrucțiunea condițională
- __enum__ – tip de date enumerat
- __extern__ – specificator pentru variabile cu legătură externă
- __float__ – tip de date real cu precizie simplă
- __for__ – buclă cu precondiție și contor
- __goto__ – instrucțiune de salt necondiționat
- __if__ – instrucțiune condițională
- __int__ – tip de date întreg
- __long__ – modificator pentru tipuri întregi extinse
- __register__ – specificator pentru stocarea variabilei în registrele procesorului
- __return__ – instrucțiune de întoarcere din funcție
- __short__ – modificator pentru tipuri întregi scurte
- __signed__ – modificator pentru tipuri întregi semnate
- __sizeof__ – operator pentru determinarea dimensiunii unui tip la compilare
- __static__ – specifică păstrarea variabilei locale pe toată durata programului
- __struct__ – tip de date structură
- __switch__ – instrucțiune de selecție multiplă
- __typedef__ – definește un nou nume pentru un tip de date
- __union__ – tip de date uniune
- __unsigned__ – modificator pentru tipuri întregi fără semn
- __void__ – tip de date vid
- __volatile__ – calificator care indică faptul că valoarea variabilei poate fi modificată în mod neexplicit
- __while__ – buclă cu precondiție

C++ include toate cuvintele cheie din C89, precum și următoarele[^1]:

- __asm__ – inserare de instrucțiuni de asamblare
- __bool__ – tip de date logic
- __catch__ – bloc pentru tratarea excepțiilor
- __class__ – tip de date definit de utilizator (clasă)
- __const_cast__ – operator pentru conversia explicită a calificatorilor _const_/_volatile_
- __delete__ – operator pentru eliberarea memoriei
- __dynamic_cast__ – operator pentru conversii de tip sigure la rulare
- __explicit__ – specificator pentru constructori care nu permit conversii implicite
- __export__ – permite utilizarea șabloanelor definite în alte fișiere
- __false__ – constantă logică „fals”
- __friend__ – definește funcții sau clase prietene
- __inline__ – specificator pentru inserarea corpului funcției direct în cod
- __mutable__ – permite modificarea membrilor chiar dacă obiectul este constant
- __namespace__ – definește un spațiu de nume
- __new__ – operator pentru alocarea dinamică a memoriei
- __operator__ – permite suprascrierea operatorilor
- __private__ – specificator de acces privat
- __protected__ – specificator de acces protejat
- __public__ – specificator de acces public
- __reinterpret_cast__ – operator pentru conversii de tip arbitrare
- __static_cast__ – operator pentru conversii de tip la compilare
- __template__ – definește funcții și clase generice
- __this__ – pointer la obiectul curent
- __throw__ – aruncă o excepție
- __true__ – constantă logică „adevărat”
- __try__ – bloc pentru tratarea excepțiilor
- __typeid__ – operator pentru identificarea tipului la rulare
- __typename__ – folosit în șabloane pentru a indica un tip
- __using__ – importă membri dintr-un spațiu de nume
- __virtual__ – specifică funcții virtuale
- __wchar_t__ – tip de date caracter larg

### Simboluri speciale

Semnele de punctuație și simbolurile speciale au diverse utilizări, de la organizarea textului sursă până la definirea operațiilor efectuate de compilator sau programul compilat.

În C++ se folosesc următoarele simboluri speciale:

- `( )`
- `[ ]`
- `{ }`
- `*`
- `,`
- `:`
- `=`
- `;`
- `...`
- `#`

Aceste semne nu definesc operații de executat și pot avea semnificații diferite în funcție de context.

Unele semne de punctuație sunt și operatori ai limbajului.

### Comentarii

În codul sursă se pot scrie atât comentarii pe o singură linie, cât și pe mai multe linii.

Comentariile pe o linie încep cu `//` și se termină la sfârșitul liniei.

Comentariile pe mai multe linii sunt delimitate de `/*` și `*/`, între care se poate scrie orice text.

Comentariile nu influențează execuția programului și sunt folosite nu doar pentru explicarea codului, ci și pentru generarea documentației tehnice (Doxygen, JavaDoc etc.) sau pentru dezactivarea temporară a unor fragmente de cod.

De asemenea, multe IDE-uri moderne utilizează comentariile pentru generarea de sugestii și documentație contextuală.

## Tipuri de bază și variabile

Orice program procesează date. Datele pot fi numere, șiruri de caractere sau combinații ale acestora (date compuse). Pentru stocarea și manipularea datelor se folosesc variabile.

O variabilă este un identificator care desemnează o zonă de memorie. Fiecare variabilă are un tip.

Tipuri de bază: numere întregi, numere reale, tip logic.

Tipul determină ce valori poate avea variabila și câți octeți ocupă în memorie.

### Numere întregi

- __char__ – reprezintă un caracter. Ocupă 1 octet. Interval: -128...127 (sau 0...255 pentru unsigned char). Poate stoca un caracter între ghilimele simple.
- __unsigned char__ – tot un caracter, dar intervalul este 0...255.
- __short__ – întreg pe 2 octeți, interval: –32768...32767.
- __int__ – întreg, dimensiunea depinde de arhitectură (2, 4 sau 8 octeți).
- __long long__ – întreg pe 8 octeți, interval: `-9 223 372 036 854 775 808` ... `+9 223 372 036 854 775 807`.

Orice număr zecimal este considerat implicit de tip `int` / `long int` / `long long int` (în funcție de dimensiune). La atribuirea către alte tipuri, se face conversie.

Pentru a specifica explicit tipul, se adaugă un sufix:

- `unsigned int` – `u` sau `U`
- `long int` – `l` sau `L`
- `unsigned long int` – `ul` sau `UL`
- `long long` – `ll` sau `LL`
- `unsigned long long` – `ull` sau `ULL`

### Numere reale

- __float__ – număr real cu precizie simplă, interval: `-3.4E+38` ... `3.4E+38`, 4 octeți.
- __double__ – real cu dublă precizie, interval: `-1.7E+308` ... `1.7E+308`, 8 octeți.
- __long double__ – real cu precizie extinsă, 96–128 biți, în funcție de implementare.

### Tipul logic

În C++ există tipul special __bool__ pentru valori logice. Valorile posibile sunt doar `true` și `false`.

O variabilă de tip __bool__ ocupă 1 octet.

Tipul __bool__ este compatibil cu __int__ la atribuire: `true` devine `1`, `false` devine `0`. Orice valoare nenulă devine `true`, `0` devine `false`.

Operațiile de comparație returnează valori de tip logic.

Operații de comparație în C++:

| operator | exemplu |
| -------- | ------- |
| Mai mic  | X < Y   |
| Mai mare | X > Y   |
| Mai mic sau egal | X <= Y |
| Mai mare sau egal | X >= Y |
| Egal     | X == Y  |
| Diferit  | X != Y  |

Operații logice în C++:

- `&&` – ȘI (conjuncție)
- `||` – SAU (disjuncție)
- `!` – NU (negație)

Tabel de adevăr:

| A     | B     | A && B | A \|\| B | !A    |
| ----- | ----- | ------ | ------- | ----- |
| true  | true  | true   | true    | false |
| true  | false | false  | true    | false |
| false | true  | false  | true    | true  |
| false | false | false  | false   | true  |

### Variabile

La declararea unei variabile se specifică tipul, urmat de nume.

```cpp
int variable;
```

Se pot declara mai multe variabile de același tip, separate prin virgulă.

```cpp
int a, b, c;
```

O variabilă poate fi inițializată la declarare.

```cpp
int x = 0, y = x;
char chr1 = 10, chr2 = 'x';
```

## Structuri de bază

Un program C++ minimal arată astfel:

```cpp
int main() {
   return 0;
}
```

Funcția `main` este punctul de intrare[^2]. Ea returnează un număr întreg – codul de terminare. Valoarea `0` înseamnă terminare cu succes, orice altă valoare – eroare.

Funcția `main` poate primi argumente din linia de comandă:

```cpp
int main(int argc, char** argv) {
   return 0;
}
```

Primul parametru, _argc_, conține numărul de argumente, iar _argv_ este un tablou de șiruri cu argumentele. Exemplu de afișare a argumentelor:

```cpp
#include <iostream>

int main(int argc, char **argv) {
  for(int i = 0; i < argc; ++i) {
    std::cout << "argv[ " << i << " ] = " << argv[i] << std::endl;
  }
  return 0;
}
```

Primul argument este numele fișierului executabil.

### Ramificări

Ramificarea permite executarea unor blocuri de cod în funcție de o condiție logică.

Dacă blocul după __else__ este gol, poate fi omis.

Dacă blocul conține o singură instrucțiune, acoladele pot fi omise (nu este recomandat).

Sintaxa completă:

```cpp
if(/* condiție */) {
    // bloc 1
}
else {
    // bloc 2
}
```

Forme scurte:

```cpp
if(/* condiție */)
    // instrucțiune 1
else
    // instrucțiune 2

if(/* condiție */) {
    // bloc
}
```

### Selecție

Construcția __switch__ / __case__ permite compararea unei expresii cu o listă de valori.

```cpp
switch( /* expresie */) {
   case /* valoare_1 */: /* instrucțiuni_1 */;
   case /* valoare_2 */: /* instrucțiuni_2 */;
   // ...................
   case /* valoare_N */: /* instrucțiuni_N */;
   default: /* instrucțiuni */;
}
```

### Bucle

Buclele permit executarea repetată a unor instrucțiuni.

Există 3 tipuri de bucle în C++:

- bucla for;
- bucla while cu precondiție;
- bucla do…while cu postcondiție.

Din C++11 există și bucla „pentru fiecare” (range-based for).

#### Buclă cu contor

Pentru repetarea unui bloc de N ori:

```cpp
for(/* inițializare */; /* condiție */; /* modificare */) {
    // corpul buclei
}
```

Inițializatorul se execută o singură dată la început. Condiția este verificată la fiecare iterație. Modificarea se execută după fiecare iterație.

#### Buclă cu precondiție

Bucla __while__ cu precondiție:

```cpp
while (/* condiție */) {
    // corpul buclei
}
```

#### Buclă cu postcondiție

Bucla __do...while__ cu postcondiție:

```cpp
do {
    // corpul buclei
}
while (/* condiție */);
```

### Funcții

Funcția este un bloc de cod cu nume, care poate primi parametri și returna o valoare.

```cpp
/* tip returnat */ /* nume_functie */(/* parametri */) {
   // corpul funcției
}
```

Exemplu:

```cpp
int sum (int a, int b) {
   return a + b;
}

int value = sum(5, 10);
```

> Termenul _argument_ se referă la valoarea transmisă la apelul funcției. Variabila care primește argumentul se numește _parametru_. Funcțiile care primesc argumente se numesc _funcții parametrizate_. [Schildt][^3]

## Gestionarea memoriei

Programele folosesc două tipuri de memorie: stivă (__stack__) și heap (__heap__).

Stiva (__stack__) – memorie fixă, alocată la compilare. Variabilele locale sunt plasate aici, iar poziția lor nu se poate schimba în timpul execuției.

Heap-ul (__heap__) – memorie dinamică, unde se pot aloca zone de memorie la rulare.

### Pointeri

C și C++ oferă tipul pointer – o variabilă care conține adresa unei zone de memorie de un anumit tip. Dimensiunea zonei indicate de pointer este dată de tipul acestuia[^4].

Declararea pointerului:

```cpp
// <tip> * <nume_pointer>;
int * sampleIntPointer;
char * sampleCharPointer;
```

Inițializarea pointerului se face cu adresa unei variabile, folosind `&`.

Exemplu:

```cpp
#include <iostream>

int main() {
    int coolValue = 256;
    int * intPtr = &coolValue;
    char * charPtr = (char*)&coolValue;

    std::cout << "Cool value = " << coolValue << std::endl;
    std::cout << "pointer of cool value = " << intPtr << std::endl;
    std::cout << "access value by pointer = " << *intPtr << std::endl;
    std::cout << "first byte = " << (int)*charPtr << std::endl;
    std::cout << "second byte = " << (int)*(charPtr + 1) << std::endl;
    std::cout << "third byte = " << (int)*(charPtr + 2) << std::endl;
    std::cout << "fourth byte = " << (int)*(charPtr + 3) << std::endl;

    return 0;
}
```

Comportamentul unei referințe este similar cu cel al unui pointer constant.

### Referințe

Memoria pentru variabilele locale este alocată pe stivă. Uneori este nevoie de un alias pentru o variabilă – acesta se numește _referință_ și se declară cu `&`.

Exemplu:

```cpp
int a = 10;
int& another_ref_a = a;
```

> O referință trebuie întotdeauna inițializată cu o altă variabilă.

```cpp
#include <iostream>

int main() {
    int value = 10;
    int &ref = value;

    std::cout << "value: " << value << ", reference = " << ref << std::endl;
    value = 12;
    std::cout << "value: " << value << ", reference = " << ref << std::endl;
    ref = 15;
    std::cout << "value: " << value << ", reference = " << ref << std::endl;
    return 0;
}
```

O referință este un alias pentru o variabilă existentă, astfel încât modificarea valorii variabilei modifică și referința.

Referințele sunt folosite frecvent ca parametri ai funcțiilor pentru a evita copierea valorilor.

> O referință se comportă similar cu un pointer constant.

### Alocare și eliberare de memorie

În C++ memoria se alocă și se eliberează cu operatorii `new` și `delete`.

Operatorul `new` alocă memorie pentru un obiect și returnează un pointer. Operatorul `delete` eliberează memoria.

```cpp
int * intPtr = new int;
*intPtr = 10;
std::cout << *intPtr << std::endl;
delete intPtr;
```

### Tablouri

Un tablou este o structură de date care stochează mai multe elemente de același tip. Se declară specificând tipul, numele și dimensiunea între paranteze pătrate. Accesul la elemente se face prin index.

```cpp
int sampleArray[10];
sampleArray[0] = 10;
sampleArray[10] = 20; // eroare! indexul 10 depășește limita (0...9)
```

Tablourile pot fi alocate dinamic cu `new`. Memoria trebuie eliberată cu `delete[]`.

```cpp
int * sampleArray = new int[10];
sampleArray[0] = 10;

// delete[] se folosește pentru tablouri
delete[] sampleArray;
```

## Bibliografie

[^1]: [C++ Keywords](https://en.cppreference.com/w/cpp/keyword)
[^2]: [Main function](https://en.cppreference.com/w/cpp/language/main_function)
[^3]: [Schildt] Herbert Schildt. C++: The Complete Reference, 4th Edition. McGraw-Hill Education, 2003. ISBN: 978-0-07-223215-8
[^4]: [Pointer declaration](https://en.cppreference.com/w/cpp/language/pointer)
