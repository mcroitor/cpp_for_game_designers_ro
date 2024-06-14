template<class InputIterator, class Function>
void for_each(InputIterator begin, InputIterator end, Function function) {
    while(begin != end) {
        function(*begin);
        ++begin;
    }
}

template<class View, class Function>
void for_each(View view, Function function) {
    auto iter = begin(view);
    auto iter2 = end(view);
    while(iter != iter2) {
        function(*iter);
        ++iter;
    }
}
