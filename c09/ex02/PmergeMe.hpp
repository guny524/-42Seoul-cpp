#pragma once
#ifndef __PmergeMe_HPP__
#define __PmergeMe_HPP__

#include <string>
#include <vector>
#include <list>


class PmergeMe
{
private:
	size_t				_chunk_size;
	double				_time_vector;
	double				_time_list;
	std::vector<int>	_vector_ori;
	std::list<int>		_list_ori;
	std::vector<int>	_vector;
	std::list<int>		_list;

	PmergeMe(void);

	void				print_vector(const std::vector<int> v);
	void				print_list(const std::list<int> v);
	void				print_time(void);
	std::vector<int>	copy_vector(const int argc, const char **argv);
	std::list<int>		copy_list(const int argc, const char **argv);
	std::vector<int>	insertion_vector(std::vector<int> v);
	std::list<int>		insertion_list(std::list<int> l);
	std::vector<int>	merge_vector(std::vector<int> v);
	std::list<int>		merge_list(std::list<int> l);

public:
	PmergeMe(const int argc, const char **argv);
	PmergeMe(const PmergeMe& p);
	~PmergeMe();

	PmergeMe&	operator=(const PmergeMe& other);
};

#endif
