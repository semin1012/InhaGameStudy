#pragma once

class GeometricObject
{
private:
	double x;
	double y;
public:
	GeometricObject() : x(0), y(0) { };
	GeometricObject(double xNum, double yNum) : x(xNum), y(yNum) { };
	virtual ~GeometricObject() { };

public:
	double	getX() const { return x; }
	double	getY() const { return y; }
	void	setX(double num) { x = num; }
	void	setY(double num) { y = num; }
};

