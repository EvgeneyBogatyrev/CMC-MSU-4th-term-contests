#include <string>
#include <sstream>
#define _USE_MATH_DEFINES
#include <math.h>

class Rectangle : public Figure
{
    double width_{};
    double height_{};
public:
    Rectangle(double width, double height) : width_(width), height_(height ) {}

    double get_square() const override
    {
        return width_ * height_;
    }

    static Rectangle *make(std::string init_string)
    {
        std::stringstream stream;
        stream << init_string;

        double width, height;
        stream >> width;
        stream >> height;

        Rectangle *new_rect = new Rectangle(width, height);

        return new_rect;
    }

    std::string to_string()
    {
        return "R";
    }
};

class Square : public Figure
{
    double width_{};
public:
    Square(double width) : width_(width) {}

    double get_square() const override
    {
        return width_ * width_;
    }

    static Square *make(std::string init_string)
    {
        std::stringstream stream;
        stream << init_string;

        double width;
        stream >> width;

        Square *new_square = new Square(width);

        return new_square;
    }

    std::string to_string()
    {
        return "S";
    }

};

class Circle : public Figure
{
    double radius_{};
public:
    Circle(double radius) : radius_(radius) {}

    double get_square() const override
    {
        return M_PI * radius_ * radius_; 
    }

    static Circle *make(std::string init_string)
    {
        std::stringstream stream;
        stream << init_string;

        double radius;
        stream >> radius;

        Circle *new_circle = new Circle(radius);

        return new_circle;
    }

    std::string to_string()
    {
        return "C";
    }

};

