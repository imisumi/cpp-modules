#include "RPN.h"
#include <iostream>
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

void runTests()
{
	std::vector<std::string> test_cases = {
		"3 4 +",
		"3 4 + 2 *",
		"3 -4 +",
		"8 9 * 9 -",
		"10 0 /",
		"1 2 * 2 / 2 * 2 4 - +",
		"7 7 * 7 -",
		"5 8 -",
		"3 4 + 2 5 + *",
		"3",
		"1000000 2000000 +",
		"-1 -2 -3 + +",
		"",
		"3 + +",
		"3 4 + b",
		"3 10 /    ",
		"",
		"1 1 1 1 1 + + + +",
	};
	
	for (const auto& expression : test_cases) 
	{
		std::cout << "Evaluating: " << expression << std::endl;
		try 
		{
			float result = RPN::calculate(expression);
			std::cout << "Result: " << result << std::endl;
		} 
		catch (const std::invalid_argument& e) 
		{
			std::cerr << "Error: " << e.what() << std::endl;
		} 
		catch (const std::out_of_range& e) 
		{
			std::cerr << "Error: Out of range: " << e.what() << std::endl;
		} 
		catch (...) 
		{
			std::cerr << "Unknown error occurred." << std::endl;
		}
		std::cout << "-----------------------------" << std::endl;
	}
}

int main(int argc, char* argv[])
{
#ifdef RUN_TESTS
	runTests();
	return 0;
#endif
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " <expression>" << std::endl;
		return 1;
	}
	try
	{
		float result = RPN::calculate(argv[1]);
		std::cout << result << std::endl;
	}
	catch (std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
		return 1;
	}
}
