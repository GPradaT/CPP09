#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	stack;

	try {
		if (argc != 2)
			throw std::logic_error("Error: Input must be 1 string.");
		std::string input = argv[1];
		stack.validInput(input);
		stack.solve(input);
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
