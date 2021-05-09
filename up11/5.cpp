#include <iostream>
#include <vector>
#include <string>
#include <cctype>

struct Container
{
    std::string data;

    Container(char s)
    {
        data = "";
        data += s;
    }

    Container(Container &c1, char oper, Container &c2)
    {
        data = "(";
        data += c1.data;
        data += oper;
        data += c2.data;
        data += ")";
    }
};


int main()
{
    std::vector<Container> stack;
    char sym;
    while (std::cin.get(sym)) {
        if (isspace((int)sym)) {
            continue;
        }
        else if (islower((int)sym)) {
            stack.push_back(Container(sym));
        } else {
            Container &c2 = stack.back();
            stack.pop_back();
            Container &c1 = stack.back();
            stack.pop_back();

            stack.push_back(Container(c1, sym, c2));
        }
    }

    std::cout << stack.back().data << std::endl;

    return 0;
}
