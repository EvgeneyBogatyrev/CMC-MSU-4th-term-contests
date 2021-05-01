#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>


class Factory
{
    Factory() {};
    Factory(const Factory &other) = delete;
    Factory(Factory &&other) =  delete;
    Factory &operator=(const Factory &other) = delete;
    Factory &operator=(Factory &&other) = delete;

    std::map<std::string, std::function<Figure * (std::string)>> build_map 
    {
        {"R", Rectangle::make},
        {"S", Square::make},
        {"C", Circle::make}
    };

public:
    static Factory &factory_instance() 
    {
        static Factory instance;
        return instance;
    }

    Figure *build_figure(const std::string &type, const std::string &init_string)
    {
        return build_map[type](init_string);
    }
};


int main()
{
    std::vector<Figure *> figures = {};
    std::string line;

    while (std::getline(std::cin, line)) {
        std::string type;
        std::string init_string;
        std::stringstream stream;

        stream << line;
        stream >> type;


        if (!type.compare("R")) {
            double w, h;
            stream >> w >> h;
            std::stringstream init;
            init << w << " " << h;  
            init_string = init.str();
        } else {
            double p;
            stream >> p;
            std::stringstream init;
            init << p;
            init_string = init.str();
        }

        Figure *new_figure = Factory::factory_instance().build_figure(type, init_string);
        figures.push_back(new_figure);
    }

    std::stable_sort(figures.begin(), figures.end(), [] (auto &a, auto &b) {
                return a->get_square() < b->get_square();
            });

    for (size_t i = 0; i < figures.size(); ++i) {
        std::cout << figures[i]->to_string() << std::endl;
    } 
    
    
    for (size_t i = 0; i < figures.size(); ++i) {
        delete figures[i];
    }
}
