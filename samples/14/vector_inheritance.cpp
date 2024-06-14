class vector
{
    double _x, _y, _z;

public:
    // конструктор по умолчанию
    vector();
    // конструктор с параметрами
    vector(double x, double y, double z);
    // конструктор копирования
    vector(const vector &);
    // деструктор
    ~vector();
};

int main(){
    vector* a = new vector;
    vector b(2.0, 1.0, 1.0);
    vector c(b);

    delete a;
    return 0;
}