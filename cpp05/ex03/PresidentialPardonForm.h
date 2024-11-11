#pragma once

#include <iostream>
#include <utility>

#include "AForm.h"

class PresidentialPardonForm : public AForm
{
public:
	// Default constructor
	PresidentialPardonForm() = delete;

	// Copy constructor
	PresidentialPardonForm(const PresidentialPardonForm&) = default;

	// Copy assignment operator
	PresidentialPardonForm& operator=(const PresidentialPardonForm&) = delete;

	// Move constructor
	PresidentialPardonForm(PresidentialPardonForm&&) noexcept = default;

	// Move assignment operator
	PresidentialPardonForm& operator=(PresidentialPardonForm&&) noexcept = delete;

	// Destructor
	virtual ~PresidentialPardonForm() override = default;

	// Custom constructor
	PresidentialPardonForm(const std::string& target);

	const std::string& getTarget() const;
	virtual void execute(const Bureaucrat& executor) const override;

private:
	const std::string m_Target;
};
