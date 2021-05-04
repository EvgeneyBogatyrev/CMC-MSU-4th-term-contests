#include <iostream>
#include <cctype>


bool check(bool &empty_word)
{
    char symbol;
    while (std::cin.get(symbol) && isspace((int)symbol)) {}
    if (std::cin.eof()) {
        empty_word = true;
        return false;
    }

    int zeros_n = 0;
    int ones_n = 0;

    while (symbol == '0') {
        ++zeros_n;
        if (!(std::cin.get(symbol))) {
            break;
        }
    }
    
    while (symbol == '1') {
        ++ones_n;
        if (!(std::cin.get(symbol))) {
            break;
        }
    }


    if (zeros_n == 0 || ones_n == 0) {
        while (!isspace((int)symbol) && std::cin.get(symbol)) {}
        return false;
    }

    if (isspace((int)symbol) || std::cin.eof()) {
        return true;
    }

    while (true) {
        int zeros_cur = zeros_n;
        int ones_cur = ones_n;

        while (symbol == '0') {
            --zeros_cur;
            if (!(std::cin.get(symbol))) {
                break;
            }
        }


        while (symbol == '1') {
            --ones_cur;
            if (!(std::cin.get(symbol))) {
                break;
            }
        }


        if (zeros_cur != 0 || ones_cur != 0) {
            while (!isspace((int)symbol) && std::cin.get(symbol)) {}
            return false;
        }

        if (isspace((int)symbol) || std::cin.eof()) {
            return true;
        }
    }

}

int main()
{
    bool empty_word = false;
    do {
        bool result = check(empty_word);
        if (empty_word) {
            empty_word = false;  
        } else {
            std::cout << result << std::endl;
        }
    } while (!(std::cin.eof()));

    return 0;
}
