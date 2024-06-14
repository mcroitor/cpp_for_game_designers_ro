#include <vector>
#include <iostream>

template <typename Iterator>
void print(const Iterator& begin, const Iterator& end) {
    Iterator it = begin;
    while(it != end) {
        std::cout << *it << " ";
        ++it;
    }
}

int main() {
    std::vector<int> v;
    typedef std::vector<int>::iterator iterator;

    v.resize(7, 0);
    
    for (auto& el : v){
        std::cin >> el;
    }

    for (int i = 0; i < v.size(); i++) {
        std::cout << v[i] << std::endl;
    }

    for (iterator i = v.begin(); i != v.end(); i++) {
        std::cout << *i << std::endl;
    }

    print(v.begin(), v.end());
    return 0;
}