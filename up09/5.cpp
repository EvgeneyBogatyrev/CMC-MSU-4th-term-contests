#include <iostream>
#include <boost/date_time.hpp>
#include <limits.h>
#include <string>
#include <sstream>

int main()
{
    std::string line;
    
    int sum = 0;
    int year, month, day;
    
    char extra;
    std::cin >> line;
    std::stringstream(line) >> year >> extra >> month >> extra >> day;

    boost::gregorian::date prev(year, month, day);

    while (std::cin >> line) {
        std::stringstream(line) >> year >> extra >> month >> extra >> day;
        
        boost::gregorian::date cur(year, month, day);
        sum += abs((cur - prev).days());
        prev = cur;
    }
    std::cout << sum << std::endl;
}
