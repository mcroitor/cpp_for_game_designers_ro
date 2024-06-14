#include <iostream>

union color_type {
    /**
     * @brief color definition as integer
     * 
     */
    int color;
    /**
     * @brief rgb representation of color
     * 
     */
    unsigned char rgb[4];
};

int main() {
    color_type color;
    color.color = 0x00ffab01;
    for(int i = 0; i < 4; i++) {
        std::cout << "rgb[" << i << "] = " << (int)(color.rgb[i]) << std::endl;
    }
    return 0;
}