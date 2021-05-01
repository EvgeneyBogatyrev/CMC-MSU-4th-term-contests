#include <iostream>
#include <string>


int main()
{
    std::string input;
    while (std::cin >> input) {
        auto it = input.begin();
        auto end = input.end();
        
        while (it != end && (*it == '3' || *it == '4')) {
            ++it;
        }

        while (it != end && (*it == '1' || *it == '2')) {
            ++it;
        }

        if (it == end) {
            std::cout << 1 << std::endl;
        } else {
            std::cout << 0 << std::endl;
        }
    }
}
