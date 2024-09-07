# Bazele limbajului C++

- [Bazele limbajului C++](#bazele-limbajului-c)
  - [Elementele limbajului C++](#elementele-limbajului-c)
    - [Constante](#constante)
    - [Identificatori](#identificatori)
    - [Cuvinte cheie](#cuvinte-cheie)
    - [Simboluri speciale](#simboluri-speciale)
    - [Comentarii](#comentarii)
  - [Tipuri de date de bază și variabile](#tipuri-de-date-de-bază-și-variabile)
    - [Numere întregi](#numere-întregi)
    - [Numere reale](#numere-reale)
    - [Tip de date logic](#tip-de-date-logic)
    - [Variabile](#variabile)
  - [Structuri de bază](#structuri-de-bază)
    - [Ramificații](#ramificații)
    - [Ramificații multiple](#ramificații-multiple)
    - [Bucle](#bucle)
      - [Bucla cu contor](#bucla-cu-contor)
      - [Bucla cu precondiție](#bucla-cu-precondiție)
      - [Bucla cu postcondiție](#bucla-cu-postcondiție)
    - [Funcții](#funcții)
  - [Gestionarea memoriei](#gestionarea-memoriei)
    - [Pointeri](#pointeri)
    - [Referințe](#referințe)
    - [Alocarea și eliberarea memoriei](#alocarea-și-eliberarea-memoriei)
    - [Vectori](#vectori)
  - [Bibliografie](#bibliografie)

## Elementele limbajului C++

Limbajul C++ ca orice alt limbaj se definește prin elementele următoare

- __constante__ - definesc datele programului;
- __identificatori__ - permit denumirea stocării datelor și algoritmilor pentru utilizarea lor;
- __cuvinte cheie__ - cuvinte rezervate de limbaj, destinate descrierii programelor;
- __simboluri speciale__ - semne de punctuație, cu semnificație specială, în funcție de context;
- __comentarii__ - blocuri de text, care nu sunt traduse în cod binar, destinate explicării codului programului.

### Constante

Constantele sunt valori care nu se schimbă pe parcursul programului. Ele pot fi reprezentate de numere (întregi sau reale), simboluri sau secvențe de caractere (șiruri de caractere).

Aici puteți găsi exemple de constante:

- `1`, `-12l`, `0b0010011`, `01237`, `0xab` - numere întregi
- `1.0`, `-2.32e+05`, `1.0e-5` - numere reale
- `'a'`, `'U'`, `'\n'`, `'\0xa3'`, `'\200'` - caractere
- `"this is a string"`, `""`, `"\13\255\32\32"` - șiruri de caractere

### Identificatori

Identificatori sunt nume care se atribuie variabilelor, funcțiilor, constantelor și altor elemente programelor.

Identificatorul se formează dintr-o secvență de caractere, care poate conține litere, cifre și simbolul de subliniere, conform regulilor:

- identificatorul poate conține unul sau mai multe caractere;
- identificatorul poate începe cu o literă sau cu simbolul `_` (de subliniere);
- identificatorul poate conține litere, cifre și simbolul `_`;
- identificatorul nu poate fi un cuvânt cheie.

Caracterele majuscule și minuscule sunt considerate diferite, adică `sample` și `Sample` sunt două identificatori diferiți.

Exemple de identificatori:

- `sample`
- `_my_variable`
- `THIS_IS_A_CONSTANT`
- `MyVariable10`

### Cuvinte cheie

Limbajul C++ conține un set de cuvinte cheie, care sunt rezervate pentru a descrie programul. Acest set de cuvinte chei include cuvinte cheie din limbajul C. În versiunea C89 a limbajului C sunt definite 32 de cuvinte cheie.

- __auto__ -  specifică că o variabilă este o variabilă locală și că valoarea sa este stocată în stiva de execuție. În versiunea C++11, cuvântul cheie _auto_ este folosit pentru a declara o variabilă cu tipul de date al unei expresii.
- __break__ - iese din structura de control
- __case__ - definește un caz într-o instrucțiune _switch_
- __char__ - definește un tip de date pentru caractere
- __const__ - definește o variabilă ca fiind constantă
- __continue__ - trece la următoarea iterație a unei structuri de control
- __default__ - definește o acțiune implicită într-o instrucțiune _switch_
- __do__ - definește o buclă cu postcondiție
- __double__ - definește un tip de date pentru numere cu virgulă mobilă dublă
- __else__ - definește o acțiune alternativă într-o structură de control
- __enum__ - definește un tip de date enumerat
- __extern__ - definește o variabilă ca fiind externă și că este definită în altă parte
- __float__ - definește un tip de date pentru numere cu virgulă mobilă
- __for__ - definește o buclă cu condiție
- __goto__ - transferă controlul la o etichetă
- __if__ - definește o structură de control cu condiție
- __int__ - definește un tip de date pentru numere întregi
- __long__ - definește un tip de date pentru numere întregi lungi
- __register__ - definește o variabilă ca fiind stocată într-un registru. Începând cu versiunea C++11, cuvântul cheie register este ignorat.
- __return__ - returnează controlul la apelant
- __short__ - definește un tip de date pentru numere întregi scurte
- __signed__ - definește un tip de date ca fiind semnat
- __sizeof__ - returnează dimensiunea unui tip de date
- __static__ - definește o variabilă ca fiind statică
- __struct__ - definește o structură
- __switch__ - definește o structură de control cu mai multe cazuri
- __typedef__ - definește un tip de date nou
- __union__ - definește un tip de date care poate stoca mai multe tipuri de date
- __unsigned__ - definește un tip de date ca fiind fără semn
- __void__ - definește un tip de date pentru funcții care nu returnează valoare
- __volatile__ - definește o variabilă ca fiind volatilă
- __while__ - definește o buclă cu precondiție

În afară de cuvintele cheie din C, C++ conține și cuvinte cheie suplimentare:

- __asm__ - cuvânt cheie pentru a insera una sau mai multe instrucțiuni de asamblare
- __bool__ - tip de date logic
- __catch__ - bloc de cod care conține partea programului care tratează o excepție
- __class__ - tip de date personalizat "clasă"
- __const_cast__ - operator de conversie folosit pentru a anula modificatorii _const_ și / sau _volatile_
- __delete__ - operator care eliberează memoria la care se referă argumentul
- __dynamic_cast__ - operator de conversie care verifică legalitatea efectuării unei operații de conversie
- __explicit__ - constructor definit cu specificatorul _explicit_ va fi utilizat numai dacă inițializarea se potrivește exact cu ceea ce este definit de constructor
- __export__ - cuvânt cheie care permite altor fișiere să utilizeze șablonul definit în alt fișier prin furnizarea doar a declarației sale.
- __false__ - constantă logică cu valoarea "fals"
- __friend__ - cuvânt cheie care definește funcții sau clase prietenoase
- __inline__ - specificator utilizat pentru a plasa corpul funcției direct în textul programului
- __mutable__ - specificator de tip care permite unui membru al unui obiect să anuleze proprietatea de constantă
- __namespace__ - cuvânt cheie pentru a crea spații de nume
- __new__ - operator care alocă memorie dinamică și returnează un pointer de tip corespunzător la acea zonă de memorie
- __operator__ - cuvânt cheie utilizat pentru a crea funcții supraincarcate
- __private__ - specificator de acces "privat" care definește modul în care se face moștenirea unei clase de bază
- __protected__ - specificator de acces "protejat" care definește modul în care se face moștenirea unei clase de bază
- __public__ - specificator de acces "public" care definește modul în care se face moștenirea unei clase de bază
- __reinterpret_cast__ - operator de conversie care convertește un tip într-un cu totul altul
- __static_cast__ - operator de conversie care efectuează conversia non-polimorfică a tipurilor
- __template__ - cuvânt cheie utilizat pentru a crea funcții și clase generice
- __this__ - folosit pentru a face referire la pointerii la obiectul care a generat apelul la funcția membru
- __throw__ - operator _throw_ generează o excepție
- __true__ - constantă logică cu valoarea "adevărat"
- __try__ - bloc de cod care conține partea programului care poate genera o excepție
- __typeid__ - operator _typeid_ returnează o referință la un obiect _type_info_ care descrie tipul obiectului la care se referă operatorul _typeid_
- __typename__ - cuvânt cheie care poate fi utilizat în loc de cuvântul cheie _class_ în declarația unui șablon sau pentru a face referire la un tip nedeterminat
- __using__ - transferă o variabilă dintr-un spațiu de nume definit în spațiul global al variabilelor
- __virtual__ - specificator de tip care definește funcții virtuale
- __wchar_t__ - tip de date de caractere de 2 octeți

Totodată, cât noul standard C, atât și noul standard C++ definește niște cuvinte cheie specifice, care se încep cu caracterul `_` [^1].

### Simboluri speciale

Simbolurile de punctuație și caractere speciale din setul de caractere C sunt utilizate pentru a organiza codul sursă și pentru a defini sarcinile pe care le va efectua compilatorul sau programul compilat.

În C++ utilizăm următoarele simboluri speciale:

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

Acestea simboluri nu definesc operații care trebuie efectuate și pot avea sensuri diferite, în funcție de context.

Unele simboluri speciale sunt utilizate pentru a defini operatori ale limbajului.

### Comentarii

Comentariile sunt utilizate pentru a explica codul sursă. Ele sunt ignorate de compilator și nu sunt incluse în codul binar.

În codul sursă pot fi incluse comentarii lineare și multiline.

Comentariu linear începe cu `//` și se termină la sfârșitul liniei.

Comentarul multiline începe cu `/*` și se termină cu `*/`, între care se poate scrie orice număr de linii de text.

Comentarii se utilizează nu numai pentru a explica codul, dar și pentru creația documentației tehnice. Există o serie de aplicații (Doxygen, JavaDoc etc.), care analizează comentariile și creează documentație în format HTML, PDF sau altul. De asemenea, IDE moderne utilizează comentariile pentru a genera pop-up-uri cu sugestii la cod.

## Tipuri de date de bază și variabile

Fiecare program este destinat pentru prelucrarea datelor. Datele pot fi numere, șiruri de caractere sau combinații de numere și șiruri de caractere (date compuse). Pentru a stoca și lucra cu date se utilizează _variabile_.

Variabila este un identificator care se referă la o zonă de memorie, în care se stochează date. Variabila are un nume și un tip de date.

Tipuri de date de bază sunt numerele întregi, numerele reale și valorile logice.

Tipul de date determină ce valori poate stoca variabila și ce operații se pot efectua cu aceste valori.

### Numere întregi

- __char__ - tip de date pentru caractere, ocupă 1 byte în memorie. Poate stoca valori de la -128 la 127. Variabilele de tip char pot fi inițializate cu un singur caracter între ghilimele simple.
- __unsigned char__ - tip de date pentru caractere, ocupă 1 byte în memorie. Poate stoca valori de la 0 la 255.
- __short__ - tip de date pentru numere întregi, ocupă 2 bytes în memorie. Poate stoca valori de la -32768 la 32767.
- __unsigned short__ - tip de date pentru numere întregi, ocupă 2 bytes în memorie. Poate stoca valori de la 0 la 65535.
- __int__ - tip de date pentru numere întregi, ocupă 2, 4 sau 8 bytes în memorie, în funcție de arhitectura procesorului.
- __long long__ - tip de date pentru numere întregi, ocupă 8 bytes în memorie. Poate stoca valori de la -9223372036854775807 la 9223372036854775807.

Fiecare număr întreg implicit se tratează ca o valoare de tip __int__, __long int__ și __long long int__, în dependența de valioarea numărului, și la atribuirea variabelelor de alt tip întreg va fi convertit implicit în alte tipuri de date întregi.

Pentru a defini tip de date implicit la numărul întreg, se adaugă la numărul întreg un sufix:

- `unsigned int` – `u` sau `U`
- `long int` – `l` sau `L`
- `unsigned long int` – `ul` sau `UL`
- `long long` – `ll` sau `LL`
- `unsigned long long` – `ull` sau `ULL`

Tip da date `char` este un tip de date întreg specific, care de obicei se utilizează pentru stocarea simbolurilor. Standardul nou de C++11 definește tipuri de date `char8_t`, `char16_t` și `char32_t` pentru stocarea simbolurilor Unicode.

### Numere reale

- __float__ - tip de date pentru numere reale, ocupă 4 bytes în memorie. Poate stoca valori de la -3.4E+38 la 3.4E+38.
- __double__ - tip de date pentru numere reale, ocupă 8 bytes în memorie. Poate stoca valori de la -1.7E+308 la 1.7E+308.
- __long double__ - tip de date pentru numere reale, ocupă 10 bytes în memorie. Poate stoca valori de la +/- 3.4E-4932 la 1.1E+4932.

### Tip de date logic

În limbajul C++ pentru valorile logice se utilizează tipul de date `bool`. Acest tip de date poate avea doar două valori: `true` sau `false`, alte valori nu sunt permise.

Variabilele de tip `bool` ocupă 1 byte în memorie.

Tipul `bool` compatibil cu tipul `__int__` la atribuire în ambele direcții, în acest caz `true` se convertește în `1`, `false` în `0`.

La convertirea înapoi `0` se convertește în `false`, orice altă valoare se convertește în `true`.

Valorile logice sunt rezultatul operațiilor de comparație sau operațiilor logice.

În C++ sunt definite următoarele operații de comparație:

| operator | exemplu |
| -------- | ------ |
| Mai mic | X < Y |
| Mai mare | X > Y |
| Mai mic sau egal | X <= Y |
| Mai mare sau egal | X >= Y |
| Egal | X == Y |
| Diferit | X != Y |

Limbajul C++ are 3 operații logice:

- `&&` - operația ȘI (conjuncție)
- `||` - operația SAU (disjuncție)
- `!` – operația NU (negare)

Acestea operații logice permit compunerea unor expresii logice mai complexe.

| A | B | A && B | A \|\| B | !A |
| ----- | ----- | ------ | ------ | ----- |
| true | true | true | true | false |
| true | false | false | true | false |
| false | true | false | true | true |
| false | false | false | false | true  |

### Variabile

La definirea variabilei se specifică tipul de date și, prin simboluri spațiale, numele variabilei.

```cpp
int variable;
```

Pot fi definite mai multe variabile de același tip într-o singură linie, separate prin virgulă.

```cpp
int a, b, c;
```

Variabilele pot fi inițializate la momentul declarării, adăugând valoarea după simbol `=`.

```cpp
int x = 0, y = x;
char chr1 = 10, chr2 = 'x';
```

## Structuri de bază

Cel mai simplu program în C++ arată în felul următor:

```cpp
int main() {
   return 0;
}
```

Cel mai simplu program în C++ constă din funcția `main`, care este __punctul de intrare__ în program[^2]. Funcția `main` întoarce un număr întreg, care reprezintă codul de ieșire al programului. Dacă programul se termină cu succes, atunci funcția `main` întoarce `0`.

Totodată, punctul de intrare în program poate avea parametrii de intrare: argumentele aplicatiei, care se transmit la lansarea programului (de exemplu, în linia de comandă).

```cpp
int main(int argc, char** argv) {
   return 0;
}
```

Primul parametru `argc` conține numărul de argumente transmise, al doilea parametru `argv` este un masiv de argumente transmise. Pentru a înțelege cum funcționează argumentele punctului de intrare, se recomandă să examinați și să executați următorul cod:

```cpp
#include <iostream>

int main(int argc, char **argv) {
  for(int i = 0; i < argc; ++i) {
    std::cout << "argv[ " << i << " ] = " << argv[i] << std::endl;
  }
  return 0;
}
```

### Ramificații

Ramificația este unul dintre blocurile de bază ale programării. Aceasta permite executarea unui cod sau altul, în funcție de condiție (expresie logică). Structura de bază a ramificației este următoarea:

```cpp
if(/* expresie logică */) {
    // bloc de comenzi 1
}
else {
    // bloc de comenzi 2
}
```

Blocul de comenzi 1 se execută dacă expresia logică este adevărată, blocul de comenzi 2 se execută dacă expresia logică este falsă.

Dacă bloc de comenzi declarat după __else__ este vid, atunci el poate fi omis.

```cpp
// nu sunt definite comenzi pentru execuție alternativă, bloc else este omis
if(/* conditie */) {
    // bloc de comenzi
}
```

Dacă bloc de comenzi este format dintr-o singură comandă, atunci acoladele pot fi omise.

```cpp
// bloc de comenzi contine o singura comanda, acoladele sunt omise, nu se recomandă
if(/* conditie */)
    // comando 1
else
    // comanda 2
```

### Ramificații multiple

Construcția __switch__ / __case__ permite compararea unei expresii cu un set de valori. După cuvântul cheie __switch__ în paranteze se află expresia de comparare. Valoarea acestei expresii este comparată cu valorile după operatorul __case__. Dacă se găsește o valoare egală, atunci se execută blocul de comenzi asociat și toate blocurile de comenzi care urmează (dacă nu este specificat __break__). Dacă nu se găsește nicio valoare egală, atunci se execută blocul de comenzi asociat cu operatorul __default__.

```cpp
switch( /* expresie */) {
   case /* valoare_1 */: /* instructii_1 */;
   case /* valoare_2 */: /* instructii_2 */;
   // ...................
   case /* valoare_N */: /* instructii_N */;
   default: /* instructii */;
}
```

### Bucle

Bucle sunt construcții de bază a limbajului de programare, care permit executarea repetată a unui bloc de comenzi.

Limbajul C++ oferă 3 tipuri de bucle:

- bucla cu contor (__for__);
- bucla cu precondiție (__while__);
- bucla cu postcondiție (__do...while__).

Fiecare tip de buclă poate fi înlocuit cu oricare altul.

Începând cu standardul C++11, a fost introdusă o nouă construcție de buclă - bucla "pentru fiecare" (__for each__). Acest tip de ciclu va fi discutat în temele următoare.

#### Bucla cu contor

Deseori apare necesitate de a executa un bloc de comenzi un număr cunoscut de ori. Pentru aceasta se utilizează __bucla cu contor__. Bucla cu contor are următoarea structură:

```cpp
for(/* initializator */; /* conditie */; /* iteratie */) {
    // corpul buclei
}
```

_Inițializator_ se execută o singură dată la începutul buclei și inițializează contorul. De obicei, aici se inițializează variabilele contorului, care se utilizează pentru controlul buclei.

_Condiție_ reprezintă expresia logică, care se evaluează la fiecare iterație a buclei. Când condiția devine falsă, bucla se termină. De exemplu, condiție poate verifica dacă contorul a atins o anumită valoare.

_Iteratie_ se execută după fiecare finalizare a blocului de comenzi și modifică contorul. De obicei, aici se incrementează sau decrementează contorul.

#### Bucla cu precondiție

Bucla cu precondiție permite executarea unui bloc de comenzi până când condiția devine falsă. Structura buclei cu precondiție este următoarea:

```cpp
while (/* conditie */) {
    // corpul buclei
}
```

#### Bucla cu postcondiție

Bucla __do...while__ este similară cu bucla cu precondiție, dar se execută cel puțin o dată, chiar dacă condiția este falsă. Structura buclei cu postcondiție este următoarea:

```cpp
do {
    // corpul buclei
}
while (/* conditie */);

```

### Funcții

În multe cazuri apare posibilitatea de a executa un bloc de comenzi de mai multe ori, în diferite locuri ale programului. În acest caz, comenzile pot fi selectate într-un bloc de comenzi separat, acest bloc poate fi numit și apelat de mai multe ori după nume. Acest bloc de comenzi cu nume se numește _funcție_. Funcția poate avea parametrii de intrare și poate returna un rezultat.

Parametrii de intrare sunt valorile care se transmit funcției la apel și care sunt utilizate în blocul de comenzi al funcției. Rezultatul funcției este valoarea care se întoarce la apelul funcției.

Declarația funcției are următoarea structură:

```cpp
/* тип de date întors */ /* nume funcție */(/* lista de parametrii */) {
    // bloc de comenzi - corpul functiei
}
```

Tipul de date întors este tipul de date al rezultatului funcției. Dacă funcția nu returnează niciun rezultat, atunci tipul de date întors este `void`.

Funcția poate fi apelată în orice loc al programului. 

Valorile, care se transmit funcției, se numesc argumente, tipurile acestor valori trebuie să fie compatibile cu tipurile parametrilor funcției.

```cpp
int sum (int a, int b) {
   return a + b;
}

int value = sum(5, 10);
```

> Notiune de _argument se referă la valoarea care se utilizează la apelul funcției. Variabila care primește acest argument se numește _parametru_. Funcțiile care primesc argumente se numesc _funcții parametrizate_. [Shildt][^3]

## Gestionarea memoriei

Aplicații în timpul execuției utilizează diferite tipuri de memorie: memoria stivă (__stack__) și memoria dinamică (__heap__).

Memoria stivă este o zonă de memorie, care se utilizează pentru stocarea variabilelor locale și a adreselor de întoarcere. Memoria stivă este organizată într-o manieră LIFO (Last In First Out), adică ultimul element introdus în stivă este primul element care este eliminat.

Memoria dinamică este o zonă de memorie, care se utilizează pentru stocarea datelor, care pot fi alocate și eliberate în timpul execuției.

### Pointeri

Limbajele de programare C și C++ oferă posibilitatea de a lucra cu adresele de memorie. Adresa de memorie este un număr, care indică locația în memorie a unei variabile. Mărimea memoriei alocate la care se referă adresa depinde de tipul de date al variabilei.

Declarația variabilei de tip pointer se face prin specificarea tipului de date, urmat de simbolul `*` și numele variabilei[^4].


```cpp
// <type> * <pointer_name>;
int * sampleIntPointer;
char * sampleCharPointer;
```

În exemplul de mai sus, `sampleIntPointer` poate conține adresa unui bloc de memorie de 4 bytes (mărimea unui int).

Initializarea pointerului se face cu ajutorul adresei variabilei sau cu ajutorul valorii `nullptr`. Luarea adresei variabilei se face cu ajutorul operatorului `&`.

Un examplu de lucru cu pointeri:

```cpp
#include <iostream>

int main() {
    int coolValue = 256;
    int * intPtr;
    char * charPtr;

    intPtr = &coolValue;
    charPtr = (char*)&coolValue;

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

### Referințe

Memoria pentru variabile locale se alocă în stivă, în această memorie alocată poate fi scrisă o valoare. Există situații când este necesar de introdus o variabilă, care să fie un pseudonim pentru o altă variabilă. Pseudonimul variabilei se numește _referință_ și se declară cu ajutorul simbolului `&`.

Exemplu de referință:

```cpp
int a = 10;
int& another_ref_a = a;
```

> Variabilă de tip referință se inițializează la momentul declarării și numaidecât cu o variabilă deja existentă.

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

Având în vedere exemplul de mai sus, referința este un pseudonim pentru variabila existentă, din ce reesă că modificarea valorii variabilei se va reflecta și în valoarea referinței.

De obicei referințele se utilizează pentru definirea parametrilor funcțiilor, pentru a evita copierea valorilor.

> Referința după comportament seamănă cu un pointer constant.

### Alocarea și eliberarea memoriei

În limbajul C++ pentru alocarea și eliberarea memoriei se utilizează operatorii `new` și `delete`.

Operatorul `new` aloca memorie pentru un obiect și returnează adresa acestui obiect. Operatorul `delete` eliberează memoria alocată pentru obiect.

```cpp
int * intPtr = new int;
*intPtr = 10;
std::cout << *intPtr << std::endl;
delete intPtr;
```


### Vectori

Vectorii sunt structuri de date, care permit stocarea mai multor elemente de același tip. Vectorii se utilizează pentru stocarea unui număr mare de elemente de același tip.

Definirea unui vector se face prin specificarea tipului de date, urmat de numele vectorului și de dimensiunea vectorului între paranteze drepte. Acces către elementele vectorului se face cu ajutorul indicelui elementului.

```cpp
int sampleArray[10];
sampleArray[0] = 10;
sampleArray[10] = 20; // eroare!!! indexul este mai mare sau egal decât dimensiunea vectorului
```

Vectorul poate fi alocat dinamic cu ajutorul operatorului `new`. Aceasta permite alocarea memoriei pentru vector în timpul execuției. După utilizarea vectorului, memoria trebuie eliberată corect cu ajutorul operatorului `delete`.

```cpp
int * sampleArray = new int[10];
sampleArray[0] = 10;

// delete[] se utilizează pentru eliberarea memoriei pentru vector
// stergerea prin delete sampleArray va duce la eroare
delete[] sampleArray;
```

## Bibliografie

[^1]: [C++ Keywords](https://en.cppreference.com/w/cpp/keyword)
[^2]: [Main function](https://en.cppreference.com/w/cpp/language/main_function)
[^3]: [Shildt] Herbert Schildt. C++: The Complete Reference, 4th Edition. McGraw-Hill Education, 2003. ISBN: 978-0-07-223215-8
[^4]: [Pointer declaration](https://en.cppreference.com/w/cpp/language/pointer)
