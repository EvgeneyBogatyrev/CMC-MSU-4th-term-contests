#include <vector>
#include <string>
#include <map>
#include <functional>

namespace numbers
{
    complex eval(const std::vector<std::string> &args, const complex &z)
    {
        std::map<std::string, std::function<void(complex_stack&)>> map
        {            
            {"+", [](complex_stack &stack) 
                {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    
                    stack = stack<<(z2 + z1);                   
                }
            },
                
            {"-", [](complex_stack &stack)
                {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    
                    stack = stack<<(z2 - z1);                   

                }
            },

            {"*", [](complex_stack &stack)
                {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    
                    stack = stack<<(z2 * z1);                   
                }
            },

            {"/", [](complex_stack &stack)
                {
                    complex z1 = +stack;
                    stack = ~stack;
                    complex z2 = +stack;
                    stack = ~stack;
                    
                    stack = stack<<(z2 / z1);                   
                }
            },

            {"!", [](complex_stack &stack)
                {
                    complex z1 = +stack;
                    
                    stack = stack<<z1;
                }
            },

            {";", [](complex_stack &stack)
                {
                    stack = ~stack;
                }
            },

            {"~", [](complex_stack &stack)
                {
                    complex z1 = +stack;
                    stack = ~stack;

                    stack = stack<<(~z1);
                }
            },

            {"#", [](complex_stack &stack)
                {
                    complex z1 = +stack;
                    stack = ~stack;

                    stack = stack<<(-z1);
                }
            }
        };
        
        complex_stack stack;
        for (size_t i = 0; i < args.size(); ++i) {
            
            
            auto iter = map.find(args[i]);
            if (iter != map.end()) {
                iter->second(stack); 
            }
            else if (args[i] == "z") {
                stack = stack<<z;
            } else {
                complex number(args[i]);
                stack = stack<<number;
            }
        }
        return +stack;
    }
}

