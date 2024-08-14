#pragma once
#include <iostream>
#include "GeometricObject.h"
#include "stdx.h"

struct RECT
{
	double left, right, top, bottom;
};

class Rectangle2D : public GeometricObject
{
private:
	double		width;
	double		height;
	RECT		rect;
	void		setRect();

public:
	Rectangle2D() : GeometricObject(), width(1), height(1) { setRect(); }
	Rectangle2D(double x, double y, double w, double h) : GeometricObject(x, y), width(w), height(h) { setRect(); }
	~Rectangle2D() { };

public:
	void		setPoint(double x, double y) { setX(x); setY(y); };
	double		getWidth()					 { return width; };
	void		setWidth(double w)			 { width = w; };
	double		getHeight()					 { return height; };
	void		setHeight(double h)			 { height = h; };

	double		getArea();
	double		getPerimeter();
	bool		contains(double x, double y) const;
	bool		contains(const Rectangle2D& r) const;
	bool		overlaps(const Rectangle2D& r) const;

	friend std::ostream& operator<<(std::ostream& os, const Rectangle2D& r);
};

