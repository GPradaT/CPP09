#include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(const PmergeMe &src) {(void)src;}

void	PmergeMe::operator=(const PmergeMe &src) {(void)src;}

void	PmergeMe::checkInput(const std::string &input)
{
	std::stringstream	easyCut(input);
	std::string		token;

	for(unsigned int i = 0; i < input.length(); ++i)
		if (!std::isspace(input[i]) && !std::isdigit(input[i]) && input[i] != '+')
			throw std::invalid_argument("Error: Only positive integers are accepted.");
	while (easyCut >> token)
	{
		double	valid = std::strtod(token.c_str(), NULL);
		if (valid < 0 || valid > INT_MAX)
			throw std::overflow_error("Error: overflow INT_MAX");
	}
}

void	FordJohnsonSort()
{

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


