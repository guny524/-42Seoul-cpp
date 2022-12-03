#pragma once
#ifndef __HUMANB_H__
# define __HUMANB_H__

# include <string>

# include "Weapon.hpp"

class	HumanB
{
private:
	std::string	_name;
	Weapon		*_wp;

public:
	HumanB(const std::string& name);
	HumanB(const HumanB& hm);
	~HumanB();

	HumanB&	operator=(const HumanB& hm);

	void	attack(void);
	void	setWeapon(Weapon& wp);
};

#endif
