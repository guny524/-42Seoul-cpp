#pragma once
#ifndef __CLAPTRAP_H__
# define __CLAPTRAP_H__

# include <string>

class	ClapTrap
{
private:
	std::string		_name;
	unsigned int	_hitPoint;
	unsigned int	_eneryPoint;
	unsigned int	_attackDamage;

	static const unsigned int	_initialHitPoint;

	ClapTrap(void);
	ClapTrap(const std::string& name);
	ClapTrap(const ClapTrap& ct);
	~ClapTrap();

	ClapTrap&	operator=(const ClapTrap& ct);

	unsigned int	getDamage() //# TODO
	bool			doesItCanDo(void);

public:
	void	attack(const std::string& target);
	void	takeDamage(unsined int amount);
	void	beRepaired(unsined int amount);
};

#endif
