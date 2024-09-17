#include "mymath.h"

int myabs(int number) {
    return number < 0 ? -number : number;
}

int mymin(int left, int right) {
    return left < right ? left : right;
}
