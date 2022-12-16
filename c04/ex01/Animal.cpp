#include <iostream>
#include <string>

#include "Animal.hpp"


Animal::Animal(void):
_type("Animal")
{
	std::cout << "Animal Default Constructor" << std::endl;
}

Animal::Animal(const Animal& a):
_type(a._type)
{
	std::cout << "Animal Copy Constructor" << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor" << std::endl;
}

Animal&	Animal::operator=(const Animal& a)
{
	std::cout << "Animal Copy Operator" << std::endl;

	if (this == &a)
		return (*this);
	_type = a._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Aniaml: " << _type << " make sound" << std::endl;
}
