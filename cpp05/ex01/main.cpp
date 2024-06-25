#include "Bureaucrat.h"

#define RED "\033[31m"
#define RESET "\033[0m\n"

auto main() -> int
{
	{
		Bureaucrat b1("John", 1);
		Bureaucrat b2 = Bureaucrat("Jane", 150);
		std::cout << b1 << std::endl;
		std::cout << b2 << std::endl;
		try
		{
			b1.incrementGrade(1);
		}
		catch(const std::exception& e)
		{
			// std::cerr << e.what() << '\n';
			std::cerr << RED << "Failed to increment b1: " << e.what() << RESET;
		}
	}

	{
		try
		{
			Bureaucrat b1("John", 151);
		}
		catch(const std::exception& e)
		{
			std::cerr << RED << "Failed to construct b1: " << e.what() << RESET;
		}
	}
	

	return (EXIT_SUCCESS);
}
