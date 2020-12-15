#pragma once
#include <utility>
#include <memory>
#include "Container.hpp"

class Any {
private:
    std::unique_ptr<ContainerBase> holder;
public:
    Any() {
        holder = nullptr;
    }
    Any(ContainerBase* other) {
        holder = std::unique_ptr<ContainerBase>(other);
    }
    
    Any(const Any& other) {
        if (other.holder == nullptr) {
            holder = nullptr;
            return;
        }
        
        holder = std::unique_ptr<ContainerBase>(other.holder->copy());
    }
    Any(Any&& other) {
        holder = std::move(other.holder);
    }

    template<class T> Any(const T& obj) {
        holder = std::make_unique<Container<T>>(obj);
    }

    ~Any() = default;

    Any& swap(Any& other) {
        std::swap(this->holder, other.holder);
        return *this;
    }
    friend void swap(Any& obj1, Any& obj2) {
        obj1.swap(obj2);
    }
    Any& operator=(Any other) {
        this->swap(other);
        return *this;
    }
};