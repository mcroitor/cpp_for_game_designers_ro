#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>
#include <numeric>

using std::chrono::system_clock;

// function for printing
void print(int i) {
    std::cout << i << " ";
}

struct RandomGenerator {
    int _min;
    int _max;
    // Seed with a real random value, if available
    std::mt19937 gen32;
 
    RandomGenerator(int min, int max):
        _min(min),
        _max(max),
        gen32(system_clock::now().time_since_epoch().count()) {
    }
    int operator()() {
        return gen32() % (_max - _min + 1) + _min;
    }
};

// functor class for Sum
struct Sum{
    int operator()(int a, int b) const{
        return a+b;
    }
};

// functor class for Product
struct Product{
    int operator()(int a, int b) const{
        return a*b;
    }
};


int main() {
    size_t size = 10;

    std::deque<int> d1(size), d2(size);
    std::vector<unsigned long long> result;
    // resize vector to necessary size
    result.resize(size);

    // define a sum functor
    Sum sum;

    // place random numbers in the d1 deque
    std::generate(d1.begin(), d1.end(), RandomGenerator(0, 100));
    // place random numbers in the d2 deque
    std::generate(d2.begin(), d2.end(), RandomGenerator(0, 100));

    // print d1
    std::cout << "generated vector 1: ";
    std::for_each(d1.begin(), d1.end(), print);
    std::cout << std::endl;

    // print d2
    std::cout << "generated vector 2: ";
    std::for_each(d2.begin(), d2.end(), print);
    std::cout << std::endl;

    // place sum of d1 and d2 to result vector and print result
    std::transform(d1.begin(), d1.end(), d2.begin(), result.begin(), sum);
    std::cout << "vector sum: ";
    std::for_each(result.begin(), result.end(), print);
    std::cout << std::endl;

    // calculate the product of elements from the result vector
    auto total = std::accumulate(result.begin(), result.end(), 1ull, Product());

    std::cout << "sum = " << total << std::endl;

    return 0;
}
