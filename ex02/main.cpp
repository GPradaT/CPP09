#include "PmergeMe.hpp"

int	main(int argc, char **argv)
{
	PmergeMe	merger;

	try {
		if (argc != 2)
			throw std::logic_error("Error: Only 1 string as argument.");
		std::string input(argv[1]);
		merger.checkInput(input);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	return 0;
}
