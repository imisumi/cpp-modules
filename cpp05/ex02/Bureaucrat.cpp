#include "Bureaucrat.h"

Bureaucrat::Bureaucrat(const std::string& name, int grade)
	: m_Name(name)
{
	if (grade < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	else if (grade > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
	m_Grade = grade;
}

const std::string& Bureaucrat::getName() const
{
	return m_Name;
}

int Bureaucrat::getGrade() const
{
	return m_Grade;
}

const char* Bureaucrat::GradeTooHighException::what() const noexcept
{
	return "Grade is too high";
}

const char* Bureaucrat::GradeTooLowException::what() const noexcept
{
	return "Grade is too low";
}

void Bureaucrat::incrementGrade(int amount)
{
	if ((m_Grade - amount) < MAX_GRADE)
	{
		throw GradeTooHighException();
	}
	m_Grade -= amount;
}

void Bureaucrat::decrementGrade(int amount)
{
	if ((m_Grade + amount) > MIN_GRADE)
	{
		throw GradeTooLowException();
	}
	m_Grade += amount;
}

void Bureaucrat::signForm(AForm& form)
{
	try
	{
		form.beSigned(*this);
		std::cout << m_Name << " signed " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << m_Name << "  couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm& form)
{
	try
	{
		form.execute(*this);
		std::cout << m_Name << " executes form: " << form.getName() << std::endl;
	}
	catch (const std::exception& e)
	{
		std::cout << m_Name << " couldn’t execute " << form.getName() << " because " << e.what() << std::endl;
	}
}

std::ostream&	operator<<(std::ostream &out, const Bureaucrat& bureaucrat)
{
	out << "Bureaucrat "<< bureaucrat.getName() << ", has a grade of " << bureaucrat.getGrade();
	return out;
}
