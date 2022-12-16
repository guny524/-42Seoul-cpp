#pragma once
#ifndef __ANIMAL_H__
# define __ANIMAL_H__

# include <string>


class Animal
{
protected:
	std::string	_type;
	// TODO animal에 브레인이 있으면 안된다 강아지랑 고양이에 각자 가지고 있어야 함
public:
	Animal(void);
	Animal(const Animal& a);
	virtual ~Animal();

	virtual Animal&	operator=(const Animal& a);

	virtual std::string	getType(void) const;
	virtual void		makeSound(void) const;
};

#endif
