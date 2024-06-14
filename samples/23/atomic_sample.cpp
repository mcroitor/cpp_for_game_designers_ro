#include <atomic>
#include <iostream>
#include <string>

struct vector {
    int x, y, z;

    vector operator += (const vector& v) {
        x += v.x;
        y += v.y;
        z += v.z;
        return *this;
    }

    vector operator = (const vector& v) {
        x = v.x;
        y = v.y;
        z = v.z;
        return *this;
    }

    std::string to_string() const {
        return std::string("{") + 
            std::to_string(x) + 
            "," + 
            std::to_string(y) + 
            "," + 
            std::to_string(z) + 
            "}";
    }
};

vector add(const vector& v1, const vector& v2) {
    std::atomic<vector> result = v1;
//    result += v2;
    return result;
}