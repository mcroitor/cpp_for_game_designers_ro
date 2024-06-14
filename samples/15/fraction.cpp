// строка компиляции gcc: g++ fraction.cpp -o fraction -std=c++20
// строка компиляции MSVC: cl.exe fraction.cpp /Fe:fraction.exe /std:c++20 /EHsc /nologo

#include <iostream>
#include <string>

class Fraction
{
    int numerator;
    int denominator;

public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d)
    {
    }
    Fraction(Fraction const &F) : numerator(F.numerator), denominator(F.denominator)
    {
    }

    Fraction operator=(const Fraction &other)
    {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }

    Fraction operator*=(const Fraction &other)
    {
        numerator *= other.numerator;
        denominator *= other.denominator;
        return *this;
    }

    std::string toString() const
    {
        return std::to_string(numerator) + "/" + std::to_string(denominator);
    }

    auto operator <=>(const Fraction &other) const
    {
        return numerator * other.denominator <=> other.numerator * denominator;
    }
};

Fraction operator*(const Fraction &left, const Fraction &right)
{
    Fraction tmp(left);
    tmp *= right;
    return tmp;
}

std::ostream &operator<<(std::ostream &out, const Fraction &left)
{
    out << left.toString();
    return out;
}

/*
    разделитель delimiter введен для правильного чтения дроби
*/
std::istream &operator>>(std::istream &in, Fraction &left)
{
    int numerator;
    int denominator;
    char delimiter;
    in >> numerator >> delimiter >> denominator;
    left = Fraction(numerator, denominator);
    return in;
}

bool operator==(const Fraction &left, const Fraction &right)
{
    return left.toString() == right.toString();
}

int main()
{

    Fraction a, b;
    std::cin >> a >> b;
    std::cout << (a * b) << " " << (a < b);
    return 0;
}