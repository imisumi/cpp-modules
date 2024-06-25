#pragma once

#include <iostream>
#include <utility>

// #define DEBUG

#ifdef DEBUG
    #define DEBUG_PRINT(msg) std::cout << msg << std::endl;
#else
    #define DEBUG_PRINT(msg)
#endif

class Form
{
public:
	// Default constructor
	Form() = default;

	// Copy constructor
	Form(const Form&) = default;

	// Copy assignment operator
	Form& operator=(const Form&) = default;

	// Move constructor
	Form(Form&&) noexcept = default;

	// Move assignment operator
	Form& operator=(Form&&) noexcept = default;

	// Destructor
	~Form() = default;

private:
	const std::string m_Name;
	const int m_SignGrade;
	const int m_ExecGrade;
	bool m_IsSigned = false;
};
