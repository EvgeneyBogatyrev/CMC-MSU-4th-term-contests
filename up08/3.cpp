#include <iostream>
#include <algorithm>

namespace Game
{
    template <typename T>
    class Coord
    {
    public:
        using value_type = T;
        T row;
        T col;
        Coord<T>(T r = {}, T c = {}) : row(r), col(c) {}
    };

    template <typename T>
    T abs(T value)
    {
        if (value > 0) {
            return value;
        }
        return -value;
    }

    template <typename T>
    T dist(Coord<T> board_size, Coord<T> cell1, Coord<T> cell2)
    {
        T col_dist = abs(cell1.col -  cell2.col);
       
        T upper_row_bound, lower_row_bound;

        if (cell1.col % 2 == 0) {
            lower_row_bound = cell1.row - col_dist / 2;
            upper_row_bound = cell1.row + (col_dist - col_dist / 2);
        } else {
            upper_row_bound = cell1.row + col_dist / 2;
            lower_row_bound = cell1.row - (col_dist - col_dist / 2);
        }

        if (lower_row_bound < 0) {
            lower_row_bound = 0;
        }
        upper_row_bound = std::min(upper_row_bound, board_size.row - 1);

        if (cell2.row >= lower_row_bound && cell2.row <= upper_row_bound) {
            return col_dist;
        }

        return col_dist + std::min(abs(lower_row_bound - cell2.row),
                abs(upper_row_bound - cell2.row));
    }
}
