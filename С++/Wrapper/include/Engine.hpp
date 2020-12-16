#pragma once
#include <map>
#include <string>
#include <vector>
#include "Wrapper.hpp"

class Engine {
private:
    std::map<std::string, Wrapper*> wrap_dict;
public:
    Engine() = default;
    ~Engine() = default;

    void register_command(Wrapper* wrapper, std::string name) {
        wrap_dict[name] = wrapper;
    }
    int execute(std::string name, std::map<std::string, int> args) {
        return wrap_dict[name]->execute(args);
    }
};