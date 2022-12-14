#pragma once
#ifndef __DIAMONDTRAP_H__
# define __DIAMONDTRAP_H__

# include <string>

# include "ScavTrap.hpp"
# include "FragTrap.hpp"

class	DiamondTrap: public FragTrap, public ScavTrap
{
private:
	std::string	_name;
public:
	DiamondTrap(void);
	DiamondTrap(const std::string& name);
	DiamondTrap(const DiamondTrap& ct);
	virtual ~DiamondTrap();

	virtual DiamondTrap&	operator=(const DiamondTrap& ct);

	virtual void	attack(const std::string& target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);

	void	whoAmI(void);
};

#endif
