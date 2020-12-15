#pragma once
#include <cstddef>
#include "Any.hpp"

class AnyArray {
private:
    Any* array;
    size_t size;
public:
    AnyArray() {
        array = nullptr;
        size = 0;
    }
    AnyArray(size_t size) {
        this->size = size;
        array = new Any[size];
    }

    AnyArray(const AnyArray& other) {
        size = other.size;
        if (other.array == nullptr) {
            array = nullptr;
            return;
        }

        array = new Any[size];
        for (size_t i = 0; i < other.size; ++i)
            array[i] = other.array[i];
    }
    AnyArray(AnyArray&& other) {
        size = other.size;
        other.size = 0;
        array = std::move(other.array);
    }

    ~AnyArray() {
        delete[] array;
    }

    void append(const Any& obj) {
        Any* tmp = new Any[++size];
        
        for (size_t i = 0; i < size - 1; ++i)
            tmp[i] = array[i];
        tmp[size - 1] = obj;
        
        delete [] array;
        array = tmp;
    }

    AnyArray& swap(AnyArray& other) {
        std::swap(this->size, other.size);
        std::swap(this->array, other.array);
        return *this;
    }
    friend void swap(AnyArray& obj1, AnyArray& obj2) {
        obj1.swap(obj2);
    }
    AnyArray& operator=(AnyArray other) {
        this->swap(other);
        return *this;
    }

    size_t get_size() const {
        return size;
    }
};