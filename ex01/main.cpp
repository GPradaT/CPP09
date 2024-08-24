#include "RPN.hpp"

int	main(int argc, char **argv)
{
	RPN	stack;

	try {
		if (argc != 2)
			return -1;
		std::string input = argv[1];
		stack.validInput(input);
//		stack.solve();
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	return 0;
}
