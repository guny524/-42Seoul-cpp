#pragma once
#ifndef __SPAN_H__
# define __SPAN_H__

#include <vector>
#include <exception>


class	Span
{
private:
	unsigned int		_N;
	std::vector<int>	_vector;

	Span(void);

public:
	Span(const unsigned int& N);
	Span(const Span& span);
	~Span();

	Span&	operator=(const Span& span);

	void	addNumber(const int& num);
	int		shortestSpan() const;
	int		longestSpan() const;

	void	print(void);

	template <typename T>
	void	fill(const T& begin, const T& end)
	{
		if (end - begin > _N)
			throw std::runtime_error("iter too big");
		for (T iter=begin; iter!=end; ++iter)
			addNumber(*iter);
	}
};

#endif
