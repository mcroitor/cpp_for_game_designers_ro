# Operații

- [Operații](#operații)
  - [Noțiunea de operație](#noțiunea-de-operație)
  - [Operații aritmetice](#operații-aritmetice)
  - [Operații pe biți](#operații-pe-biți)
  - [Incrementare și Decrementare](#incrementare-și-decrementare)
  - [Operatori compuși](#operatori-compuși)
  - [Operații logice](#operații-logice)
  - [Prioritatea operatorilor](#prioritatea-operatorilor)
  - [Supraîncărcarea operatorilor](#supraîncărcarea-operatorilor)
  - [Operatorul de comparație](#operatorul-de-comparație)
  - [Operatorul „spaceship”](#operatorul-spaceship)
  - [Referințe](#referințe)

## Noțiunea de operație

În sens general, o operație este o acțiune (proces) efectuată asupra uneia sau mai multor valori, numite _operanzi_. Această acțiune este definită de un _operator_ – o construcție specială a limbajului.

Operațiile pot fi:

- _unare_ – cu un singur operand. Exemplu: incrementarea, schimbarea semnului unui număr;
- _binare_ – cu doi operanzi. Exemplu: adunarea, înmulțirea, „sau”;
- _ternare_ – cu trei operanzi.

## Operații aritmetice

În limbajul C/C++ sunt suportate următoarele operații aritmetice:

- `+` – adunare;
- `-` – scădere;
- `*` – înmulțire;
- `/` – împărțire;
- `%` – restul împărțirii.

Operațiile aritmetice pot fi aplicate pentru:

- tipuri întregi;
- tipuri cu virgulă mobilă (tipuri reale);
- tipuri (clase) care au operatorii aritmetici supraîncărcați.

Dacă într-o expresie aritmetică se folosesc operanzi de tipuri diferite, compilatorul convertește implicit operandul de tip mai mic la tipul operandului de tip mai mare.

Operatorii `+` și `–` pot fi folosiți și ca unari, pentru schimbarea semnului expresiei.

Operatorul `%` se folosește doar pentru tipuri întregi.

Dacă la împărțire ambii operanzi sunt întregi, rezultatul va fi tot un număr întreg.

## Operații pe biți

Limbajul C/C++ suportă următoarele operații logice pe biți (bitwise):

- `&` – ȘI pe biți (AND);
- `^` – XOR pe biți (sau exclusiv);
- `|` – SAU pe biți (OR);
- `~` – inversare pe biți (NOT).

Există și operații de deplasare pe biți:

- `<<` – deplasare la stânga a valorii operandului stâng cu numărul de biți dat de operandul drept;
- `>>` – deplasare la dreapta a valorii operandului stâng cu numărul de biți dat de operandul drept.

| __bit1__ | __bit2__ | `&` | `\|` | `^` | `~` |
| -------- | -------- | --- | ---- | --- | --- |
| 0 | 0 | 0 | 0 | 0 | 1 |
| 0 | 1 | 0 | 1 | 1 | 1 |
| 1 | 0 | 0 | 1 | 1 | 0 |
| 1 | 1 | 1 | 1 | 0 | 0 |

Exemplu de operații pe biți cu numerele 17 și 45:

| Expresie   | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | Rezultat |
| ---------- | --- | -- | -- | -- | - | - | - | - | -------- |
| `17`       | 0   | 0  | 0  | 1  | 0 | 0 | 0 | 1 | 17       |
| `45`       | 0   | 0  | 1  | 0  | 1 | 1 | 0 | 1 | 45       |
| `17 & 45`  | 0   | 0  | 0  | 0  | 0 | 0 | 0 | 1 | 1        |
| `17 \| 45` | 0   | 0  | 1  | 1  | 1 | 1 | 0 | 1 | 61       |
| `17 ^ 45`  | 0   | 0  | 1  | 1  | 1 | 1 | 0 | 0 | 60       |
| `~17`      | 1   | 1  | 1  | 0  | 1 | 1 | 1 | 0 | 238      |

## Incrementare și Decrementare

În C++ sunt definiți doi operatori care măresc sau micșorează o valoare întreagă cu 1:

- operatorul `++` – incrementare;
- operatorul `--` – decrementare.

Acești operatori sunt unari, adică necesită un singur operand. Pot fi plasați înainte sau după operand.

- `A++` este echivalent cu `A = A + 1`. Returnează valoarea inițială a lui _A_.
- `++A` este echivalent cu `A = A + 1`. Returnează valoarea modificată a lui _A_.
- `A--` este echivalent cu `A = A - 1`. Returnează valoarea inițială a lui _A_.
- `--A` este echivalent cu `A = A - 1`. Returnează valoarea modificată a lui _A_.

## Operatori compuși

Operatorii compuși permit efectuarea unei operații aritmetice și atribuirea rezultatului primului operand.

Sunt definite următoarele operații compuse: `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`.

De exemplu, `A += B` este echivalent cu `A = A + B`.

## Operații logice

Operațiile logice sunt elemente de bază ale expresiilor logice și sunt folosite la organizarea logicii condiționale, de exemplu în ramificații (`if`) sau bucle (`while`, `for`).

În C++ există 3 operații logice:

- `&&` – ȘI logic (conjuncție);
- `||` – SAU logic (disjuncție);
- `!` – NU logic (negație).

Operațiile logice permit combinarea mai multor expresii logice simple într-una mai complexă.

Tabelul de adevăr pentru operațiile logice:

| `A`   | `B`   | `A && B` | `A \|\| B` | `!A`  |
| ----- | ----- | -------- | ---------- | ----- |
| true  | true  | true     | true       | false |
| true  | false | false    | true       | false |
| false | true  | false    | true       | true  |
| false | false | false    | false      | true  |

## Prioritatea operatorilor

| prioritate | operator | descriere | grupă |
| ---------- | -------- | --------- | ----- |
| 1 | `::` | Rezoluția domeniului | acces |
| 2 | `.`  | Acces membru obiect | acces |
| 2 | `->` | Acces membru pointer | acces |
| 2 | `[]` | Indexare tablou | acces |
| 2 | `()` | Apel funcție | altele |
| 2 | `++` | Incrementare postfixată | incrementare/decrementare |
| 2 | `--` | Decrementare postfixată | incrementare/decrementare |
| 2 | `typeid` | Nume tip | speciale |
| 2 | `const_cast` | Conversie const | speciale |
| 2 | `dynamic_cast` | Conversie dinamică | speciale |
| 2 | `reinterpret_cast` | Conversie reinterpretată | speciale |
| 2 | `static_cast` | Conversie statică | speciale |
| 3 | `sizeof` | Dimensiunea obiectului sau tipului | speciale |
| 3 | `++` | Incrementare prefixată | incrementare/decrementare |
| 3 | `--` | Decrementare prefixată | incrementare/decrementare |
| 3 | `~` | Negare pe biți | aritmetice |
| 3 | `!` | Negare logică | logice |
| 3 | `-` | Minus unar | aritmetice |
| 3 | `+` | Plus unar | aritmetice |
| 3 | `&` | Adresă | acces |
| 3 | `*` | Dereferențiere | acces |
| 3 | `new` | Alocare obiect | speciale |
| 3 | `delete` | Ștergere obiect | speciale |
| 3 | `()` | Conversie tip | speciale |
| 4 | `.*` | Acces pointer la membru obiect | acces |
| 4 | `->*` | Acces pointer la membru pointer | acces |
| 5 | `*` | Înmulțire | aritmetice |
| 5 | `/` | Împărțire | aritmetice |
| 5 | `%` | Modulo | aritmetice |
| 6 | `+` | Adunare | aritmetice |
| 6 | `-` | Scădere | aritmetice |
| 7 | `<<` | Deplasare la stânga | aritmetice |
| 7 | `>>` | Deplasare la dreapta | aritmetice |
| 8 | `<=>` | Comparație spațială | comparații |
| 9 | `<` | Mai mic | comparații |
| 9 | `>` | Mai mare | comparații |
| 9 | `<=` | Mai mic sau egal | comparații |
| 9 | `>=` | Mai mare sau egal | comparații |
| 10 | `==` | Egalitate | comparații |
| 10 | `!=` | Diferență | comparații |
| 11 | `&` | ȘI pe biți | aritmetice |
| 12 | `^` | XOR pe biți | aritmetice |
| 13 | `\|` | SAU pe biți | aritmetice |
| 14 | `&&` | ȘI logic | logice |
| 15 | `\|\|` | SAU logic | logice |
| 16 | `?:` | Operator ternar | altele |
| 16 | `=` | Atribuire | atribuire |
| 16 | `*=` | Atribuire cu înmulțire | atribuire |
| 16 | `/=` | Atribuire cu împărțire | atribuire |
| 16 | `%=` | Atribuire cu modulo | atribuire |
| 16 | `+=` | Atribuire cu adunare | atribuire |
| 16 | `-=` | Atribuire cu scădere | atribuire |
| 16 | `<<=` | Atribuire cu deplasare la stânga | atribuire |
| 16 | `>>=` | Atribuire cu deplasare la dreapta | atribuire |
| 16 | `&=` | Atribuire cu ȘI pe biți | atribuire |
| 16 | `\|=` | Atribuire cu SAU pe biți | atribuire |
| 16 | `^=` | Atribuire cu XOR pe biți | atribuire |
| 17 | `,` | Virgulă (separator de comenzi) | altele |

## Supraîncărcarea operatorilor

Adesea, pentru comoditate, este util să redefinim un operator pentru o clasă (de exemplu, + pentru vectori). Astfel, codul devine mai compact și mai ușor de înțeles. Forma generală a definirii unui operator este:

`<tip_returnat> operator <semn_operator> (<parametri_operator>);`

Operatorii pot fi unari (lucrează cu un singur obiect) sau binari (lucrează cu două obiecte). Exemple de operatori unari: `++`, `--`, `*` (dereferențiere). Exemple de operatori binari: `+`, `+=`, `*` (înmulțire), `==`.

Operatorii sunt funcții cu nume speciale. Ei pot fi declarați atât în interiorul clasei, cât și în afara acesteia. Exemplu de supraîncărcare a operatorilor:

```cpp
class int_pair{
    int first, second;
public:
    int_pair(int f = 0, int s = 0): first(f), second(s) {}
    bool operator == (const int_pair& p) const {
        return (first == p.first) && (second == p.second);
    }
    std::string to_string() const {
        return "[ " + std::to_string(first) + ", " + std::to_string(second) + " ]";
    }
};

bool operator != (const int_pair& p1, const int_pair& p2){
    return !(p1 == p2);
}

std::ostream& operator << (std::ostream& out, const int_pair& p) {
    out << p.to_string();
    return out;
}
```

Operatorii unari se declară ca membri ai clasei. Operatorii binari pot fi declarați atât în interiorul, cât și în afara clasei. Operatorul binar declarat în interiorul clasei are un singur parametru (primul operand este obiectul curent). Operatorii binari declarați în afara clasei au doi parametri.

 > __Recomandare:__ pentru a decide unde să definiți operatorul – în interiorul sau în afara clasei – întrebați-vă dacă operatorul modifică operanzii săi. Dacă da, operatorul ar trebui să fie membru al clasei. Dacă nu, este mai bine să-l definiți în afara clasei. De exemplu, operatorul de atribuire modifică operandul din stânga, deci e mai bine să fie membru al clasei; operatorul de adunare nu modifică operanzii, deci e mai bine să fie definit în afara clasei.

Exemplu de supraîncărcare a operatorilor pentru un vector bidimensional:

```cpp
class vector{
    float x, y;
public:
    vector(float p1 = 0, float p2 = 0): x(p1), y(p2) {}
    vector& operator = (const vector& p){
        x = p.x;
        y = p.y;
        return *this;
    }
    void operator += (const vector& p){
        x += p.x;
        y += p.y;
    }
};

vector operator + (const vector& p1, const vector& p2){
    vector tmp = p1;
    tmp += p2;
    return tmp;
}
```

Nu toți operatorii pot fi supraîncărcați în C++. De exemplu, operatorii `::`, `.`, `.*`, `?:` nu pot fi redefiniți.

## Operatorul de comparație

Pentru compararea obiectelor se folosește operația de bază `a == b`, iar operația `a != b` este derivată din aceasta.

```cpp
class int_pair{
    int first, second;
public:
    // ...
    // operator de comparație
    bool operator == (const int_pair& p) const {
        return (first == p.first) && (second == p.second);
    }
};

bool operator != (const int_pair& p1, const int_pair& p2){
    return !(p1 == p2);
}
```

## Operatorul „spaceship”

Până la standardul `C++20`, pentru ordonare se folosea operatorul de bază `<` (_mai mic_). Ceilalți operatori erau derivați din acesta și implementați în biblioteca standard, în spațiul de nume `std::rel_ops`.

Începând cu standardul `C++20`, a fost introdus operatorul de comparație triplă (en. __spaceship__ – „nava spațială”) – `<=>`, care a devenit baza pentru operațiile de ordonare. Semantica operatorului este următoarea:

- `a <=> b` este mai mic decât zero dacă `a < b`;
- `a <=> b` este mai mic sau egal cu zero dacă `a <= b`;
- `a <=> b` este mai mare decât zero dacă `a > b`;
- `a <=> b` este mai mare sau egal cu zero dacă `a >= b`.

Dacă acest operator este definit, compilatorul va genera automat toți operatorii de ordonare pe baza lui.

```cpp
/**
 * @file spaceship.cpp
 * @brief Exemplu de utilizare a operatorului spaceship
 * @details g++ -std=c++20 spaceship.cpp
 */
#include <iostream>
class int_pair{
    int first, second;
public:
    // ...
    // spaceship
    auto operator <=> (const int_pair& p) const {
        return first <=> p.first;
    }
};
// ...
int main() {
    int_pair pair(2, 3);
    int_pair pair2(1, 5);
    bool result = pair < pair2;
    std::cout << pair << std::endl;
    return 0;
}
```

> Pentru o compatibilitate maximă, este recomandat să specificați explicit tipul de returnare, de exemplu `std::strong_ordering`.

## Referințe

1. [C++ Operator Precedence, cppreference.com](https://en.cppreference.com/w/cpp/language/operator_precedence)
2. [Andrey2008, Operații de comparație în C++20, Habr: Pvs-Studio](https://habr.com/ru/companies/pvs-studio/articles/465575/)
