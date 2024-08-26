#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {(void)src;}

void	PmergeMe::operator=(const PmergeMe &src) {(void)src;}

void	PmergeMe::checkInput(const std::string &input)
{
	std::stringstream	easyCut(input);
	double			token;

	for(unsigned int i = 0; i < input.length(); ++i)
		if (!std::isspace(input[i]) && !std::isdigit(input[i]) && input[i] != '+')
			throw std::invalid_argument("Error: Only positive integers are accepted.");
	while (easyCut >> token)
	{
		if (token > INT_MAX)
			throw std::overflow_error("Error: Too large number.");
		SortedVector.push_back(static_cast<int>(token));
		SortedList.push_back(static_cast<int>(token));
	}
}

void	PmergeMe::FordJohnsonSort(std::vector<int> &vect)
{
	if (vect.size() == 1)
		return ;
	if (vect.size() == 2)
	{
		if (*(vect.begin()) > *(vect.begin() + 1))
			std::iter_swap(vect.begin(), vect.begin() + 1);
		return ;
	}

	size_t	mid = vect.size() / 2;
	std::vector<int>	leftHalf(vect.begin(), vect.begin() + mid);
	std::vector<int>	rightHalf(vect.begin() + mid, vect.end());
	
	FordJohnsonSort(leftHalf);
	FordJohnsonSort(rightHalf);
	vect.resize(leftHalf.size() + rightHalf.size());
	std::merge(leftHalf.begin(), leftHalf.end(), \
			rightHalf.begin(), rightHalf.end(), vect.begin());
}

void	PmergeMe::FordJohnsonSort(std::list<int> &list)
{
	if (list.size() == 1)
		return ;
	if (list.size() == 2)
	{
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator next = it;
		++next;
		if (*it > *next)
			std::iter_swap(it, next);
		return ;
	}
	
	size_t	mid = list.size() / 2;
	std::list<int>::iterator	it = list.begin();
	
	std::advance(it, mid);
	
	std::list<int>	leftList(list.begin(), it);
	std::list<int>	rightList(it, list.end());
	
	FordJohnsonSort(leftList);
	FordJohnsonSort(rightList);
	list.clear();
	std::merge(leftList.begin(), leftList.end(), \
			rightList.begin(), rightList.end(), std::back_inserter(list));
}

void	PmergeMe::printList() const
{
	std::list<int>::const_iterator it = SortedList.begin();
	unsigned int i = 0;
	for (;it != SortedList.end() && i < 6; ++it, ++i)
		std::cout << " " << *it;
	SortedList.size() > 5 ? std::cout << " [...]" << std::endl : std::cout << std::endl;
}

void	PmergeMe::printVect() const
{
	for (unsigned int i = 0; i < SortedVector.size() && i < 6; ++i)
		std::cout << " " << SortedVector[i];
	SortedVector.size() > 5 ? std::cout << " [...]" << std::endl : std::cout << std::endl;
}

//	for (std::list<int>::iterator it = SortedList.begin(); it != SortedList.end(); ++it)
//		std::cout << "Content list -> " << *it << std::endl;
//	for (unsigned int i = 0; i < SortedVector.size(); ++i)
//		std::cout << "Sorted -> " << SortedVector[i] << std::endl;

void	PmergeMe::solve(int argc, char **argv)
{
	times[0] = 0, times[1] = 0, times[2] = 0;
	try {
		struct timeval check, checkEnd;
		gettimeofday(&check, NULL);
		for (int i = 1; i < argc; ++i)
			checkInput(argv[i]);
		gettimeofday(&checkEnd, NULL);
		times[0] = (checkEnd.tv_sec - check.tv_sec) * 1000000 + (checkEnd.tv_usec - check.tv_usec);
		std::cout << "Time to check valid parameters " << times[0] << " us." << std::endl;
		std::cout << "List before:	";
		printList();
		std::cout << "Vector before:	";
		printVect();
		struct timeval startV, endV, startL, endL;
		gettimeofday(&startV, NULL);
		FordJohnsonSort(SortedVector);
		gettimeofday(&endV, NULL);
		times[1] = (endV.tv_sec - startV.tv_sec) * 1000000 + (endV.tv_usec - startV.tv_usec);
		gettimeofday(&startL, NULL);
		FordJohnsonSort(SortedList);
		gettimeofday(&endL, NULL);
		times[2] = (endL.tv_sec - startL.tv_sec) * 1000000 + (endL.tv_usec - startL.tv_usec);
		std::cout << "List after:	";
		printList();
		std::cout << "Vector after:	";
		printVect();
		std::cout << "Time to sort a range of "
			<< SortedVector.size() << " elements with std::vector<int>:	" << times[1] << " us." << std::endl;
		
		std::cout << "Time to sort a range of "	<< SortedList.size() << " elements with std::list<int>:	" << times[2] << " us." << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}



