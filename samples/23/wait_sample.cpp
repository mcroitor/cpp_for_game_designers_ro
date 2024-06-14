#include <iostream>
#include <mutex>
#include <string>
#include <thread>

bool isReady;
std::mutex m;

void wait_for_flag() {
    std::unique_lock<std::mutex> locker(m);
    while(!isReady) {
        m.unlock();
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
        m.lock();
    }
}

void print_string(const std::string& s) {
    wait_for_flag();
    std::cout << s << std::endl;
}

void create_string(std::string& s) {
    for(char a = 'a'; a <= 'z'; a++) {
        s += a;
        std::this_thread::sleep_for(std::chrono::milliseconds(5));
    }
    isReady = true;
}

int main () {
    std::string str;
    std::jthread t_create(create_string, std::ref(str));
    std::jthread t_print(print_string, std::cref(str));
    return 0;
}