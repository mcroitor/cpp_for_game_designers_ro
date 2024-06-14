class vector
{
    float x;
    float y;

public:
    vector add(vector y);

    vector();
    vector(const vector &y);
    vector(float x, float y);
    ~vector(); // destructor
};

vector add(vector x, vector y)
{
    return x.add(y);
}

int main()
{
    vector v1;
    vector* pv = new vector(1, 1);
    {
        vector v2(1, 2);
    }
    vector v3(v1);
    v1 = add(*pv, v3);
    delete pv;
    return 0;
}