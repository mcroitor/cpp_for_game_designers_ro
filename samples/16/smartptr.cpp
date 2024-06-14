#include <iostream>

template <typename TYPE>
class SmartPtr
{
    TYPE *m_value;

public:
    SmartPtr(TYPE *value) : m_value(value)
    {
        std::cout << "Memory is allocated" << std::endl;
    }
    ~SmartPtr()
    {
        std::cout << "Memory is freed" << std::endl;
        delete m_value;
    }

    TYPE &operator*() const
    {
        return *m_value;
    }
};

int main()
{
    SmartPtr<int> value(new int{7});
    {
        SmartPtr<int> name(new int{7});
        name = value;
    }
    std::cout << *value << std::endl;
    return 0;
}
