#include <string>
#include "queue.h"
#include "switch.h"
#include <iostream>

int main()
{
    init_switch();
    queue q;
    std::size_t n;
    std::cin >> n;
    std::string enter;
    int v;
    std::size_t j = 0;
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
                v = q.get();
                j++;
                break;
            case del:
                q.del();
                break;
        }
    }
    if (j > 0)
        std::cout << v << std::endl;
    return 0;
}