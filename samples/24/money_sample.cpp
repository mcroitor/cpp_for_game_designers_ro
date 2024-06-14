#include <iostream>
#include <map>
#include <string>

enum class Currency
{
    EUR,
    USD,
    MDL,
};

const static std::map<Currency, std::string> currency_converter{
    {Currency::USD, "USD"},
    {Currency::EUR, "EUR"},
    {Currency::MDL, "MDL"},
};

class Money
{
    Currency _currency;
    double _value;

public:
    Money(const Currency &currency, const double value) : _value(value), _currency(currency) {}
    std::string ToString() const { return std::to_string(_value) + currency_converter.at(_currency); }
};
std::ostream &operator<<(std::ostream &out, const Money &money)
{
    out << money.ToString();
    return out;
}

Money operator"" _USD(long double value)
{
    return Money(Currency::USD, value);
}
Money operator"" _MDL(long double value)
{
    return Money(Currency::MDL, value);
}
Money operator"" _EUR(long double value)
{
    return Money(Currency::EUR, value);
}

int main() {
    Money leraMoney = 2.3_MDL;

    std::cout << leraMoney << std::endl;
    return 0;
}