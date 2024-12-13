#include <iostream>
#include <string>

template<typename TYPE, int SIZE>
class array {
    TYPE elements[SIZE];
public:
    const TYPE& operator [](int index) const {
        return elements[index];
    }

    TYPE& operator [](int index) {
        return elements[index];
    }
    int size() const {
        return SIZE;
    }
};

int main(){
    array<int, 15> a;
    array<std::string, 2> str;
    for(int i = 0; i < a.size(); ++i) {
        a[i] = i;
    }
    for(int i = 0; i < a.size(); ++i) {
        std::cout << a[i] << " ";
    }
    std::cout << std::endl;

    str[0] = "hello";
    str[1] = "world";
    for(int i = 0; i < str.size(); ++i) {
        std::cout << str[i] << " ";
    }

    return 0;
}