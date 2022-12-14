#pragma once
#ifndef __SCAVTRAP_H__
# define __SCAVTRAP_H__

# include <string>

# include "ClapTrap.hpp"

class	ScavTrap: public ClapTrap
{
public:
	ScavTrap(void);
	ScavTrap(const std::string& name);
	ScavTrap(const ScavTrap& ct);
	~ScavTrap();

	ScavTrap&	operator=(const ScavTrap& ct);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	guardGate(void);
};

#endif
