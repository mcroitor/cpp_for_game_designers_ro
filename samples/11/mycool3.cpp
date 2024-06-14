#include <iostream>

int a = 10;

void foo()
{
    std::cout << a << std::endl;
    a++;
}

int main()
{
    for (int i = 0; i < 4; i++)
    {
        foo();
    }

    return 0;
}