#include <iostream>

int square(int x){
    return x*x;
}

struct _square
{
    int operator() (int x){
        return x*x;
    }
};

int main(){
    int a = 42;
    _square square2;
    std::cout << a << "^2 = " << square(a) << std::endl;
    std::cout << a << "^2 = " << square2(a) << std::endl;
    return 0;
}

