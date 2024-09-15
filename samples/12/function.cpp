#include <cstdio>
#include <vector>

int Length(const char* str) {
    int length = 0;
    while (*str != '\0') {
        length++;
        str++;
    }
    return length;
}

int main() {
    int number;
    std::vector<int> number2;

    std::vector<int>::const_iterator it = number2.begin();
    auto it2 = number2.begin();

    const char* str = "";
    int length = Length(str);
    printf("Length of \"%s\" is %d\n", str, length);
    const char* str2 = " ";
    int length2 = Length(str2);
    printf("Length of \"%s\" is %d\n", str2, length2);
    return 0;
}