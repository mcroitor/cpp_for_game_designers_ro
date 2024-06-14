#include <iostream>

class cut
{
    double size_;

public:
    cut(double s) : size_(s) {}

    double size() const
    {
        return size_;
    }

    cut operator=(cut const right)
    {
        size_ = right.size_; // <=> this->size_ = right.size_
        return *this;
    }

    cut operator+=(cut const right)
    {
        size_ += right.size_; // <=> this->size_ += right.size_
        return *this;
    }
};

cut operator+(const cut &left, const cut &right)
{
    cut result = left;
    result += right;
    return result;
}

// == operator
bool operator==(const cut &left, const cut &right)
{
    return left.size() == right.size();
}

int main()
{
    cut a(2);
    cut b(3);
    cut c = a + b;
    std::cout << c;
    return 0;
}