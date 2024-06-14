// g++ ref_sample.cpp -oref_sample -std=c++20
#include <iostream>
#include <thread>
#include <vector>

using vector = std::vector<int>;

void sum(int a, int b, int &result){
    result = a + b;
}

int main(){
    vector a {1, 2, 3, 4, 5};
    vector b {5, 4, 3, 2, 1};
    vector result(5, 0);

    for(int i = 0; i != 5; ++i) {
        std::jthread thread(sum, a[i], b[i], std::ref(result[i]));
    //  std::jthread thread(sum, a[i], b[i],result[i]);
    }
    for(auto el: result) {
        std::cout << el << " ";
    }
    return 0;
}