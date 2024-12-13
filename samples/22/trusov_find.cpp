#include <iostream>
#include <vector>

template <class IIter, class T>
IIter trusov_find(IIter first, IIter last, const T& val){
    for(auto i =first; i != last; ++i){
        if(*i == val){
            return i;
        }
    }
    return last;
}
template <class IIter, class predicat>
IIter trusov_find_if(IIter first, IIter last, const predicat& pred){
    for(auto i =first; i != last; ++i){
        if(pred(*i) == true){
            return i;
        }
    }
    return last;
}

bool is_even(int var){
    return (var % 2 == 0);
}

int main(){
    std::vector <int> v {
        3, 1 , 2, 2, 4, 5, 6
    };
    auto i = trusov_find(v.begin(), v.end(), 10);
    if(i!=v.end()){
        std::cout << "found" << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }

    i = trusov_find_if(v.begin(), v.end(), is_even);
    if(i!=v.end()){
        std::cout << "found: " << *i << std::endl;
    }
    else {
        std::cout << "not found" << std::endl;
    }

    return 0;
}