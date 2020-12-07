#pragma once

#include "Animal.h"

class Dog : public Animal {
private:
	std::string getSound() const { return "Woof!"; }
};