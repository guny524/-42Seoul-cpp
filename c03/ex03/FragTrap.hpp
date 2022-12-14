#pragma once
#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include <string>

# include "ClapTrap.hpp"

class	FragTrap: virtual public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& ct);
	virtual ~FragTrap();

	virtual FragTrap&	operator=(const FragTrap& ct);

	virtual void	attack(const std::string& target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);

	void	highFivesGuys(void);
};

#endif
