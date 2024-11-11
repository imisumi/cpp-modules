#pragma once

#include <iostream>
#include <utility>

#include "AForm.h"

class ShrubberyCreationForm : public AForm
{
public:
	// Default constructor
	ShrubberyCreationForm() = delete;

	// Copy constructor
	ShrubberyCreationForm(const ShrubberyCreationForm&) = default;

	// Copy assignment operator
	ShrubberyCreationForm& operator=(const ShrubberyCreationForm&) = default;

	// Move constructor
	ShrubberyCreationForm(ShrubberyCreationForm&&) noexcept = default;

	// Move assignment operator
	ShrubberyCreationForm& operator=(ShrubberyCreationForm&&) noexcept = default;

	// Destructor
	virtual ~ShrubberyCreationForm() override = default;

	// Custom constructor
	ShrubberyCreationForm(const std::string& target);

	const std::string& getTarget() const;
	virtual void execute(const Bureaucrat& executor) const override;

private:
	const std::string m_Target;
};
