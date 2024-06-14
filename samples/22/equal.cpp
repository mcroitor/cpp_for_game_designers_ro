

template<typename InputIterator1, typename InputIterator2>
bool equal(InputIterator1 begin1, InputIterator1 end1, InputIterator2 begin2) {
    while (begin1 != end1) {
        if(*begin1 != *begin2) {
            return false;
        }
        ++begin1;
        ++begin2;
    }
    return true;
}

template<typename InputIterator1, typename InputIterator2, typename Predicate>
bool equal(InputIterator1 begin1, InputIterator1 end1, InputIterator2 begin2, Predicate predicate) {
    while (begin1 != end1) {
        if(!predicate(*begin1, *begin2)) {
            return false;
        }
        ++begin1;
        ++begin2;
    }
    return true;
}
