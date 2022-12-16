#include <iostream>
#include <string>

#include "Cure.hpp"


Cure::Cure(void): AMateria("cure")
{}

Cure::Cure(const Cure& c): AMateria(c)
{}

Cure::~Cure()
{}

Cure&	Cure::operator=(const Cure& c)
{
	std::cout << "Cure " << c.getType() << " doesn't make sense" << std::endl;
	return (*this);
}

Cure*	Cure::clone() const
{
	return (new Cure());
}

void	use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
