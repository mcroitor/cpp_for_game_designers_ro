#include <vector>
#include <algorithm>
#include <chrono>
#include <execution>
#include <random>
#include <iostream>

using std::chrono::system_clock;
using ms_t = std::chrono::microseconds;

const int SIZE = 10'000'000;
std::mt19937 gen(system_clock::now().time_since_epoch().count());

void fill(std::vector<int> &v)
{
    v.resize(SIZE);
    for (int i = 0; i < v.size(); ++i)
    {
        v[i] = gen() % 2000;
    }
}

int main()
{
    std::vector<int> v;
    fill(v);
    ms_t ms;

    // default
    auto s = std::chrono::system_clock::now();
    int count = std::count(v.begin(), v.end(), 100);
    auto e = std::chrono::system_clock::now();
    
    ms = std::chrono::duration_cast<ms_t>(e - s);
    std::cout << "[seq] found " << count << " in " << ms.count() << " ms" << std::endl;

    // seq policy
    s = std::chrono::system_clock::now();
    count = std::count(std::execution::seq, v.begin(), v.end(), 100);
    e = std::chrono::system_clock::now();
    
    ms = std::chrono::duration_cast<ms_t>(e - s);
    std::cout << "[sq2] found " << count << " in " << ms.count() << " ms" << std::endl;
    
    // parallel policy
    s = std::chrono::system_clock::now();
    count = std::count(std::execution::par, v.begin(), v.end(), 100);
    e = std::chrono::system_clock::now();
    
    ms = std::chrono::duration_cast<ms_t>(e - s);
    std::cout << "[par] found " << count << " in " << ms.count() << " ms" << std::endl;
    return 0;
}
