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
		std::cout << "Tu resultado essss......   " << stack.getResult() << std::endl;
	} catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}

	try {
		std::stack<int>	s;
		s.push(4);
		s.pop();
		if (!(s.top()))
			std::cout << "mierda" << std::endl;

	}catch (...) {
		std::cout << "LLEGO" << std::endl;
	}
	return 0;
}
