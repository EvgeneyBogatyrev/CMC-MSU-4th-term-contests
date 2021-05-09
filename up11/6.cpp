#include <iostream>
#include <string>
#include <map>
#include <set>

struct Rule
{
    char state;
    char symbol;

    Rule(char in_state, char in_symbol)
    {
        state = in_state;
        symbol = in_symbol;
    }
};

bool operator == (const Rule &rule1, const Rule &rule2) 
{
    return (rule1.state == rule2.state) && (rule1.symbol == rule2.symbol);
}

bool operator < (const Rule &rule1, const Rule &rule2)
{
    return (rule1.state < rule2.state) || (rule1.state == rule2.state && rule1.symbol < rule2.symbol);
}

class Automate
{
    std::multimap<Rule, char> rules = {
        {Rule('H', '0'), 'A'},
        {Rule('H', '1'), 'A'},
        {Rule('H', '1'), 'B'},
        {Rule('A', '0'), 'A'},
        {Rule('A', '1'), 'A'},
        {Rule('A', '1'), 'B'},
        {Rule('B', '0'), 'C'},
        {Rule('B', '1'), 'C'},
        {Rule('C', '0'), 'S'},
        {Rule('C', '1'), 'S'}
    };

public:
    bool work(std::string &input)
    {
        bool error = false;
        std::set<char> states = {'H'};
        for (auto it = input.begin(); it < input.end(); ++it) {
            std::set<char> new_states = {};

            for (const char &state : states) {
                for (auto &rule : rules) {
                    Rule tmp(state, *it);
                    if (rule.first == tmp) {
                        new_states.insert(rule.second);
                    }
                }
            }
       
            if (new_states.size() == 0) {
                error = true;
                break;
            }

            states = new_states;
        }
        
        if (states.find('S') != states.end() && !error) {
            return true;
        }

        return false;
    }
};

int main()
{
    Automate automate;
    std::string input;
    while (std::cin >> input) {
        std::cout << automate.work(input) << std::endl;
    }
    return 0;
}
