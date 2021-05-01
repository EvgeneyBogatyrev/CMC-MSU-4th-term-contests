#include <iostream>
#include <iomanip>
#include <math.h>

enum
{
    PRECISION = 10
};

int 
main()
{
    int amount = 0;
    double sum = 0;
    double sum_squares = 0;

    double number;
    while (std::cin >> number) {
        ++amount;
        sum += number;
        sum_squares += number * number;
    }

    double mean = sum / amount;
    double disp = sqrt(sum_squares / amount - mean * mean);
    std::cout << std::setprecision(PRECISION) << mean << " " << disp << std::endl;

    return 0; 
}
