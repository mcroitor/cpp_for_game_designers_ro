// g++ async_sample.cpp -oasync_sample -std=c++20
#include <iostream>
#include <thread>
#include <vector>
#include <future>

int sum(int a, int b){
    return a + b;
}

int main(){
    std::vector<int> a {1, 2, 3, 4, 5};
    std::vector<int> b {5, 4, 3, 2, 1};
    std::vector<std::future<int>> result(5);

    for(int i = 0; i != 5; ++i) {
        result[i] =  std::async(sum, a[i], b[i]);
    }
    for(std::future<int>& el: result) {
        std::cout << el.get() << " ";
    }
    return 0;
}