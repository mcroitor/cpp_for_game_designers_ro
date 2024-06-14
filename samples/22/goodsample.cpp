#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <iterator>

using vector = std::vector<int>;

int main()
{
    vector v;
    vector filtered;

    std::ifstream fin("oops.txt");

    std::copy(std::istream_iterator<int>(fin), std::istream_iterator<int>(), std::inserter(v, v.end()));

    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));
    std::cout << std::endl;

    std::copy_if(v.begin(), v.end(), std::inserter(filtered, filtered.end()), [](int el)
                 { return el % 2 == 1; });

    std::copy(filtered.begin(), filtered.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
