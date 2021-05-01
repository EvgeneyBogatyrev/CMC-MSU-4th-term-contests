class Sum
{
public:
    Sum(int a, int b) noexcept : a_{a}, b_{b} {}
    Sum(Sum s, int c) noexcept : b_{c}
    {
        a_ = s.get();
    }
    int get() const noexcept { return a_ + b_; }
private:
    int a_{};
    int b_{};
};
