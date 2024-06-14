#include <algorithm>
#include <vector>
#include <iostream>

struct additional {
    int val;
    additional(int v) : val(v){}
    int operator()(int element) const { return val + element; }
};

int main() {
    std::vector<int> values {1, 2, 3, 4, 5, 6, 7, 8, 9};
    // std::vector<int> result(values.size(), 0);

    int a = 5;
    
    auto oops = [a](int element) { return element + a; };

    std::transform(values.begin(), values.end(), values.begin(), oops);
    std::transform(values.begin(), values.end(), values.begin(), additional(a));

    std::for_each(values.begin(), values.end(), [](int element) { std::cout << element << " "; });

    return 0;
}