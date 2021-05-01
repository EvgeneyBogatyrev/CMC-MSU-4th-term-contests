#include <iostream>
#include <limits.h>

// Функция представляет из себя hyperoperation function

class Result
{
    int64_t value_;
public:
    Result(int64_t value = 0) : value_(value) {}
    int64_t value() const
    {
        return value_;
    }
    void set_value(int64_t value)
    {
        value_ = value;
    }
};

void func(int64_t a, int64_t b, uint32_t k)
{
    if (k == 0) {
        throw Result{a + b};
    }

    if (k > 0 && b == 1) {
        throw Result{a};
    }

    Result second_param;
    try {
        func(a, b - 1, k);
    } catch (const Result &result) {
        second_param.set_value(result.value());
    }

    try {
        func(a, second_param.value(), k - 1);
    } catch (const Result &result) {
        throw;
    } 

}

int main()
{
    uint64_t a, b;
    uint32_t k;

    while (std::cin >> a) {
        std::cin >> b >> k;
        try {
            func(a, b, k);
        } catch (const Result &result) {
            std::cout << result.value() << std::endl;
        }
    }
}
