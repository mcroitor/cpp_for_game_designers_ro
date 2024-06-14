#include <thread>
#include <iostream>
#include <string>

void hello(std::string message) {
    std::cout << message << std::endl;
}

int main() {
    std::thread t1(hello, "hello from child process");
    std::thread t2(hello, "hello from another child process");

    t1.join();
    t2.join();
    return 0;
}
