#include <iostream>
#include <string>

#include "HumanB.hpp"


HumanB::HumanB(const std::string& name):
_name(name),
_wp(NULL)
{}

HumanB::HumanB(const HumanB& hm):
_name(hm._name),
_wp(NULL)
{}

HumanB::~HumanB()
{}

HumanB&	HumanB::operator=(const HumanB& hm)
{
	_name = _name;
	_wp = NULL;
	return (*this);
}

void	HumanB::attack(void)
{
	if (_wp == NULL)
		std::cout << _name << " attacks with their " << "None Weapon" << std::endl;
	else
		std::cout << _name << " attacks with their " << _wp->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon& wp)
{
	_wp = &wp;
}
