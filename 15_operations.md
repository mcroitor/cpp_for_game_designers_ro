# Operații

- [Operații](#operații)
  - [Noțiune de operație](#noțiune-de-operație)
  - [Operații aritmetice](#operații-aritmetice)
  - [Operații pe biți](#operații-pe-biți)
  - [Increment / decrement](#increment--decrement)
  - [Operatori compuși](#operatori-compuși)
  - [Operații logice](#operații-logice)
  - [Prioritatea operațiilor](#prioritatea-operațiilor)
  - [Supraincarcarea operatorilor](#supraincarcarea-operatorilor)
  - [Operator de comparare](#operator-de-comparare)
  - [Operator de comparare în trei sensuri](#operator-de-comparare-în-trei-sensuri)
  - [Bibiliografie](#bibiliografie)

## Noțiune de operație

În sens general, operația este o acțiune (proces) efectuată asupra unei sau mai multor valori, numite _operanzi_. Această acțiune este definită de _operator_ - o construcție specială a limbajului.

Operațiile sunt:

- _unare_ - cu un singur operand. Exemplu de operație unară - incrementare, schimbarea semnului unui număr;
- _binare_ - cu doi operanzi. Exemplu de operație binară - adunare, înmulțire, `sau`;
- _ternare_ - cu trei operanzi.

## Operații aritmetice

În limbajul C/C++ sunt suportate următoarele operații aritmetice:

- `+` – adunare;
- `-` – scădere;
- `*` – înmulțire;
- `/` – împărțire;
- `%` – restul împărțirii.

Operațiile aritmetice pot fi aplicate pentru:

- tipuri de date întregi;
- tipuri cu virgulă mobilă (reale);
- tipuri (clase) care conțin operații aritmetice supraincarcate.

Dacă în expresie aritmetică sunt folosite operanzi de tipuri diferite, compilatorul va converti implicit operandul de tip mai mic la tipul operandului mai mare.

Operațiile `+` și `-` pot fi utilizate ca unare, pentru a schimba semnul expresiei.

Operația `%` este utilizată numai pentru tipuri de date întregi.

Dacă în operația de împărțire operandele sunt de tip întreg, rezultatul va fi întreg.

## Operații pe biți

Limbajul C/C++ suportă următoarele operații pe biți

- `&` - ȘI (AND) pe biți;
- `^` - XOR (sau SAU exclusiv) pe biți;
- `|` - SAU (OR) pe biți;
- `~` - negarea pe biți (NOT).

Totodată, există operații de deplasare pe biți:

- `<<` - deplasare la stânga a valorii operandului stâng cu numărul de biți specificat de operandul drept;
- `>>` - deplasare la dreapta a valorii operandului stâng cu numărul de biți specificat de operandul drept.

| __bit 1__ | __bit 2__ | `&` | `\|` | `^` | `~` |
| --------- | --------- | --- | ---- | --- | --- |
|         0 |         0 |   0 |    0 |   0 |   1 |
|         0 |         1 |   0 |    1 |   1 |   1 |
|         1 |         0 |   0 |    1 |   1 |   0 |
|         1 |         1 |   1 |    1 |   0 |   0 |

Următorul exemplu arată operațiile pe biți pentru numerele 17 și 45:

| Expresie   | 128 | 64 | 32 | 16 | 8 | 4 | 2 | 1 | Rezultat |
| ---------- | --- | -- | -- | -- | - | - | - | - | -------- |
| `17`       | 0   | 0  | 0  | 1  | 0 | 0 | 0 | 1 | 17       |
| `45`       | 0   | 0  | 1  | 0  | 1 | 1 | 0 | 1 | 45       |
| `17 & 45`  | 0   | 0  | 0  | 0  | 0 | 0 | 0 | 1 | 1        |
| `17 \| 45` | 0   | 0  | 1  | 1  | 1 | 1 | 0 | 1 | 61       |
| `17 ^ 45`  | 0   | 0  | 1  | 1  | 1 | 1 | 0 | 0 | 60       |
| `~17`      | 1   | 1  | 1  | 0  | 1 | 1 | 1 | 0 | 238      |

## Increment / decrement

În limbajul C++ definite două operații care efectuează creșterea sau scăderea unei valori întregi cu 1:

- operator `++` – incrementare;
- operator `––`  – decrementare.

Acestea operatori sunt unari, adică necesită un singur operand. Acești operatori pot fi plasați înainte și după operand.

- `A++` - este echivalent cu `A = A + 1`. Returnează valoarea inițială a _A_;
- `++A` - este echivalent cu `A = A + 1`. Returnează valoarea modificată a _A_;
- `A--` - este echivalent cu `A = A - 1`. Returnează valoarea inițială a _A_;
- `--A` - este echivalent cu `A = A - 1`. Returnează valoarea modificată a _A_.

## Operatori compuși

Operatori compuși permit efectuarea unei operații aritmetice și atribuirea rezultatului în primul operand.

Sunt definite următoarele operatori compuși: `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`.

De exemplu, `A += B` este echivalent cu `A = A + B`.

## Operații logice

Operații logice sunt elemente compuse ale expresiilor logice și sunt utilizate pentru organizarea logicii condiționale, de exemplu, în ramificări (`if`) sau cicluri (`while`, `for`).

Limbajul suportă următoarele operații logice:

- `!` - negarea logică (NOT);
- `&&` - conjuncția logică (AND);
- `||` - disjuncția logică (OR).

Operațiile logice permit formarea unei expresii logice complexe din mai multe expresii logice simple.

Regulile operațiilor logice sunt prezentate în tabelul următor:

| `A`   | `B`   | `A && B` | `A \|\| B` | `!A`  |
| ----- | ----- | -------- | ---------- | ----- |
| true  | true  | true     | true       | false |
| true  | false | false    | true       | false |
| false | true  | false    | true       | true  |
| false | false | false    | false      | true  |

## Prioritatea operațiilor

| prioritate | operator | descriere | grup   |
| ---------- | -------- | --------- | ------ |
| 1 | `::` | rezolvarea domeniului | acces |
| 2 | `.`  | selectarea membrului obiectului | acces |
| 2 | `->` | selectarea membrului pentru pointer la obiect | acces |
| 2 | `[]` | indexarea array-ului | acces |
| 2 | `()` | apelul funcției | altul |
| 2 | `++` | incrementare postfixată | incrementare / decrementare |
| 2 | `--` | decrementare postfixată | incrementare / decrementare |
| 2 | `typeid` | numele tipului | special |
| 2 | `const_cast` | conversie constantă a tipului | special |
| 2 | `dynamic_cast` | conversie dinamică a tipului | special |
| 2 | `reinterpret_cast` | conversie interpretativă a tipului | special |
| 2 | `static_cast` | conversie statică a tipului | special |
| 3 | `sizeof` | dimensiunea obiectului sau tipului | special |
| 3 | `++` | incrementare prefixată | incrementare / decrementare |
| 3 | `--` | decrementare prefixată | incrementare / decrementare |
| 3 | `~` | complement la unu (complement bit) | aritmetic |
| 3 | `!` | negarea logică | logic |
| 3 | `-` | negarea unară | aritmetic |
| 3 | `+` | plus unar | aritmetic |
| 3 | `&` | luarea adresei | acces |
| 3 | `*` | dereferențierea | acces |
| 3 | `new` | crearea obiectului | special |
| 3 | `delete` | distrugerea obiectului | special |
| 3 | `()` | conversie a tipului | special |
| 4 | `.*` | selectarea pointerului la membrul obiectului | acces |
| 4 | `->*` | pointer la membru (pointer la obiect) | acces |
| 5 | `*` | înmulțire | aritmetic |
| 5 | `/` | împărțire | aritmetic |
| 5 | `%` | modul | aritmetic |
| 6 | `+` | adunare | aritmetic |
| 6 | `-` | scădere | aritmetic |
| 7 | `<<` | deplasare la stânga | aritmetic |
| 7 | `>>` | deplasare la dreapta | aritmetic |
| 8 | `<=>` | comparare | comparare |
| 9 | `<` | mai mic | comparare |
| 9 | `>` | mai mare | comparare |
| 9 | `<=` | mai mic sau egal | comparare |
| 9 | `>=` | mai mare sau egal | comparare |
| 10 | `==` | comparare (egalitate) | comparare |
| 10 | `!=` | nu egal (inegalitate) | comparare |
| 11 | `&` | și pe biți | aritmetic |
| 12 | `^` | sau exclusiv pe biți | aritmetic |
| 13 | `\|` | sau pe biți | aritmetic |
| 14 | `&&` | și logic | logic |
| 15 | `\|\|` | sau logic | logic |
| 16 | `?:` | logic condițional | altul |
| 16 | `=` | atribuire | atribuire |
| 16 | `*=` | atribuire înmulțire | atribuire |
| 16 | `/=` | atribuire împărțire | atribuire |
| 16 | `%=` | atribuire rest împărțire | atribuire |
| 16 | `+=` | atribuire adunare | atribuire |
| 16 | `-=` | atribuire scădere | atribuire |
| 16 | `<<=` | atribuire deplasare la stânga | atribuire |
| 16 | `>>=` | atribuire deplasare la dreapta | atribuire |
| 16 | `&=` | atribuire și pe biți | atribuire |
| 16 | `\|=` | atribuire sau pe biți | atribuire |
| 16 | `^=` | atribuire sau exclusiv pe biți | atribuire |
| 17 | `,` | virgulă (separator de comenzi) | altul |

> __Notă:__ Prioritatea operațiilor este importantă pentru a evita ambiguitățile în evaluarea expresiilor. De exemplu, în expresia `a + b * c` în primul rând se va efectua înmulțirea, apoi adunarea. Dacă prioritatea operatorilor nu este specificată, atunci se va folosi prioritatea implicită.

## Supraincarcarea operatorilor

Deseori, pentru comoditate, este util să se redefinească un operator pentru o clasă (de exemplu, `+` pentru vectori). În acest caz, programul devine mai compact și mai ușor de înțeles. Forma generală a definirii unui operator este următoarea:

`<return_type> operator <operator_sign> (<operator_parametres>);`

Operatorii pot fi unari (care lucrează cu un singur operand) și binari (care lucrează cu doi operanzi). Exemple de operatori unari: `++`, `--`, `*` (operator de dereferențiere). Exemple de operatori binari: `+`, `+=`, `*` (înmulțire), `==`.

Operatorii sunt funcții speciale care au un nume special. Ei pot fi definiti ca funcții membre ale clasei sau ca funcții externe. Exemplu de supraincarcare a operatorilor:

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

Operatoarele unare se declara ca parte a clasei. Operatoarele binare pot fi declarate atât în interiorul clasei, cât și în afara clasei. Operatorul binar declarat în interiorul clasei are doar un parametru de intrare (al doilea parametru al operatorului va fi obiectul, operatorul căruia este apelat). Operatorii binari declarați în afara clasei au doi parametri.

> __Recomandare:__ pentru determinarea locului potrivit pentru definirea operatorului - în interiorul clasei sau în afara ei - întrebați-vă dacă acest operator modifică operanzii săi. Dacă modifică - atunci acest operator este parte a clasei. Dacă nu modifică, atunci cel mai bine este să definiți operatorul în afara clasei. De exemplu, operația de atribuire modifică operandul din dreapta, deci este mai bine să o definiți în interiorul clasei; operația de adunare nu modifică operanzii săi, deci este mai bine să o definiți în afara clasei.

În exemplul următor sunt prezentate modurile de supraincarcare a operatorilor pentru vector bidimensional:

```cpp
class vector{
    float x, y;
public:
    vector(float p1 = 0, float p2 = 0): x(p1), y(p2) {}
    vector operator = (const vector& p){
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
    vector tmp;
    tmp = p1;
    tmp += p2;
    return tmp;
}
```

## Operator de comparare

Pentru a compara obiecte de același tip se folosește operatorul de bază `==` și operatorul `!=` care este derivat din operatorul de bază.

```cpp
class int_pair{
    int first, second;
public:
    // ...
    // operator de comparare
    bool operator == (const int_pair& p) const {
        return (first == p.first) && (second == p.second);
    }
};

bool operator != (const int_pair& p1, const int_pair& p2){
    return !(p1 == p2);
}
```

## Operator de comparare în trei sensuri

Până la standardul `C++20` pentru a ordona obiecte se folosea operația de bază `<` (_mai mic_). Celelalte operații erau derivate din aceasta și implementate în biblioteca standard, în spațiul de nume `std::rel_ops`.

Începând cu standardul `C++20` a fost introdus operatorul de comparare în trei sensuri (en. __spaceship__ - `navă cosmică`) - `<=>`. Semantica operatorului este următoarea:

- `a <=> b` egal cu zero, dacă `a == b`;
- `a <=> b` mai mic decât zero, dacă `a < b`;
- `a <=> b` mai mare decât zero, dacă `a > b`.

Definirea acestui operator pentru un tip de date automat permite compilatorului să genereze toate celelalte operații de comparare.

```cpp
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

## Bibiliografie

1. [C++ Operator Precedence, cppreference.com](https://en.cppreference.com/w/cpp/language/operator_precedence)
2. [Andrey2008, Операции сравнения в C++20, Habr: Pvs-Studio](https://habr.com/ru/companies/pvs-studio/articles/465575/)
