#include <optional>
#include <iostream>

auto& operator <<(std::ostream& out, const std::optional<int>& p){
    if (p.has_value())
        out << p.value();
    else
        out << "oops";
    return out;
}

int main(int argc, char* argv[]) {
    std::optional<int> variable;
    std::cout << variable << std::endl;
 
    variable = 10;
    std::cout << variable << std::endl;

    return 0;
}