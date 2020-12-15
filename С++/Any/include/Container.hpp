#pragma once

class ContainerBase {
    public:
    virtual ~ContainerBase() = default;
    virtual ContainerBase* copy() const = 0;
};

template <class T>
class Container : public ContainerBase {
    private:
        T obj;
    public:
    Container(const T& obj) {
        this->obj = obj;
    }
    Container(T&& obj) {
        this->obj = std::move(obj);
    }
    ~Container() = default;

    ContainerBase* copy() const override {
        return new Container(obj);
    }
};