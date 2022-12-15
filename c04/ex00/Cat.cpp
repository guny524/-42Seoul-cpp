#include <iostream>
#include <string>

#include "Cat.hpp"


Cat::Cat(void)
{
	Animal::_type = "Cat";
}

Cat::Cat(const Cat& a)
{
	Animal::_type = a._type;
}

Cat::~Cat()
{}

Cat&	Cat::operator=(const Cat& a)
{
	_type = a._type;
	return (*this);
}

std::string	Cat::getType(void) const
{
	return (_type);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat " << _type << "Meow~" << std::endl;
}
