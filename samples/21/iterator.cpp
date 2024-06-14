template<class Type>
struct InputIterator {
    const Type& operator *() const;
    void operator ++();
    void operator ++(int);
};

template<class Type>
struct OutputIterator {
    Type& operator *();
    void operator ++();
    void operator ++(int);
};

template<class Type>
struct SequenceIterator: InputIterator, OutputIterator{
};

template<class Type>
struct BidirectionalIterator: SequenceIterator {
    void operator --();
    void operator --(int);
};

template<class Type>
struct RandomAccessIterator: BidirectionalIterator {
    RandomAccessIterator operator + (size_t);
};

template<class Type>
size_t operator - (const RandomAccessIterator<Type>&, const RandomAccessIterator<Type>&);

template<class Type>
bool operator < (const RandomAccessIterator<Type>& a, const RandomAccessIterator<Type>& b) {
    return a - b < 0;
}

template<typename Type>
class Container {
public:
    typedef Type value_type;

    struct Iterator {
        const Type& operator *() const;
        Type& operator *();
        void operator ++();
    };

    Container();
    Container(const Container&);
    ~Container();

    Iterator begin();
    Iterator end();

    bool operator == (const Container&);
    void operator = (const Container&);
    size_t size() const;
    size_t max_size() const;
    bool empty() const;
    void swap(Container&);

    Type& operator[](size_t n) {
        return *(this->begin() + n);
    }
};

int main() {
    Container<int> container;

    Container<int>::value_type value;

    Container<int>::iterator it;
    for(it = container.begin(); it != container.end(); ++it) {
        // very bad
        if(*it == 10) {
            container.erase(it);
        }
        std::cout << "was removed " << *it;
    }
    return 0;
}