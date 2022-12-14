#include <iostream>
#include <string>

#include "Cat.hpp"


Cat::Cat(void): Animal()
{
	std::cout << "Cat Default Constructor" << std::endl;

	Animal::_type = "Cat";
}

Cat::Cat(const Cat& c): Animal(c)
{
	std::cout << "Cat Copy Constructor" << std::endl;

	Animal::_type = c._type;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
}

Cat&	Cat::operator=(const Cat& c)
{
	std::cout << "Cat Copy Operator" << std::endl;

	if (this == &c)
		return (*this);
	Animal::_type = c._type;
	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: " << Animal::_type << ", Meow~" << std::endl;
}
