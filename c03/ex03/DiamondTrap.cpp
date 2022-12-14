#include <iostream>
#include <string>

#include "DiamondTrap.hpp"


DiamondTrap::DiamondTrap(void): ClapTrap(), FragTrap(), ScavTrap()
{
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "DiamondTrap: " << _name << " created!!" << std::endl;
}

DiamondTrap::DiamondTrap(const std::string& name): ClapTrap(name + "_clap_name"), FragTrap(name), ScavTrap(name)
{
	_name = name;
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "DiamondTrap: " << _name << " created!!" << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& ct): ClapTrap(ct), FragTrap(ct), ScavTrap(ct)
{
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "DiamondTrap: " << _name << " created!!" << std::endl;
}

DiamondTrap::~DiamondTrap()
{
	std::cout << "DiamondTrap: " << _name << " destroyed..." << std::endl;
}

DiamondTrap&	DiamondTrap::operator=(const DiamondTrap& ct)
{
	_name = ct._name;
	_hitPoint = FragTrap::_hitPoint;
	_energyPoint = ScavTrap::_energyPoint;
	_attackDamage = FragTrap::_attackDamage;
	return (*this);
}

void	DiamondTrap::attack(const std::string& target)
{
	ScavTrap::attack(target);
}

void	DiamondTrap::takeDamage(unsigned int amount)
{
	unsigned int	hitPoint = _hitPoint - amount;
	if (hitPoint > _hitPoint)
		hitPoint = 0;
	std::cout << "DiamondTrap: " << _name << " take damge of " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
}

void	DiamondTrap::beRepaired(unsigned int amount)
{
	if (!doesItCanDo())
		return ;

	unsigned int	hitPoint = _hitPoint + amount;
	if (hitPoint > DiamondTrap::_initialHitPoint)
		hitPoint = DiamondTrap::_initialHitPoint;

	std::cout << "DiamondTrap: " << _name << " be repaired with amount " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
	--_energyPoint;
}

void	DiamondTrap::whoAmI(void)
{
	std::cout << "I am " << _name << std::endl;
	std::cout << "I am " << ClapTrap::_name << std::endl;
}
