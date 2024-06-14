#include <any>
#include <string>
#include <iostream>

auto& operator <<(std::ostream& out, const std::any& p){
    out << std::any_cast<int>(p);
    return out;
}

int main() {
    std::any variable = 10;
    std::cout << variable << std::endl;
 
    variable = "test";
    std::cout << variable << std::endl;

    return 0;
}