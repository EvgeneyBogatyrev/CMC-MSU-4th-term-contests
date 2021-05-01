#include <iostream>
#include <math.h>
#include <vector>
#include <string>

#include "cmc_complex.h"
#include "cmc_complex_stack.h"
#include "cmc_complex_eval.h"


enum { BASE = 10 };

int main(int argc, char *argv[])
{
    numbers::complex center(argv[1]);
    double R = strtod(argv[2], NULL);
    int N = strtol(argv[3], NULL, BASE);

    std::vector<std::string> args;

    for (int i = 4; i < argc; ++i) {
        args.push_back(argv[i]);
    }

    numbers::complex result = 0;
    for (int i = 0; i < N; ++i) {
        numbers::complex point = center;
        double angle = 2 * M_PI * i / N;
        point += numbers::complex(R * cos(angle), R * sin(angle));
        numbers::complex point_value = numbers::eval(args, point);

        double next_angle = 2 * M_PI * (i + 1) / N;
        numbers::complex distance = numbers::complex(R * cos(next_angle), R * sin(next_angle)) 
            - (point - center);

        result += point_value * distance; 
    }

    std::cout << result.to_string() << std::endl;
    return 0;
}
