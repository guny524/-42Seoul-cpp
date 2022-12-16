#include <iostream>
#include <string>

#include "WrongCat.hpp"


WrongCat::WrongCat(void): WrongAnimal()
{
	WrongAnimal::_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wc): WrongAnimal()
{
	WrongAnimal::_type = wc._type;
}

WrongCat::~WrongCat()
{}

WrongCat&	WrongCat::operator=(const WrongCat& wc)
{
	if (this == &wc)
		return (*this);
	_type = wc._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: " << _type << ", Meow~" << std::endl;
}
