#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	merger;

	if (argc < 2)
	{
		std::cout << "Error: No arguments." << std::endl;
		return -1;
	}
		merger.solve(argc, argv);

	return 0;
}
