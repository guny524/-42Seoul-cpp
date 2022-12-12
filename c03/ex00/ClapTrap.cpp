#include <iostream>
#include <string>

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void):
_name("empty"),
_hitPoint(10),
_energyPoint(10),
_attackDamage(10),
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
_name(name),
_hitPoint(10),
_energyPoint(10),
_attackDamage(10),
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct):
_name(ct._name),
_hitPoint(ct._hitPoint),
_energyPoint(ct._energyPoint),
_attackDamage(ct._attackDamage),
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap: " << _name << " destroyed..." << std::endl;
}

ClapTrap&	ClapTrap::operator=(const ClapTrap& ct)
{
	_name = ct._name;
	_hitPoint = ct._hitPoint;
	_energyPoint = ct._energyPoint;
	_attackDamage = ct._attackDamage;
	return (*this);
}

bool	ClapTrap::doesItCanDo(void)
{
	if (_hitPoint == 0 || __energyPoint == 0)
	{
		std::cout << "ClapTrap: " << _name << " can't do anything" << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (doesItCanDo())
		return ;
	std::cout << "ClapTrap: " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attackDamage << " points of damage!" << std::endl;
	--_eneryPoint;
}

void	ClapTrap::takeDamage(unsined int amount)
{
	if (doesItCanDo())
		return ;
	std::cout << "ClapTrap: " << _name << " attacked!!" << std::endl;
	--_hitPoint;
}

void	ClapTrap::beRepaired(unsined int amount)
{
	if (doesItCanDo())
		return ;
	std::cout << "ClapTrap: " << _name << " be repaired with hit point " << _initialHitPoint << std::endl;
	_hitPoint = _initialHitPoint;
	--_eneryPoint;
}
