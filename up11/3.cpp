#include <iostream>
#include <string>
#include <map>
#include <set>

struct State {
    std::string state;
    char symbol;

    State(const std::string& s, char sym)
    {
        state = s;
        symbol = sym;
    }
};


// For .find() method
bool operator < (State s1, State s2)
{
    return ((s1.state < s2.state) || (s1.state == s2.state && s1.symbol < s2.symbol));
}

struct Container
{
    int data;
    int count;
    std::string state;

    Container(int d, int c, std::string s) 
    {
        data = d;
        count = c;
        state = s;
    }

    void print()
    {
        std::cout << data << std::endl;
        std::cout << count << std::endl;
        std::cout << state << std::endl;
    }
};


class Automate 
{
    const std::map<State, std::string> rules;
    const std::set<std::string> terminals;
    std::string state;

public:
    Automate(std::map<State, std::string> &&in_rules, std::string &in_start, std::set<std::string> &&in_terminals) :
        rules{in_rules}, terminals{in_terminals}
    {
        state = in_start;
    }

    Container work(std::string input)
    {   
        auto cur = input.begin();
        auto last = input.end();
        auto end = rules.end();
        
        int count = 0;

        while (cur != last) {
            auto it = rules.find(State(state, *cur));
            if (it == end) {
                break;
            }
            state = it->second;
            ++count;
            ++cur;
        }

        if (cur == last && terminals.find(state) != terminals.end()) {
            return Container(1, count, state);
        }
    
        return Container(0, count, state);
    }
};

int main() 
{
    std::map<State, std::string> rules;
    const std::string end = "END";

    while (true) {
        std::string line;
        std::cin >> line;
        if (line == end) {
            break;
        }
        char symbol;
        std::cin >> symbol;
        std::string next;
        std::cin >> next;
        rules.emplace(State(line, symbol), next);
    }    

    std::set<std::string> terminals;
    while (true) {
        std::string line;
        std::cin >> line;
        if (line == end) {
            break;
        }
        terminals.emplace(line);
    }
    
    std::string start;
    std::cin >> start;

    Automate automate(std::move(rules), start, std::move(terminals));
    
    std::string input;
    std::cin >> input;

    Container res = automate.work(input);
    res.print();

    return 0;
}
