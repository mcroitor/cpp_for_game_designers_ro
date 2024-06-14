#include <iostream>
#include <thread>
void sum (int a,int b, int &result)
{
    result = a + b;
}

int main(int argc, char const *argv[])
{
    int a = 10;
    int b = 5;
    int c = 0;
    //sum (a,b,c);
    std::jthread t(sum, a,b,std:: ref (c));
    std::this_thread::sleep_for(std::chrono::milliseconds(1));
    std::cout << c << std::endl;
    return 0;
}
