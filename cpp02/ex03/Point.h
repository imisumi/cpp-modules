#pragma once

#include "Fixed.h"

class Point
{
	public:
	// constructor
		Point();
		Point(const Point& other);
		Point(const float x, const float y);

	// destructor
		~Point();

	// operator overloads
		Point&	operator=(const Point& other) = delete;

	// member functions
		float	getX(void) const;
		float	getY(void) const;

	private:
		Fixed const	m_x;
		Fixed const	m_y;
};

bool	bsp( Point const a, Point const b, Point const c, Point const point);