#include <iostream>
#include <string>

class PrintReverse
{
    std::string string_;
public:
    PrintReverse(const std::string &string) : string_(string) {}
    ~PrintReverse() 
    {
        std::cout << string_ << std::endl;
    }
};

void print()
{
    std::string line;
    try {
        if (std::cin >> line) {
            PrintReverse tmp{line};
            print();
        } else {
            throw int{};
        }
    } catch (int) {
        throw;
    }
}

int main()
{
    try {
        print();
    } catch (int) {
    }
    return 0;
}
