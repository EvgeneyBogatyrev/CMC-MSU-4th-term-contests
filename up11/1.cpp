#include <iostream>
#include <cctype>

class Info
{
public:
    int nonterminal_count = 0;
    bool has_S = false;
    bool has_eps = false;
    int size = 0;
    char first_nonterminal = ' ';
    
};

Info get_info(std::string &input)
{
    Info info;
    info.size = input.size();
    for (auto &symbol : input) {
        if (isupper((int) symbol)) {
            ++info.nonterminal_count;
            if (info.nonterminal_count == 1) {
                info.first_nonterminal = symbol;
            }
            if (symbol == 'S') {
                info.has_S = true;
            }
        } else if (symbol == '_') {
            info.has_eps = true;
        }
    }
    return info;
}

int main() {
    std::string right;
    char left;

    bool was_S_in_right = false;
    bool S_to_eps = false;
    bool S_to_nonterminal = false;
    bool non_shortning = true;
    bool left_lin = true;
    bool right_lin = true;
    bool automate = true;
    
    while (std::cin >> left) {
        std::cin >> right;
        Info right_part = get_info(right);

        if (right_part.has_eps) {
            if (left == 'S' && right == "_") {
                S_to_eps = true;
            } else {
                non_shortning = false;
            }
        }

        if (right_part.has_S) {
            was_S_in_right = true;
        }

        if (left == 'S' && right_part.size == 1 && right_part.nonterminal_count == 1) {
            S_to_nonterminal = true;
        }

        if (right_part.nonterminal_count > 1) {
            // S -> AB - not automatic
            automate = false;
            left_lin = false;
            right_lin = false;

        } else if (right_part.nonterminal_count == 1) {
            if (right_part.first_nonterminal != right[0]) {
                left_lin = false;
            }
            if (right_part.first_nonterminal != right[right_part.size - 1]) {
                right_lin = false;
            }
            if (right_part.size >= 3) {
                automate = false;
            } else if (right_part.size == 1 && left != 'S') {
                automate = false;
            }
        } else if (right_part.nonterminal_count == 0){
            if (right_part.size > 1 || (left != 'S' && right_part.has_eps)) {
                automate = false;
            }
        }
    }

    if (S_to_eps && was_S_in_right) {
        non_shortning = false;
        automate = false;
    }

    if (!S_to_eps && S_to_nonterminal) {
        automate = false;
    }

    if (left_lin || right_lin) {
        if (automate) {
            if (left_lin) {
                std::cout << "311" << std::endl;
            } else {
                std::cout << "321" << std::endl;
            }
        } else {
            if (left_lin) {
                std::cout << "31" << std::endl;
            } else {
                std::cout << "32" << std::endl;
            }
        }
    } else {
        if (non_shortning) {
            std::cout << "21" << std::endl;
        } else {
            std::cout << "2" << std::endl;
        }
    }
}


