#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	merger;

	if (argc > 1)
		merger.solve(argc, argv);
	return 0;
}
