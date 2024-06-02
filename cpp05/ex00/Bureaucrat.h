#pragma once

#include <iostream>
#include <utility>

// #define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(msg) std::cout << msg << std::endl;
#else
    #define DEBUG_PRINT(msg)
#endif

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

	// Move constructor (noexcept if all member-wise moves are noexcept)
	Bureaucrat(Bureaucrat&&) noexcept = default;

	// Move assignment operator (noexcept if all member-wise moves are noexcept)
	Bureaucrat& operator=(Bureaucrat&&) noexcept = default;

	// Destructor
	~Bureaucrat() = default;

	Bureaucrat(const std::string& name, int grade);

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

	const std::string& getName() const;
	int getGrade() const;

	void incrementGrade(int amount = 1);
	void decrementGrade(int amount = 1);

private:
	std::string m_Name{};
	int m_Grade{};
};

std::ostream&	operator<<(std::ostream &o, const Bureaucrat& bureaucrat);
