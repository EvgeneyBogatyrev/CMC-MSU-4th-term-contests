#include <vector>
#include <inttypes.h>

void process(const std::vector<uint64_t> &v1, std::vector<uint64_t> &v2, int step) 
{
    auto cur_v2 = v2.end() - 1;
    auto begin_v2 = v2.begin();

    for (auto it = v1.begin(); it < v1.end(); it += step) {
        if (cur_v2 - begin_v2 < 0) {
            break;
        }

        *cur_v2 += *it;
        --cur_v2;
    }
}
