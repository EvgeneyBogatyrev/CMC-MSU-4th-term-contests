#include <functional>

template <typename T>
T myfilter(T object, std::function<bool(typename T::value_type)> f)
{
    T new_object{};
    for (const auto &elem : object) {
        if (f(elem)) {
            new_object.insert(new_object.end(), elem);
        }
    }

    return new_object;
}

