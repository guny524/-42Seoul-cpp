#include <iostream>
#include <string>

#include "ClapTrap.hpp"


ClapTrap::ClapTrap(void):
_name("empty"),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0),
_initialHitPoint(_hitPoint)
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::ClapTrap(const std::string& name):
_name(name),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0),
_initialHitPoint(_hitPoint)
{
	std::cout << "ClapTrap: " << _name << " created!!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap& ct):
_name(ct._name),
_hitPoint(ct._hitPoint),
_energyPoint(ct._energyPoint),
_attackDamage(ct._attackDamage),
_initialHitPoint(ct._initialHitPoint)
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
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << _name << " can't do anything" << std::endl;
		return (false);
	}
	return (true);
}

void	ClapTrap::attack(const std::string& target)
{
	if (!doesItCanDo())
		return ;
	std::cout << "ClapTrap: " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attackDamage << " points of damage!" << std::endl;
	--_energyPoint;
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	unsigned int	hitPoint = _hitPoint - amount;
	if (hitPoint > _hitPoint)
		hitPoint = 0;
	std::cout << "ClapTrap: " << _name << " take damge of " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (!doesItCanDo())
		return ;

	unsigned int	hitPoint = _hitPoint + amount;
	if (hitPoint > ClapTrap::_initialHitPoint)
		hitPoint = ClapTrap::_initialHitPoint;

	std::cout << "ClapTrap: " << _name << " be repaired with amount " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
	--_energyPoint;
}
