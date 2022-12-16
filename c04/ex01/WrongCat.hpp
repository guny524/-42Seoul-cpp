#pragma once
#ifndef __WRONGCAT_H__
# define __WRONGCAT_H__

# include <string>

# include "Brain.hpp"
# include "WrongAnimal.hpp"


class WrongCat: public WrongAnimal
{
private:
	Brain	*_brain;

public:
	WrongCat(void);
	WrongCat(const WrongCat& c);
	~WrongCat();

	WrongCat&	operator=(const WrongCat& c);

	void	makeSound(void) const;
};

#endif
