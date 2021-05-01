#include <iostream>
#include <array>
#include <vector>

enum
{
    x = 0,
    y = 1,
    z = 2,
};

class Cube
{
    std::array<std::array<std::array<bool, 5>, 5>, 5> map = {};
    std::vector<int> dir = {0, 0, 1};
    std::vector<int> pos = {1, 2, 2};
    int visited = 1;
    bool stopped = false;
    char side = 'F';
public:
    Cube()
    {
        map[1][2][2] = true;
    }

    void move(bool main = false)
    {
        for (int i = 0; i < 3; ++i) {
            pos[i] += dir[i];
        }

        if (main) {
            correct_position();
        }
        if (!map[pos[x]][pos[y]][pos[z]]) {
            visited++;
        }
        map[pos[x]][pos[y]][pos[z]] = true;
    }


    void apply_rotation(int coord1, int coord2, char where, int axis_direction)
    {
        // coord1 > coord2 !!!
        std::vector<int> new_dir = dir;

        int mult = 1;
        if (where == 'R') {
            mult = 1;
        } else if (where == 'L'){
            mult = -1;
        }
    
        new_dir[coord1] = -dir[coord2] * axis_direction * mult;
        new_dir[coord2] = dir[coord1] * axis_direction * mult;

        dir = new_dir;
    }

    void rotate(char where)
    {
        if (side == 'F' || side == 'B') {
            apply_rotation(y, z, where, get_axis_direction(pos[x]));
        } else if (side == 'L' || side == 'R') {
            apply_rotation(z, x, where, get_axis_direction(pos[y]));
        } else if (side == 'U' || side == 'D') {
            apply_rotation(x, y, where, get_axis_direction(pos[z]));
        }
    }

    void round(int coord) 
    {
        if (pos[coord] == 0) {
            pos[coord] = 1;
        } else if (pos[coord] == 4) {
            pos[coord] = 3;
        }
    }

    void correct_position()
    {
        if (pos[x] == 1 && (pos[y] == 0 || pos[y] == 4) && side == 'F') {
            round(y);
            dir = {1, 0, 0};

            if (pos[y] == 1) {
                side = 'L';
            } else {
                side = 'R';
            }

        } else if (pos[x] == 1 && (pos[z] == 0 || pos[z] == 4) && side == 'F') {
            round(z);
            dir = {1, 0, 0};

            if (pos[z] == 1) {
                side = 'D';
            } else {
                side = 'U';
            }

        } else if (pos[x] == 3 && (pos[y] == 0 || pos[y] == 4) && side == 'B') {
            round(y);
            dir = {-1, 0, 0};

            if (pos[y] == 1) {
                side = 'L';
            } else {
                side = 'R';
            }

        } else if (pos[x] == 3 && (pos[z] == 0 || pos[z] == 4) && side == 'B') {
            round(z);
            dir = {-1, 0, 0};

            if (pos[z] == 1) {
                side = 'D';
            } else {
                side = 'U';
            }

        } else if (pos[y] == 1 && (pos[z] == 0 || pos[z] == 4) && side == 'L') {
            round(z);
            dir = {0, 1, 0};

            if (pos[z] == 1) {
                side = 'D';
            } else {
                side = 'U';
            }

        } else if (pos[y] == 1 && (pos[x] == 0 || pos[x] == 4) && side == 'L') {
            round(x);
            dir = {0, 1, 0};

            if (pos[x] == 1) {
                side = 'F';
            } else {
                side = 'B';
            }

        } else if (pos[y] == 3 && (pos[z] == 0 || pos[z] == 4) && side == 'R') {
            round(z);
            dir = {0, -1, 0};

            if (pos[z] == 1) {
                side = 'D';
            } else {
                side = 'U';
            }

        } else if (pos[y] == 3 && (pos[x] == 0 || pos[x] == 4) && side == 'R') {
            round(x);
            dir = {0, -1, 0};

            if (pos[x] == 1) {
                side = 'F';
            } else {
                side = 'B';
            }

        } else if (pos[z] == 1 && (pos[x] == 0 || pos[x] == 4) && side == 'D') {
            round(x);
            dir = {0, 0, 1};

            if (pos[x] == 1) {
                side = 'F';
            } else {
                side = 'B';
            }

        } else if (pos[z] == 1 && (pos[y] == 0 || pos[y] == 4) && side == 'D') {
            round(y);
            dir = {0, 0, 1};

            if (pos[y] == 1) {
                side = 'L';
            } else {
                side = 'R';
            }

        } else if (pos[z] == 3 && (pos[x] == 0 || pos[x] == 4) && side == 'U') {
            round(x);
            dir = {0, 0, -1};

            if (pos[x] == 1) {
                side = 'F';
            } else {
                side = 'B';
            }

        } else if (pos[z] == 3 && (pos[y] == 0 || pos[y] == 4) && side == 'U') {
            round(y);
            dir = {0, 0, -1};

            if (pos[y] == 1) {
                side = 'L';
            } else {
                side = 'R';
            }
        }        
    }

    int get_axis_direction(int coord)
    {
        if (coord == 1) {
            return -1;
        }
        return 1;
    }

    bool operator! ()
    {
        return !stopped;
    }

    void act(char action) {
        if (action == 'F') {
            move(true);
        } else if (action == 'L' || action == 'R') {
            rotate(action);
        } else if (action == 'S') {
            stopped = true;
        }
    }

    void print()
    {
        std::cout << visited << std::endl;
    }

};


int main()
{
    Cube cube;
    while (!cube) {
        char action;
        std::cin.get(action);
        cube.act(action);
    }

    cube.print();
}
