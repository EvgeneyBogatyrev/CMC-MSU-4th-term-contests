#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

enum { PRECISION = 10 };

class Sum
{
    int num{};
    double sum{};  
public:
    void operator() (double a) {
        sum += a;
        ++num;
    }

    void result() const {
        std::cout << std::setprecision(PRECISION) << sum / num << std::endl;
    }
};


int main()
{
    std::vector<double> data;
    double in;
    while (std::cin >> in) {
        data.push_back(in);
    }


    size_t skip = data.size() / 10;

    auto begin = data.begin() + skip;
    auto end = data.end() - skip;

    std::sort(begin, end, [](auto a, auto b) {return a < b;});

    skip = (end - begin) / 10;

    begin += skip;
    end -= skip;

    Sum s = std::for_each(begin, end, Sum());
    s.result();

    return 0;
}
