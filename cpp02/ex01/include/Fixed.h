

#pragma once
#include "Constant.h"
#include <iostream>
#include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed& other);
		Fixed(const int value);
		Fixed(const float value);
		~Fixed();

		Fixed&	operator=(const Fixed& other);

		int		getRawBits(void) const;
		void	setRawBits(int const raw);
		int		toInt(void) const;
		float	toFloat(void) const;
	private:
		int					m_fixedPoint;
		static const int	m_bits = 8;
};

std::ostream& operator<<(std::ostream &out, const Fixed &fixed);