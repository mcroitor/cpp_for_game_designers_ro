#include "mymath.h"

namespace my {
    int min(int a, int b){
        return a < b ? a : b;
    }

    int mod(int a){
        return a >= 0 ? a : -a;
    }
}