# Bazele limbajului C++

- [Bazele limbajului C++](#bazele-limbajului-c)
  - [Elemente de limbaj](#elemente-de-limbaj)
    - [Constante](#constante)
    - [identificatoare](#identificatoare)
    - [Cuvinte cheie](#cuvinte-cheie)
    - [simboluri speciale](#simboluri-speciale)
    - [Comentarii](#comentarii)
  - [Tipuri de date de bază și variabile](#tipuri-de-date-de-bază-și-variabile)
    - [Numere întregi](#numere-întregi)
    - [Действительные числа](#действительные-числа)
    - [Логический тип](#логический-тип)
    - [Переменные](#переменные)
  - [Базовые структуры](#базовые-структуры)
    - [Ветвления](#ветвления)
    - [Выбор](#выбор)
    - [Циклы](#циклы)
      - [Цикл со счетчиком](#цикл-со-счетчиком)
      - [Цикл с предусловием](#цикл-с-предусловием)
      - [Цикл с постусловием:](#цикл-с-постусловием)
    - [Функции](#функции)
  - [Управление памятью](#управление-памятью)
    - [Cсылки](#cсылки)
    - [Указатели](#указатели)
    - [Выделение и освобождение памяти](#выделение-и-освобождение-памяти)
    - [Массивы](#массивы)

## Elemente de limbaj

Limbajul C++ la fel ca orice alt limbaj este definit de următoarele elemente:

 - __constante__ - definesc datele programului;
 - __identificatori__ - permit denumirea de containere de date și algoritmi pentru utilizarea lor;
 - __cuvinte cheie__ - cuvinte rezervate de limbaj, destinate descrierii programelor;
 - __simboluri speciale__ - caractere de punctuație cu o semnificație specială, în funcție de context;
 - __comentarii__ - blocuri de text care nu sunt traduse în cod binar, destinate explicării codului programului.

### Constante

Constantele sunt valori imutabile și pot fi reprezentate de un număr (întreg sau real), un caracter sau o secvență de caractere (șir de caractere).

Exemple de constante:
 * `1`, `-12l`, `0b0010011`, `01237`, `0xab` - numere intregi 
 * `1.0`, `-2.32e+05`, `1.0e-5` - numere reale
 * `'a'`, `'U'`, `'\n'`, `'\0xa3'`, `'\200'` - simboluri 
 * `"this is a string"`, `""`, `"\13\255\32\32"` - șiruri de caractere 

### identificatoare

Identificatorii sunt numele variabilelor, funcțiilor, constantelor și tipurilor de date personalizate.

Un identificator este o secvență de caractere utilizată pentru a denumi:

 * Un identificator constă dintr-unul sau mai multe caractere.
 * Un identificator poate începe cu un caracter de subliniere sau cu o literă din alfabetul latin.
 * După primul caracter din identificator poate urma un caracter de subliniere, litere din alfabetul latin sau cifre.
 * Nu se pot utiliza cuvinte cheie ca identificatori.

Caracterele majuscule și minuscule sunt diferite! ( `sample` != `Sample` )

Exemple:
 - `sample`
 - `_my_variable`
 - `THIS_IS_A_CONSTANT`
 - `MyVariable10`

### Cuvinte cheie

În standardului С89 a limbajului C sunt definite 32 cuvinte chei.

 - __auto__ — Instruiți compilatorului să deducă tipul unei variabile pe baza tipului valorii atribuite
 - __break__ — Operator de ieșire în buclă
 - __case__ — Operator pentru specificarea unei alegeri (utilizat împreună cu _switch_)
 - __char__ — Tip de date caracter
 - __const__ — Obiectele de tip _const_ nu pot fi modificate de program în timpul execuției sale
 - __continue__ — Operatorul de continuare a buclei, omite instrucțiunile rămase până la sfârșitul blocului
 - __default__ — Operator de selecție implicit
 - __do__ — Operator buclă cu postcondiție fără contor
 - __double__ — Tip de date cu precizie dublă în virgulă mobilă
 - __else__ — Operatorul condiționat "else"
 - __enum__ — Tip de date personalizat "tip de enumerare"
 - __extern__ — Specificator de tip pentru a indica compilatorului legarea externă a unei variabile
 - __float__ — Tip de date cu virgulă mobilă
 - __for__ — Operator buclă cu precondiție, cu contor
 - __goto__ — Operator de salt necondiționat
 - __if__ — Operator condițional "dacă".
 - __int__ — Tip de date întreg
 - __long__ — Modificator de tip de date pentru definirea variabilelor lungi
 - __register__ — Specificator de tip pentru stocarea unei variabile în registrele procesorului
 - __return__ — Operator pentru returnarea unei valori dintr-o funcție
 - __short__ — Modificator de tip de date pentru definirea variabilelor scurte
 - __signed__ — Modificator de tip de date pentru definirea variabilelor semnate
 - __sizeof__ — Operator folosit pentru a determina dimensiunea unui tip de date la momentul compilării
 - __static__ - Spune compilatorului să stocheze o variabilă locală pe parcursul ciclului de viață al programului
 - __struct__ — Tip de date personalizat "structură"
 - __switch__ — Operator de selecție
 - __typedef__ — Operator pentru a crea un nou nume de tip de date
 - __union__ — Tip de date personalizat "union"
 - __unsigned__ — Modificator de tip de date pentru definirea variabilelor nesemnate
 - __void__ — Tip de date gol
 - __volatile__ — Calificatorul de tip îi spune compilatorului că valoarea variabilei poate fi modificată prin mijloace specificate implicit în program
 - __while__ — Operator buclă cu precondiție, fără contor

Limbajul C++ conține toate cuvinte chei ale limbajului C, standard _C89_ inclusiv următoarele:

 - __asm__ — Cuvânt cheie pentru inserarea uneia sau mai multor instrucțiuni de asamblare
 - __bool__ — tip de date boolean
 - __catch__ — Bloc de program care conține acea parte a programului care gestionează eroarea
 - __class__ — Tip de date personalizat "class"
 - __const_cast__ — Operatorul de tip casting, folosit pentru a suprascrie în mod explicit modificatorii _const_ și/sau _volatile_
 - __delete__ — Operatorul eliberează memoria indicată de argument
 - __dynamic_cast__ — Operator de turnare de tip, verifică legalitatea efectuării unei operațiuni de turnare de tip dat
 - __explicit__ — Un constructor definit cu specificatorul _explicit_ va fi folosit numai dacă inițializarea este exact aceeași cu cea specificată de constructor
 - __export__ - Un cuvânt cheie care permite altor fișiere să utilizeze un șablon declarat într-un alt fișier specificând doar declarația acestuia.
 - __false__ — O constantă logică care are valoarea "false".
 - __friend__ — Cuvântul cheie definește funcțiile sau clasele de prieteni
 - __inline__ — Specificator folosit pentru a plasa corpul unei funcții direct în textul programului
 - __mutable__ — Specificatorul de tip permite unui membru al unui obiect să suprascrie proprietatea de persistență
 - __namespace__ — Cuvânt cheie pentru crearea unui spațiu de nume
 - __new__ — Operatorul alocă memorie dinamică și returnează un pointer de tipul adecvat în această zonă de memorie
 - __operator__ — Cuvântul cheie operator este folosit pentru a crea funcții de operator supraîncărcate
 - __private__ — specificatorul de acces "privat" care determină modul în care este moștenită clasa de bază
 - __protected__ — specificatorul de acces "protejat" care determină modul în care este moștenită clasa de bază
 - __public__ — specificatorul de acces "public" care determină modul în care este moștenită clasa de bază
 - __reinterpret_cast__ - Operator de turnare tip, convertește un tip într-unul complet diferit
 - __static_cast__ — Operator de turnare de tip, efectuează turnare de tip nepolimorf
 - __template__ — Cuvântul cheie _template_ este folosit pentru a crea funcții și clase generice
 - __this__ — Folosit pentru a indica pointerii către obiectul care a generat apelul la funcția membru
 - __throw__ — Operatorul _throw_ aruncă o excepție
 - __true__ — O constantă logică care are valoarea "adevărat"
 - __try__ - Un bloc de program care conține acea parte a programului care este destinată gestionării erorilor
 - __typeid__ — Operatorul _typeid_ returnează o referință la obiectul _type\_info_ care descrie tipul de obiect căruia îi aparține operatorul _typeid_
 - __typename__ — Un cuvânt cheie care poate fi folosit în locul cuvântului cheie _class_ într-o declarație șablon sau pentru a denota un tip nedefinit
 - __using__ — Mută ​​o variabilă dintr-un spațiu de nume specific în domeniul de aplicare al variabilei globale
 - __virtual__ — Specificator de tip care definește funcțiile virtuale
 - __wchar_t__ — Tip de date caracter pe doi octeți

### simboluri speciale

Semnele de punctuație și caracterele speciale din setul de caractere C/C++ au o varietate de utilizări, de la organizarea textului programului până la definirea sarcinilor efectuate de un compilator sau un program compilat.

Următoarele caractere speciale sunt utilizate în C++:

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

Aceste semne nu precizează operațiunile de efectuat și pot avea semnificații diferite în funcție de context.

Unele semne de punctuație sunt și operatori de limbă.


### Comentarii

Codul sursă poate conține cât comentarii pe o singură linie atât și blocuri de comentarii.

Comentariu pe o singură linie se începe cu simboluri `//` și se consideră până la sfârșitul liniei.

Un bloc de comentarii se definește cu etichete `/*` `*/`, printre care putem specifica orice număr de linii de text.

Comentariile sunt utilizate pe scară largă nu numai pentru a explica codul programului, dar și pentru a crea documentație tehnică. Există o serie de aplicații (Doxygen, JavaDoc etc.) care analizează comentariile și creează documentație în HTML, PDF sau alt format. De asemenea, IDE-urile moderne folosesc comentarii pentru a genera sfaturi pentru cod.

## Tipuri de date de bază și variabile

Fiecare program este conceput pentru a procesa date. Datele sunt numere, șiruri de caractere sau o combinație de numere și șiruri de caractere (date compuse). În consecință, pentru a stoca date și a lucra cu acestea, sunt utilizate "stocare" speciale - _variabile_.

O variabilă este un identificator care desemnează o zonă din memorie. Fiecare variabilă are propriul ei tip.

Tipuri de bază sunt numere întregi, numere reale, tip boolean.

Tipul determină ce valori poate avea o variabilă și câți octeți în memorie va ocupa.

### Numere întregi

 * __char__ - представляет один символ. Занимает в памяти 1 байт. Может хранить любое значение из диапазона от -128 до 127. Переменным типа char можно присвоить один символ в одинарных кавычках.
 * __unsigned char__ - представляет один символ. Занимает в памяти 1 байт (8 бит). Может хранить значение из диапазона от 0 до 255.
 * __short__ -  представляет целое число в диапазоне от –32768 до 32767. Занимает в памяти обычно 2 байта.
 * __int__ - представляет целое число. В зависимости от архитектуры процессора может занимать 2, 4 или 8 байт.
 * __long long__ - представляет целое число в диапазоне от -9223372036854775807 до +9 223 372 036 854 775 807. Занимает в памяти, как правило, 8 байт.

Любое десятичное число рассматривается по умолчанию как значение типов `int` / `long int` / `long long int`` (в зависимости от размера) и при присвоении переменным другим типов будет выполняться преобразование.

Чтобы указать, что число явным образом представляет определенный тип, к числу добавляется определенный суффикс:
 - `unsigned int` – `u` или `U`
 - `long int` – `l` или `L`
 - `unsigned long int` – `ul` или `UL`
 - `long long` – `ll` или `LL`
 - `unsigned long long` – `ull` или `ULL`

### Действительные числа

 * __float__ - представляет вещественное число одинарной точности с плавающей точкой в диапазоне `-3.4E+38` до `3.4E+38`. В памяти занимает 4 байта.
 * __double__ - представляет вещественное число двойной точности с плавающей точкой в диапазоне `-1.7E+308` до `1.7E+308`. В памяти занимает 8 байт.
 * __long double__ - представляет вещественное число двойной точности с плавающей точкой в диапазоне +/- 3.4E-4932 до 1.1E+4932. В памяти занимает 10 байт (80 бит). На некоторых системах может занимать 96 и 128 бит.

### Логический тип

В языке С++ для логических значений существует специальный тип — __bool__. Допустимыми значениями этого типа являются только `true` и `false`, при этом других значений у переменной данного типа быть не может.

Переменная типа __bool__ может занимать в памяти ровно 1 байт.

Тип bool совместим с типом __int__ по присваиванию в обе стороны, при этом `true` переходит в `1`, `false` — в `0`.

При обратном приведении любое число, не равное нулю — переходит в `true`, `0` — в `false`.

Значения логического типа являются результатом выполнения операций сравнения или составленных из сравнений выражений.

В С++ определены следующие операции сравнения:

| оператор | пример |
| -------- | ------ |
| Меньше   | X < Y |
| Больше   | X > Y |
| Меньше или равно | X <= Y |
| Больше или равно | X >= Y |
| Равно    | X == Y |
| Не равно | X != Y |

В языке C++ существует 3 логические операции

 * `&&` - операция И (конъюнкция)
 * `||` - операция ИЛИ (дизъюнкция)
 * `!` – операция НЕ (отрицание)

Логические операции позволяют составить из нескольких простых логических выражений одно более сложное.

| A | B | A && B | A \|\| B | !A |
| ----- | ----- | ------ | ------ | ----- |
| true | true | true | true | false |
| true | false | false | true | false |
| false | true | false | true | true |
| false | false | false | false | true  |

### Переменные

При объявлении переменной сначала указывается её тип, потом, через пробельный символ (символы), название переменной.

```cpp
int variable;
```

Можно определить сразу несколько переменных одного типа, перечислив их через запятую.

```cpp
int a, b, c;
```
Переменную можно сразу инициализировать, присвоив ей значение по умолчанию.

```cpp
int x = 0, y = x;
char chr1 = 10, chr2 = 'x';
```

## Базовые структуры

Простейшая программа на С++ выглядит следующим образом:

```cpp
int main() {
   return 0;
}
```

Простейшая программа на С++ состоит из функции main, называемой точкой входа.

Функция main возвращает целое число – код завершения программы. Также точка входа может иметь входные параметры: аргументы программы, передаваемые при запуске (например, в командной строке).

```cpp
int main(int argc, char** argv) {
   return 0;
}
```

Первый параметр _argc_ содержит количество передаваемых аргументов, второй параметр _argv_ представляет собой массив передаваемых аргументов. Для понимания работы с аргументами точки входа рекомендуется рассмотреть и выполнить следующий код:

```cpp
#include <iostream>

int main(int argc, char **argv) {
  for(int i = 0; i < argc; ++i) {
    std::cout << "argv[ " << i << " ] = " << argv[i] << std::endl;
  }
  return 0;
}
```

### Ветвления

Ветвление является одним из базовых блоков программирования. Оно позволяет выполнять тот или иной код, в зависимости от условия (логическое выражение).

Если блок команд после __else__ пустой, то он может пропускаться.

Если блок команд в условии состоит из одной команды, фигурные скобки могут быть пропущены.

Полный синтаксис ветвления выглядит следующим образом:

```cpp
if(/* условие */) {
    // блок команд 1
}
else {
    // блок команд 2
}
```

Однако могут встречаться и укороченные (упрощенные) формы, в зависимости от сложности конструкции:

```cpp
// блок команд содержит одну команду, фигурные скобки опущены, не рекомендуется
if(/* условие */)
    // команда 1
else
    // команда 2

// нет команд для альтернативного выполнения, блок else пропущен
if(/* условие */) {
    // блок команд
}
```

### Выбор

Конструкция __switch__ / __case__ позволяет сравнить некоторое выражение с набором значений.
После ключевого слова __switch__ в скобках идет сравниваемое выражение. Значение этого выражения последовательно сравнивается со значениями после оператора __сase__. И если совпадение будет найдено, то будет выполняться определенный блок __сase__ и все последующие за ним (если не стоит __break__).

```cpp
switch( /* выражение */) {
   case /* значение_1 */: /* инструкции_1 */;
   case /* значение_2 */: /* инструкции_2 */;
   // ...................
   case /* значение_N */: /* инструкции_N */;
   default: /* инструкции */;
}
```

### Циклы
Циклы являются одной из базовых конструкций языка, позволяющей выполнить ряд одних и тех же команд несколько раз.

В языке C++ существует 3 вида операторов цикла:

 - цикл for;
 - цикл while с предусловием;
 - цикл do…while с постусловием.

Любой из вышеприведенных операторов цикла может быть заменен другим.

Начиная со стандарта С++11 введен цикл «для каждого» (for each).

#### Цикл со счетчиком

Часто возникает необходимость выполнить одну и ту же последовательность действий несколько (N) раз. Для этого используются циклы со счетчиком:

```cpp
for(/* инициализация счетчика */; /* условие */; /* изменение счетчика */) {
    // тело цикла
}
```

_Инициализатор_ выполняется один раз при начале выполнения цикла и представляет установку начальных условий, как правило, это инициализация счетчиков - специальных переменных, которые используются для контроля за циклом.
_Условие_ представляет условие, при соблюдении которого выполняется цикл. Как правило, в качестве условия используется операция сравнения, и если она возвращает ненулевое значение (то есть условие истинно), то выполняется тело цикла, а затем выполняется итерация.
_Итерация_ выполняется после каждого завершения блока цикла и задает изменение параметров цикла. Обычно здесь происходит увеличение счетчиков цикла.

#### Цикл с предусловием

Цикл __while__ с предусловием позволяет выполнить одну и ту же последовательность действий пока проверяемое условие истинно. При этом условие записывается до тела цикла и проверяется до выполнения тела цикла.

```cpp
while (/* условие */) {
    // тело цикла
}
```

#### Цикл с постусловием:

Цикл __while__ с постусловием отличается от цикла с предусловием тем, что сначала выполняется блок цикла, а потом проверяется условие. Если условие истинно, то цикл будет выполнен еще раз, и так до тех пор, пока условие будет истинно.

```cpp
do {
    // тело цикла
}
while (/* условие */);

```

### Функции

Во многих случаях возникает необходимость выполнить ряд команд несколько раз в разных участках кода. В этом случае эти команды можно выделить в отдельный блок, присвоить им имя и использовать по имени.

Функция это именованный блок программного кода. Функция может иметь входные параметры, позволяющие при работе с функцией передавать аргументы (значения, для вычислений).

Имя функции должно отражать / описывать её назначение.

```cpp
/* тип возвращаемого значения */ /* имя функции */(/* параметры */) {
   // тело функции
}
```

Функция может вызываться из любого количества мест в программе. Значения, передаваемые функции, являются аргументами, типы которых должны быть совместимы с типами параметров в определении функции.

```cpp
int sum (int a, int b) {
   return a + b;
}

int value = sum(5, 10);
```

> Термин _аргумент_ относится к значению, которое используется при вызове функции. Переменная, которая принимает этот аргумент, называется _параметром_. Функции, которые принимают аргументы, называются _параметризованными функциями_. [Шилдт]

## Управление памятью

Программы, при работе, используют два вида памяти: стек (__stack__) и куча (__heap__).

Стек (__stack__) - фиксированная память, выделяемая при компиляции. В нее записываятся объявления переменных и изменение размещения переменных в памяти при работе программы невозможно.

Куча (__heap__) - динамическая память, в которой можно выделять участки памяти в процессе работы программы.

### Cсылки

Объявление переменной выделяет память в стеке, в которую можно впоследствии записать некоторое значение. В некоторых случаях возникает необходимость вводить псевдонимы переменных. Данные псевдонимы называются ссылками и объявляются при помощи знака `&` (амперсант).

Пример объявления ссылки:

```cpp
int a = 10;
int& another_ref_a = a;
```

__Ссылка всегда инициализируется, и инициализируется другой переменной.__

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

Так как ссылка представляет собой псевдоним существующей переменной, то изменение значения переменной изменяет значение ссылки.

Чаще всего ссылка используется при объявлении параметров функций.

### Указатели

Языки С / C++ предлагают специализированный тип данных: указатель на область памяти определённого типа.
Значение переменной данного типа представляет собой целое число, которое представляет собой адрес памяти. Размер памяти, на которую указывает данный указатель, определяется прописанным типом данных.

Объявление указателя выполняется указанием типа, потом пишется специальный знак `*`, после которого пишется имя переменной. 

```cpp
// <type> * <pointer_name>;
int * sampleIntPointer;
char * sampleCharPointer;
```

В примере `sampleIntPointer` может содержать адрес участка памяти в 4 байта.

Чтобы проинициализировать указатель, в переменную необходимо записать адрес ячейки памяти. Взятие адреса переменной выполняется при помощи специального символа `&`.

Пример работы с указателями:

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

Поведение ссылки похоже на поведение константного указателя.

### Выделение и освобождение памяти

### Массивы