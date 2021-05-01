#include <string>

class Figure
{
public:
    virtual ~Figure() {};
    virtual double get_square() const = 0;

    virtual std::string to_string() 
    {
        return "~0~";
    }
};
