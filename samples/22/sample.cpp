#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

/**
 * a = {a_1, a_2, ..., a_n}
 * b = {b_1, b_2, ..., b_n}
 * a * b = sum {i: 1, n} (a_i * b_i)
 */

int product(int x, int y){
    return x * y;
}

template<class IIter, class OIter>
void copy(IIter first1, IIter last1, OIter first2){
    while(first1 != last1){
        *first2 = *first1;
        ++first1;
        ++first2;
    }
}

int main() {
    std::vector<int> a {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    std::vector<int> b {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    std::vector<int> tmp;

    std::transform(
        a.begin(), a.end(),
        b.begin(),
        //result.begin(),
        std::back_inserter(tmp),
        product
    );

    auto result = std::accumulate(tmp.begin(), tmp.end(), 0);

    std::cout << "product scalar = " << result << std::endl;
    return 0;
}