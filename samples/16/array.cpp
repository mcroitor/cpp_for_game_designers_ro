#include <iostream>

template <typename TYPE, size_t SIZE>
class Array
{
    TYPE values[SIZE];

public:
    size_t size() const { return SIZE; }

    Array() = default;
    Array(const Array<TYPE, SIZE> &array)
    {
        for (size_t i = 0; i < array.size(); i++)
        {
            values[i] = array.values[i];
        }
    };

    TYPE &operator[](size_t i) { return values[i]; }
};

// bool specialization
template <size_t SIZE>
class Array<bool, SIZE>
{
    const static size_t INTERNAL_SIZE = SIZE / 8 + 1;
    char values[INTERNAL_SIZE];

public:
    size_t size() const { return SIZE; }

    Array() = default;
    Array(const Array<bool, SIZE> &array)
    {
        for (size_t i = 0; i < INTERNAL_SIZE; i++)
        {
            values[i] = array.values[i];
        }
    };

    bool &operator[](size_t i)
    {
        size_t cell_index = i / 8;
        size_t shift = i % 8;
        return (bool)(values[cell_index] & (1 << shift));
    }

    static size_t internal_size() { return INTERNAL_SIZE; }
};

template <typename ARRAY_TYPE>
std::ostream &operator<<(std::ostream &out, const ARRAY_TYPE &array)
{
    for (size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
    return out;
}

int main()
{
    Array<bool, 5> array;
    array[0] = true;
    array[2] = true;

    /* for (size_t i = 0; i < array.size(); i++)
    {
        std::cout << array[i] << std::endl;
    }
    */

    std::cout << array << std::endl;

    std::cout << array.internal_size() << std::endl;
    return 0;
}