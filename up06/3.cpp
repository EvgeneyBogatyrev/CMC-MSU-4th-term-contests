#include <iostream>
#include <map>
#include <tuple>
#include <inttypes.h>

enum
{
    MODULE = 4294967161,
};

void print_matrix(std::map<std::tuple<uint32_t, uint32_t>, uint64_t> &m);


std::map<uint32_t, std::map<uint32_t, uint64_t>>
input_matrix()
{
    std::map<uint32_t, std::map<uint32_t, uint64_t>> matrix;

    uint32_t row, column;
    uint64_t data;

    while (true) {
        if (!(std::cin >> row)) {
            break;
        }

        std::cin >> column >> data;

        if (row == 0 && column == 0 && data == MODULE) {
            break;
        }

        matrix[column][row] = data;
    }

    return matrix;
}


void multiply(std::map<uint32_t, std::map<uint32_t, uint64_t>> &matrix)
{
    uint32_t row, column;
    uint64_t data;

    std::map<std::tuple<uint32_t, uint32_t>, uint64_t> result;
    while (std::cin >> row) {
        std::cin >> column >> data;
        data %= MODULE;
        for (auto &elem : matrix[row]) {
            std::tuple key = {elem.first, column};
            result[key] = (result[key] + (elem.second * data) % MODULE) % MODULE;
        }
    }

    print_matrix(result);
}


void print_matrix(std::map<std::tuple<uint32_t, uint32_t>, uint64_t> &matrix)
{
    for (auto &elem : matrix) {
        if (elem.second > 0) {
            std::cout << std::get<0>(elem.first) << " " << std::get<1>(elem.first) << " " << elem.second << std::endl;
        }
    }
}


int main()
{
    auto matrix_1 = input_matrix();
    multiply(matrix_1);
}
