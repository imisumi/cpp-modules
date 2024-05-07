

#include "Fixed.h"

// default constructor
Fixed::Fixed()
	: m_fixedPoint(0)
{
	std::cout << GREEN << "Default constructor called" << RESET;
}

// copy constructor
Fixed::Fixed(const Fixed &other)
	: m_fixedPoint(other.getRawBits())
{
	std::cout << BLUE << "Copy constructor called" << RESET;
}

/* 10 << 8
000 1010 = 10
0000 1010 << 8 = 1010 0000 0000 = 2560
*/
Fixed::Fixed(const int value)
	: m_fixedPoint(value << m_bits)
{
	std::cout << CYAN << "Int constructor called" << RESET;
}

/*10.5 * (1 << 8)
1 << 8 = 0000 0001
0000 0001 << 8 = 1 0000 0000 = 256
10.5 * 256 = 2688
*/
Fixed::Fixed(const float value)
	: m_fixedPoint(roundf(value * (1 << m_bits)))
{
	std::cout << CYAN << "Float constructor called" << RESET;
}

// destructor
Fixed::~Fixed()
{
	std::cout << RED << "Destructor called" << RESET;
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
	return m_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	m_fixedPoint = raw;
}

/* 2560 >> 8
1010 0000 0000 >> 8 = 0000 1010 = 10
*/
int Fixed::toInt(void) const
{
	return m_fixedPoint >> m_bits;
}

/* 2688 / (1 << 8)
0000 0001 << 8 = 0000 0001 0000 0000 = 256
2688 / 256 = 10.5
*/
float Fixed::toFloat(void) const
{
	return (float)m_fixedPoint / (1 << m_bits);
}

// overload << operator
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

