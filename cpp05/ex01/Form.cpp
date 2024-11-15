#include "Form.h"
#include "Bureaucrat.h"

Form::Form(const std::string& name, int signGrade, int execGrade)
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

const char* Form::GradeTooHighException::what() const noexcept
{
	return "Form: Grade is too high";
}

const char* Form::GradeTooLowException::what() const noexcept
{
	return "Form: Grade is too low";
}

const std::string& Form::getName() const
{
	return m_Name;
}

int Form::getSignGrade() const
{
	return m_SignGrade;
}

int Form::getExecGrade() const
{
	return m_ExecGrade;
}

bool Form::isSigned() const
{
	return m_IsSigned;
}

void Form::beSigned(const Bureaucrat& bureaucrat)
{
	if (bureaucrat.getGrade() > m_SignGrade)
	{
		throw GradeTooLowException();
	}
	m_IsSigned = true;
}

std::ostream&	operator<<(std::ostream &out, const Form& form)
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