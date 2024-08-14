#pragma once
#include <iostream>
#include "GeometricObject.h"
#include "stdx.h"

class Circle2D : public GeometricObject
{
private:
	double		radius;

public:
	Circle2D() : radius(1), GeometricObject(0, 0) { }
	Circle2D(double x, double y, double r) : GeometricObject(x, y), radius(r) { }
	~Circle2D() { };

public:
	double		getRadius()		{ return radius; };
	
	double		getArea();
	double		getPerimeter();
	bool		contains(const double px, const double py) const;
	bool		contains(const Circle2D& circle);
	bool		overlaps(const Circle2D& circle) const;

	double		getDistance(const double px, const double py) const;

	friend std::ostream& operator<<(std::ostream& os, const Circle2D& r);
};