
template <typename T>
struct InputIterator
{
    const T &operator*() const;
    InputIterator<T> operator++();
    InputIterator<T> operator++(int);
};

template <typename T>
struct OutputIterator
{
    T &operator*();
    OutputIterator<T> operator++();
    OutputIterator<T> operator++(int);
};

template <typename T>
struct ForwardIterator
{
    T &operator*();
    const T &operator*() const;
    ForwardIterator<T> operator++();
    ForwardIterator<T> operator++(int);
};

template <typename T>
struct BidirectionalIterator
{
    T &operator*();
    const T &operator*() const;
    BidirectionalIterator<T> operator++();
    BidirectionalIterator<T> operator++(int);
    BidirectionalIterator<T> operator--();
    BidirectionalIterator<T> operator--(int);
};

template <typename T>
struct RandomAccessIterator
{
    T &operator*();
    const T &operator*() const;
    RandomAccessIterator<T> operator++();
    RandomAccessIterator<T> operator++(int);
    RandomAccessIterator<T> operator--();
    RandomAccessIterator<T> operator--(int);

    void operator+=(size_t);
    T &operator[](size_t);
    const T &operator[](size_t) const;
};

template <typename T>
size_t operator-(const RandomAccessIterator<T> &, const RandomAccessIterator<T> &);

template <typename T>
RandomAccessIterator<T> &operator+(const RandomAccessIterator<T> &, size_t);
template <typename T>
RandomAccessIterator<T> &operator+(size_t, const RandomAccessIterator<T> &);

template <typename Type>
class Container
{
    Type *values;
    size_t size;

public:
    typedef Type value_type;

    class iterator
    {
    public:
        iterator<Type> operator ++();
        iterator<Type> operator ++(int);
        Type &operator *();
        const Type &operator *() const;
    };

    Container();
    Container(const Container<Type>&);
    ~Container();

    iterator<Type> begin();
    iterator<Type> end();

    size_t size() const;
    bool empty() const;
    size_t max_size() const;
    void swap(Container<Type>&);
};