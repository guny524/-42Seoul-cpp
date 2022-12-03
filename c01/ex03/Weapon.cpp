#include <iostream>

#include "Weapon.hpp"


Weapon::Weapon(void):
_type("empty")
{}

Weapon::Weapon(const std::string& type):
_type(type)
{}

Weapon::Weapon(const Weapon& wp):
_type(wp._type)
{}

Weapon::~Weapon()
{}

Weapon&	Weapon::operator=(const Weapon& wp)
{
	_type = wp._type;
	return (*this);
}

const std::string&	Weapon::getType() const
{
	return (_type);
}

void	Weapon::setType(const std::string& type)
{
	_type = type;
}
