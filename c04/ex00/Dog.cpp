#include <iostream>
#include <string>

#include "Dog.hpp"


Dog::Dog(void): Animal()
{
	std::cout << "Dog Default Constructor" << std::endl;

	Animal::_type = "Dog";
}

Dog::Dog(const Dog& d): Animal(d)
{
	std::cout << "Dog Copy Constructor" << std::endl;

	Animal::_type = d._type;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog Copy Operator" << std::endl;

	if (this == &d)
		return (*this);
	Animal::_type = d._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: " << Animal::_type << ", Bark!!" << std::endl;
}
