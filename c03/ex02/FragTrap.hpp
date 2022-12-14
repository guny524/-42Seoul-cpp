#pragma once
#ifndef __FRAGTRAP_H__
# define __FRAGTRAP_H__

# include <string>

# include "ClapTrap.hpp"

class	FragTrap: public ClapTrap
{
public:
	FragTrap(void);
	FragTrap(const std::string& name);
	FragTrap(const FragTrap& ct);
	~FragTrap();

	FragTrap&	operator=(const FragTrap& ct);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);

	void	guardGate(void);
};

#endif
