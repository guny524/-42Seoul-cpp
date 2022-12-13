#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include <string>

# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

	const unsigned int	_initialHitPoint;

	bool			doesItCanDo(void);

public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& ct);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& ct);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
