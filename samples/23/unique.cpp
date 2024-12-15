#include <vector>
#include <iostream>
#include <algorithm>

std::vector<int> getUnique(std::vector<int> const &v)
{
    std::vector<int> unique;
    for (const auto &el : v)
    {
        if (std::find(unique.begin(), unique.end(), el) == unique.end())
        {
            unique.push_back(el);
        }
    }
    return unique;
}

int main()
{
    for (const auto &el : getUnique({0, 1, 2, 0, 4, 5, 2, 0, 8, 8}))
    {
        std::cout << el << " ";
    }
    return 0;
}