#include <iostream>
#include <string>

#include "WrongCat.hpp"


WrongCat::WrongCat(void): WrongAnimal()
{
	std::cout << "WrongCat Default Constructor" << std::endl;

	_brain = new Brain();
	_brain->setIdea(1, "IdeaCat");

	WrongAnimal::_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& wc): WrongAnimal()
{
	std::cout << "WrongCat Copy Constructor" << std::endl;

	_brain = new Brain();
	_brain->setIdea(1, wc._brain->getIdea(1));

	WrongAnimal::_type = wc._type;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
	delete _brain;
	_brain = NULL;
}

WrongCat&	WrongCat::operator=(const WrongCat& wc)
{
	if (this == &wc)
		return (*this);
	WrongAnimal::_type = wc._type;

	delete _brain;
	_brain = new Brain();
	_brain->setIdea(1, wc._brain->getIdea(1));

	return (*this);
}

void	WrongCat::makeSound(void) const
{
	std::cout << "WrongCat: " << WrongAnimal::_type << ", Meow~" << std::endl;
	std::cout << " think " << "idx 0: " << _brain->getIdea(0) << ", ";
	std::cout << "idx 0: " << _brain->getIdea(1) << std::endl;
}
