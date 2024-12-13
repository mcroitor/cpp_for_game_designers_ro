#include <iostream>
#include <string>

template<typename TYPE>
void my_swap(TYPE& a, TYPE& b){
    TYPE tmp = a;
    a       = b;
    b       = tmp;
}

int main(){
    int i1 = 10;
    int i2 = 20;

    std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;
    my_swap(i1, i2);
    std::cout << "i1 = " << i1 << ", i2 = " << i2 << std::endl;

    double d1 = 1.0;
    double d2 = -1.0;

    std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;
    my_swap(d1, d2);
    std::cout << "d1 = " << d1 << ", d2 = " << d2 << std::endl;

    std::string s1 = "hello";
    std::string s2 = "world";

    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;
    my_swap(s1, s2);
    std::cout << "s1 = " << s1 << ", s2 = " << s2 << std::endl;

    return 0;
}