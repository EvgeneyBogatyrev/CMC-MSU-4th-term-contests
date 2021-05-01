#include <iostream>
#include <algorithm>

template <typename T>
struct Coord
{
    using value_type = T;
    value_type row;
    value_type col;
    Coord<T>(value_type r = {}, value_type c = {}) : row(r), col(c) {}
};

template <typename T>
T dist(Coord<T> board_size, Coord<T> cell1, Coord<T> cell2)
{
    T x_distance = std::min(std::max(cell1.row, cell2.row) - std::min(cell1.row, cell2.row), 
            board_size.row - std::max(cell1.row, cell2.row) + std::min(cell1.row, cell2.row));

    T y_distance = std::min(std::max(cell1.col, cell2.col) - std::min(cell1.col, cell2.col), 
            board_size.col - std::max(cell1.col, cell2.col) + std::min(cell1.col, cell2.col));

    return std::max(x_distance, y_distance);

}

