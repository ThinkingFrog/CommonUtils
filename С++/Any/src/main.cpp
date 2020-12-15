#include <iostream>
#include <vector>
#include <string>
#include <list>
#include "AnyArray.hpp"

int main() {
    AnyArray arr1;
    AnyArray arr2;

    std::cout << "First array size: " << arr1.get_size() << std::endl;
    std::cout << "Second array size: " << arr2.get_size() << std::endl;
    std::cout << std::endl << "Now append 4 elements to first array" << std::endl;

    arr1.append(5);
    arr1.append(std::list<bool>{true, false, false, true});
    arr1.append(40.5);
    Any str(std::string{"I'm string"});
    arr1.append(str);

    std::cout << "First array size: " << arr1.get_size() << std::endl;
    std::cout << "Second array size: " << arr2.get_size() << std::endl;
    std::cout << std::endl << "Now assign first array to second" << std::endl;

    arr2 = arr1;

    std::cout << "First array size: " << arr1.get_size() << std::endl;
    std::cout << "Second array size: " << arr2.get_size() << std::endl;
    std::cout << std::endl << "Now append 2 elements to second array" << std::endl;

    Any vec(std::vector<int>{106, 647, 42});
    arr2.append(vec);
    arr2.append(true);

    std::cout << "First array size: " << arr1.get_size() << std::endl;
    std::cout << "Second array size: " << arr2.get_size() << std::endl;

    return 0;
}