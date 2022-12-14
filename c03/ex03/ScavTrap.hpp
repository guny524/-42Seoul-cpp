#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include <string>

# include "ClapTrap.hpp"

class	ScavTrap: virtual public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& ct);
	~ScavTrap();

	virtual ScavTrap&	operator=(const ScavTrap& ct);

	virtual void	attack(const std::string& target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);

	virtual void	guardGate(void);
};

#endif
