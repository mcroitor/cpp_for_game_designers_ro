#include <memory>
#include <vector>
#include <iostream>

using pInt = std::shared_ptr<int>;

int main() {
    std::unique_ptr<int> p = std::make_unique<int>(10);
    std::unique_ptr<int> p2(new int (5));

    std::shared_ptr<int> shared1 = std::make_shared<int>(10);

    auto shared2 = shared1;
    
    std::weak_ptr<int> weak = shared1;

    std::vector<pInt> pointers;

    for(int i = 0; i < 10; i++) {
        pointers.push_back(std::make_shared<int>(i));
    }

    for(auto el: pointers) {
        std::cout << *el << " ";
    }

    return 0;
}