#pragma once
#ifndef __ITER_H__
# define __ITER_H__

# include <cstddef>
# include <iostream>


template <typename T>
void	iter(const T *arr, const size_t length, void (*f)(const T&))
{
	for (size_t i=0; i<length; ++i)
		f(arr[i]);
}

template <typename T>
void	print(const T& t)
{
	std::cout << t << std::endl;
}

// // TODO remove
// #include <iostream>
// class Awesome
// {
// private:
// 	int _n;

// public:
// 	Awesome(void): _n(42) { return; }
// 	int			get() const { return this->_n; }
// };

// std::ostream&	operator<<(std::ostream& o, const Awesome& a) { o << a.get(); return o; }

#endif
