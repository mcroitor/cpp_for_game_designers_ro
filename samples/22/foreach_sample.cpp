#include <iostream>
//#include <algorithm>
#include <vector>

template<typename InputIter, typename Func>
void for_each(InputIter begin, InputIter end, Func function){
    while(begin != end){
        function(*begin);
        ++begin;
    }
}

void print(int i);

int main() {
    std::vector<int> data {8, 12, 10, 5, 4, 9, 13, 15};

    for_each(data.begin(), data.end(), print);

    return 0;
}

void print(int i) {
    std::cout << i << " ";
}
