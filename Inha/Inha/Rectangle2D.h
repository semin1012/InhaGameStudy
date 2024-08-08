#pragma once
#include <iostream>

struct Point
{
	double x;
	double y;
};

struct RECT
{
	double left, right, top, bottom;
};

class Rectangle2D
{
private:
	Point		point;
	double		width;
	double		height;
	RECT		rect;
	void		setRect();

public:
	Rectangle2D();
	Rectangle2D(double x, double y, double w, double h);
	~Rectangle2D();

public:
	Point		getPoint()					 { return point; };
	void		setPoint(double x, double y) { point.x = x; point.y = y; };
	double		getWidth()					 { return width; };
	void		setWidth(double w)			 { width = w; };
	double		getHeight()					 { return height; };
	void		setHeight(double h)			 { height = h; };

	double		getArea();
	double		getPerimeter();
	bool		isContains(double x, double y);
	bool		isContains(const Rectangle2D& r);
	bool		isOverlaps(const Rectangle2D& r);

	friend std::ostream& operator<<(std::ostream& os, const Rectangle2D& r);
};

