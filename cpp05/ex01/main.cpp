#include "Bureaucrat.h"

#define RED "\033[31m"
#define RESET "\033[0m\n"

int main()
{
	std::cout << "Testing Form Creation with Invalid Sign Grades\n" << std::endl;

	try
	{
		std::cout << "Attempting to create a form with sign grade 0 (invalid)" << std::endl;
		Form formA("Form_A", 0, 1);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTesting Form Creation with Invalid Execute Grades\n" << std::endl;

	try
	{
		std::cout << "Attempting to create a form with execute grade 0 (invalid)" << std::endl;
		Form formB("Form_B", 1, 0);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to create a form with execute grade 151 (invalid)" << std::endl;
		Form formC("Form_C", 1, 151);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	try
	{
		std::cout << "Attempting to create a form with sign grade 151 (invalid)" << std::endl;
		Form formD("Form_D", 151, 1);
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTesting Form Signing with Sufficient Bureaucrat Grade\n" << std::endl;

	try
	{
		Bureaucrat admin("Administrator", 1);
		Form formE("Form_E", 150, 150);

		std::cout << formE << std::endl;
		admin.signForm(formE);
		std::cout << "After signing: " << formE << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	std::cout << "\nTesting Form Signing with Insufficient Bureaucrat Grade\n" << std::endl;

	try
	{
		Bureaucrat manager("Manager", 2);
		Form formF("Form_F", 1, 1);

		std::cout << formF << std::endl;
		manager.signForm(formF);
		std::cout << "After signing: " << formF << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception: " << e.what() << std::endl;
	}

	return 0;
}