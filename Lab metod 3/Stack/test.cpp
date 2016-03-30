#include <string>
#include "stack.h"
#include "switch.h"

int main()
{
    init_switch();
    stack s;
    std::size_t n;
    std::cin >> n;
    std::string enter;
    std::string cmd;
    std::string value;
    int v;
    for (std::size_t i = 0; i < n; ++i)
    {
        std::getline(std::cin, enter);
        std::size_t length = enter.copy(cmd, 3, 0);
        switch(cmd_map[cmd])
        {
            case add:
                s.add(2);
                break;
            case get:
                v = s.get();
                break;
            case del:
                s.del();
                break;
        }
    }
    std::cout << v << std::endl;
    return 0;
}
