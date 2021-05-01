#include <vector>
#include <inttypes.h>


void process(std::vector<int64_t> &v, int64_t threshold)
{
    v.reserve(v.size() * 2);

    auto begin = v.begin();
    auto end = v.end();

    for (auto it = end - 1; it - begin >= 0; --it) { 
        if (*it >= threshold) {
            v.push_back(*it);
        }
    }

    v.shrink_to_fit();
}

