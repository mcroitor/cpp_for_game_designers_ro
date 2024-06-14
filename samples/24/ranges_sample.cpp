#include <ranges>
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v{7, 8, 1, 2, 3, 4, 5, 6};

    auto output = v | 
        std::views::filter([](int el) { return el % 2 == 0; }) | 
        std::views::transform([](int el) { return el * el + 1;});

    for (auto el : output)
    {
        std::cout << el << " ";
    };
    return 0;
}