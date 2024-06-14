#include <variant>
#include <string>
#include <vector>
#include <iostream>

using variant = std::variant<int, std::string>;

auto& operator <<(std::ostream& out, const variant& p){
    if (std::holds_alternative<int>(p)) {
        out << std::get<int>(p);
    }
    else if (std::holds_alternative<std::string>(p)) {
        out << std::get<std::string>(p);
    }
    return out;
}

int main() {
    variant variable = 10;
    std::cout << variable << std::endl;
 
    variable = "test";
    std::cout << variable << std::endl;

    return 0;
}