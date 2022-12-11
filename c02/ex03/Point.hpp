#pragma once
#ifndef __POINT_H__
# define __PONT_H__

# include <iostream>
# include "Fixed.hpp"

class Point
{
private:
	const Fixed	_x;
	const Fixed	_y;
public:
	Point(void);
	Point(const Point& p);
	Point(const Fixed& x, const Fixed& y);
	Point(const float& x, const float& y);
	~Point();

	Fixed	getX(void) const;
	Fixed	getY(void) const;

	Point	operator=(const Point& p);
	Point	operator-(const Point& p);
	Fixed	operator*(const Point& p);
};

std::ostream&	operator<<(std::ostream& out, const Point& p);

Point	operator-(const Point& a, const Point& b);
Fixed	operator*(const Point& a, const Point& b);

bool	bsp(Point const a, Point const b, Point const c, Point const point);

#endif
