typedef unsigned char age_type;
typedef unsigned long long duration_type;
typedef unsigned long long time_point_type;

int main()
{
    age_type age;
    duration_type seconds;

    time_point_type start = 100;
    time_point_type end = 200;

    seconds = end - start;
    return 0;
}