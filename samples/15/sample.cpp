#include <iostream>
#include <fstream>
#include <string>

class Fraction {
    int numerator;
    int denominator;
public:
    Fraction(int n = 0, int d = 1) : numerator(n), denominator(d) {}
    Fraction operator = (const Fraction& other) {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }
    Fraction operator += (const Fraction& other) {
        numerator = numerator * other.denominator + other.numerator * denominator;
        denominator = denominator * other.denominator;
        return *this;
    }

    int getNumerator() const { return numerator; }
    int getDenominator() const { return denominator; }

    std::string toString() const {
        return std::to_string(numerator) + '/' + std::to_string(denominator);
    }
};

Fraction operator + (const Fraction& a, const Fraction& b) {
    Fraction result(a);
    result += b;
    return result;
}

int operator <=> (const Fraction& a, const Fraction& b) {
    return a.getNumerator() * b.getDenominator() - b.getNumerator() * a.getDenominator();
}

bool operator == (const Fraction& a, const Fraction& b) {
    return (a <=> b) == 0;
}

bool operator != (const Fraction& a, const Fraction& b) {
    return !(a == b);
}

bool operator < (const Fraction& a, const Fraction& b) {
    return (a <=> b) < 0;
}

std::istream& operator >> (std::istream& in, Fraction& f) {
    int n, d;
    char c;
    in >> n >> c >> d;
    f = Fraction(n, d);
    return in;
}

std::ostream& operator << (std::ostream& out, const Fraction& f) {
    out << f.toString();
    return out;
}

int main() {
    Fraction a;
    std::cin >> a;

    std::ofstream fout("output.txt");
    fout << a;
    fout.close();

    Fraction b;
    std::ifstream fin("output.txt");
    fin >> b;

    if (a == b) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "ERROR" << std::endl;
    }
    return 0;
}