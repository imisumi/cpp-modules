#pragma once

#include <iostream>
#include <utility>

// #include "Bureaucrat.h"
#define MAX_GRADE 1
#define MIN_GRADE 150

class Bureaucrat;

class Form
{
public:
	// Default constructor
	Form() = delete;

	// Copy constructor
	Form(const Form&) = default;

	// Copy assignment operator
	Form& operator=(const Form&) = delete;

	// Move constructor
	Form(Form&&) noexcept = default;

	// Move assignment operator
	Form& operator=(Form&&) noexcept = delete;

	// Destructor
	~Form() = default;

	// Custom constructor
	Form(const std::string& name, int signGrade, int execGrade);


	const std::string& getName() const;
	int getSignGrade() const;
	int getExecGrade() const;
	bool isSigned() const;
	void beSigned(const Bureaucrat& bureaucrat);

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
	const std::string m_Name;
	const int m_SignGrade;
	const int m_ExecGrade;
	bool m_IsSigned = false;
};

std::ostream&	operator<<(std::ostream &o, const Form& form);