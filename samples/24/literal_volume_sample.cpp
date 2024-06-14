#include <iostream>

// volume in liters
using volume_t = long double;

constexpr volume_t operator "" _l(long double volume){
    return volume;
}

constexpr volume_t operator "" _l(unsigned long long volume){
    return (volume_t)volume;
}

volume_t operator "" _l(const char* str, size_t len){
    return std::strtold(str, nullptr);
}

constexpr volume_t operator "" _ml(long double volume){
    return 0.001 * volume;
}

constexpr volume_t operator "" _ml(unsigned long long volume){
    return 0.001 * (volume_t)volume;
}

volume_t operator "" _ml(const char* str, size_t len){
    return 0.001 * std::strtold(str, nullptr);
}

constexpr volume_t operator "" _m3(long double volume){
    return 1000.0 * volume;
}

constexpr volume_t operator "" _m3(unsigned long long volume){
    return 1000.0 * (volume_t)volume;
}

volume_t operator "" _m3(const char* str, size_t len){
    return 1000.0 * std::strtold(str, nullptr);
}

int main() {
    volume_t volume = 12.2_l + 2_m3 - "300"_ml;
    std::cout << "Volume: " << volume << std::endl;
}
