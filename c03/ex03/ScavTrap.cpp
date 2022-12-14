#include <iostream>
#include <string>

#include "ScavTrap.hpp"


ScavTrap::ScavTrap(void): ClapTrap()
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "ScavTrap: " << _name << " created!!" << std::endl;
}

ScavTrap::ScavTrap(const std::string& name): ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "ScavTrap: " << _name << " created!!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap& ct): ClapTrap(ct)
{
	_hitPoint = 100;
	_energyPoint = 50;
	_attackDamage = 20;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "ScavTrap: " << _name << " created!!" << std::endl;
}

ScavTrap::~ScavTrap()
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

void	ScavTrap::guardGate(void)
{
	std::cout << "ScavTrap: " << _name << " enter Gate keeper mode" << std::endl;
}
