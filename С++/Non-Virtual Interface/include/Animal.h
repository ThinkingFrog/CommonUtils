#pragma once

#include <iostream>
#include <string>

class Animal {
public:
	void speak() const {
		std::cout << getSound() << std::endl;
	}
private:
	virtual std::string getSound() const = 0;
};