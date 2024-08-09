#pragma once
#include <iostream>
#include "stdx.h"

class Circle2D
{
private:
	Point		point;
	double		radius;

public:
	Circle2D();
	Circle2D(double x, double y, double r);
	~Circle2D();

public:
	Point		getPoint()		{ return point; };
	double		getRadius()		{ return radius; };
	
	double		getArea();
	double		getPerimeter();
	bool		isContains(Point p) const;
	bool		isContains(const Circle2D& circle) const;
	bool		isOverlaps(const Circle2D& circle) const;

	double		getDistance(const Point& p) const;

	friend std::ostream& operator<<(std::ostream& os, const Circle2D& r);
};