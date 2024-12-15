#include <iostream>
#include <algorithm>

int main()
{
    auto empty = []() {};
    auto sum = [](int a, int b)
    { return a + b; };

    empty();
    std::cout << sum(1, 2) << std::endl;

    int array[]{1, 2, 3, 4, 5};
    int value = 10;

    std::for_each(
        array,
        array + 5,
        [value](auto element)
        {
            std::cout << element + value << std::endl;
        });

    return 0;
}