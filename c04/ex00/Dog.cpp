#include <iostream>
#include <string>

#include "Dog.hpp"


Dog::Dog(void)
{
	Animal::_type = "Dog";
}

Dog::Dog(const Dog& a)
{
	Animal::_type = a._type;
}

Dog::~Dog()
{}

Dog&	Dog::operator=(const Dog& a)
{
	_type = a._type;
	return (*this);
}

std::string	Dog::getType(void) const
{
	return (_type);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog " << _type << "Bark!!" << std::endl;
}
