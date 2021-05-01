#include <iostream>

class S
{
    int num_{};
    bool should_print_ = false;
public:
    S()
    {
        should_print_ = bool(std::cin >> num_);
    }

    S(S &&other)
    {
        num_ = other.num_;
        
        int num;
        if (std::cin >> num) {
            should_print_ = true;
            other.should_print_ = false;
            num_ += num;
        }
    }

    ~S()
    {
        if (should_print_) {
            std::cout << num_ << std::endl;
        }
    }

    operator bool()
    {
        return should_print_;
    }
};
