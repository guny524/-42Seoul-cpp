#include <iostream>
#include <string>

#include "ICharacter.ipp"
#include "AMateria.hpp"


AMateria::AMateria(void):
_type("")
{}

AMateria::AMateria(const std::string& type):
_type(type)
{}

AMateria::AMateria(const AMateria& am):
_type(am._type)
{}

AMateria::~AMateria()
{}

AMateria&	AMateria::operator=(const AMateria& am)
{
	std::cout << "AMateria " << am.getType() << " assign doesn't make sense" << std::endl;
	return (*this);
}

const std::string&	AMateria::getType() const
{
	return (_type);
}

void	use(ICharacter& target)
{
	std::cout << "* Meteria " << target.getName() << " *" << std::endl;
}
