#include <cstdio>

int main() {
    int number = 10;

    try {
        if (number == 10) {
            throw "Number is 10";
        }
        printf("Number is %d\n", number);
    } catch (const char* message) {
        printf("Caught exception: %s\n", message);
    }
    return 0;
}