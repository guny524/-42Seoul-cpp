#pragma once
#ifndef __CAT_H__
# define __CAT_H__

# include <string>

# include "Animal.hpp"


class Cat: public Animal
{
public:
	Cat(void);
	Cat(const Cat& c);
	virtual ~Cat();

	virtual Cat&	operator=(const Cat& c);

	virtual void	makeSound(void) const;

};

#endif
