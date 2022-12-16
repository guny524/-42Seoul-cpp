#include <iostream>
#include <string>

#include "Cat.hpp"


Cat::Cat(void): Animal()
{
	Animal::_type = "Cat";
}

Cat::Cat(const Cat& c): Animal()
{
	Animal::_type = c._type;
}

Cat::~Cat()
{}

Cat&	Cat::operator=(const Cat& c)
{
	if (this == &c)
		return (*this);
	_type = c._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: " << _type << ", Meow~" << std::endl;
}
