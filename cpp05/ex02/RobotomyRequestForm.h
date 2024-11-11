#pragma once

#include <iostream>
#include <utility>

#include "AForm.h"

class RobotomyRequestForm : public AForm
{
public:
	// Default constructor
	RobotomyRequestForm() = delete;

	// Copy constructor
	RobotomyRequestForm(const RobotomyRequestForm&) = default;

	// Copy assignment operator
	RobotomyRequestForm& operator=(const RobotomyRequestForm&) = default;

	// Move constructor
	RobotomyRequestForm(RobotomyRequestForm&&) noexcept = default;

	// Move assignment operator
	RobotomyRequestForm& operator=(RobotomyRequestForm&&) noexcept = default;

	// Destructor
	virtual ~RobotomyRequestForm() override = default;

	// Custom constructor
	RobotomyRequestForm(const std::string& target);

	const std::string& getTarget() const;
	virtual void execute(const Bureaucrat& executor) const override;

private:
	const std::string m_Target;
};
