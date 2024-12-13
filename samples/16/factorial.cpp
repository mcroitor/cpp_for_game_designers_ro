#include <iostream>

template <int NUMBER>
int sum() {
    return NUMBER + sum<NUMBER - 1>();
}

template<>
int sum<0>() {
    return 0;
}

template<class TYPE1, class TYPE2>
struct is_same {
    enum {result = false};
};

template<class TYPE>
struct is_same<TYPE, TYPE> {
    enum {result = true};
};

int main() {
    std::cout << sum<10>() << std::endl;

    std::cout << is_same<int, double>::result << std::endl;
    std::cout << is_same<int, int>::result << std::endl;

    auto a = 10ll;

    if(is_same<int, decltype(a)>::result) {
        std::cout << "int" << std::endl;
    }
    else if(is_same<double, decltype(a)>::result) {
        std::cout << "double" << std::endl;
    }
    else if(is_same<long long, decltype(a)>::result) {
        std::cout << "long long" << std::endl;
    }
    return 0;
}

// sum<10> ==> 10 + sum<9> ==> 10 + 9 + sum<8> ...