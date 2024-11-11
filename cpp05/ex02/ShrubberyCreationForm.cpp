#include "ShrubberyCreationForm.h"

#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(const std::string& target)
	: AForm("ShrubberyCreationForm", 145, 137), m_Target(target)
{
}

const std::string& ShrubberyCreationForm::getTarget() const
{
	return m_Target;
}

void ShrubberyCreationForm::execute(const Bureaucrat& executor) const
{
	validateExecution(executor);
	std::ofstream file(m_Target + "_shrubbery");

	if (!file.is_open())
	{
		std::cerr << "Failed to open file" << std::endl;
		return;
	}

	file << "       _-_\n"
			"    /~~   ~~\\\n"
			" /~~         ~~\\\n"
			"{               }\n"
			" \\  _-     -_  /\n"
			"   ~  \\\\ //  ~\n"
			"_- -   | | _- _\n"
			"  _ -  | |   -_\n"
			"      // \\\\";

	file.close();
}