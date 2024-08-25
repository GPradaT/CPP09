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
//		SortedList.push_back(static_cast<int>(valid));
	}
}

/*
	FordJohnsonSort(array A, int n)

	if n == 1
		return;
	if n >= 2
		if A[0] > A[1]
			swap A[0], A[1]
		return;
	=====RECURSIVE PART=====
	int mid = n / 2

	array	leftHalf(0, mid)
	array	rightHalf(mid, n-1)

	FordJohnsonSort(leftHalf, mid)
	FordJohnsonSort(rightHalf, n - mid)
	====FINAL INSERTION=====
	merge(A, leftHalf, rightHalf, mid, n - mid)

	for i from mid+1 to n-1
		key = A[i]
		j == i - 1
		while j >= 0 && A[j] > key
			A[j+1] = A[j]
			j = j - 1
		A[j+1] = key

*/
void	PmergeMe::FordJohnsonSort(std::vector<int> &vect)
{
	if (vect.size() == 1)
		return;
	if (vect.size() == 2)
	{
		if (*(vect.begin()) > *(vect.begin() + 1))
			std::iter_swap(vect.begin(), vect.begin() + 1);
		return;
	}
	size_t	mid = vect.size() / 2;

	std::vector<int>	leftHalf(vect.begin(), vect.begin() + mid);
	std::vector<int>	rightHalf(vect.begin() + mid, vect.end());

	FordJohnsonSort(leftHalf);
	FordJohnsonSort(rightHalf);
	vect.resize(leftHalf.size() + rightHalf.size());
	std::merge(leftHalf.begin(), leftHalf.end(), rightHalf.begin(), rightHalf.end(), vect.begin());
}

void	PmergeMe::solve(int argc, char **argv)
{
	std::string	token;

	try {
		for (int i = 1; i < argc; ++i)
		{
			token = argv[i];
			checkInput(token);
		}
	//	for (unsigned int i = 0; i < SortedVector.size(); ++i)
	//		std::cout << "Unsorted -> " << SortedVector[i] << std::endl;
		struct timeval start, end;
		gettimeofday(&start, NULL);
		FordJohnsonSort(SortedVector);
		gettimeofday(&end, NULL);
		std::cout << "Time to process a range of "<< SortedVector.size() << " elements with std::vector<int>: " << end.tv_usec - start.tv_usec << " us." << std::endl;
	//	for (unsigned int i = 0; i < SortedVector.size(); ++i)
	//		std::cout << "Sorted -> " << SortedVector[i] << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
}



