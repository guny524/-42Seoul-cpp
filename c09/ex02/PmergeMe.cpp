#include "PmergeMe.hpp"
#include <iostream>
#include <string>
#include <sstream>
#include <stdexcept>
#include <vector>
#include <list>
#include <iterator>
#include <iomanip>


PmergeMe::PmergeMe(void):
_chunk_size(5),
_time_vector(0),
_time_list(0)
{}

PmergeMe::PmergeMe(const int argc, const char **argv):
_chunk_size(5),
_time_vector(0),
_time_list(0)
{
	std::clock_t start = std::clock();
	_vector_ori = copy_vector(argc, argv);
	_vector = merge_vector(_vector_ori);
	_time_vector = static_cast<double>(std::clock() - start) * (1000.0 / CLOCKS_PER_SEC);

	start = std::clock();
	_list_ori = copy_list(argc, argv);
	_list = merge_list(_list_ori);
	_time_list = static_cast<double>(std::clock() - start) * (1000.0 / CLOCKS_PER_SEC);

	std::cout << "Before:  ";
	print_vector(_vector_ori);
	// print_list(_list_ori); // TODO
	std::cout << "After:   ";
	print_vector(_vector);
	// print_list(_list);
	print_time();
}

PmergeMe::PmergeMe(const PmergeMe& p):
_chunk_size(5),
_time_vector(p._time_vector),
_time_list(p._time_list),
_vector_ori(p._vector_ori),
_list_ori(p._list_ori),
_vector(p._vector),
_list(p._list)
{}

PmergeMe::~PmergeMe()
{
	_vector_ori.clear();
	_list_ori.clear();
	_vector.clear();
	_list.clear();
}

PmergeMe&	PmergeMe::operator=(const PmergeMe& other)
{
	if (this == &other)
		return (*this);
	this->_time_vector = other._time_vector;
	this->_time_list = other._time_list;
	this->_vector_ori = other._vector_ori;
	this->_list_ori = other._list_ori;
	this->_vector = other._vector;
	this->_list = other._list;
	return (*this);
}

void	PmergeMe::print_vector(const std::vector<int> v)
{
	for (std::vector<int>::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

// TODO
void	PmergeMe::print_list(const std::list<int> v)
{
	for (std::list<int>::const_iterator iter=v.begin(); iter!=v.end(); ++iter)
		std::cout << *iter << " ";
	std::cout << std::endl;
}

void	PmergeMe::print_time(void)
{
	std::cout << "Time to process a range of " << _vector.size();
	std::cout << " elements with std::" << "vector" << " : ";
	std::cout << std::fixed << _time_vector << " us" << std::endl;

	std::cout << "Time to process a range of " << _vector.size();
	std::cout << " elements with std::" << "list" << " : ";
	std::cout << std::fixed << _time_list << " us" << std::endl;
}

std::vector<int>	PmergeMe::copy_vector(const int argc, const char **argv)
{
	std::vector<int> ret(argc);
	int	num;

	for (int i=0; i<argc; ++i)
	{
		std::stringstream	num_stream(argv[i]);

		num_stream >> num;
		if (num_stream.fail() || !num_stream.eof())
			throw std::runtime_error("many number in each argv");
		if (num < 0)
		{
			std::ostringstream	num_stream;
			num_stream << num;
			throw std::runtime_error("minus number " + num_stream.str());
		}
		ret[i] = num;
	}
	return ret;
}

std::list<int>		PmergeMe::copy_list(const int argc, const char **argv)
{
	std::list<int> ret;
	int	num;

	for (int i=0; i<argc; ++i)
	{
		std::stringstream	num_stream(argv[i]);

		num_stream >> num;
		if (num_stream.fail() || !num_stream.eof())
			throw std::runtime_error("many number in each argv");
		if (num < 0)
		{
			std::ostringstream	num_stream;
			num_stream << num;
			throw std::runtime_error("minus number " + num_stream.str());
		}
		ret.push_back(num);
	}
	return ret;
}

std::vector<int>	PmergeMe::insertion_vector(std::vector<int> v)
{
	for (size_t i=1; i<v.size(); ++i)
    {
        int key = v[i];
		size_t j;
        for (j=i; j>0; --j)
		{
			if (v[j-1] <= key)
				break;
            v[j] = v[j-1];
		}
        v[j] = key;
    }
    return v;
}

std::list<int> PmergeMe::insertion_list(std::list<int> l)
{

	for (std::list<int>::iterator iter=l.begin(); iter!=l.end(); ++iter)
	{
		std::list<int>::iterator min_iter = iter;
		for (std::list<int>::iterator iter2=iter; iter2!=l.end(); ++iter2)
		{
			if (iter == iter2)
				continue;
			if (*min_iter > *iter2)
				min_iter = iter2;
		}
		// swap
		int tmp = *iter;
		*iter = *min_iter;
		*min_iter = tmp;
	}

    for (std::list<int>::iterator iter = ++(l.begin()); iter != l.end(); ++iter)
    {
        int key = *iter;
        std::list<int>::iterator j = iter;
        std::list<int>::iterator prev_j = j;

        // Move iterator j and prev_j
        if (j != l.begin())
            --prev_j;

        while (j != l.begin() && *prev_j > key)
        {
            *j = *prev_j;
            --j;
            if (j != l.begin())
                --prev_j;
        }
        *j = key;
    }
    return l;
}


std::vector<int>	PmergeMe::merge_vector(std::vector<int> v)
{
	if (v.size() <= _chunk_size)
		return insertion_vector(v);

	// split
	std::vector<int> front = merge_vector(std::vector<int>(v.begin(), v.begin() + v.size()/2));
	std::vector<int> back = merge_vector(std::vector<int>(v.begin() + v.size()/2, v.end()));

	// merge
	std::vector<int>::iterator front_iter = front.begin();
	std::vector<int>::iterator back_iter = back.begin();

	std::vector<int> ret(v.size());
	for (std::vector<int>::iterator iter=ret.begin(); iter!=ret.end(); ++iter)
	{
		if (front_iter == front.end())
		{
			*iter = *back_iter++;
			continue;	
		}
		if (back_iter == back.end())
		{
			*iter = *front_iter++;
			continue;	
		}

		if (*front_iter < *back_iter)
			*iter = *front_iter++;
		else
			*iter = *back_iter++;
	}
	return ret;
}

std::list<int>		PmergeMe::merge_list(std::list<int> l)
{
	if (l.size() <= _chunk_size)
		return insertion_list(l);

	// split
	std::list<int>::iterator begin = l.begin();
	std::advance(begin, l.size()/2);
	std::list<int> back = merge_list(std::list<int>(begin, l.end()));
	// reverse iterator
	std::list<int>::iterator end = l.begin();
	std::advance(end, l.size()/2);
	std::list<int> front = merge_list(std::list<int>(l.begin(), end));

	// merge
	front.merge(back);
	return front;
}
