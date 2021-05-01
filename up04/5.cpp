#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <inttypes.h>

struct Position
{
    int x{};
    int y{};
};

class Map
{
    std::vector<std::vector<uint32_t>> matrix{};
public:
    void add_line(std::vector<uint32_t> line) noexcept {
        matrix.push_back(line);
    }

    void print(void) const noexcept {
        for (auto it_line = matrix.begin(); it_line - matrix.end() < 0; ++it_line) {
            for (auto it = it_line->begin(); it - it_line->end() < 0; ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        }
    }

    Position find_max(void) const noexcept {
        uint32_t max_value = 0;
        Position pos{};
        for (auto it_line = matrix.begin(); it_line - matrix.end() < 0; ++it_line) {
            for (auto it = it_line->begin(); it - it_line->end() < 0; ++it) {
                if (*it > max_value) {
                    max_value = *it;
                    pos.y = it - it_line->begin();
                    pos.x = it_line - matrix.begin();
                }
            }
        }
        return pos;
    }

    void apply(uint32_t value) noexcept {
        Position max_pos = find_max();

        for (int x = -1; x <= 1; ++x) {
            for (int y = -1; y <= 1; ++y) {
                Position cur_pos = max_pos;
                cur_pos.x += x;
                cur_pos.y += y;

                if (!valid_index(cur_pos)) {
                    continue;
                } 

                uint32_t cur_value = value;
                if (x != 0 || y != 0) {
                    if (x * y == 0) {
                        cur_value /= 2;
                    } else {
                        cur_value /= 4;
                    }
                }

                modify(cur_pos, cur_value);
            }
        }
    }

    bool valid_index(Position pos) const noexcept {
        if ((size_t) pos.x >= matrix.size()) {
            return false;
        }

        auto it = matrix.begin() + pos.x;
        
        if ((size_t) pos.y >= it->size()) {
            return false;
        }
        return true;
    }

    void modify(Position pos, uint32_t value) noexcept {
        auto it = matrix.begin() + pos.x;
        
        auto it_line = it->begin() + pos.y;

        if (*it_line >= value) {
            *it_line -= value;
        } else {
            *it_line = 0;
        }
    }
    
};

int main()
{
    Map map;

    std::string str;
    while (true) {
        std::getline(std::cin, str);
        if (str.length() == 0) {
            break;
        }
        std::vector<uint32_t> line{};

        std::stringstream stream;
        stream << str;

        uint32_t num;
        while (stream >> num) {
            line.push_back(num);
        }

        map.add_line(line);
    }

    uint32_t value;
    while (std::cin >> value) {
        map.apply(value);
    }
    
    map.print();
    return 0;
}
