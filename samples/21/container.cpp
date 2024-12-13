#include <iostream>

template <class TYPE, size_t SIZE>
class Container
{
    TYPE data[SIZE];
public:
    typedef TYPE value_type;
    typedef TYPE* iterator;
    typedef const TYPE* const_iterator;

    Container(){}
    Container(const Container<TYPE, SIZE>& other) {
        for(size_t i = 0; i < SIZE; i++) {
            data[i] = other.data[i];
        }
    }
    ~Container() {}

    iterator begin() { return data; }
    iterator end() { return data + SIZE; }
    const_iterator begin() const { return data; }
    const_iterator end() const { return data + SIZE; }

    bool operator==(const Container<TYPE, SIZE>& rhs) {
        for(size_t i = 0; i < SIZE; i++) {
            if(data[i] != rhs.data[i]) {
                return false;
            }
        }
        return true;
    }

    Container<TYPE, SIZE>& operator=(const Container<TYPE, SIZE>& rhs) {
        for(size_t i = 0; i < SIZE; i++) {
            data[i] = rhs.data[i];
        }
        return *this;
    }
    TYPE& operator[](size_t index) { return *(begin() + index); }
    const TYPE& operator[](size_t index) const { return *(begin() + index); }

    size_t size() const{ return SIZE; }
    size_t max_size() const{ return SIZE; }
    bool empty() const{ return SIZE == 0; }

    TYPE front() const { return *(begin()); }
    TYPE back() const { return *(--end()); }
};

int main()
{
    Container<int, 10> c;

    for(size_t i = 0; i < c.size(); i++) {
        c[i] = i * i;
    }

    for(auto it = c.begin(); it != c.end(); it++) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    return 0;
}

template <class TYPE1, class TYPE2>
struct pair{
    TYPE1 first;
    TYPE2 second;
};
