#include <iostream>
#include <string>

#include "Cat.hpp"


Cat::Cat(void): Animal()
{
	std::cout << "Cat Default Constructor" << std::endl;

	_brain = new Brain();
	_brain->setIdea(1, "IdeaCat");

	Animal::_type = "Cat";
}

Cat::Cat(const Cat& c): Animal(c)
{
	std::cout << "Cat Copy Constructor" << std::endl;

	_brain = new Brain();
	_brain->setIdea(1, c._brain->getIdea(1));

	Animal::_type = c._type;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	delete _brain;
	_brain = NULL;
}

Cat&	Cat::operator=(const Cat& c)
{
	std::cout << "Cat Copy Operator" << std::endl;

	if (this == &c)
		return (*this);
	Animal::_type = c._type;

	delete _brain;
	_brain = new Brain();
	_brain->setIdea(1, c._brain->getIdea(1));

	return (*this);
}

void	Cat::makeSound(void) const
{
	std::cout << "Cat: " << Animal::_type << ", Meow~";
	std::cout << " think " << "idx 0: " << _brain->getIdea(0) << ", ";
	std::cout << "idx 0: " << _brain->getIdea(1) << std::endl;
}
