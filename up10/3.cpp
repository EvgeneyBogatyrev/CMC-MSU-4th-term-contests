#include <iostream>
#include <cctype>

/*
Язык типа 1
L = {(a)^k (0)^m (b)^k (1)^m, k > 0, m > 0}
*/

bool check(bool &empty_word)
{
    char symbol;
    while (std::cin.get(symbol) && isspace((int)symbol)) {}
    if (std::cin.eof()) {
        empty_word = true;
        return false;
    }
    

    int a_count = 0;
    while (symbol == 'a') {
        ++a_count;
        if (!std::cin.get(symbol)) {
            break;
        }
    }

    if (a_count < 1) {
        while (!isspace((int)symbol) && std::cin.get(symbol));
        return false;
    }

    int zero_count = 0;
    while (symbol == '0') {
        ++zero_count;
        if (!std::cin.get(symbol)) {
            break;
        }
    }

    if (zero_count < 1) {
        while (!isspace((int)symbol) && std::cin.get(symbol));
        return false;
    }

    int b_count = 0;
    while (symbol == 'b') {
        ++b_count;
        if (!std::cin.get(symbol)) {
            break;
        }
    }

    if (b_count != a_count) {
        while (!isspace((int)symbol) && std::cin.get(symbol));
        return false;
    }

    int one_count = 0;
    while (symbol == '1') {
        ++one_count;
        if (!std::cin.get(symbol)) {
            break;
        }
    }

    if (one_count != zero_count) {
        while (!isspace((int)symbol) && std::cin.get(symbol));
        return false;       
    }

    if (isspace((int)symbol) || std::cin.eof()) {
        return true;        
    }

    while (!isspace((int)symbol) && std::cin.get(symbol));
    return false;

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
    } while (!std::cin.eof());
}
