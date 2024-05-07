

#include "Fixed.h"

// constructor

Fixed::Fixed()
	: m_fixedPoint(0)
{
}

Fixed::Fixed(const Fixed &other)
	: m_fixedPoint(other.m_fixedPoint)
{
}

/* 10 << 8
000 1010 = 10
0000 1010 << 8 = 1010 0000 0000 = 2560
*/
Fixed::Fixed(const int value)
	: m_fixedPoint(value << m_bits)
{
}

/*10.5 * (1 << 8)
1 << 8 = 0000 0001
0000 0001 << 8 = 1 0000 0000 = 256
10.5 * 256 = 2688
*/
Fixed::Fixed(const float value)
	: m_fixedPoint(roundf(value * (1 << m_bits)))
{
}

// destructor
Fixed::~Fixed()
{
}

// operator overloads
Fixed&	Fixed::operator=(const Fixed &other)
{
	if (this == &other)
		return *this;
	m_fixedPoint = other.getRawBits();
	return *this;
}

float Fixed::operator*(const Fixed& other) const
{
	return toFloat() * other.toFloat();
}

float Fixed::operator+(const Fixed& other) const
{
	return toFloat() + other.toFloat();
}

float Fixed::operator-(const Fixed& other) const
{
	return toFloat() - other.toFloat();
}

float Fixed::operator/(const Fixed& other) const
{
	if (other.toFloat() == 0)
	{
		std::cerr << "Error: division by zero" << std::endl;
		return 0;
	}
	return toFloat() / other.toFloat();
}

bool	Fixed::operator>(const Fixed& other) const
{
	return m_fixedPoint > other.m_fixedPoint;
}

bool	Fixed::operator<(const Fixed& other) const
{
	return m_fixedPoint < other.m_fixedPoint;
}

bool	Fixed::operator>=(const Fixed& other) const
{
	return m_fixedPoint >= other.m_fixedPoint;
}

bool	Fixed::operator<=(const Fixed& other) const
{
	return m_fixedPoint <= other.m_fixedPoint;
}

bool	Fixed::operator==(const Fixed& other) const
{
	return m_fixedPoint == other.m_fixedPoint;
}

bool	Fixed::operator!=(const Fixed& other) const
{
	return m_fixedPoint != other.m_fixedPoint;
}

Fixed&	Fixed::operator++(void) // Pre-increment operator
{
	m_fixedPoint++;
	return *this;
}

Fixed	Fixed::operator++(int) // Post-increment operator
{
	Fixed tmp(*this);
	++m_fixedPoint;
	return tmp;
}

Fixed&	Fixed::operator--(void)
{
	m_fixedPoint--;
	return *this;
}

Fixed	Fixed::operator--(int)
{
	Fixed tmp(*this);
	--m_fixedPoint;
	return tmp;
}

// member functions

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

// static member functions
Fixed&	Fixed::min(Fixed &first, Fixed &second)
{
	return (first.m_fixedPoint <= second.m_fixedPoint) ? first : second;

}

Fixed&	Fixed::max(Fixed &first, Fixed &second)
{
	return (first.m_fixedPoint >= second.m_fixedPoint) ? first : second;
}

const Fixed&	Fixed::min(Fixed const &first, Fixed const &second)
{
	return (first.m_fixedPoint <= second.m_fixedPoint) ? first : second;
}

const Fixed&	Fixed::max(Fixed const &first, const Fixed &second)
{
	return (first.m_fixedPoint >= second.m_fixedPoint) ? first : second;
}

// non-member functions
std::ostream& operator<<(std::ostream &out, const Fixed &fixed)
{
	out << fixed.toFloat();
	return out;
}
