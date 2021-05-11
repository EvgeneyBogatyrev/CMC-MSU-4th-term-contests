#include <iostream>
#include <stack>
#include <string>
#include <cctype>


int main()
{
    std::stack<std::string> stack;
    char sym;
    while ((sym = std::cin.get()) != EOF) {
        if (isspace((int)sym)) {
            continue;
        }
        else if (islower((int)sym)) {
            stack.push(std::string{sym});
        } else if (sym == '+' || sym == '-' || sym == '*' || sym == '/') {
            std::string s2 = stack.top();
            stack.pop();
            std::string s1 = stack.top();
            stack.pop();

            stack.push("(" + s1 + sym + s2 + ")");
        }
    }

    std::cout << stack.top() << std::endl;
    stack.pop();

    return 0;
}
