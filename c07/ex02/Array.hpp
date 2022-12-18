#ifndef __ARRAY_H__
# define __ARRAY_H__

# include <iostream>
# include <exception>


template <typename T>
class Array
{
private:
	T*				_arr;
	unsigned int	_length;
public:

	Array(void);
	Array(const unsigned int n);
	Array(const Array& a);
	virtual ~Array();

	Array&	operator=(const Array& rhs);
	T&		operator[](const unsigned index) const;

	unsigned int	size(void) const;
};



template <typename T>
Array<T>::Array(void):
	_arr(new T[0]),
	_length(0)
{}

template <typename T>
Array<T>::Array(const unsigned int n):
	_arr(new T[n]),
	_length(n)
{}

template <typename T>
Array<T>::Array(const Array& a):
	_arr(new T[a.size()]),
	_length(a.size())
{
	for (unsigned int i=0; i<size(); ++i)
		_arr[i] = a._arr[i];
}

template <typename T>
Array<T>::~Array(void)
{
	delete[] _arr;
}

template <typename T>
Array<T>& Array<T>::operator=(const Array& rhs)
{
	if (this == &rhs)
		return (*this);
	delete[] _arr;
	const_cast<unsigned int&>(_length) = rhs.size();
	_arr = new T[rhs.size()];
	for (unsigned int i = 0; i < rhs.size(); i++)
		_arr[i] = rhs._arr[i];
	return (*this);
}

template <typename T>
T&  Array<T>::operator[](const unsigned index) const
{
	if (_length <= index)
		throw std::out_of_range("Array out of range");
	return (_arr[index]);
}

template <typename T>
unsigned int	Array<T>::size(void) const
{
	return (_length);
}

#endif
