#include <iostream>
#include <string>

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(void): ClapTrap(),
_name("empty"),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0),
_initialHitPoint(10)
{
	std::cout << "ScavTrap: " << _name << " created!!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name),
_name(name),
_hitPoint(10),
_energyPoint(10),
_attackDamage(0),
_initialHitPoint(10)
{
	std::cout << "ScavTrap: " << _name << " created!!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ct): ClapTrap(ct),
_name(ct._name),
_hitPoint(ct._hitPoint),
_energyPoint(ct._energyPoint),
_attackDamage(ct._attackDamage),
_initialHitPoint(ct._initialHitPoint)
{
	std::cout << "ScavTrap: " << _name << " created!!" << std::endl;
}

ScavTrap::~ScavTrap() // TODO
{
	std::cout << "ScavTrap: " << _name << " destroyed..." << std::endl;
}

ScavTrap&	ScavTrap::operator=(const ScavTrap& ct)
{
	_name = ct._name;
	_hitPoint = ct._hitPoint;
	_energyPoint = ct._energyPoint;
	_attackDamage = ct._attackDamage;
	return (*this);
}

bool	ScavTrap::doesItCanDo(void)
{
	if (_hitPoint == 0 || _energyPoint == 0)
	{
		std::cout << "ScavTrap: " << _name << " can't do anything" << std::endl;
		return (false);
	}
	return (true);
}

void	ScavTrap::attack(const std::string& target)
{
	if (!doesItCanDo())
		return ;
	std::cout << "ScavTrap: " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attackDamage << " points of damage!" << std::endl;
	--_energyPoint;
}

void	ScavTrap::takeDamage(unsigned int amount)
{
	unsigned int	hitPoint = _hitPoint - amount;
	if (hitPoint > _hitPoint)
		hitPoint = 0;
	std::cout << "ScavTrap: " << _name << " take damge of " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
}

void	ScavTrap::beRepaired(unsigned int amount)
{
	if (!doesItCanDo())
		return ;

	unsigned int	hitPoint = _hitPoint + amount;
	if (hitPoint > ScavTrap::_initialHitPoint)
		hitPoint = ScavTrap::_initialHitPoint;

	std::cout << "ScavTrap: " << _name << " be repaired with amount " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
	--_energyPoint;
}
