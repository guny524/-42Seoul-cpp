#pragma once
#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

class	ClapTrap
{
protected:
	std::string		_name;
	unsigned int	_hitPoint;
	unsigned int	_energyPoint;
	unsigned int	_attackDamage;

	const unsigned int	_initialHitPoint;

	bool			doesItCanDo(void);

public:
	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& ct);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& ct);

	void	attack(const std::string& target);
	void	takeDamage(unsigned int amount);
	void	beRepaired(unsigned int amount);
};

#endif
