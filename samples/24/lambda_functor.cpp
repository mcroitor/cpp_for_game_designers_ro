#include <iostream>

struct _sum {
    int operator()(int a, int b) const {
        return a + b;
    }
};

int main() {
    _sum sum;

    auto sum2 = [](int a, int b) { return a + b; };
    auto divide = [](int a, int b) -> float { return (float)a / b; };

    // [capture zone](params) -> return type { calculus }

    std::cout << sum(10, 20) << std::endl;
    std::cout << sum2(10, 20) << std::endl;
    std::cout << divide(10, 20) << std::endl;
    return 0;
}