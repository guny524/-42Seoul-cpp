#include <iostream>
#include <string>

#include "HumanA.hpp"


HumanA::HumanA(const std::string& name, Weapon& wp):
_name(name),
_wp(wp)
{}

HumanA::HumanA(const HumanA& hm):
_name(hm._name),
_wp(hm._wp)
{}

HumanA::~HumanA()
{}

HumanA&	HumanA::operator=(const HumanA& hm)
{
	_name = hm._name;
	_wp = hm._wp;
	return (*this);
}

void	HumanA::attack(void)
{
	std::cout << _name << " attacks with their " << _wp.getType() << std::endl;
}
