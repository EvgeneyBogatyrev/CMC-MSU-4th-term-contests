#include <iostream>

class A
{
public:
    A() noexcept
    {
        std::cin >> a_;
        sum_ = false;
    }

    A(A &other) noexcept
    {
        std::cin >> a_;
        a_ += other.a();
        sum_ = true;
    }

    ~A() noexcept
    {
        if (sum_)
        {
            std::cout << a_ << std::endl;
        }
    }

    int a() const { return a_; }

private:
    int a_{};
    bool sum_{};
};

