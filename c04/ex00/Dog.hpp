#pragma once
#ifndef __DOG_H__
# define __DOG_H__

# include <string>

# include "Animal.hpp"


class Dog: public Animal
{
public:
	Dog(void);
	Dog(const Dog& d);
	virtual ~Dog();

	virtual Dog&	operator=(const Dog& d);

	virtual void	makeSound(void) const;

};

#endif
