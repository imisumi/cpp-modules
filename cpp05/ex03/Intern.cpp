#include "Intern.h"

#include <functional>

#include "PresidentialPardonForm.h"
#include "RobotomyRequestForm.h"
#include "ShrubberyCreationForm.h"

AForm* Intern::makeForm(const std::string& formName, const std::string& target) const
{
	constexpr uint8_t size = 3;

	std::pair<const std::string, std::function<AForm*(const std::string&)>> ads[size] = {
		{"presidential pardon", [this](const std::string& target) { return makePresidentialPardonForm(target); }},
		{"robotomy request", [this](const std::string& target) { return makeRobotomyRequestForm(target); }},
		{"shrubbery creation", [this](const std::string& target) { return makeShrubberyCreationForm(target); }}
	};

	for (uint8_t i = 0; i < size; i++)
	{
		auto& [name, func] = ads[i];
		if (name == formName)
		{
			std::cout << "Intern creates " << formName << " form" << std::endl;
			return func(target);
		}
	}
	std::cout << "Form not found" << std::endl;
	return nullptr;
}

AForm* Intern::makePresidentialPardonForm(const std::string& target) const
{
	return new PresidentialPardonForm(target);
}

AForm* Intern::makeRobotomyRequestForm(const std::string& target) const
{
	return new RobotomyRequestForm(target);
}

AForm* Intern::makeShrubberyCreationForm(const std::string& target) const
{
	return new ShrubberyCreationForm(target);
}
