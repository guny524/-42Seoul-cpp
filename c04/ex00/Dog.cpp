#include <iostream>
#include <string>

#include "Dog.hpp"


Dog::Dog(void): Animal()
{
	Animal::_type = "Dog";
}

Dog::Dog(const Dog& d): Animal()
{
	Animal::_type = d._type;
}

Dog::~Dog()
{}

Dog&	Dog::operator=(const Dog& d)
{
	if (this == &d)
		return (*this);
	_type = d._type;
	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: " << _type << ", Bark!!" << std::endl;
}
