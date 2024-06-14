#include <iostream>
#include <thread>
#include <mutex>
#include <vector>
#include <algorithm>

using vector = std::vector<int>;

std::mutex locker;

void populate_vector(vector& v, size_t size) {
    //std::lock_guard<std::mutex> lg(locker);
    std::this_thread::sleep_for(std::chrono::microseconds(10));
    while(size > 0) {
        v.push_back(size);
        --size;
    }
}

void find_value(const vector& v, size_t value) {
    //std::lock_guard<std::mutex> lg(locker);
    auto it = std::find(v.begin(), v.end(), value);
    it == v.end()
        ? std::cout << "not found!" << std::endl
        : std::cout << "found!" << std::endl;
}

int main() {
    vector v;
    std::jthread t_populate(populate_vector, std::ref(v), 10);
    std::jthread t_find2(find_value, std::cref(v), 7);
    return 0;
}