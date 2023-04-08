#include "RPN.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <algorithm>


RPN::RPN(void)
{}

RPN::RPN(const std::string& expr):
_expr(expr)
{
	check_expr();
}

RPN::RPN(const RPN& rpn):
_expr(rpn._expr),
_stack(rpn._stack)
{}

RPN::~RPN()
{
	while (!_stack.empty())
		_stack.pop();
}

RPN&	RPN::operator=(const RPN& other)
{
	if (this == &other)
		return (*this);
	this->_expr = other._expr;
	this->_stack = other._stack;
	return (*this);
};

void	RPN::check_expr(void)
{
	const std::string	op = "+-*/";

	for (std::string::iterator iter=_expr.begin(); iter != _expr.end(); ++iter)
		if (!(std::isspace(*iter) || std::isdigit(*iter) || op.find(*iter) != std::string::npos))
			throw std::runtime_error(*iter + " is not a valid argument");
}

void	RPN::run(void)
{
	std::istringstream	stream(_expr);

	while (!(stream.fail() || stream.eof()))
	{
		while (std::isspace(stream.peek()))
			stream.get();
		// TODO
	}
}
