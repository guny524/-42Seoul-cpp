#include "RPN.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>


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
}

void	RPN::check_expr(void)
{
	const std::string	op = "+-*/";
	std::string arg;

	for (std::string::iterator iter=_expr.begin(); iter != _expr.end(); ++iter)
		if (!(std::isspace(*iter) || std::isdigit(*iter) || op.find(*iter) != std::string::npos))
		{
			arg = *iter;
			throw std::runtime_error(arg + " is not a valid argument");
		}
}

void	RPN::calculate(const char& c)
{
	// we already check stack size == 2 in run() func before call this calculate() func
	int second = _stack.top();
	_stack.pop();
	int first = _stack.top();
	_stack.pop();

	int res;
	switch (c)
	{
		case '+':
			res = first + second;
		break;
		case '-':
			res = first - second;
		break;
		case '*':
			res = first * second;
		break;
		case '/':
			res = first / second;
		break;
	}

	_stack.push(res);
}

void	RPN::run(void)
{
	std::istringstream	stream(_expr);
	char c;

	while (!(stream.fail() || stream.eof()))
	{
		while (std::isspace(stream.peek()))
			stream.get();
		if (stream.fail())
			throw std::runtime_error("fail to parse expr");
		else if (stream.eof())
			break;

		if (std::isdigit(stream.peek())) // number
		{
			stream >> c;
			_stack.push(c - '0');
		}
		else if (_stack.size() < 2) // char
			throw std::runtime_error("expr something wrong");
		else // char
		{
			stream >> c;
			calculate(c);
		}
		if (stream.fail())
			throw std::runtime_error("fail to parse expr");
	}

	if (_stack.size() != 1)
		throw std::runtime_error("calculation something wrong");
	
	std::cout << _stack.top() << std::endl;
	_stack.pop();
}
