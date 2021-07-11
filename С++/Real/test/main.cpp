#include "Real.hpp"

int main() {
    Rational* a = Rational::create(0, 1);
    Rational* b = Rational::create(3, 2);
    Rational* c = Rational::create(4, 1);
    Rational* d = Rational::create(11, 2);

    Real* first = Real::create(a, b);
    Real* second = Real::create(c, d);

    std::cout << "first interval is " << Real::toString(first) << std::endl;
    std::cout << "second interval is " << Real::toString(second) << std::endl;

    Real* add = Real::add(first, second);
    std::cout << Real::toString(first) << " + " << Real::toString(second) << " = " << Real::toString(add) << std::endl;

    Real* mul = Real::mul(first, second);
    std::cout << Real::toString(first) << " * " << Real::toString(second) << " = " << Real::toString(mul) << std::endl;

    std::cout << Real::toString(first) << " > " << Real::toString(second) << " is " << toString(Real::GT(first, second)) << std::endl;
    std::cout << Real::toString(first) << " < " << Real::toString(second) << " is " << toString(Real::LE(first, second)) << std::endl;
    std::cout << Real::toString(first) << " intersects " << Real::toString(second) << " is " << toString(Real::intersect(first, second)) << std::endl;
    
    delete a;
    delete b;
    delete c;
    delete d;

    delete first;
    delete second;

    return 0;
}