#pragma once
#ifndef __BRAIN_H__
# define __BRAIN_H__

# include <string>


class	Brain
{
private:
	static const int	_NUM = 100;
	std::string	_ideas[_NUM];

public:
	Brain(void);
	Brain(const Brain& b);
	~Brain();

	Brain&	operator=(const Brain& b);

	void		setIdea(int idx, std::string idea);
	std::string	getIdea(int idx) const;
};

#endif
