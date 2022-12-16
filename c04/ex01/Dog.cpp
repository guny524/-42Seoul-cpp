#include <iostream>
#include <string>

#include "Dog.hpp"


Dog::Dog(void): Animal()
{
	std::cout << "Dog Default Constructor" << std::endl;

	_brain = new Brain();
	_brain->setIdea(0, "IdeaDog");

	Animal::_type = "Dog";
}

Dog::Dog(const Dog& d): Animal(d)
{
	std::cout << "Dog Copy Constructor" << std::endl;

	_brain = new Brain();
	_brain->setIdea(0, d._brain->getIdea(0));

	Animal::_type = d._type;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
	delete _brain;
	_brain = NULL;
}

Dog&	Dog::operator=(const Dog& d)
{
	std::cout << "Dog Copy Operator" << std::endl;

	if (this == &d)
		return (*this);
	Animal::_type = d._type;

	delete _brain;
	_brain = new Brain();
	_brain->setIdea(0, d._brain->getIdea(0));

	return (*this);
}

void	Dog::makeSound(void) const
{
	std::cout << "Dog: " << Animal::_type << ", Bark!!";
	std::cout << " think " << "idx 0: " << _brain->getIdea(0) << ", ";
	std::cout << "idx 0: " << _brain->getIdea(1) << std::endl;
}
