#pragma once
#include <iostream>
#include "Boolean.hpp"

class Rational {
private:
    int numer;
    int denom;
    
    Rational(int a, int b) : numer(a), denom(b) {}
public:
    inline static Rational* create(int a, int b) { return b == 0 ? nullptr : new Rational(a, b); }
    inline Rational* clone() const { return new Rational(numer, denom); }

    inline static Rational* add(Rational* const a, Rational* const b) { return create(a->numer * b->denom + b->numer * a->denom, a->denom * b->denom); }
    inline static Rational* sub(Rational* const a, Rational* const b) { return create(a->numer * b->denom - b->numer * a->denom, a->denom * b->denom); }
    inline static Rational* mul(Rational* const a, Rational* const b) { return create(a->numer * b->numer, a->denom * b->denom); }
    inline static Rational* div(Rational* const a, Rational* const b) { return create(a->numer * b->denom, a->denom * b->numer); }

    inline static boolean GT(Rational* const a, Rational* const b) { return a->numer * b->denom > b->numer * a->denom ? TRUE : FALSE; }
    inline static boolean LE(Rational* const a, Rational* const b) { return a->numer * b->denom < b->numer * a->denom ? TRUE : FALSE; }

    static Rational* min(Rational** arr, size_t size) {
        Rational* min = arr[0];
        for (size_t i = 1; i < size; ++i)
            if (Rational::LE(arr[i], min))
                min = arr[i];
        return min;
    }

    static Rational* max(Rational** arr, size_t size) {
        Rational* max = arr[0];
        for (size_t i = 1; i < size; ++i)
            if (Rational::LE(arr[i], max))
                max = arr[i];
        return max;
    }

    //inline friend std::ostream& operator <<(std::ostream &out, Rational* const rat) { return out << rat->numer << "/" << rat->denom; }
    inline static std::string toString(Rational* const rat) { return rat != nullptr ? std::to_string(rat->numer) + "/" + std::to_string(rat->denom) : "nullptr"; }
};
