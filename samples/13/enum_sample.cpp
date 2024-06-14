#include <iostream>

// using namespace std;
using std::cout;

enum color_type
{
    no_color,
    black = 10,
    white
};

// const int no_color = 20;

int main()
{

    color_type myColor = color_type::no_color;

    cout << "myColor: " << myColor << std::endl;

    return 0;
}