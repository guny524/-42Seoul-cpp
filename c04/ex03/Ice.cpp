#include <iostream>
#include <string>

#include "Ice.hpp"


Ice::Ice(void): AMateria("ice")
{}

Ice::Ice(const Ice& ice): AMateria(ice)
{}

Ice::~Ice()
{}

Ice&	Ice::operator=(const Ice& ice)
{
	std::cout << "Ice " << ice.getType() << " doesn't make sense" << std::endl;

	return (*this);
}

Ice*	Ice::clone() const
{
	return (new Ice());
}

void	use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
