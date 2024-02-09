

#pragma once
#include <iostream>
#include <cmath>
#include <limits>

// template to add float + int
template <typename T>
T add(T a, T b)
{
	return a + b;
}

class Fixed
{
	public:
	// constructor
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
	// destructor
		~Fixed();
	// operator overloads
		Fixed&	operator=(const Fixed& other);

		float	operator*(const Fixed& other) const;
		float	operator+(const Fixed& other) const;
		float	operator-(const Fixed& other) const;
		float	operator/(const Fixed& other) const;

		bool	operator>(const Fixed& other) const;
		bool	operator<(const Fixed& other) const;
		bool	operator>=(const Fixed& other) const;
		bool	operator<=(const Fixed& other) const;
		bool	operator==(const Fixed& other) const;
		bool	operator!=(const Fixed& other) const;

		Fixed&	operator++(void);
		Fixed	operator++(int);
		Fixed&	operator--(void);
		Fixed	operator--(int);

	// member functions
		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;

	// static member functions -- member function of the class, not of the object so no "this->"
		static Fixed&	min(Fixed &first, Fixed &second);
		static Fixed&	max(Fixed &first, Fixed &second);
		static const Fixed&	min(Fixed const &first, Fixed const &second);
		static const Fixed&	max(Fixed const &first, const Fixed &second);

	private:
		int					m_fixedPoint;
		static const int	m_bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);

