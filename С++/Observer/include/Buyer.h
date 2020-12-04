#pragma once
#include <iostream>
#include "IObserver.h"

class Buyer : public IObserver {
public:
    Buyer() = default;
    ~Buyer() = default;

    void getUpdate(const std::string &msg) override {
        std::cout << msg << std::endl;
    }
};