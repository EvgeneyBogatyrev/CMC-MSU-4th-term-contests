#include <functional>
#include <iterator>


template <typename iterT, typename Func>
void myapply(iterT begin, iterT end, Func f)
{
    for (auto it = begin; it != end; ++it) {
        f(*it);
    }
}

template <typename iterT, typename Func>
std::vector<std::reference_wrapper<typename std::iterator_traits<iterT>::value_type>> 
myfilter2(iterT begin, iterT end, Func f)
{
    std::vector<std::reference_wrapper<typename std::iterator_traits<iterT>::value_type>> v{};

    for (auto it = begin; it != end; ++it) {
        if (f(*it)) {
            v.insert(v.end(), std::reference_wrapper<typename std::iterator_traits<iterT>::value_type>(*it));
        }
    }

    return v;
}

