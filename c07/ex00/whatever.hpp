#pragma once
#ifndef __WHATEVER_H__
# define __WHATEVER_H__


template<typename T>
void	swap(T& l ,T& r)
{
	T	tmp;

	tmp = l;
	l = r;
	r = tmp;
}

template<typename T>
T&	min(T& l, T& r)
{
	if (l < r)
		return (l);
	else
		return (r);
}

template<typename T>
const T&	min(const T& l, const T& r)
{
	if (l < r)
		return (l);
	else
		return (r);
}

template<typename T>
T&	max(T& l, T& r)
{
	if (l > r)
		return (l);
	else
		return (r);
}

template<typename T>
const T&	max(const T& l, const T& r)
{
	if (l > r)
		return (l);
	else
		return (r);
}

#endif

// // TODO remove
// #include <iostream>
// class Awesome
// {
// private:
// 	int _n;

// public:
// 	Awesome(void): _n(0) {}
// 	Awesome(int n): _n(n) {}
// 	Awesome&	operator=(Awesome& a) { _n = a._n; return *this; }
// 	bool		operator==(const Awesome& rhs) const { return (this->_n == rhs._n); }
// 	bool		operator!=(const Awesome& rhs) const { return (this->_n != rhs._n); }
// 	bool		operator>(const Awesome& rhs) const { return (this->_n > rhs._n); }
// 	bool		operator<(const Awesome& rhs) const { return (this->_n < rhs._n); }
// 	bool		operator>=(const Awesome& rhs) const { return (this->_n >= rhs._n); }
// 	bool		operator<=(const Awesome& rhs) const { return (this->_n <= rhs._n); }

// 	int			get_n() const { return _n; }
// };

// std::ostream&	operator<<(std::ostream& o, const Awesome& a) { o << a.get_n(); return o; }
