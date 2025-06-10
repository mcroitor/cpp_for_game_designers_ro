# Funcționalități suplimentare ale bibliotecii standard C++

- [Funcționalități suplimentare ale bibliotecii standard C++](#funcționalități-suplimentare-ale-bibliotecii-standard-c)
  - [Expresii lambda](#expresii-lambda)
  - [Formatarea șirurilor de caractere](#formatarea-șirurilor-de-caractere)
  - [Literele definite de utilizator](#literele-definite-de-utilizator)
  - [Semantica mutării](#semantica-mutării)
  - [Tupluri (tuples)](#tupluri-tuples)
  - [Intervale (ranges)](#intervale-ranges)
  - [Pointeri inteligenți](#pointeri-inteligenți)
  - [valarray](#valarray)
  - [variant, optional, any](#variant-optional-any)
  - [Expresii regulate](#expresii-regulate)
  - [Bibliografie](#bibliografie)

## Expresii lambda

Începând cu standardul `C++11`, limbajul permite scrierea calculelor într-o formă compactă – sub forma __expresiilor lambda__.

Sintaxă:

```cpp
[/*captură*/](/*parametri*/) -> /*tip*/ { /*cod*/; }
```

```cpp
// Expresie lambda denumită
auto sum = [](int a, int b) {return a + b;};
auto result = sum(a, b);

// Expresie lambda anonimă, folosită direct
std::cout << [](int a, int b) {return a + b;}(10, 15);
```

Implicit, expresiile lambda nu au acces la variabilele din exterior (cu excepția variabilelor globale și statice), însă în parantezele pătrate pot fi enumerate, separate prin virgulă, variabilele care trebuie să fie accesibile în lambda.

```cpp
int a = 10;

std::cout << [a]{ return a;}();
```

Expresiile lambda pot fi generice (generic lambda) dacă cel puțin un parametru este declarat ca `auto`.

```cpp
int arr[] {1, 2, 3, 4, 5, 6};

std::for_each(arr, arr + 6, [](auto el){ std::cout << el << " ";});
```

## Formatarea șirurilor de caractere

Începând cu standardul `C++20`, biblioteca standard oferă posibilitatea de a formata șiruri de caractere folosind funcția `std::format`. Aceasta primește un șablon de format și argumente care vor fi inserate în șir. Șablonul de format conține specificatori de format care încep cu `{` și se termină cu `}`.

```cpp
/**
 * @file format.cpp
 * @brief Exemplu de utilizare a funcției std::format
 * @details g++ -std=c++20 format.cpp -o format
 */
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

Specificatorii de format pot conține următoarele elemente, în ordinea apariției:

```text
[[fill]align][sign][#][0][width][.precision][type]
```

- `fill` – caracterul folosit pentru completarea spațiului gol;
- `align` – aliniere: `<` – la stânga, `>` – la dreapta, `^` – centrat;
- `sign` – semnul numerelor: `+` – mereu, `-` – doar pentru negative, ` ` – spațiu pentru pozitive;
- `#` – formă alternativă de afișare;
- `0` – completare cu zerouri;
- `width` – lățimea minimă a câmpului;
- `precision` – numărul de zecimale;
- `type` – tipul datelor: `f` – număr real, `g` – format general, `e` – format exponențial, `x` – hexazecimal etc.

Exemplu de formatare a unui tabel:

```cpp
/**
 * @file format_table.cpp
 * @brief Exemplu de formatare a unui tabel cu std::format
 * @details g++ -std=c++20 format_table.cpp -o format_table
 */
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

## Literele definite de utilizator

__Literalul__ este o constantă fără nume. În C++ există 6 tipuri de litere:

- numere întregi: `312`, `-1ll`
- numere reale: `12.29`
- caractere: `'a'`
- șiruri de caractere: `"sample"`
- valori logice: `true`
- pointeri: `nullptr`

Începând cu `C++11`, utilizatorul poate defini propriile litere (user-defined literals), care permit crearea de obiecte de tipuri personalizate.

```cpp
ReturnType operator "" _a(unsigned long long int);   // Literal pentru tip integral definit de utilizator
ReturnType operator "" _b(long double);              // Literal pentru tip real definit de utilizator
ReturnType operator "" _c(char);                     // Literal pentru caracter definit de utilizator
ReturnType operator "" _d(wchar_t);                  // Literal pentru caracter larg definit de utilizator
ReturnType operator "" _e(char16_t);                 // Literal pentru caracter UTF-16 definit de utilizator
ReturnType operator "" _f(char32_t);                 // Literal pentru caracter UTF-32 definit de utilizator
ReturnType operator "" _g(const char*, size_t);      // Literal pentru șir definit de utilizator
ReturnType operator "" _h(const wchar_t*, size_t);   // Literal pentru șir larg definit de utilizator
ReturnType operator "" _i(const char16_t*, size_t);  // Literal pentru șir UTF-16 definit de utilizator
ReturnType operator "" _j(const char32_t*, size_t);  // Literal pentru șir UTF-32 definit de utilizator
ReturnType operator "" _r(const char*);              // Literal raw
template<char...> ReturnType operator "" _t();       // Literal template
```

Sufixul literalului poate fi orice identificator valid.

Exemplu:

```cpp
// volum în litri
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

## Semantica mutării

Prin semantica mutării se înțelege un set de mecanisme ale limbajului C++ care permit evitarea costurilor de copiere la crearea de noi obiecte. Elementele principale ale semanticii mutării sunt: constructorul de mutare și operatorul de atribuire prin mutare.

Semantica mutării permite scrierea unui cod mai eficient.

```cpp
my_string a = "hell", b = "o";
my_string result = a + b;
```

În exemplul de mai sus, în urma adunării a două șiruri, se creează un obiect temporar care este copiat în variabila `result` și apoi distrus. Se poate evita copierea inutilă și distrugerea obiectului dacă obiectul temporar este mutat în `result`. Acest lucru se realizează cu operatorul de atribuire prin mutare. Sintaxa operatorului:

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

Implementarea poate fi simplificată folosind funcția standard `std::move`, care realizează mutarea obiectului:

```cpp
class my_string {
public:
  my_string(my_string&& other): _data(std::move(other._data)){
    other._data = nullptr;
  }

  my_string& operator=(my_string&& other) {
    _data = std::move(other._data);
    return *this;
  }

private:
  char*_data;
};
```

## Tupluri (tuples)

Tuplurile sunt structuri de date care permit stocarea mai multor elemente de tipuri diferite. Tuplurile sunt definite în antetul `<tuple>`. Pot fi folosite pentru a returna mai multe valori dintr-o funcție.

Exemplu de utilizare a tuplurilor:

```cpp
/**
 * @file tuple.cpp
 * @brief Exemplu de utilizare a tuplurilor
 * @details g++ -std=c++20 tuple.cpp -o tuple
 */
#include <tuple>
#include <iostream>
#include <string>

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

## Intervale (ranges)

Majoritatea algoritmilor STL operează cu intervale de containere, definite ca perechi de iteratori. Începând cu standardul `C++20`, biblioteca standard generalizează intervalele ca perechi de iteratori.

În biblioteca de intervale sunt definite următoarele concepte:

- `range` – interval, adică o pereche de iteratori: început și sfârșit. Definit în spațiul de nume `std::ranges`.
- `view` – adaptor de interval, care permite transformarea și filtrarea elementelor. Definit în `std::ranges::views`.
- `algorithm` – algoritmi care primesc intervale ca argumente. Definiți în `std::ranges::algorithm`.

Exemplu de utilizare a intervalelor:

```cpp
/**
 * @file ranges.cpp
 * @brief Exemplu de utilizare a intervalelor
 * @details g++ -std=c++20 ranges.cpp -o ranges
 */
#include <ranges>
#include <numeric>
#include <iostream>
#include <vector>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto reverse_numbers = numbers | std::views::reverse;

    std::ranges::for_each(reverse_numbers, [](int el){ std::cout << el << " "; });
    std::cout << std::endl;

    return 0;
}
```

Utilizarea adaptoarelor de intervale se bazează pe idei din programarea funcțională, permițând procesarea în lanț a datelor. Pentru aceasta, operatorul `|` este suprascris pentru a transmite datele între adaptoare.

Câțiva adaptoare utile pentru intervale:

- `views::all` – transformă un container într-un interval
- `views::filter` – selectează elemente după o proprietate
- `views::transform` – modifică fiecare element
- `views::take` – selectează primele _N_ elemente
- `views::take_while` – selectează elemente cât timp condiția este adevărată
- `views::drop` – elimină primele _N_ elemente
- `views::drop_while` – elimină elemente cât timp condiția este adevărată
- `views::reverse` – inversează ordinea elementelor
- `views::join` – concatenează secvențe
- `views::split` – împarte secvența în subsevențe
- `views::keys` – selectează cheile dintr-o pereche, tuplu sau container asociativ
- `views::values` – selectează valorile dintr-o pereche, tuplu sau container asociativ
- `views::zip` – combină mai multe secvențe într-una, elementele cu același index fiind grupate într-un tuplu

Exemplu de utilizare:

```cpp
/**
 * @file ranges_pipeline.cpp
 * @brief Exemplu de procesare în lanț cu intervale
 * @details g++ -std=c++20 ranges_pipeline.cpp -o ranges_pipeline
 */
#include <ranges>
#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Selectăm numerele pare și le înmulțim cu 2
    auto result = numbers | std::views::filter([](int el){ return el % 2 == 0; })
            | std::views::transform([](int el){ return el * 2; });
    
    // Afișăm rezultatul
    std::ranges::for_each(result, [](int el){ std::cout << el << " "; });

    return 0;
}
```

## Pointeri inteligenți

Începând cu standardul `C++11`, biblioteca standard C++ oferă o abstracție (wrapper) peste pointeri, care eliberează automat memoria la finalul utilizării variabilei.

Sunt disponibile următoarele tipuri de pointeri inteligenți:

- `unique_ptr` – la atribuirea unui obiect pointer inteligent `Ptr1` către `Ptr2`, proprietarul memoriei devine `Ptr2` (pointerul este mutat), iar `Ptr1` devine `nullptr`.
- `shared_ptr` – la copierea unui pointer inteligent `Ptr1` către `Ptr2`, ambele variabile indică aceeași zonă de memorie; memoria este eliberată când ambele variabile sunt distruse.
- `weak_ptr` – referință slabă la memorie: nu poate elibera/modifica memoria și indică întotdeauna către o zonă creată de un `shared_ptr`.

## valarray

Clasa șablon `std::valarray` este declarată în antetul `valarray`. Permite efectuarea de operații aritmetice pe vectori.

Exemplu de utilizare:

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

Containerele speciale `std::variant`, `std::optional`, `std::any` permit stocarea valorilor de tipuri diferite într-un singur obiect.

- `std::variant` – alternativă la pointeri și referințe pentru stocarea valorilor de tipuri diferite.
- `std::optional` – container care poate conține o valoare sau poate fi gol.
- `std::any` – container care poate conține valori de orice tip.

Exemplu de utilizare:

```cpp
/**
 * @file variant.cpp
 * @brief Exemplu de utilizare a std::variant
 * @details g++ -std=c++17 variant.cpp -o variant
 */
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

## Expresii regulate

> __Expresiile regulate__ sunt un limbaj formal care descrie șabloane de șiruri de caractere. Sunt folosite pentru căutare, înlocuire și validare de text.

Biblioteca standard C++ oferă suport pentru expresii regulate prin clasa `std::regex` (antetul `<regex>`).

Exemplu: verificarea dacă un șir este un email valid:

```cpp
/**
 * @file regex_email.cpp
 * @brief Exemplu de verificare a unui email cu expresii regulate
 * @details g++ -std=c++11 regex_email.cpp -o regex_email
 */
#include <regex>
#include <iostream>

int main()
{
    std::string email = "i@love.you";
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

Expresia regulată `(\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+` verifică dacă șirul respectă formatul unui email:

- `(\w+)` – unul sau mai multe caractere alfanumerice
- `(\.|_)?` – punct sau underscore, opțional
- `(\w*)` – zero sau mai multe caractere alfanumerice
- `@` – simbolul @
- `(\w+)` – unul sau mai multe caractere alfanumerice
- `(\.(\w+))+` – una sau mai multe secvențe: punct urmat de unul sau mai multe caractere alfanumerice

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
