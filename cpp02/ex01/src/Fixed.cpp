

#include "Fixed.h"

Fixed::Fixed()
	: m_fixedPoint(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &other)
	: m_fixedPoint(other.m_fixedPoint)
{
	std::cout << "Copy constructor called" << std::endl;
}

/* 10 << 8
000 1010 = 10
0000 1010 << 8 = 1010 0000 0000 = 2560
*/
Fixed::Fixed(const int value)
	: m_fixedPoint(value << m_bits)
{
	std::cout << "Int constructor called" << std::endl;
}

/*10.5 * (1 << 8)
1 << 8 = 0000 0001
0000 0001 << 8 = 1 0000 0000 = 256
10.5 * 256 = 2688
*/
Fixed::Fixed(const float value)
	: m_fixedPoint(roundf(value * (1 << m_bits)))
{
	std::cout << "Float constructor called" << std::endl;
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed&	Fixed::operator=(const Fixed &other)
{
	std::cout << "Copy assignment operator called" << std::endl;
	if (this != &other)
		this->m_fixedPoint = other.m_fixedPoint;
	return *this;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return m_fixedPoint;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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

std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}

