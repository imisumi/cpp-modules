
#include "Intern.h"
#include "Bureaucrat.h"

#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m\n"

int main()
{
	Intern	intern;
	AForm	*f = nullptr;

	std::cout << CYAN << "Sign and execute the form" << RESET;
	try 
	{
		f = intern.makeForm("shrubbery creation", "28C");

		if (f)
		{
			std::cout << *f << std::endl;

			Bureaucrat	b("Bureaucrat", 1);
			b.signForm(*f);

			b.executeForm(*f);

			std::cout << *f << std::endl;


			delete f;
			f = nullptr;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET;
	}

	std::cout << CYAN << "Sign and execute the form with grade too low" << RESET;
	try 
	{
		f = intern.makeForm("shrubbery creation", "28C");
		if (f)
		{
			std::cout << *f << std::endl;

			Bureaucrat	b("Bureaucrat", 150);
			b.signForm(*f);

			b.executeForm(*f);

			std::cout << *f << std::endl;


			delete f;
			f = nullptr;
		}
	}
	catch (std::exception& e)
	{
		std::cerr << RED << e.what() << RESET;
	}

	std::cout << CYAN << "Presidential pardon form" << RESET;

	f = intern.makeForm("presidential pardon", "28A");
	if (f)
	{
		std::cout << *f << std::endl;
		delete f;
		f = nullptr;
	}


	std::cout << CYAN << "Robotomy request form" << RESET;

	f = intern.makeForm("robotomy request", "28B");
	if (f)
	{
		std::cout << *f << std::endl;
		delete f;
		f = nullptr;
	}


	std::cout << CYAN << "Undefined form" << RESET;

	f = intern.makeForm("undefined", "0U");
	if (f)
	{
		std::cout << *f << std::endl;
		delete f;
		f = nullptr;
	}


	return EXIT_SUCCESS;
}