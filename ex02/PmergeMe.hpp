#pragma once

#include <cstdlib>
#include <climits>
#include <sys/time.h>
#include <iostream>
#include <sstream>
#include <vector>
#include <list>
#include <algorithm>
#include <stdexcept>

class	PmergeMe
{
	private:
		PmergeMe(const PmergeMe &src);
		void	operator=(const PmergeMe &src);
		std::string		ValidInput;
		std::vector<int>	SortedVector;
	//	std::list<int>		SortedList;
	public:
		PmergeMe();
		~PmergeMe();
		void		checkInput(const std::string &input);
		void		solve(int argc, char **argv);
		void		FordJohnsonSort(std::vector<int> &vect);
//		void		FordJohnsonSort(std::list<int> list);
};
