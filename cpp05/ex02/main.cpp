#include "Bureaucrat.h"
#include "ShrubberyCreationForm.h"
#include "RobotomyRequestForm.h"
#include "PresidentialPardonForm.h"

#define RED "\033[31m"
#define CYAN "\033[36m"
#define RESET "\033[0m\n"

int main()
{
	Bureaucrat		Odin("Odin", 1);
	Bureaucrat		Thor("Thor", 40);
	Bureaucrat		Loki("Loki", 150);

	srand(time(NULL));
	std::cout << "--------------------------------------------------" << std::endl;
	std::cout << CYAN << "Unsigned presidential pardon form" << RESET;
	try
	{
		PresidentialPardonForm from = PresidentialPardonForm("28Z");
		from.execute(Odin);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << CYAN << "\nSign and execute a presidential pardon form" << RESET;
	try
	{
		PresidentialPardonForm form = PresidentialPardonForm("28A");
		form.beSigned(Odin);
		form.execute(Odin);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << CYAN << "Unsigned robotomy request form" << RESET;
	try
	{
		RobotomyRequestForm form = RobotomyRequestForm("28Y");
		form.execute(Odin);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << CYAN << "\nLet's sign and execute robotomy request form with different people" << RESET;
	try
	{
		RobotomyRequestForm form = RobotomyRequestForm("28B");
		Odin.signForm(form);
		std::cout << std::endl;
		for (int i = 0; i < 5; i++)
		{
			Thor.executeForm(form);
			std::cout << std::endl;
		}
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "--------------------------------------------------" << std::endl;

	std::cout << CYAN << "Let's execute shrubbery creation form with unauthorized bureaucrat" << RESET;
	try
	{
		ShrubberyCreationForm form = ShrubberyCreationForm("28C");
		Odin.signForm(form);
		Thor.executeForm(form);
		Loki.executeForm(form);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}
	return 0;
}