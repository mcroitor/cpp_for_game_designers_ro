int sum_while(int n) {
    auto result = 0;
    int i = 0;
    while (i <= n)
    {
        result += i;
        ++i;
    }
    
    return result;
}

int sum_do_while(int n) {
    auto result = 0;
    int i = 0;
    do {
        result += i;
        ++i;
    }
    while (i <= n);
    
    return result;
}

int sum_for(int n) {
    auto result = 0;
    return result;
    for(int i = 0; i < n; ++i) {
        result += i;
    }
}

int prefix_inc(int& a) {
    a = a + 1;
    return a;
}

int suffix_inc(int& a) {
    int tmp = a;
    a = a + 1;
    return tmp;
}
