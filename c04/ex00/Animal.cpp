#include <iostream>
#include <string>

#include "Animal.hpp"


Animal::Animal(void):
_type("Animal")
{}

Animal::Animal(const Animal& a):
_type(a._type)
{}

Animal::~Animal()
{}

Animal&	Animal::operator=(const Animal& a)
{
	_type = a._type;
	return (*this);
}

std::string	Animal::getType(void) const
{
	return (_type);
}

void	Animal::makeSound(void) const
{
	std::cout << "Aniaml " << _type << "make sound" << std::endl;
}
