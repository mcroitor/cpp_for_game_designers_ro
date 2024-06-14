#include <list>
#include <vector>
#include <string>
#include <iostream>

// #include <bits/stdc++.h>

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::vector<T>& v) {
    for(auto& el : v) {
        out << el;
    }
    return out;
}

template<typename T>
std::ostream& operator<<(std::ostream& out, const std::list<T>& v) {
    for(auto& el : v) {
        out << el;
    }
    return out;
}

int main() {
    std::list<char> str(10, 'a');
    std::string str2(3, 'b');
    std::vector<char> str3(str.begin(), str.end());

    str2.insert(str2.begin(), 'c');

    str3.insert(str3.begin() + 2, str2.begin() + 2, str2.begin() + 4);

    auto it = --(str3.end());
    std::cout << (*it) << std::endl;
    str3.erase(it);
    std::cout << (*it) << std::endl;

    std::cout << str << std::endl;
    std::cout << str2 << std::endl;
    std::cout << str3 << std::endl;
    return 0;
}