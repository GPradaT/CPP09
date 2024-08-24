#include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(const RPN &src) {(void)src;}

void	RPN::operator=(const RPN &src) {(void)src;}

bool	RPN::isOperator(char c) const
{
	return (c == '+' || c == '-' || c == '*' || c == '/');
}

void	RPN::validInput(const std::string &input)
{
	for (unsigned int i = 0; i < input.length(); ++i)
	{
		const char c = input[i];
		if (!std::isspace(c) && !std::isdigit(c) && !isOperator(c)) 
			throw std::logic_error("Error: Invalid chars.");
	}
}

void	RPN::solve(const std::string &input)
{
	std::stringstream	easyCut(input);
	std::string		token;

	while (easyCut >> token)
	{
		if (token.length() > 1)
			throw std::logic_error("Error: Too long parameter.");
		int a, b;
		if (std::isdigit(token[0]))
			operands.push(std::atoi(token.c_str()));
		else if (isOperator(token[0]))
		{
			if (operands.empty())
				throw std::logic_error("Error: empty stack");
			int operand2 = operands.top();
			operands.pop();
			if (operands.empty())
				throw std::logic_error("Error: empty stack");
			int operand1 = operands.top();
			operands.pop();
			result = calculator(operand1, token[0], operand2);
			operands.push(result);
		}

		std::cout << "Token:	    "  << token << std::endl;
		std::cout << "Token length: " << token.length() << std::endl;
	}
}

/*
 * la intencion de solucion que tengo es algo parecido a esto:
 *
 * mirar acerca de reference top() para comprobar que no de segfault
 * try {
 * 	if (isnum(token))
 * 		stack.push(atoi(token))
 *	if (is_operand(token))
 *		operand2 = stack.top();
 *		operand1 = stack.top();
 *		result = calculator(operand1, operator, operand2);
 *		stack.push(result);
 *} catch (elerror) {
 	printar error etc;
 }
 *
 * */
