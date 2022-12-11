#include <iostream>

#include "Fixed.hpp"
#include "Point.hpp"


Point::Point(void):
_x(0),
_y(0)
{}

Point::Point(const Point& p):
_x(p._x),
_y(p._y)
{}

Point::Point(const Fixed& x, const Fixed& y):
_x(x),
_y(y)
{}

Point::Point(const float& x, const float& y):
_x(Fixed(x)),
_y(Fixed(y))
{}

Point::~Point()
{}

Fixed	Point::getX(void) const
{
	return (_x);
}

Fixed	Point::getY(void) const
{
	return (_y);
}

Point	Point::operator=(const Point& p)
{
	const_cast<Fixed&>(_x) = p.getX();
	const_cast<Fixed&>(_x) = p.getY();
	return (*this);
}

Point	Point::operator-(const Point& p)
{
	return (Point(getX() - p.getX(), getY() - p.getY()));
}

Fixed	Point::operator*(const Point& p)
{
	return (getX() * p.getY() - getY() * p.getX());
}

std::ostream&	operator<<(std::ostream& out, const Point& p)
{
	out << "x: " << p.getX() << ", " << "y: " << p.getY();
	return (out);
}

Point	operator-(const Point& a, const Point& b)
{
	return (Point(a.getX() - b.getX(), a.getY() - b.getY()));
}

Fixed	operator*(const Point& a, const Point& b)
{
	return (a.getX() * b.getY() - a.getY() * b.getX());
}
