#include <iostream>
#include <string>
#include <vector>
#include "switch.h"

template<typename T, typename Container = std::vector<T>>
class PriorityQueue
{
public:
    void push(T const& lhs)
    {
        con.push_back(lhs);
        std::sort(con.begin(), con.end());
    }
    
    void pop()
    {
        con.erase(con.begin());
    }
    
    T const& top()const
    {
        return con.front();
    }
    
    bool empty() const
    {
        return con.empty();
    }
private:
    Container con;
};

int main() {
    init_switch();
    std::string enter;
    PriorityQueue<int> pq;
    int count;
    std::cin >> count;
    for (int i = 0; i < count; ++i)
        while (count-- > 0) {
            std::cin >> enter;
            switch (cmd_map[enter]) {
                case add:
                    int n;
                    std::cin >> n;
                    pq.push(n);
                    break;
                case get:
                    std::cout << pq.top() << std::endl;
                    break;
                case del:
                    pq.pop();
                    break;
            }
        }
    return 0;
}
