#include <iostream>
#include <valarray>

int main()
{
    std::valarray<int> a{1, 2, 3};
    std::valarray<int> b{1, 2, 3};

    std::valarray<int> result = a * 5 + b;

    result = result.apply([](int el){ return el - 1; });

    for (auto element : result)
    {
        std::cout << element << " ";
    }
}