class complex
{
    float real;
    float imaginary;

public:
    complex sum(complex c);
    complex product(complex p);
};
complex sum(complex a, complex b)
{

    complex result = a.sum(b);
    return result;
}

int main()
{

    return 0;
}