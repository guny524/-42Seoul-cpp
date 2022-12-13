#include <iostream>
#include <string>

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void):
_name("empty"),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0)
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
_name(name),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0)
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct):
_name(ct._name),
_hitPoint(ct._hitPoint),
_energyPoint(ct._energyPoint),
_attackDamage(ct._attackDamage)
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

unsigned int	ClapTrap::getDamage()
{
	return (_attackDamage);
}

bool	ClapTrap::doesItCanDo(void)
{
	if (_hitPoint == 0 || _energyPoint == 0)
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
	--_energyPoint;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	if (doesItCanDo())
		return ;
	std::cout << "ClapTrap: " << _name << " attacked!!" << std::endl;
	// TODO
	--_hitPoint;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (doesItCanDo())
		return ;

	unsigned int	hitPoint = amount + _hitPoint;
	if (hitPoint > _initialHitPoint)
		hitPoint = _initialHitPoint;

	std::cout << "ClapTrap: " << _name << " be repaired with amount " << _initialHitPoint - _hitPoint << std::endl;
	_hitPoint = hitPoint;
	--_energyPoint;
}
