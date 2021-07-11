#pragma once
#include "Rational.hpp"
#include "Boolean.hpp"

class Real {
private:
    Rational* left;
    Rational* right;

    Real(Rational* const left, Rational* const right) {
        this->left = left->clone();
        this->right = right->clone();
    }
public:
    ~Real() {
        delete left;
        delete right;
    }

    static Real* create(Rational* const left, Rational* const right) { 
        if (left == nullptr || right == nullptr || Rational::GT(left, right))
            return nullptr;
        else 
            return new Real(left, right); 
    }

    static Real* add(Real* const a, Real* const b) {
        Rational* left = Rational::add(a->left, b->left);
        Rational* right = Rational::add(a->right, b->right);
        
        Real* res = Real::create(left, right);
        
        delete left;
        delete right;
        
        return res;
    }

    static Real* sub(Real* const a, Real* const b) {
        Rational* left = Rational::sub(a->left, b->left);
        Rational* right = Rational::sub(a->right, b->right);
        
        Real* res = Real::create(left, right);
        
        delete left;
        delete right;
        
        return res;
    }

    static Real* mul(Real* const a, Real* const b) {
        Rational* ac = Rational::mul(a->left, b->left);
        Rational* ad = Rational::mul(a->left, b->right);
        Rational* bc = Rational::mul(a->right, b->left);
        Rational* bd = Rational::mul(a->right, b->right);

        Rational* arr[4]{ac, ad, bc, bd};

        Rational* left = Rational::min(arr, 4);
        Rational* right = Rational::max(arr, 4);
        
        Real* res = Real::create(left, right);
        
        delete ac;
        delete ad;
        delete bc;
        delete bd;
        
        return res;
    }

    static Real* div(Real* const a, Real* const b) {
        Rational* ac = Rational::div(a->left, b->left);
        Rational* ad = Rational::div(a->left, b->right);
        Rational* bc = Rational::div(a->right, b->left);
        Rational* bd = Rational::div(a->right, b->right);

        Rational* arr[4]{ac, ad, bc, bd};

        Rational* left = Rational::min(arr, 4);
        Rational* right = Rational::max(arr, 4);
        
        Real* res = Real::create(left, right);
        
        delete ac;
        delete ad;
        delete bc;
        delete bd;
        
        return res;
    }

    inline static boolean GT(Real* const a, Real* const b) { return Rational::GT(a->left, b->right); }

    inline static boolean LE(Real* const a, Real* const b) { return Rational::LE(a->right, b->left); }

    inline static boolean intersect(Real* const a, Real* const b) { return !Real::GT(a, b) || Real::LE(a, b) ? FALSE : TRUE; }

    inline static std::string toString(Real* real) { return real != nullptr ? "[" + Rational::toString(real->left) + ", " + Rational::toString(real->right) + "]" : "nullptr"; }
};