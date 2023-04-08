#pragma once
#ifndef __RPN_HPP__
#define __RPN_HPP__

#include <string>
#include <stack>


class RPN
{
private:
	std::string		_expr;
	std::stack<int>	_stack;

	RPN(void);


public:
	RPN(const std::string& expr);
	RPN(const RPN& rpn);
	~RPN();

	RPN&	operator=(const RPN& other);

	void	check_expr(void);
	void	run(void);
};

#endif
