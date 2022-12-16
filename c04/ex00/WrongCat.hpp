#pragma once
#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

# include <string>

# include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal
{
public:
	WrongCat(void);
	WrongCat(const WrongCat& c);
	~WrongCat();

	WrongCat&	operator=(const WrongCat& c);

	void	makeSound(void) const;

};

#endif
