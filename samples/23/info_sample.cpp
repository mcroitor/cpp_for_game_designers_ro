#include <thread>
#include <string>
#include <iostream>
#include <atomic>

void info(std::string const& name) {
    std::cout << name << " process id: " << std::this_thread::get_id() << std::endl;
}

int main() {
    int cores = std::thread::hardware_concurrency();
    std::cout << " cores: " << cores << std::endl;

    std::thread thread(info, "child");
    info("parent");
    std::cout << " child process id: " << thread.get_id() << std::endl;
    thread.join();

    return 0;
}