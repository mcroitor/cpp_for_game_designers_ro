#include <iostream>

int main() {
    int i = 0;
    int size = 9;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    std::cout << "ptr(a) = " << a << std::endl;
    std::cout << "deref(a) = " << *a << std::endl;
    for(i = 0; i < size; i++) {
        std::cout << "a [" << i << "] = " << i[a] << std::endl;
    }
    // a[i] <=> *(a + i) <=> *(i + a) <=> i[a]
    std::cout << (size - 1)[a] << std::endl;
    return 0;
}