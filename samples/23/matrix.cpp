// g++ matrix.cpp -o matrix -std=c++20
#include <array>
#include <iostream>
#include <thread>
#include <mutex>

using matrix = std::array<std::array<double, 4>, 4>;
std::mutex mutex;

void sum(const matrix &a, const matrix &b, matrix &c)
{
    std::lock_guard<std::mutex> locker(mutex);
    for (int i = 0; i < 4; i++)
    {
        for (int row = 0; row < 4; row++)
        {
            c[row][i] = a[row][i] + b[row][i];
        }
    }
}

void print(const matrix &m)
{
   // std::this_thread::sleep_for(std::chrono::milliseconds(2));
   // std::lock_guard<std::mutex> locker(mutex);
   mutex.lock();
    for (int row = 3; row > -1; row--)
    {
        for (int col = 0; col < 4; ++col)
        {
            std::cout << m[row][col] << " ";
        }
        std::cout << std::endl;
    }
   // mutex.unlock();
}

int main()
{
    matrix a{
        std::array<double, 4>{2, 3, 4, 1},
        std::array<double, 4>{1, 3, 2, 4},
        std::array<double, 4>{0, 3, 3, 0},
        std::array<double, 4>{4, 1, 1, 1},
    };
    matrix b{
        std::array<double, 4>{1, 3, 4, 1},
        std::array<double, 4>{1, 3, 0, 4},
        std::array<double, 4>{0, 4, 3, 0},
        std::array<double, 4>{4, 1, 2, 1},
    };
    matrix c{
        std::array<double, 4>{0, 0, 0, 0},
        std::array<double, 4>{0, 0, 0, 0},
        std::array<double, 4>{0, 0, 0, 0},
        std::array<double, 4>{0, 0, 0, 0},
    };

    std::jthread tprint(print,std::cref (c));
    std::jthread t1(sum,std::cref(a),std::cref(b), std::ref(c));
    // std::jthread tprint2(print, c);
    return 0;
}