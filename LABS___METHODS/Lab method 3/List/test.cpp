#include <string>
#include "list.h"
#include "switch.h"
#include <iostream>

int main()
{
    init_switch();
    list l;
    std::size_t n;
    std::cin >> n;
    std::string enter;
    int v;
    std::size_t j = 0;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::size_t index;
        std::cin >> enter;
        switch(cmd_map[enter])
        {
            case add:
                int value;
                std::cin >> index >> value;
                l.add(index, value);
                break;
            case get:
                std::cin >> index;
                v = l.get(index);
                j++;
                break;
            case del:
                std::cin >> index;
                l.del(index);
                break;
        }
    }
    if (j > 0)
        std::cout << v << std::endl;
    return 0;
}