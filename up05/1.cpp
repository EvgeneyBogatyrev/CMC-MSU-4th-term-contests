#include <iterator>

enum 
{
    ITER = 3
};

template <typename T>
typename T::value_type process(T container)
{
    typename T::value_type sum{};

    if (container.size() == 0) {
        return sum;
    }
    
    int iter_count = 0;
    for (auto it = container.rbegin(); it != container.rend() && iter_count < 2 * ITER; ++it) {
        ++iter_count;
        if (iter_count % 2 == 0) {
            continue;
        }

        if (iter_count == 0) {
            sum = *it;
        } else {
            sum += *it;
        }
    }

    return sum;
}

