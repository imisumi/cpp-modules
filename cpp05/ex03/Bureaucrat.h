#pragma once

#include <iostream>
#include <utility>

#include "AForm.h"

#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat
{
public:
	// Default constructor
	Bureaucrat() = delete;

	// Copy constructor
	Bureaucrat(const Bureaucrat&) = default;

	// Copy assignment operator
	Bureaucrat& operator=(const Bureaucrat&) = default;

	// Move constructor
	Bureaucrat(Bureaucrat&&) noexcept = default;

	// Move assignment operator
	Bureaucrat& operator=(Bureaucrat&&) noexcept = default;

	// Destructor
	~Bureaucrat() = default;

	// Custom constructor
	Bureaucrat(const std::string& name, int grade);


	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade(int amount = 1);
	void decrementGrade(int amount = 1);

	void signForm(class AForm& form);

	void executeForm(const AForm& form);

private:
	class GradeTooHighException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

	class GradeTooLowException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

private:
	std::string m_Name;
	int m_Grade = 0;
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);
