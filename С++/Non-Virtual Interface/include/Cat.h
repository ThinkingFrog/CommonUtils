#pragma once

#include "Animal.h"

class Cat : public Animal {
private:
	std::string getSound() const { return "Meow!"; }
};
