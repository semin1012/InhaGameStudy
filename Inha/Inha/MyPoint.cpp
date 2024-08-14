#include "MyPoint.h"
#include <iostream>

double MyPoint::distance(double tx, double ty)
{
    return sqrt(pow(getX() - tx, 2) + pow(getY() - ty, 2));
}

bool MyPoint::contains(const Circle2D& circle)
{
    return circle.contains(getX(), getY());
}

bool contains(const Rectangle2D& rect, const MyPoint& point)
{
    return rect.contains(point.getX(), point.getY());
}

bool contains(const Circle2D& circle, const MyPoint& point)
{
    return circle.contains(point.getX(), point.getY());
}

std::ostream& operator<<(std::ostream& os, const MyPoint& p)
{
    os << "ÁÂÇ¥: (" << p.getX() << ", " << p.getY() << ")";
    return os;
}
