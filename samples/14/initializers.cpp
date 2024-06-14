#include <iostream>

struct A
{
    int* field;
    A()
    {
        field = 0;
        std::cout << "field = " << field << std::endl;
    }
    A(int f): field(new int[f])
    {
//        std::cout << "field = " << field << std::endl;
    }
};

struct B : public A
{
    B() = default;
    B(int f): A(5)
    {
//        std::cout << "field = " << field << std::endl;
    }
};

int main()
{
    B b(5);
    std::cout << b.field << std::endl;
    return 0;
}