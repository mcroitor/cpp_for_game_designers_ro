# Intrebari la tema Funcționalități suplimentare ale bibliotecii standard C++

## Cunostinte

Intrebari legate de cunostintele necesare pentru implementarea temei. Sunt de tip Single Choice, alegerea unei singure variante corecte din patru posibile. Total 20 intrebari.

1. Ce înseamnă simbolurile dintre paranteze pătrate într-o expresie lambda `[a]`?
   - [x] capturarea variabilelor din exterior
   - [ ] declararea parametrilor funcției
   - [ ] declararea tipului de retur
   - [ ] definirea unui array

2. În ce standard C++ a fost introdusă funcția `std::format`?
   - [x] C++20
   - [ ] C++11
   - [ ] C++17
   - [ ] C++14

3. Ce permite semantica mutării în C++?
   - [x] evitarea costurilor de copiere la crearea de noi obiecte
   - [ ] mutarea variabilelor din stack în heap
   - [ ] schimbarea tipului unei variabile
   - [ ] mutarea funcțiilor între clase

4. În ce antet este declarată clasa `std::tuple`?
   - [x] <tuple>
   - [ ] <utility>
   - [ ] <memory>
   - [ ] <vector>

5. Ce reprezintă conceptul `view` în biblioteca ranges?
   - [x] adaptor de interval care permite transformarea și filtrarea elementelor
   - [ ] o fereastră de vizualizare grafică
   - [ ] un tip special de iterator
   - [ ] un container secvențial

6. Ce tip de pointer inteligent transferă proprietatea memoriei la atribuire?
   - [x] unique_ptr
   - [ ] shared_ptr
   - [ ] weak_ptr
   - [ ] auto_ptr

7. În ce antet este declarată clasa `std::valarray`?
   - [x] <valarray>
   - [ ] <array>
   - [ ] <vector>
   - [ ] <numeric>

8. Ce container permite stocarea unei valori sau poate fi gol?
   - [x] std::optional
   - [ ] std::variant
   - [ ] std::any
   - [ ] std::unique_ptr

9. Ce clasă din biblioteca standard oferă suport pentru expresii regulate?
   - [x] std::regex
   - [ ] std::pattern
   - [ ] std::match
   - [ ] std::search

10. Ce operator este folosit pentru a concatena adaptoarele de intervale?
    - [x] |
    - [ ] +
    - [ ] >>
    - [ ] &

11. Cum se declară un parametru generic într-o expresie lambda?
    - [x] auto
    - [ ] template
    - [ ] typename
    - [ ] generic

12. Ce simbol se folosește pentru a specifica tipul de retur al unei expresii lambda?
    - [x] ->
    - [ ] :
    - [ ] =>
    - [ ] ::

13. Ce operator trebuie definit pentru a crea un literal definit de utilizator?
    - [x] operator ""
    - [ ] operator ()
    - [ ] operator []
    - [ ] operator ->

14. Ce funcție standard realizează mutarea unui obiect?
    - [x] std::move
    - [ ] std::transfer
    - [ ] std::copy
    - [ ] std::swap

15. Cum se accesează primul element dintr-un tuple `t`?
    - [x] std::get<0>(t)
    - [ ] t[0]
    - [ ] t.first()
    - [ ] t.at(0)

16. Ce adaptor de intervale selectează primele N elemente?
    - [x] views::take
    - [ ] views::first
    - [ ] views::head
    - [ ] views::limit

17. Ce tip de pointer inteligent permite mai multor variabile să partajeze aceeași memorie?
    - [x] shared_ptr
    - [ ] unique_ptr
    - [ ] weak_ptr
    - [ ] auto_ptr

18. Ce metodă verifică dacă un `std::optional` conține o valoare?
    - [x] has_value()
    - [ ] is_valid()
    - [ ] exists()
    - [ ] empty()

19. Ce funcție verifică dacă un șir corespunde complet unei expresii regulate?
    - [x] std::regex_match
    - [ ] std::regex_search
    - [ ] std::regex_find
    - [ ] std::regex_check

20. În standardul C++20, ce spațiu de nume conține definițiile intervalelor?
    - [x] std::ranges
    - [ ] std::views
    - [ ] std::iterators
    - [ ] std::algorithms

## Utilizare

Intrebari legate de utilizarea corecta a temei. Sunt de tip Short Answer, unde studentul trebuie sa scrie un raspuns scurt. Total 10 intrebari.

1. Scrieți sintaxa generală a unei expresii lambda:
   - [](parametri) -> tip { cod; }
   - [capturi](parametri) -> tip { cod; }

2. Scrieți apelul funcției `std::format` pentru a crea șirul "Name: John, Age: 25" cu variabilele `name` și `age`:
   - std::format("Name: {}, Age: {}", name, age)

3. Scrieți declarația unui literal definit de utilizator pentru metri, cu sufixul `_m`:
   - constexpr double operator "" _m(long double value) { return value; }

4. Scrieți declarația constructorului de mutare pentru o clasă `MyClass`:
   - MyClass(MyClass&& other)

5. Scrieți declarația unui tuplu care conține un `int`, `double` și `string`:
   - std::tuple<int, double, std::string> t;

6. Scrieți expresia pentru a filtra numerele pare dintr-un vector `numbers` folosind ranges:
   - numbers | std::views::filter([](int n) { return n % 2 == 0; })

7. Scrieți declarația unui `unique_ptr` pentru un obiect de tip `int`:
   - std::unique_ptr<int> ptr;
   - std::unique_ptr<int> ptr = std::make_unique<int>(10);

8. Scrieți declarația unui `std::optional` care poate conține un `int`:
   - std::optional<int> opt;

9. Scrieți declarația unui obiect `std::regex` pentru pattern-ul "hello":
   - std::regex pattern("hello");

10. Scrieți expresia pentru a transforma fiecare element al unui vector `numbers` înmulțindu-l cu 2, folosind ranges:
    - numbers | std::views::transform([](int n) { return n * 2; })


## Integrare

Intrebari legate de integrarea temei cu alte teme. Sunt de tip Long Answer (Essay) unde studentul trebuie sa scrie un cod (program sau implementare functie, clasa etc). Total 5 intrebari.

1. Scrieți un program care utilizează o expresie lambda pentru a calcula suma elementelor unui vector de întregi. Folosiți `std::accumulate` cu lambda.
   - ```cpp
     #include <iostream>
     #include <vector>
     #include <numeric>

     int main() {
         std::vector<int> numbers = {1, 2, 3, 4, 5};
         
         int sum = std::accumulate(numbers.begin(), numbers.end(), 0,
             [](int acc, int val) { return acc + val; });
         
         std::cout << "Sum: " << sum << std::endl;
         return 0;
     }
     ```

2. Scrieți un program care folosește `std::format` pentru a afișa un tabel cu 3 coloane (nume, vârstă, oraș) pentru cel puțin 3 persoane. Folosiți aliniere și formatare adecvată.
   - ```cpp
     #include <iostream>
     #include <format>

     int main() {
         std::cout << std::format("| {:<15} | {:>5} | {:<15} |", "Name", "Age", "City") << std::endl;
         std::cout << std::format("|{:-^17}|{:-^7}|{:-^17}|", "", "", "") << std::endl;
         std::cout << std::format("| {:<15} | {:>5} | {:<15} |", "John Doe", 25, "New York") << std::endl;
         std::cout << std::format("| {:<15} | {:>5} | {:<15} |", "Jane Smith", 30, "London") << std::endl;
         std::cout << std::format("| {:<15} | {:>5} | {:<15} |", "Bob Johnson", 35, "Paris") << std::endl;
         return 0;
     }
     ```

3. Scrieți un program care utilizează `std::ranges` pentru a selecta numerele impare dintr-un vector, le înmulțește cu 3, și afișează rezultatul. Folosiți `views::filter` și `views::transform`.
   - ```cpp
     #include <iostream>
     #include <vector>
     #include <ranges>

     int main() {
         std::vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
         
         auto result = numbers 
             | std::views::filter([](int n) { return n % 2 != 0; })
             | std::views::transform([](int n) { return n * 3; });
         
         for (int n : result) {
             std::cout << n << " ";
         }
         std::cout << std::endl;
         return 0;
     }
     ```

4. Scrieți o funcție care returnează un `std::optional<int>` reprezentând rădăcina pătrată întreagă a unui număr (dacă există). Funcția trebuie să returneze `std::nullopt` dacă numărul nu are rădăcină pătrată întreagă.
   - ```cpp
     #include <iostream>
     #include <optional>
     #include <cmath>

     std::optional<int> integer_sqrt(int n) {
         if (n < 0) {
             return std::nullopt;
         }
         int root = static_cast<int>(std::sqrt(n));
         if (root * root == n) {
             return root;
         }
         return std::nullopt;
     }

     int main() {
         auto result1 = integer_sqrt(16);
         auto result2 = integer_sqrt(15);
         
         if (result1.has_value()) {
             std::cout << "sqrt(16) = " << result1.value() << std::endl;
         }
         
         if (!result2.has_value()) {
             std::cout << "15 does not have integer square root" << std::endl;
         }
         return 0;
     }
     ```

5. Scrieți un program care utilizează `std::regex` pentru a extrage toate adresele de email dintr-un text dat. Afișați fiecare email găsit pe o linie separată.
   - ```cpp
     #include <iostream>
     #include <regex>
     #include <string>

     int main() {
         std::string text = "Contact us at info@example.com or support@test.org for help.";
         std::regex email_pattern(R"((\w+)(\.|_)?(\w*)@(\w+)(\.(\w+))+)");
         
         auto emails_begin = std::sregex_iterator(text.begin(), text.end(), email_pattern);
         auto emails_end = std::sregex_iterator();
         
         std::cout << "Found emails:" << std::endl;
         for (std::sregex_iterator i = emails_begin; i != emails_end; ++i) {
             std::smatch match = *i;
             std::cout << match.str() << std::endl;
         }
         return 0;
     }
     ```

