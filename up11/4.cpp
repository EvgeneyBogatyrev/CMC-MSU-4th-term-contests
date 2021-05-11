#include <iostream>
#include <stack>
#include <string>
#include <cctype>

int priority(char);

struct Container
{
    std::string value;
    bool has_oper = false;
    int oper_priority;

    Container(std::string &v, bool has = false, char oper = ' ')
    {
        value = v;
        has_oper = has;
        if (has_oper) {
            oper_priority = priority(oper);
        }
    }

    Container(char s = ' ')
    {
        value = "";
        value += s;
    }
};


int priority(char s)
{
    if (s == '|') {
        return 0;
    }
    if (s == '^') {
        return 1;
    }
    if (s == '&') {
        return 2;
    }
    if (s == '+' || s == '-') {
        return 3;
    }
    if (s == '*' || s == '/') {
        return 4;
    }
    return -1;
}

std::string to_postfix(std::string line)
{
    std::stack<char> oper;

    std::string out = "";

    for (auto s = line.begin(); s != line.end(); ++s) {
        if (isspace((int) *s)) {
            continue;
        } else if (islower((int)*s)) {
            out += *s;
        } else if (*s == '(') {
            oper.push(*s);
        } else if (*s == ')') {
            while (oper.top() != '(') {
                out += oper.top();
                oper.pop();
            }
            oper.pop();
        } else {
            while (!oper.empty() && priority(oper.top()) >= priority(*s)) {
                out += oper.top();
                oper.pop();
            }
            oper.push(*s);
        }
    }

    while (!oper.empty()) {
        out += oper.top();
        oper.pop();
    }

    return out;
}

std::string to_infix(std::string line)
{
    std::stack<Container> stack;
    for (auto s = line.begin(); s != line.end(); ++s) {
        if (isspace((int) *s)) {
            continue;
        } else if (islower((int) *s)) {
            stack.push(Container(*s));
        } else {
            Container c1, c2;
            c2 = stack.top();
            stack.pop();
            c1 = stack.top();
            stack.pop();

            std::string first, second;
            if (c1.has_oper && c1.oper_priority < priority(*s)) {
                first = "(" + c1.value + ")";
            } else {
                first = c1.value;
            }
            
            if (c2.has_oper && c2.oper_priority <= priority(*s)) {
                second = "(" + c2.value + ")";
            } else {
                second = c2.value;
            }
            std::string res = first + *s + second;
            stack.push(Container(res, true, *s));
        }
    }

    if (!stack.empty()) {
        return stack.top().value;
    }
    return "";
}

int main()
{
    std::string line;
    std::cin >> line;
    std::string postfix = to_postfix(line);
    std::string infix = to_infix(postfix);
    std::cout << infix << std::endl;
    return 0;
}
