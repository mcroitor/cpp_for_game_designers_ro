#include <iostream>

template <size_t index>
size_t fibbonacci()
{
    return fibbonacci<index - 1>() + fibbonacci<index - 2>();
}

template <>
size_t fibbonacci<0>()
{
    return 0;
}

template <>
size_t fibbonacci<1>()
{
    return 1;
}

int main()
{
    std::cout << fibbonacci<10>() << std::endl;
    return 0;
}