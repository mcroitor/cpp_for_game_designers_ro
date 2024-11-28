# Instrumente adiționale ale limbajului C++

- [Instrumente adiționale ale limbajului C++](#instrumente-adiționale-ale-limbajului-c)
  - [expresii lambda](#expresii-lambda)
  - [formatarea textului](#formatarea-textului)
  - [literals](#literals)
  - [semantica move](#semantica-move)
  - [Tupluri](#tupluri)
  - [interval (ranges)](#interval-ranges)
  - [smart-pointeri](#smart-pointeri)
  - [valarray](#valarray)
  - [variant, optional, any](#variant-optional-any)
  - [expresii regulate](#expresii-regulate)
  - [Bibliografie](#bibliografie)

## expresii lambda

Începând cu standardul `C++11` în limbaj a fost introdusă posibilitatea de a scrie calcule într-o formă compactă - sub forma __expresiilor lambda__.

Sintaxa expresiilor lambda:

```cpp
[/*capture*/](/*params*/) -> /*type*/ { /*code*/; }
```

Exemplu de definire / utilizare a unei expresii lambda:

```cpp
// expresie lambda cu nume
auto sum = [](int a, int b) { return a + b; };
auto result = sum(a, b);

// definirea expresiei lambda în locul utilizării
std::cout << [](int a, int b) { return a + b; }(10, 15);
```

Implicit expresiile lambda nu au acces la variabilele externe, dar în paranteze pătrate se pot enumera toate variabilele care trebuie să fie accesibile în expresia lambda.

```cpp
int a = 10;

std::cout << [a]{ return a; }();
```

Expresiile lambda pot fi generice (generic lambda function) dacă cel puțin unul dintre parametrii este declarat ca `auto`.

```cpp
int arr[] {1, 2, 3, 4, 5, 6};

std::for_each(arr, arr + 6, [](auto el){ std::cout << el << " ";});
```

## formatarea textului

Începând cu standardul `C++20` în biblioteca standard a fost introdusă posibilitatea de a formata textul cu ajutorul funcției `std::format`. Funcția `std::format` primește ca argumente un șir de formatare și argumentele care vor fi plasate în șir. Șirul de formatare conține specificatori de format care încep cu caracterul `{` și se termină cu caracterul `}`.

```cpp
#include <format>
#include <iostream>

int main()
{
    std::string name = "John";
    int age = 25;

    std::string result = std::format("Name: {}, Age: {}", name, age);
    std::cout << result << std::endl;
    return 0;
}
```

Specificatorii de format pot avea următoarele elemente, în ordinea apariției lor:

```text
[[fill]align][sign][#][0][width][.precision][type]
```

- `fill` - simbolul care va fi utilizat pentru umplerea spațiilor goale;
- `align` - alinierea: `<` - la stânga, `>` - la dreapta, `^` - în centru;
- `sign` - semnul numărului: `+` - întotdeauna, `-` - doar pentru numere negative, ` ` - spațiu pentru numere pozitive;
- `#` - forma alternativă de afișare;
- `0` - umplere cu zerouri;
- `width` - lățimea minimă a câmpului;
- `precision` - numărul de zecimale;
- `type` - tipul de date: `f` - număr real, `g` - format general, `e` - format exponențial, `x` - număr hexazecimal etc.

Mai jos este prezentat un exemplu de utilizare a funcției `std::format` pentru afișarea unui tabel:

```cpp
#include <format>
#include <iostream>
#include <vector>

int main()
{
  std::vector<std::tuple<std::string, std::string, int>> data = {
    {"John", "Doe", 25},
    {"Jane", "Smith", 30},
    {"Alice", "Brown", 35}
  };

  std::cout << std::format("| {:<10} | {:<10} | {:>3} |", "First", "Last", "Age") << std::endl;
  std::cout << std::format("|{:-^12}|{:-^12}|{:-^5}|", "", "", "") << std::endl;
  for (const auto& [first, last, age] : data)
  {
    std::string result = std::format("| {:<10} | {:<10} | {:>3} |", first, last, age);
    std::cout << result << std::endl;
  }
  return 0;
}
```

## literals

În programare __literalul__ este o reprezentare a unei valori constante. În limbajul de programare C++ există șase tipuri de literal:

- numere întregi: `312`, `-1ll`
- numere reale: `12.29`
- caractere: `'a'`
- șiruri de caractere: `"sample"`
- valori logice: `true` și `false`
- pointeri: `nullptr`

Începând cu standardul `C++11` a fost introdusă posibilitatea de a defini literal-uri personalizate. Literal-urile personalizate sunt folosite pentru a crea obiecte de tipuri de date definite de utilizator.

```cpp
ReturnType operator "" _a(unsigned long long int);   // Literal operator for user-defined INTEGRAL literal
ReturnType operator "" _b(long double);              // Literal operator for user-defined FLOATING literal
ReturnType operator "" _c(char);                     // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _d(wchar_t);                  // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _e(char16_t);                 // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _f(char32_t);                 // Literal operator for user-defined CHARACTER literal
ReturnType operator "" _g(const char*, size_t);      // Literal operator for user-defined STRING literal
ReturnType operator "" _h(const wchar_t*, size_t);   // Literal operator for user-defined STRING literal
ReturnType operator "" _i(const char16_t*, size_t);  // Literal operator for user-defined STRING literal
ReturnType operator "" _g(const char32_t*, size_t);  // Literal operator for user-defined STRING literal
ReturnType operator "" _r(const char*);              // Raw literal operator
template<char...> ReturnType operator "" _t();       // Literal operator template
```

Nume de sufixe pentru literal-uri personalizate pot fi orice secvență de caractere permise (se aplică regula de numirea variabilelor).

Exemple:

```cpp
// volume in liters
using volume_t = long double;

constexpr volume_t operator "" _l(long double volume){
    return volume;
}

constexpr volume_t operator "" _ml(long double volume){
    return 0.001 * volume;
}

constexpr volume_t operator "" _m3(long double volume){
    return 1000.0 * volume;
}

volume_t volume = 12.2_l + 2.1_m3 - 300.0_ml;
```

## semantica move

Sub semantica __move__ se înțelege un set de mijloace specializate ale limbajului C++, care permit evitarea costurilor de copiere a obiectelor la crearea unui obiect nou. Elementele de bază ale semanticii de mutare sunt constructorul de mutare și operatorul de atribuire de mutare.

Semantica de mutare este folosită pentru a evita copierea obiectelor temporare, ce permite creșterea eficienței programelor.

```cpp
my_string a = "hell", b = "o";
my_string result = a + b;
```

În exemplu dat în rezultatul adunării a două obiecte de tip `my_string` va fi creat un obiect temporar, care va fi copiat în variabila `result`. După aceasta obiectul temporar va fi distrus. Pentru a evita copierea obiectului temporar, se poate folosi semantica de mutare. Operatorul de copiere va avea în acest caz următoarea sintaxă:

```cpp
T& operator = (T&& other);
```

Exemplu de cod:

```cpp
class my_string {
public:
  my_string& operator=(my_string&& other) {
    if (this != &other) {
      delete[] this->_data;
      this->_data = other._data;
      other._data = nullptr;
    }
    return *this;
  }

private:
  char*_data;
};
```

Această realizare poate fi simplificată prin utilizarea funcției standard `std::move`, care realizează semantica de mutare a obiectului:

```cpp
class my_string {
public:
  my_string(my_string&& other): _data(std::move(other)){}

  my_string& operator=(my_string&& other) {
    _data = std::move(other._data);
    return *this;
  }

private:
  char*_data;
};
```

## Tupluri

Tupluri sunt structuri de date care permit păstrarea mai multor elemente de tipuri diferite. Tuplurile sunt definite în fișierul antet `<tuple>`. Tuplurile pot fi folosite pentru a returna mai multe valori dintr-o funcție.

Un exemplu de utilizare a tuplurilor:

```cpp
#include <tuple>
#include <iostream>

std::tuple<int, double, std::string> get_data()
{
    return {10, 3.14, "Hello"};
}

int main()
{
    auto [a, b, c] = get_data();
    std::cout << a << " " << b << " " << c << std::endl;

    std::tuple<int, double, std::string> values = {10, 3.14, "Hello"};
    std::cout << std::get<0>(values) << " " 
              << std::get<1>(values) << " " 
              << std::get<2>(values) << std::endl;
    return 0;
}
```

## interval (ranges)

Majoritatea algoritmelor STL operează cu intervale de containere definite ca perechi de iteratori. De aceea în biblioteca standard, începând cu standardul `C++20`, este prezentată generalizarea intervalelor ca perechi de iteratori.

Biblioteca de intervale (`ranges`) definește următoarele concepte:

- `range` - interval, care este o pereche de iteratori: început și sfârșit. Definit în spațiul de nume `std::ranges`.
- `view` - adaptor de interval, care oferă posibilitatea de a transforma și filtra elementele intervalului. Definit în spațiul de nume `std::ranges::views`.
- `algorithm` - algoritmi care primesc intervale ca argumente. Definiți în spațiul de nume `std::ranges::algorithm`.

Exemplu de utilizare a intervalelor:

```cpp
#include <ranges>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto result = std::ranges::accumulate(numbers, 0);

    std::cout << "Sum: " << result << std::endl;
    return 0;
}
```

Utilizarea adaptatoarelor de intervale se bazează pe ideile programării funcționale, care permit procesarea în cascada a datelor. Pentru a implementa procesarea în cascada a datelor se folosește suprascrierea operatorului `|` pentru a transmite date între adaptatoare.

Unele adaptere de intervale interesante:

- `views::all` - transformarea unui container într-un interval
- `views::filter` - selectarea elementelor în funcție de o proprietate
- `views::transform` - transformarea fiecărui element
- `views::take` - selectarea primelor _N_ elemente
- `views::take_while` - selectarea elementelor până la îndeplinirea unei condiții
- `views::drop` - eliminarea primelor _N_ elemente
- `views::drop_while` - eliminarea elementelor până la îndeplinirea unei condiții
- `views::for_each` - aplicarea unei funcții fiecărui element
- `views::reverse` - ordinea inversă a elementelor
- `views::join` - unirea secvențelor
- `views::split` - divizarea secvenței în subsecvențe
- `views::keys` - selectarea cheilor dintr-o pereche, tuplu sau container asociativ
- `views::values` - selectarea valorilor dintr-o pereche, tuplu sau container asociativ
- `views::zip` - unirea a mai multor secvențe într-una, elementele cu aceleași indici sunt unite într-un tuplu

Un exemplu de utilizare a adaptatoarelor de intervale:

```cpp
#include <ranges>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // select even numbers, multiply by 2 and print them
    auto result = numbers | std::views::filter([](int el){ return el % 2 == 0; })
            | std::views::transform([](int el){ return el * 2; });
    
    result | std::views::for_each([](int el){ std::cout << el << " "; });

    return 0;
}
```

## smart-pointeri

Începând cu standardul `C++11` biblioteca standardă propune o abstractizare (înveliș) peste pointeri, care eliberează automat memoria la terminarea utilizării variabilelor.

Există următoarele tipuri de smart-pointer:

- `unique_ptr` - la copierea obiectului smart-pointer `Ptr1` în `Ptr2` memoria devine proprietatea `Ptr2`, iar `Ptr1` referă la `nullptr`.
- `shared_ptr` - la copierea obiectului smart-pointer `Ptr1` în `Ptr2` ambele variabile referă la aceeași memorie; eliberarea memoriei se face la ștergerea ambelor variabile.
- `weak_ptr` - referință _slabă_ la memoria alocată: nu poate șterge / modifica memoria și întotdeauna referă la memoria creată de `shared_ptr`.

## valarray

Clasa generică `std::valarray` este definită în fișer antet `valarray`. Această clasă permite efectuarea operațiilor aritmetice asupra vectorilor.

Un exemplu de utilizare:

```cpp
std::valarray<int> a{1, 2, 3};
std::valarray<int> b{1, 2, 3};
std::valarray<int> result = a * 5 + b;
result = result.apply([](int el){ return el - 1; });
for (auto element : result)
{
    std::cout << element << " ";
}
```

## variant, optional, any

Containerele speciale `std::variant`, `std::optional`, `std::any` permit stocarea valorilor de diferite tipuri într-un singur obiect.

- `std::variant` - permite stocarea a mai multe tipuri de date, dar în același timp permite accesul la un singur tip de date.
- `std::optional` - permite stocarea unui singur tip de date sau a unui tip de date nul.
- `std::any` - permite stocarea a orice tip de date.

Exemplu de utilizare:

```cpp
#include <optional>
#include <iostream>

std::optional<int> divide(int a, int b)
{
    if (b == 0)
    {
        return std::nullopt;
    }
    return a / b;
}

int main()
{
    auto result = divide(10, 0);

    if (result.has_value())
    {
        std::cout << "Result: " << result.value() << std::endl;
    }
    else
    {
        std::cout << "Division by zero" << std::endl;
    }
    return 0;
}
```

## expresii regulate

> __Expresie regulată__ este un limbaj formal care descrie șabloane șirurilor de caractere. Acestea sunt folosite pentru a căuta, înlocui și valida șiruri de caractere.

Totodată biblioteca standard C++ oferă posibilitatea de a lucra cu expresii regulate. Pentru aceasta se folosește clasa `std::regex`. Pentru a lucra cu expresii regulate este necesar să se includă fișierul antet `<regex>`.

Următorul exemplu verifică dacă șirul este un email valid:

```cpp
#include <regex>
#include <iostream>

int main()
{
    std::string email = "an@email.example";
    std::regex pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");

    if (std::regex_match(email, pattern))
    {
        std::cout << "Valid email" << std::endl;
    }
    else
    {
        std::cout << "Invalid email" << std::endl;
    }
    return 0;
}
```

## Bibliografie

1. [Standard format specification, cppreference.com](https://en.cppreference.com/w/cpp/utility/format/spec)
2. [User-defined literals, cppreference.com](https://en.cppreference.com/w/cpp/language/user_literal)
3. [Ranges library, cppreference.com](https://en.cppreference.com/w/cpp/ranges)
4. [Smart pointers, cppreference.com](https://en.cppreference.com/w/cpp/memory)
5. [valarray, cppreference.com](https://en.cppreference.com/w/cpp/numeric/valarray)
6. [variant, cppreference.com](https://en.cppreference.com/w/cpp/utility/variant)
7. [optional, cppreference.com](https://en.cppreference.com/w/cpp/utility/optional)
8. [any, cppreference.com](https://en.cppreference.com/w/cpp/utility/any)
9. [Regular expressions, cppreference.com](https://en.cppreference.com/w/cpp/regex)
