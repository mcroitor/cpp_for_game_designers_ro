#include <thread>
#include <iostream>
#include <string>
#include <vector>

void print(std ::string message)
{
    std::cout << "thread id: " << std::this_thread::get_id() << std::endl;
    std::cout << message;
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    std::cout << "cores: " << std::thread::hardware_concurrency() << std::endl;
    std::vector<std::thread> threads;
    for (int i = 1; i < argc; i++)
    {
        threads.push_back(std::thread(print, argv[i]));
        std::cout << threads[i - 1].get_id() << std::endl;
    }
    for (int i = 0; i < argc - 1; i++)
    {
        threads[i].join();
    }
    return (0);
}
