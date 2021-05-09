#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <map>
#include <set>


struct Rule
{
    std::string line;
    bool reached = false;

    Rule(std::string &in_line)
    {
        line = in_line;
    }
};


int main()
{
    std::map<char, std::vector<Rule>> rules;
    
    char left;
    std::string right;
    while (std::cin >> left >> right) {
        auto it = rules.find(left);
        Rule rule(right);

        if (it != rules.end()) {
            it->second.push_back(rule);
        } else {
            rules.emplace(left, std::vector{rule});
        }
    }
 
    std::set<char> to_check{'S'};
    std::set<char> checked;

    while (to_check.size() != 0) {
        
        checked = to_check;
        to_check = {};

        for (auto &nonterminal : checked) {
            if (rules.find(nonterminal) != rules.end()) {
                for (auto it = rules[nonterminal].begin(); it != rules[nonterminal].end(); ++it) {
                    if (!it->reached) {
                        it->reached = true;
                        for (auto symbol = it->line.begin(); symbol != it->line.end(); ++symbol) { 
                            if (isupper((int)*symbol) && checked.find(*symbol) == checked.end()) {
                                to_check.insert(*symbol);
                            }
                        }
                    }
                }
            }
        }
    }

    for (auto &line : rules) {
        for (auto &rule : line.second) {
            if (rule.reached) {
                std::cout << line.first << ' ' << rule.line << std::endl;
            }
        }
    }

    return 0;
}
