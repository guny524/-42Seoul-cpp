#pragma once
#ifndef __HUMANA_H__
# define __HUMANA_H__

# include <string>

# include "Weapon.hpp"

class	HumanA
{
private:
	std::string	_name;
	Weapon&		_wp;

public:
	HumanA(const std::string& name, Weapon& wp);
	HumanA(const HumanA& hm);
	~HumanA();

	HumanA&	operator=(const HumanA& hm);

	void	attack(void);
};

#endif
