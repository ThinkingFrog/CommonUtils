#pragma once
#include <string>

class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void getUpdate(const std::string &msg) = 0;
};
