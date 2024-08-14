#include "Circle2D.h"
#include <math.h>
#define PI 3.141592

double Circle2D::getArea()
{
    return PI * radius * radius;
}

double Circle2D::getPerimeter()
{
    return 2 * PI * radius;
}

bool Circle2D::contains(const double px, const double py) const
{
    if (getDistance(px, py) <= radius * radius)
        return true;
    return false;
}

bool Circle2D::contains(const Circle2D& circle)
{
    if (getDistance(circle.getX(), circle.getY()) + pow(circle.radius, 2) <= pow(radius, 2))
        return true;
    return false;
}

bool Circle2D::overlaps(const Circle2D& circle) const
{
    getDistance(circle.getX(), circle.getY());
    if (getDistance(circle.getX(), circle.getY()) <= pow(radius + circle.radius, 2))
    {
        return true;
    }
    return false;
}

double Circle2D::getDistance(const double px, const double py) const
{
    return pow(getX() - px, 2) + pow(getY() - py, 2);
}

std::ostream& operator<<(std::ostream& os, const Circle2D& c)
{
    using std::cout;
    os << "중점 좌표: (" << c.getX() << ", " << c.getY() << "), 반지름: " << c.radius;
    return os;
}