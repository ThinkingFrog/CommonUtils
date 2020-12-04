#pragma once
#include "IPublisher.h"

class Store : public IPublisher {
private:
    unsigned phonesCount;
public:
    Store() {
        phonesCount = 0;
    }
    ~Store() {
        subs.clear();
    }

    void addSub(IObserver* sub) override {
        subs.push_back(sub);
    }
    void deleteSub(IObserver* sub) override {
        subs.remove(sub);
    }
    void notify() override {
        std::string msg = "We have a new phone in stock, total is ";
        for (auto sub : subs)
            sub->getUpdate(msg + std::to_string(phonesCount));
    }

    void newPhoneArrived() {
        ++phonesCount;
        notify();
    }
};