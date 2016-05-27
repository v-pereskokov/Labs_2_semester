#include <iostream>
#include <string>
#include <vector>
#include "list.cpp"
#include "switch.h"

int main()
{
    init_switch();
    list l;
    std::size_t n;
    std::cin >> n;
    std::string enter;
    std::vector<int> out;
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
                out.push_back(l.get(index));
                break;
            case del:
                std::cin >> index;
                l.del(index);
                break;
        }
    }
    for (auto a : out)
        std::cout << a << std::endl;
    return 0;
}
