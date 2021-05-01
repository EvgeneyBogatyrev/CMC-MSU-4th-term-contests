#include <functional>
#include <iterator>

template<typename ITER1, typename ITER2>
typename std::iterator_traits<ITER1>::value_type 
scalar_mul(ITER1 Ibeg, ITER1 Iend, ITER2 I2, 
        typename std::iterator_traits<ITER1>::value_type Init = {},
        std::function<typename std::iterator_traits<ITER1>::value_type 
            (typename std::iterator_traits<ITER1>::value_type, typename std::iterator_traits<ITER2>::value_type)> 
            MulF = [] (typename std::iterator_traits<ITER1>::value_type a, 
                typename std::iterator_traits<ITER2>::value_type b) 
            {
                return a * b;
            },
        std::function<typename std::iterator_traits<ITER1>::value_type 
            (typename std::iterator_traits<ITER1>::value_type, typename std::iterator_traits<ITER2>::value_type)> 
            AddF = [] (typename std::iterator_traits<ITER1>::value_type a, 
                typename std::iterator_traits<ITER2>::value_type b)
            {
                return a + b;
            }
        )
{
    auto other = I2;
    typename std::iterator_traits<ITER1>::value_type sum = Init;

    for (auto it = Ibeg; it != Iend; ++it) {
        auto factor = MulF(*it, *other);
        sum = AddF(sum, factor);
        ++other;
    }

    return sum;
}
