#include <iostream>
#include <complex>
#include <array>
#include <vector>
#include <utility>

namespace Equations
{

    template <typename T>
    bool is_zero(std::complex<T> number)
    {
        if (std::norm<T>(number) < std::numeric_limits<T>::epsilon() * 32) {
            return true;
        }
        return false;
    }

    template <typename T>
    std::pair<bool, std::vector<std::complex<T>>> quadratic(std::array<std::complex<T>, 3> input)
    {
        std::complex<T> a = input[2];
        std::complex<T> b = input[1];
        std::complex<T> c = input[0];

        if (is_zero(a) && is_zero(b) && is_zero(c)) {
            std::vector<std::complex<T>> res = {};
            std::pair<bool, std::vector<std::complex<T>>> return_value = {false, res};
            return return_value;
        }

        if (is_zero(a) && is_zero(b) && !is_zero(c)) { 
            std::vector<std::complex<T>> res = {};
            std::pair<bool, std::vector<std::complex<T>>> return_value = {true, res};
            return return_value;
        }

        if (is_zero(a) && !is_zero(b)) {
            std::vector<std::complex<T>> res = {-c / b};
            std::pair<bool, std::vector<std::complex<T>>> return_value = {true, res}; 
            return return_value;
        }

        std::complex<T> k1 = std::complex<T>(4, 0);
        std::complex<T> k2 = std::complex<T>(2, 0);
        std::complex<T> D = b * b - k1 * a * c;
        std::vector<std::complex<T>> res = {(-b + std::sqrt(D)) / (k2 * a), (-b - std::sqrt(D)) / (k2 * a)};
        std::pair<bool, std::vector<std::complex<T>>> return_value = {true, res};  
        return return_value;

    }

};

