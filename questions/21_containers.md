# Intrebari la tema Containere

## Cunostinte

Intrebari legate de cunostintele necesare pentru implementarea temei. Sunt de tip Single Choice, alegerea unei singure variante corecte din patru posibile. Total 20 intrebari.

1. Obiect special care permite parcurgerea elementelor a unei colecții se numește:
   - [x] iterator
   - [ ] adapter
   - [ ] predicat
   - [ ] functor

2. Ce înseamnă acronimul STL?
   - [x] Standard Template Library
   - [ ] Simple Template Library
   - [ ] Standard Type Library
   - [ ] Structured Template Library

3. În ce spațiu de nume este declarată biblioteca standard C++?
   - [x] std
   - [ ] standard
   - [ ] stl
   - [ ] cpp

4. Care dintre următoarele NU este un tip principal de componentă STL?
   - [x] processor
   - [ ] container
   - [ ] iterator
   - [ ] algorithm

5. Tipul de iterator care permite doar citirea valorilor din container se numește:
   - [x] iterator de intrare
   - [ ] iterator de ieșire
   - [ ] iterator bidirecțional
   - [ ] iterator secvențial

6. Tipul de iterator care permite deplasarea înainte și înapoi în container se numește:
   - [x] iterator bidirecțional
   - [ ] iterator secvențial
   - [ ] iterator de intrare
   - [ ] iterator de ieșire

7. Care tip de iterator suportă operații precum `i + n` și `i[n]`?
   - [x] iterator cu acces aleator
   - [ ] iterator bidirecțional
   - [ ] iterator de intrare
   - [ ] iterator secvențial

8. Ce metodă returnează un iterator la primul element al unui container?
   - [x] begin()
   - [ ] first()
   - [ ] start()
   - [ ] front()

9. Ce metodă returnează un iterator după ultimul element al unui container?
   - [x] end()
   - [ ] last()
   - [ ] back()
   - [ ] finish()

10. Care container are complexitate O(1) pentru inserare și ștergere?
    - [x] list
    - [ ] vector
    - [ ] array
    - [ ] queue

11. Care container suportă operatorul `[]` pentru acces direct la elemente?
    - [x] vector
    - [ ] list
    - [ ] set
    - [ ] forward_list

12. Care container stochează elemente unice ordonate crescător?
    - [x] set
    - [ ] vector
    - [ ] list
    - [ ] multiset

13. Ce container permite inserare și ștergere la ambele capete în O(1)?
    - [x] deque
    - [ ] vector
    - [ ] list
    - [ ] stack

14. Care container stochează perechi cheie-valoare ordonate după cheie?
    - [x] map
    - [ ] set
    - [ ] vector
    - [ ] list

15. Ce complexitate are inserarea într-un `set`?
    - [x] O(log n)
    - [ ] O(1)
    - [ ] O(n)
    - [ ] O(n²)

16. Ce metodă adaugă un element la sfârșitul unui `vector`?
    - [x] push_back()
    - [ ] insert()
    - [ ] add()
    - [ ] append()

17. Cum se accesează valoarea asociată unei chei într-un `map`?
    - [x] a[k] sau a.at(k)
    - [ ] a.get(k)
    - [ ] a.value(k)
    - [ ] a.find(k)

18. Ce metodă șterge toate elementele dintr-un container?
    - [x] clear()
    - [ ] erase_all()
    - [ ] delete_all()
    - [ ] remove_all()

19. Ce metodă verifică dacă un container este gol?
    - [x] empty()
    - [ ] is_empty()
    - [ ] size() == 0
    - [ ] length() == 0

20. Care container permite chei duplicate?
    - [x] multiset
    - [ ] set
    - [ ] map
    - [ ] vector

## Utilizare

Intrebari legate de utilizarea corecta a temei. Sunt de tip Short Answer, unde studentul trebuie sa scrie un raspuns scurt. Total 10 intrebari.

1. Obiect special care permite parcurgerea elementelor a unei colecții se numește:
   - iterator

2. Scrieți expresia pentru a obține dimensiunea unui container `c`:
   - c.size()

3. Scrieți declarația unui vector de întregi numit `v` în C++:
   - std::vector<int> v;

4. Scrieți apelul de metodă pentru a adăuga elementul `5` la sfârșitul unui vector `v`:
   - v.push_back(5)

5. Scrieți expresia pentru a accesa al treilea element (index 2) al unui vector `v`:
   - v[2]
   - v.at(2)

6. Scrieți expresia pentru a verifica dacă un set `s` conține elementul `x`:
   - s.find(x) != s.end()
   - s.count(x) > 0

7. Scrieți cod pentru a insera perechea cheie-valoare `{"key", 10}` într-un map `m`:
   - m["key"] = 10;
   - m.insert({"key", 10});

8. Scrieți apelul de metodă pentru a șterge toate elementele dintr-un container `c`:
   - c.clear();

9. Scrieți un range-based for loop pentru a parcurge un container `c`:
   - for(auto elem : c) { ... }
   - for(const auto& elem : c) { ... }

10. Scrieți apelul de metodă pentru a adăuga elementul `x` la începutul unei liste `l`:
    - l.push_front(x);

## Integrare

Intrebari legate de integrarea temei cu alte teme. Sunt de tip Long Answer (Essay) unde studentul trebuie sa scrie un cod (program sau implementare functie, clasa etc). Total 5 intrebari.

1. Scrieți un program care utilizează un container standard C++ pentru a stoca valori întregi. In program se insereaza consecutiv valori `1 2 3 4 5 6 7 8 9` și afișează aceste valori la ecran.
   - ```cpp
     #include <iostream>
     #include <vector>
     #include <algorithm>

     int main() {
         std::vector<int> numbers;
         for (int i = 1; i <= 9; ++i) {
             numbers.push_back(i);
         }
         for (const auto& num : numbers) {
             std::cout << num << " ";
         }
         return 0;
     }
     ```

2. Scrieți un program care utilizează un `std::set` pentru a elimina duplicatele dintr-un vector de întregi și afișează elementele unice sortate.
   - ```cpp
     #include <iostream>
     #include <vector>
     #include <set>

     int main() {
         std::vector<int> numbers = {5, 2, 8, 2, 9, 1, 5, 8};
         std::set<int> unique_numbers(numbers.begin(), numbers.end());
         
         for (const auto& num : unique_numbers) {
             std::cout << num << " ";
         }
         std::cout << std::endl;
         return 0;
     }
     ```

3. Scrieți un program care utilizează un `std::map` pentru a număra frecvența de apariție a cuvintelor dintr-un vector de string-uri.
   - ```cpp
     #include <iostream>
     #include <map>
     #include <vector>
     #include <string>

     int main() {
         std::vector<std::string> words = {"apple", "banana", "apple", "cherry", "banana", "apple"};
         std::map<std::string, int> frequency;
         
         for (const auto& word : words) {
             frequency[word]++;
         }
         
         for (const auto& pair : frequency) {
             std::cout << pair.first << ": " << pair.second << std::endl;
         }
         return 0;
     }
     ```

4. Scrieți o funcție template care primește un container și un element, și returnează `true` dacă elementul există în container, `false` în caz contrar. Funcția trebuie să funcționeze cu orice container STL.
   - ```cpp
     #include <iostream>
     #include <vector>
     #include <list>
     #include <algorithm>

     template<typename Container, typename T>
     bool contains(const Container& container, const T& element) {
         return std::find(container.begin(), container.end(), element) != container.end();
     }

     int main() {
         std::vector<int> vec = {1, 2, 3, 4, 5};
         std::list<std::string> lst = {"hello", "world"};
         
         std::cout << std::boolalpha;
         std::cout << "Vector contains 3: " << contains(vec, 3) << std::endl;
         std::cout << "List contains 'test': " << contains(lst, std::string("test")) << std::endl;
         return 0;
     }
     ```

5. Scrieți un program care utilizează un `std::deque` pentru a implementa o coadă de comenzi de joc (string-uri). Programul trebuie să permită adăugarea de comenzi la sfârșitul cozii și executarea (ștergerea) comenzilor de la început. Afișați comenzile executate.
   - ```cpp
     #include <iostream>
     #include <deque>
     #include <string>

     int main() {
         std::deque<std::string> commandQueue;
         
         // Adăugare comenzi
         commandQueue.push_back("move_forward");
         commandQueue.push_back("turn_left");
         commandQueue.push_back("attack");
         commandQueue.push_back("defend");
         
         std::cout << "Executing commands:" << std::endl;
         
         // Executare comenzi
         while (!commandQueue.empty()) {
             std::string command = commandQueue.front();
             commandQueue.pop_front();
             std::cout << "Executing: " << command << std::endl;
         }
         
         return 0;
     }
     ```