#include <iostream>
#include <string>

#include "WrongAnimal.hpp"


WrongAnimal::WrongAnimal(void):
_type("WrongAnimal")
{
	std::cout << "WrongAnimal Default Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& wa):
_type(wa._type)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal&	WrongAnimal::operator=(const WrongAnimal& wa)
{
	std::cout << "WrongAnimal Copy Operator" << std::endl;

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
