#pragma once
#include "Circle2D.h"
#include "Rectangle2D.h"

class MyPoint
{
private:
	double		x;
	double		y;

public:
	MyPoint();
	MyPoint(double tx, double ty);
	~MyPoint();

public:
	double		getX()	{ return x; };
	double		getY()	{ return y; };
	double		distance(double tx, double ty);

	friend bool contains(const Circle2D& circle, const MyPoint& point);
	friend bool contains(const Rectangle2D& rect, const MyPoint& point);

	friend std::ostream& operator<<(std::ostream& os, const MyPoint& p);
};

