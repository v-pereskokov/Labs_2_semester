#include <string>
#include "stack.h"
#include "switch.h"
#include <iostream>

int main()
{
    init_switch();
    stack s;
    std::size_t n;
    std::cin >> n;
    std::string enter;
    std::size_t j = 0;
    int v;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> enter;
        switch(cmd_map[enter])
        {
            case add:
                int value;
                std::cin >> value;
                s.add(value);
                break;
            case get:
                v = s.get();
                j++;
                break;
            case del:
                s.del();
                break;
        }
    }
    if (j > 0)
        std::cout << v << std::endl;
    return 0;
}