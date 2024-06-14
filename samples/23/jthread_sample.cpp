/**
 * @file jthread_sample.cpp
 * @author your name (you@domain.com)
 * @brief g++ jthread_sample.cpp -ojthread -std=c++20
 * @version 0.1
 * @date 2023-10-28
 * 
 * @copyright Copyright (c) 2023
 * 
 */

#include <thread>
#include <iostream>

void hello() {
    std::cout << "hello from " << std::this_thread::get_id() << std::endl;
}

int main() {
    std::jthread t(hello);
    return 0;
}
