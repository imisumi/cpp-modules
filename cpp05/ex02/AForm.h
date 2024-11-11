#pragma once

#include <iostream>
#include <utility>

// #include "Bureaucrat.h"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class AForm
{
public:
	// Default constructor
	AForm() = delete;

	// Copy constructor
	AForm(const AForm&) = default;

	// Copy assignment operator
	AForm& operator=(const AForm&) = default;

	// Move constructor
	AForm(AForm&&) noexcept = default;

	// Move assignment operator
	AForm& operator=(AForm&&) noexcept = default;

	// Destructor
	virtual ~AForm() = default;

	// Custom constructor
	AForm(const std::string& name, int signGrade, int execGrade);


	const std::string& getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);
	virtual void execute(const Bureaucrat& executor) const = 0;
	void validateExecution(const Bureaucrat& executor) const;


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

	class FormNotSignedException : public std::exception
	{
	public:
		const char* what() const noexcept override;
	};

private:
	const std::string m_Name;
	const int m_SignGrade;
	const int m_ExecGrade;
	bool m_IsSigned = false;
};

std::ostream&	operator<<(std::ostream &o, const AForm& form);