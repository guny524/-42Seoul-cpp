#pragma once
#ifndef __EASYFIND_H__
#define __EASYFIND_H__

#include <algorithm>


template <typename T>
typename T::iterator	easyfind(T& container, const int val)
{
	return (std::find(container.begin(), container.end(), val));
}

#endif
