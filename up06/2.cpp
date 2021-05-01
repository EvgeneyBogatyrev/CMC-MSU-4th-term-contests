#include <iostream>
#include <map>
#include <inttypes.h>

enum
{
    MODULE = 4294967161,
};


std::map<std::tuple<uint32_t, uint32_t>, uint64_t>
input_matrix(uint32_t &max_row, uint32_t &max_col)
{
    std::map<std::tuple<uint32_t, uint32_t>, uint64_t> matrix;

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

        data %= MODULE;

        std::tuple<uint32_t, uint32_t> key = {row, column};
        matrix[key] = data;

        if (row > max_row) {
            max_row = row;
        }

        if (column > max_col) {
            max_col = column;
        }
    }

    return matrix;
}


void
add(std::map<std::tuple<uint32_t, uint32_t>, uint64_t> &matrix_1,
        std::map<std::tuple<uint32_t, uint32_t>, uint64_t> &matrix_2)
{
    for (auto &[key, value] : matrix_2) {
        uint64_t result = (value + matrix_1[key]) % MODULE;
        matrix_1[key] = result;
    }

}

void print_matrix(std::map<std::tuple<uint32_t, uint32_t>, uint64_t> &matrix, uint32_t max_row, uint32_t max_col)
{
    for (uint32_t i = 0; i <= max_row; ++i) {
        for (uint32_t j = 0; j <= max_col; ++j) {
            std::tuple<uint32_t, uint32_t> key = {i, j};
            uint64_t value = matrix[key];

            if (value > 0) {
                std::cout << i << " " << j << " " << value << std::endl;
            }
        }
    }
}


int main()
{
    uint32_t max_col = 0, max_row = 0;
    auto matrix_1 = input_matrix(max_row, max_col);
    auto matrix_2 = input_matrix(max_row, max_col);
    
    add(matrix_1, matrix_2);

    print_matrix(matrix_1, max_row, max_col);

}
