#include <ranges>
#include <algorithm>
#include <vector>
#include <iostream>

int main() {
    std::vector<int> values { 1, 2, 3, 4, 5, 6, 7, 8, 9, 13, 14, 2, 6, 5 };
    int cut = 9;

    auto odd = values |
        std::ranges::views::filter([](int el) { return el % 2 == 1; }) |
        std::ranges::views::take_while([cut](int el) {return el < cut; }); // |
        //std::ranges::views::transform([](int el) { std::cout << el << " "; return el; });

    std::ranges::for_each(odd, [](int el) { std::cout << el << " "; });
    return 0;
}