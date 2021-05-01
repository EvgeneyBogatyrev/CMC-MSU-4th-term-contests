#include <iostream>
#include <cctype>
#include <algorithm>

class Info 
{
public:
    int nonterminal_count = 0;
    bool S_exists = false;
    bool eps_exists = false;
    int size = 0;
};

Info get_info(std::string& input) 
{
    Info info;
    info.size = input.size();
    for (auto &symbol : input) {
        if (isupper((int)symbol)) {
            ++info.nonterminal_count;
            if (symbol == 'S') {
                info.S_exists = true;
            }
        } else if (symbol == '_') {
            info.eps_exists = true;
        }
    }
    return info;
}

int main() 
{
    std::string l, r;

    bool was_S = false;
    bool was_S_in_right = false;
    bool S_to_eps = false;
    bool shortning = true;
    bool context_free = true;
    
    while (std::cin >> l && std::cin >> r) {
        Info left = get_info(l);
        Info right = get_info(r);

        if (left.nonterminal_count == 0 || left.eps_exists || (right.eps_exists && (right.size > 1))) {
            std::cout << "-1" << std::endl;
            return 0;
        }

        if (!was_S && l == "S") {
            was_S = true;
        }

        if (!was_S_in_right && right.S_exists) {
            was_S_in_right = true;
        }

        if (left.size > right.size || right.eps_exists) {
            if (l == "S" && r == "_") {
                S_to_eps = true;
            } else {
                shortning = false;
            }
        }
        
        if (context_free && left.size > 1) {
            context_free = false;
        }
    }

    if (S_to_eps && was_S_in_right) {
        shortning = false;
    }

    if (was_S) {
        if (context_free) {
            if (shortning) {
                std::cout << "23" << std::endl;
            } else {
                std::cout << "2" << std::endl;
            }
        } else {
            std::cout << "10" << std::endl;
        }
    } else {
        std::cout << "-1" << std::endl;
    }

    return 0;
}
