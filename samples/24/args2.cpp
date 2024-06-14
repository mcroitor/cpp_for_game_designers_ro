#include <iostream>
#include <cstdlib>

void help(int argc, char* argv[]) {
    std::cout << "Usage: " << argv[0] << " [<number1>] [<number2>]" << std::endl;
}

int main(int argc, char* argv[]) {
    if(argc < 3) {
        help(argc, argv);
        return 1;
    }

    int a = atoi(argv[1]);
    int b = atoi(argv[2]);

    std::cout << a + b << std::endl;
    return 0;
}