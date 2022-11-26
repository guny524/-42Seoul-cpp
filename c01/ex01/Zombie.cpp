#include <iostream>

#include "Zombie.hpp"


Zombie::Zombie(void):
_name("emtpy")
{}

Zombie::Zombie(const std::string name):
_name(name)
{}

Zombie::Zombie(const Zombie& zb)
{
	_name = zb._name;
}

Zombie::~Zombie()
{
	std::cout << _name << std::endl;
}

Zombie& Zombie::operator=(const Zombie& zb)
{
	_name = zb._name;
	return (*this);
}

std::string	Zombie::getName(void)
{
	return (_name);
}

void	Zombie::setName(std::string name)
{
	_name = name;
}

void	Zombie::announce(void)
{
	std::cout << _name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

std::ostream& operator<<(std::ostream& out, Zombie &zb)
{
	out << zb.getName();
	return (out);
}
