#pragma once

#include <cstdlib>
#include <climits>
#include <iostream>
#include <sstream>
#include <vector>
#include <stdexcept>

class	PmergeMe
{
	private:
		PmergeMe(const PmergeMe &src);
		void	operator=(const PmergeMe &src);

//		std::vector<int>	SortedVector;
//		std::list<int>		SortedList;
	public:
		PmergeMe();
		~PmergeMe();
		void		checkInput(const std::string &input);
//		void		FordJohnsonSort(std::vector<int> vect);
//		void		FordJohnsonSort(std::list<int> list);

};
