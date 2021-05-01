#include <iostream>
#include <string>

enum
{
    ONE_CODE = '1',
    NINE_CODE = '9'
};

int main()
{
    int real_liter;
    bool is_zero = false;
    bool start = true;

    std::string output = "";

    while ((real_liter = std::cin.get()) != EOF) {
        unsigned char liter = (unsigned char) real_liter;
        if (liter == '0') {
            if (start) {
                is_zero = true;
            } else {
                output += liter;
            }
        } else if (ONE_CODE <= liter && liter <= NINE_CODE) {
            output += liter;
            is_zero = false;
            start = false;
        } else {
            if (is_zero) {
                output += '0';
            }

            output += liter;
            is_zero = false;
            start = true;
        }
    }

    if (is_zero) {
        output += '0';
    }

    std::cout << output;
    return 0;
}
