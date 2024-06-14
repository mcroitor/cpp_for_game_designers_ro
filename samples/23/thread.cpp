#include <thread>
#include <iostream>
#include <string>
using std::string;

void print(string message){
    std::cout << "message: " << message << std::endl;
}

int main(){

    std::thread t1(print, "child1_process");
    std::thread t2(print, "child2_process");
    t1.join();
    t2.detach();

    print("main process");

    return 0;
}