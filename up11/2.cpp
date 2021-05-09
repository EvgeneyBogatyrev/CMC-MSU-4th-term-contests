#include <iostream>
#include <string>
#include <list>
#include <cctype>

struct Symbol
{
    char symbol;
    bool reached = false;

    Symbol(std::string in)
    {
        symbol = in[0];
    }

    Symbol() {}
};

bool operator < (Symbol s1, Symbol s2)
{
    return s1.symbol < s2.symbol;
}

struct Rule
{
    Symbol symbol;
    std::string line;
    bool observed = false;
    int order;
    
    Rule(Symbol &in_symbol, std::string &in_line, int current_order)
    {
        symbol = in_symbol;
        line = in_line;
        order = current_order;
    }

    void print()
    {
        std::cout << symbol.symbol << " " << line << std::endl;
    }
};

bool operator < (Rule &r1, Rule &r2)
{
    return r1.order < r2.order;
}

int main()
{
    std::list<Rule> rules;

    int current_order = 0;
    while (!std::cin.eof()) {
        std::string left, right;
        std::cin >> left >> right;

        Symbol symbol(left);
        if (symbol.symbol == 'S') {
            symbol.reached = true;
        }
        
        Rule new_rule(symbol, right, current_order++);

        rules.push_back(new_rule);


    }

    for (auto it = rules.begin(); it != rules.end(); ++it) {
        if (it->symbol.reached) {
            for (auto sym = it->line.begin(); sym != it->line.end(); ++sym) {
                if (isupper((int) *sym)) {
                    for (auto it2 = it; it2 != rules.end(); ++it2) {
                        if (it2->symbol.symbol == *sym) {
                            it2->symbol.reached = true;
                        }
                    }
                }
            }
        } else if (!it->observed){
            it->observed = true;
            auto move_it = it;
            --it;
            rules.splice(rules.end(), rules, move_it);   
        }
    }

    rules.sort();

    for (auto it = rules.begin(); it != rules.end(); ++it) {
        if (it->symbol.reached) {
            it->print();
        }
    }

    return 0;
}
