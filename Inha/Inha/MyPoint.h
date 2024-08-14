#pragma once
#include "GeometricObject.h"
#include "Circle2D.h"
#include "Rectangle2D.h"

class MyPoint : public GeometricObject
{
public:
	MyPoint() : GeometricObject() { };
	MyPoint(double tx, double ty) : GeometricObject(tx, ty) { };
	~MyPoint() { };

public:
	double	distance(double tx, double ty);

	bool	contains(const Circle2D& circle);

	friend bool contains(const Rectangle2D& rect, const MyPoint& point);
	friend bool contains(const Circle2D& circle, const MyPoint& point);

	friend std::ostream& operator<<(std::ostream& os, const MyPoint& p);
};

