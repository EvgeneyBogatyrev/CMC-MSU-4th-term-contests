#include <algorithm>

template <typename ITER1, typename ITER2>
ITER2 myremove(ITER1 b_indices, ITER1 e_indices, ITER2 b_data, ITER2 e_data)
{
    ITER2 result = b_data;

    auto it = b_data;
    for (int idx = 0; it != e_data; ++it, ++idx) {
        bool remove = false;
        for (auto ind_it = b_indices; ind_it != e_indices; ++ind_it) {
            if (*ind_it == idx) {
                remove = true;
                break;
            }
        }

        if (!remove) {
            std::swap(*result, *it);
            ++result;
        }
    }

    return result;
}

