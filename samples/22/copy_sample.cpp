#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>

void print(int i);

template <typename InputIter_1, typename OutputIter_2>
void copy(InputIter_1 begin_1, InputIter_1 end_1, OutputIter_2 begin_2)
{
    while (begin_1 != end_1)
    {
        *begin_2 = *begin_1;
        ++begin_2;
        ++begin_1;
    }
}

template <typename InputIter_1, typename OutputIter_2, typename Predicate>
void copy_if(InputIter_1 begin_1, InputIter_1 end_1, OutputIter_2 begin_2, Predicate predicate)
{
    while (begin_1 != end_1)
    {
        if (predicate(*begin_1))
        {
            *begin_2 = *begin_1;
            ++begin_2;
        }
        ++begin_1;
    }
}

struct isOdd
{

    bool operator()(int i) const
    {

        return i % 2 == 1;
    }
};

int main()
{
    std::deque<int> d{8, 12, 10, 5, 4, 9, 13, 15};
    std::vector<int> v;

    isOdd _isOdd;

    std::cout << "vector before copying: ";
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    v.resize(d.size());
    std::cout << "vector after resize: ";
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    std::copy_if(d.begin(), d.end(), v.begin(), _isOdd);
    std::cout << "vector after copying: ";
    std::for_each(v.begin(), v.end(), print);
    std::cout << std::endl;

    return 0;
}

void print(int i)
{
    std::cout << i << " ";
}