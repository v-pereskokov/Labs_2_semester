#include <iostream>
#include <string>
#include <vector>
#include "queue.cpp"
#include "switch.h"

int main()
{
    init_switch();
    queue q;
    std::size_t n;
    std::cin >> n;
    std::string enter;
    std::vector<int> out;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::cin >> enter;
        switch(cmd_map[enter])
        {
            case add:
                int value;
                std::cin >> value;
                q.add(value);
                break;
            case get:
                out.push_back(q.get());
                break;
            case del:
                q.del();
                break;
        }
    }
    for (auto a : out)
        std::cout << a << std::endl;
    return 0;
}
