#include <map>
#include <string>
#include <iostream>

enum cmd_value { add,
    get,
    del };

std::map<std::string, cmd_value> cmd_map;

static void init_switch()
{
    cmd_map["add"] = add;
    cmd_map["get"] = get;
    cmd_map["del"] = del;
}

