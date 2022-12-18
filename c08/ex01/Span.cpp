#include <iostream>
#include <algorithm>
#include <vector>
#include <exception>

#include "Span.hpp"


Span::Span(void):
_N(0)
{}

Span::Span(const unsigned int& N):
_N(N)
{
	_vector.reserve(N);
}

Span::Span(const Span& span)
{
	*this = span;
}

Span::~Span()
{}

Span&	Span::operator=(const Span& span)
{
	if (this == &span)
		return (*this);
	_vector = span._vector;
	_N = span._N;
	return (*this);
}

void	Span::addNumber(const int& num)
{
	if (_vector.size() >= _N)
		throw std::runtime_error("Span is Full");
	_vector.push_back(num);
}

int	Span::shortestSpan() const
{
	if (_vector.size() == 1)
		throw std::runtime_error("No Span exist");

	std::vector<int>	copy(_vector);
	sort(copy.begin(), copy.end());

	int	minSpan = std::numeric_limits<int>::max();
	for (unsigned int i=0; i<_vector.size() - 1; ++i)
		minSpan = std::min(minSpan, std::abs(_vector[i + 1] - _vector[i]));

	return (minSpan);
}

int	Span::longestSpan() const
{
	if (_vector.size() == 1)
		throw std::runtime_error("No Span exist");

	int maxSpan = *std::max_element(_vector.begin(), _vector.end());
	int minSpan = *std::min_element(_vector.begin(), _vector.end());

	return (maxSpan - minSpan);
}

void	Span::print(void)
{
	for (std::vector<int>::iterator iter=_vector.begin(); iter!=_vector.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}
