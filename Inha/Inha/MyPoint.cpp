#include "MyPoint.h"
#include <iostream>

MyPoint::MyPoint()
{
    x = 0;
    y = 0;
}

MyPoint::MyPoint(double tx, double ty)
{
    x = tx;
    y = ty;
}

MyPoint::~MyPoint()
{
}

double MyPoint::distance(double tx, double ty)
{
    return sqrt(pow(x - tx, 2) + pow(y - ty, 2));
}

bool contains(const Circle2D& circle, const MyPoint& point)
{
    return circle.isContains({point.x, point.y});
}

bool contains(const Rectangle2D& rect, const MyPoint& point)
{
    return rect.isContains(point.x, point.y);
}

std::ostream& operator<<(std::ostream& os, const MyPoint& p)
{
    os << "ÁÂÇ¥: (" << p.x << ", " << p.y << ")";
    return os;
}
