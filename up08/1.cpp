#include <iostream>
#include <algorithm>
#include <cmath>


int main()
{
    int width, height;
    std::cin >> width >> height;

    while (true) {
        int x1, y1, x2, y2;

        if (!(std::cin >> x1)) {
            break;
        }

        std::cin >> y1 >> x2 >> y2;

        int x_distance = std::min(abs(x1 - x2), width - std::max(x1, x2) + std::min(x1, x2));
        int y_distance = std::min(abs(y1 - y2), height - std::max(y1, y2) + std::min(y1, y2));

        std::cout << x_distance + y_distance << std::endl;
    }
}
