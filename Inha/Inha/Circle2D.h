#pragma once

struct Point
{
	double x, y;
};


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
	bool		isContains(Point p);
	bool		isContains(const Circle2D& circle);
	bool		isOverlaps(const Circle2D& circle);

	void		printInfo();
	double		getDistance(const Point& p);
};