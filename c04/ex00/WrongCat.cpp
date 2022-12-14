#include <iostream>
#include <string>

#include "WrongCat.hpp"


WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "WrongCat Default Constructor" << std::endl;

	WrongAnimal::_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wc): WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor" << std::endl;

	WrongAnimal::_type = wc._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat&	WrongCat::operator=(const WrongCat& wc)
{
	if (this == &wc)
		return (*this);
	WrongAnimal::_type = wc._type;
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: " << WrongAnimal::_type << ", Meow~" << std::endl;
}
