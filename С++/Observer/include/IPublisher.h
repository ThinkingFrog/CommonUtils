#pragma once
#include <list>
#include "IObserver.h"

class IPublisher {
protected:
    std::list<IObserver*> subs;
public:
    virtual ~IPublisher() {}
    virtual void addSub(IObserver* sub) = 0;
    virtual void deleteSub(IObserver* sub) = 0;
    virtual void notify() = 0;
};