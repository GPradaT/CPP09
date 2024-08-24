#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) {(void)src;}

void	RPN::operator=(const RPN &src) {(void)src;}

void	RPN::validInput(const std::string &input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		const char c = input[i];
		if (!std::isspace(c) && !std::isdigit(c)
			&& (c != '+' && c != '-' && c != '*' && c != '/'))
			throw std::runtime_error("Error: Invalid chars");
	}
}
