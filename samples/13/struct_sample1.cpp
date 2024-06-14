struct point_t {
    double x;
    double y;
};

int main() {
    point_t point = {1, 3};
    
    point_t anotherPoint {0, 0};
    int a {2};
    double dbl = {0.2};

    point.x = 1.0;
    point.y = 1.0;
    return 0;
}