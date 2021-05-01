
namespace numbers
{
    class complex_stack
    {
        complex *stack_;
        size_t size_{};

    public:
        complex_stack() : size_{0}
        {
            stack_ = new complex[size_];
        }

        complex_stack(const complex_stack &other, bool cut = false) : size_{other.size_}
        {
            int add = 0;
            
            if (cut) {
                add = 1;
                size_ -= 1;
            }

            stack_ = new complex[size_];
            for (size_t i = 0; i < size_; ++i) {
                stack_[i] = other.stack_[i + add];
            }
        }

        complex_stack(const complex_stack &other, complex new_elem) : size_{other.size_ + 1}
        {
            stack_ = new complex[size_];
            stack_[0] = new_elem;
            for (size_t i = 1; i < size_; ++i) {
                stack_[i] = other.stack_[i - 1];
            }
        }

        void swap(complex_stack other) noexcept
        {
            std::swap(stack_, other.stack_);
            std::swap(size_, other.size_);
        }

        complex_stack &operator=(const complex_stack &other)
        {
            swap(other);
            return *this;
        }
        
        ~complex_stack()
        {
            delete[] stack_;
        }

        size_t size() const noexcept
        {
            return size_;
        }

        complex operator[](size_t  index) const noexcept
        {
            return stack_[size_ - index - 1];            
        }

        complex operator+() const noexcept
        {
            return stack_[0];
        }

        complex_stack operator~() const noexcept
        {
            complex_stack new_stack(*this, true);
            return new_stack;
        }
    };

    inline complex_stack operator<<(complex_stack stack, complex z)
    {
        complex_stack new_stack(stack, z);
        return new_stack;
    }

}

