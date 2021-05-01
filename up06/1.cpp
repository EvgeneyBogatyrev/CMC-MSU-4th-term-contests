#include <iostream>
#include <inttypes.h>
#include <iomanip>

enum 
{
    BIT_NUM = 32,
    PRECISION = 10,
};

void read_bits(uint32_t data, uint32_t &likes, uint32_t &dislikes)
{
    for (int i = 0; i < BIT_NUM; ++i) {
        if (data & 1) {
            ++likes;
        } else {
            ++dislikes;
        }
        data >>= 1;
    }
}

double calculate_score(uint32_t likes, uint32_t all)
{
    return -1 + 2 * (double) likes / all; 
}

int main()
{
    uint32_t w1, w2;
    std::cin >> w1 >> w2;

    uint32_t likes = 0;
    uint32_t dislikes = 0;

    uint32_t data;
    while (std::cin >> data) {
        read_bits(data, likes, dislikes);
    }

    uint32_t all = likes + dislikes;

    double best, worst;

    if (dislikes > w1) {
        best = calculate_score(likes + w1, all);
    } else {
        best = 1;
    }


    if (likes > w2) {
        worst = calculate_score(likes - w2, all);
    } else {
        worst = -1;
    }

    std::cout << std::setprecision(PRECISION) << worst << " " << best << std::endl;

    return 0;
}
