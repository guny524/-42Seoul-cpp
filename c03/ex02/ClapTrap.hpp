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
	virtual ~ClapTrap();

	virtual ClapTrap&	operator=(const ClapTrap& ct);

	virtual void	attack(const std::string& target);
	virtual void	takeDamage(unsigned int amount);
	virtual void	beRepaired(unsigned int amount);
};

#endif
