/**
 * floating-point data representation in one byte (8 bits):
 *  - Bit 7 (MSB): sign of mantissa (0 = positive, 1 = negative)
 *  - Bits 6-3: mantissa (4 bits)
 *  - Bit 2: sign of exponent (0 = positive, 1 = negative)
 *  - Bits 1-0 (LSB): exponent value (2 bits)
 */
#include <iostream>
#include <string>
#include <cmath>

typedef unsigned char FloatInByte;

FloatInByte fromFloat(float f) {
    if (f == 0.0f) return 0;

    // 1. Extract sign of mantissa
    unsigned char signMantissa = (f < 0) ? 1 : 0;
    float absF = std::abs(f);

    // 2. Normalize using frexp: absF = mantissa * 2^exp
    int exp;
    float mantissa = std::frexp(absF, &exp); // mantissa is in [0.5, 1.0)

    // Scale mantissa to fit 4 bits (values 0 to 15)
    int mVal = static_cast<int>(mantissa * 16.0f) & 0x0F;

    // 3. Extract exponent sign and magnitude (clamp to 2 bits: 0-3)
    unsigned char signExp = (exp < 0) ? 1 : 0;
    int absExp = std::abs(exp);
    if (absExp > 3) absExp = 3; 

    // 4. Pack fields into 1 byte
    FloatInByte result = 0;
    result |= (signMantissa & 0x01) << 7; // Bit 7
    result |= (mVal & 0x0F)         << 3; // Bits 6-3
    result |= (signExp & 0x01)      << 2; // Bit 2
    result |= (absExp & 0x03)       << 0; // Bits 1-0

    return result;
}

std::string toBinaryString(FloatInByte f) {
    std::string result;
    for (int i = 7; i >= 0; --i) {
        result += (f & (1 << i)) ? '1' : '0';
    }
    return result;
}

int main() {
    float input = 0.5;
    FloatInByte b = fromFloat(input);
    std::cout << "Input float: " << input 
        << " Binary representation: " << toBinaryString(b) << std::endl;
    input = 0.25;
    b = fromFloat(input);
    std::cout << "Input float: " << input 
        << " Binary representation: " << toBinaryString(b) << std::endl;
    input = 3.;
    b = fromFloat(input);
    std::cout << "Input float: " << input 
        << " Binary representation: " << toBinaryString(b) << std::endl;
    input = 1. / 3.;
    b = fromFloat(input);
    std::cout << "Input float: " << input 
        << " Binary representation: " << toBinaryString(b) << std::endl;
    return 0;
}