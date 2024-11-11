#include "AForm.h"
#include "Bureaucrat.h"

AForm::AForm(const std::string& name, int signGrade, int execGrade)
	: m_Name(name), m_SignGrade(signGrade), m_ExecGrade(execGrade)
{
	if (signGrade < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	else if (signGrade > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
	if (execGrade < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	else if (execGrade > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
}

const char* AForm::GradeTooHighException::what() const noexcept
{
	return "Form: Grade is too high";
}

const char* AForm::GradeTooLowException::what() const noexcept
{
	return "Form: Grade is too low";
}

const char* AForm::FormNotSignedException::what() const noexcept
{
	return "Form: Form is not signed";
}

const std::string& AForm::getName() const
{
	return m_Name;
}

int AForm::getSignGrade() const
{
	return m_SignGrade;
}

int AForm::getExecGrade() const
{
	return m_ExecGrade;
}

bool AForm::isSigned() const
{
	return m_IsSigned;
}

void AForm::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_SignGrade)
	{
		throw GradeTooLowException();
	}
	m_IsSigned = true;
}

void AForm::validateExecution(const Bureaucrat& executor) const
{
	if (!m_IsSigned)
	{
		throw FormNotSignedException();
	}
	if (executor.getGrade() > m_ExecGrade)
	{
		throw GradeTooLowException();
	}
}

std::ostream&	operator<<(std::ostream &out, const AForm& form)
{
	if (form.isSigned())
	{
		out << "Form " << form.getName() << ""<< ", is signed" << ", required a grade of " << form.getSignGrade() << " to sign and a grade of " << form.getExecGrade() << " to execute";
	}
	else
	{
		out << "Form " << form.getName() << ""<< ", has not been signed" << ", requires a grade of " << form.getSignGrade() << " to sign and a grade of " << form.getExecGrade() << " to execute";
	}
	// out << ", requires a grade of " << form.getSignGrade() << " to sign and a grade of " << form.getExecGrade() << " to execute";
	return out;
}