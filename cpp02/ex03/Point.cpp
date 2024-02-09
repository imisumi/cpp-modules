#include "Point.h"

// constructor
Point::Point()
	: m_x(0), m_y(0)
{
}

Point::Point(const Point& other)
	: m_x(other.m_x), m_y(other.m_y)
{
}

Point::Point(const float x, const float y)
	: m_x(x), m_y(y)
{
}

// destructor
Point::~Point()
{
}


// member functions
float Point::getX(void) const
{
	return m_x.toFloat();
}

float Point::getY(void) const
{
	return m_y.toFloat();
}