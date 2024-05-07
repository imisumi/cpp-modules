

#include "Fixed.h"

// default constructor
Fixed::Fixed()
	: m_fixedPoint(0)
{
	std::cout << GREEN << "Default constructor called" << RESET;
}

// destructor
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET;
}

// copy constructor
Fixed::Fixed(const Fixed &other)
	: m_fixedPoint(other.getRawBits())
{
	std::cout << BLUE << "Copy constructor called" << RESET;
}

// copy assignment operator
Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << YELLOW << "Copy assignment operator called" << RESET;
	if (this == &other)
		return *this;
	m_fixedPoint = other.getRawBits();
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << MAGENTA << "getRawBits member function called" << RESET;
	return m_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << MAGENTA << "setRawBits member function called" << RESET;
	m_fixedPoint = raw;
}
