#include <iostream>
#include <string>

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void):
_type("WrongAnimal")
{}

WrongAnimal::WrongAnimal(const WrongAnimal& wa):
_type(wa._type)
{}

WrongAnimal::~WrongAnimal()
{}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wa)
{
	if (this == &wa)
		return (*this);
	_type = wa._type;
	return (*this);
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

void	WrongAnimal::makeSound(void) const
{
	std::cout << "Aniaml: " << _type << ", make sound" << std::endl;
}
