#include "RPN.h"

#include <stack>
#include <stdexcept>
#include <iostream>

namespace RPN
{
	float calculate(const std::string& expression)
	{
		if (expression.empty())
		{
			throw std::invalid_argument("Expression is empty.");
		}
		if (expression.find_first_not_of("0123456789 +-*/") != std::string::npos)
		{
			throw std::invalid_argument("Expression contains invalid characters.");
		}
		std::stack<float> stack;

		std::string::size_type pos = 0;
		while (pos < expression.size())
		{
			if (expression[pos] == ' ')
			{
				++pos;
				continue;
			}
			std::string::size_type next_pos = expression.find(' ', pos);
			std::string token = expression.substr(pos, next_pos - pos);
			pos = next_pos;
			if (token == "+" || token == "-" || token == "/" || token == "*")
			{
				if (stack.size() < 2)
				{
					throw std::invalid_argument("Not enough operands for operator: " + token);
				}
				float right = stack.top();
				stack.pop();
				float left = stack.top();
				stack.pop();

				switch (token[0])
				{
					case '+':	stack.push(left + right);	break;
					case '-':	stack.push(left - right);	break;
					case '*':	stack.push(left * right);	break;
					case '/':
						if (right == 0)
						{
							throw std::invalid_argument("Division by zero.");
						}
						stack.push(left / right);
						break;
				}
			}
			else
			{
				try
				{
					stack.push(std::stoi(token));
				}
				catch (const std::invalid_argument& e)
				{
					throw std::invalid_argument("Invalid token: " + token);
				}
			}
		}
		if (stack.size() != 1)
		{
			throw std::invalid_argument("Invalid expression.");
		}
		return stack.top();
	}
}