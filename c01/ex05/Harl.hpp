#pragma once
#ifndef __HARL_H__
# define __HARL_H__

# include <string>

class Harl
{
public:
	Harl(void);
	Harl(const Harl& h);
	~Harl();

	Harl&	operator=(const Harl& h);

	void	debug(void);
	void	info(void);
	void	warning(void);
	void	error(void);

	void	complain(std::string level);
};

#endif
