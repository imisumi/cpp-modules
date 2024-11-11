#pragma once

#include <iostream>
#include <utility>

#include "AForm.h"

class Intern
{
public:
	// Default constructor
	Intern() = default;

	// Copy constructor
	Intern(const Intern&) = default;

	// Copy assignment operator
	Intern& operator=(const Intern&) = default;

	// Move constructor
	Intern(Intern&&) noexcept = default;

	// Move assignment operator
	Intern& operator=(Intern&&) noexcept = default;

	// Destructor
	~Intern() = default;

	AForm* makeForm(const std::string& formName, const std::string& target) const;

private:
	[[nodiscard]] AForm* makePresidentialPardonForm(const std::string& target) const;
	[[nodiscard]] AForm* makeRobotomyRequestForm(const std::string& target) const;
	[[nodiscard]] AForm* makeShrubberyCreationForm(const std::string& target) const;
};
