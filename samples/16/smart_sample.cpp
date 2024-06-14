#include <iostream>

template <typename TYPE>
class SmartPointer
{
    TYPE* ptr;

public:
    SmartPointer(TYPE* p): ptr(p){}
    ~SmartPointer() { delete ptr; }

    static SmartPointer<TYPE> create(TYPE value) {
        TYPE* p = new TYPE(value);
        return SmartPointer<TYPE>(p);
    }

    TYPE& operator*() const { return *ptr; }
    TYPE* operator->() const { return ptr; }
};

struct Point {
    int x, y;
};

int main() {
    SmartPointer<int> ptr(new int {10});
    SmartPointer<int> ptr3(new int {10});

    ptr3 = ptr;

    auto ptr2 = SmartPointer<Point>::create({11, 12});



/*    for(auto i = 0; i < 10; ++i) {
        int * oops = new int[10000000];
        oops[rand() % 100000] = 10;
        // std::cout << "pause" << std::endl;
        system("read -s -n 1 -p 'Press any key to continue . . .'");
    }
*/
    std::cout << *ptr << std::endl;
    std::cout << ptr2->x << ", " << ptr2->y << std::endl;

    return 0;
}