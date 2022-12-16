#include <iostream>
#include <string>

#include "FragTrap.hpp"


FragTrap::FragTrap(void): ClapTrap()
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "FragTrap: " << _name << " created!!" << std::endl;
}

FragTrap::FragTrap(const std::string& name): ClapTrap(name)
{
	_hitPoint = 100;
	_energyPoint = 100;
	_attackDamage = 30;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "FragTrap: " << _name << " created!!" << std::endl;
}

FragTrap::FragTrap(const FragTrap& ct): ClapTrap(ct)
{
	_hitPoint = ct._hitPoint;
	_energyPoint = ct._energyPoint;
	_attackDamage = ct._attackDamage;
	const_cast<unsigned int&>(_initialHitPoint) = _hitPoint;
	std::cout << "FragTrap: " << _name << " created!!" << std::endl;
}

FragTrap::~FragTrap()
{
	std::cout << "FragTrap: " << _name << " destroyed..." << std::endl;
}

FragTrap&	FragTrap::operator=(const FragTrap& ct)
{
	_name = ct._name;
	_hitPoint = ct._hitPoint;
	_energyPoint = ct._energyPoint;
	_attackDamage = ct._attackDamage;
	return (*this);
}

void	FragTrap::attack(const std::string& target)
{
	if (!doesItCanDo())
		return ;
	std::cout << "FragTrap: " << _name << " attacks " << target << ", ";
	std::cout << "causing " << _attackDamage << " points of damage!" << std::endl;
	--_energyPoint;
}

void	FragTrap::takeDamage(unsigned int amount)
{
	unsigned int	hitPoint = _hitPoint - amount;
	if (hitPoint > _hitPoint)
		hitPoint = 0;
	std::cout << "FragTrap: " << _name << " take damge of " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
}

void	FragTrap::beRepaired(unsigned int amount)
{
	if (!doesItCanDo())
		return ;

	unsigned int	hitPoint = _hitPoint + amount;
	if (hitPoint > FragTrap::_initialHitPoint)
		hitPoint = FragTrap::_initialHitPoint;

	std::cout << "FragTrap: " << _name << " be repaired with amount " << amount;
	_hitPoint = hitPoint;
	std::cout << " and remain hit point " << _hitPoint << std::endl;
	--_energyPoint;
}

void	FragTrap::highFivesGuys(void)
{
	std::cout << "High Fives !!!" << std::endl;
}
