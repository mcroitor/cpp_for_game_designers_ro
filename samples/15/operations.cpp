#include <string>
#include <iostream>

class int_pair{
    int first, second;
public:
    // конструктор с параметрами
    int_pair(int f = 0, int s = 0): first(f), second(s) {}
    // оператор копирования
    int_pair operator = (const int_pair& p) {
        first = p.first;
        second = p.second;
        return *this;
    }
    // оператор сравнения
    bool operator == (const int_pair& p) const {
        return (first == p.first) && (second == p.second);
    }
    auto operator <=> (const int_pair& p) const {
        return first <=> p.first;
    }
    // строковое представление объекта
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

std::istream& operator >> (std::istream& in, int_pair& p) {
    int a, b;
    in >> a >> b;
    p = int_pair(a, b);
    return in;
}

int main() {
    int_pair pair(2, 3);
    int_pair pair2(pair);
    bool result = pair < pair2;
    std::cout << pair << std::endl;
    return 0;
}