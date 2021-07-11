#include <iostream>
#include "Rational.hpp"

int main() {
    Rational* null = Rational::create(5, 0);
    Rational* a = Rational::create(1, 2);
    Rational* b = Rational::create(1, 3);

    if (null == nullptr)
        std::cout << "Couldn't create a rational number named 'null' with zero denominator" << std::endl;

    Rational* addition = Rational::add(a, b);        
    std::cout << Rational::toString(a) << " + " << Rational::toString(b) << " = " << Rational::toString(addition) << std::endl;
    
    Rational* subtraction = Rational::sub(a, b);
    std::cout << Rational::toString(a) << " - " << Rational::toString(b) << " = " << Rational::toString(subtraction) << std::endl;
    
    Rational* multiplication = Rational::mul(a, b);
    std::cout << Rational::toString(a) << " * " << Rational::toString(b) << " = " << Rational::toString(multiplication) << std::endl;
    
    Rational* division = Rational::div(a, b);
    std::cout << Rational::toString(a) << " / " << Rational::toString(b) << " = " << Rational::toString(division) << std::endl;

    std::cout << Rational::toString(a) << " > " << Rational::toString(b) << " is " << toString(Rational::GT(a, b)) << std::endl;
    std::cout << Rational::toString(a) << " < " << Rational::toString(b) << " is " << toString(Rational::LE(a, b)) << std::endl;
    
    delete null;
    
    delete a;
    delete b;
    
    delete addition;
    delete subtraction;
    delete multiplication;
    delete division;
    
    return 0;
}