class C
{

public:
    int a_;

    C(int a = 0, int b = 0)
    {
        a_ = a + b;
    }
            
    C(const C *other)
    {
        a_ = other->a_;
    }

    friend int operator+(int other, const C &ob)
    {
        return ob.a_ + other;
    }

    int operator~() const
    {
        return ~a_;
    }

    C operator++()
    {
        ++a_;
        return *this;
    }

    int operator*(C *other)
    {
        return a_ * other->a_;
    }
};
