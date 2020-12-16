#pragma once

class Subject {
public:
    Subject() = default;
    ~Subject() = default;

    int sumOfTwo(int a, int b) {
        return a + b;
    }
    int sumOfThree(int a, int b, int c) {
        return a + b + c;
    }
    int sumOfFour(int a, int b, int c, int d) {
        return a + b + c + d;
    }
};