#include "Circle2D.h"
#include <math.h>
#define PI 3.141592

Circle2D::Circle2D()
{
    point.x = 0;
    point.y = 0;
    radius = 1;
}

Circle2D::Circle2D(double x, double y, double r)
{
    point.x = x;
    point.y = y;
    radius = r;
}

Circle2D::~Circle2D()
{

}

double Circle2D::getArea()
{
    return PI * radius * radius;
}

double Circle2D::getPerimeter()
{
    return 2 * PI * radius;
}

bool Circle2D::isContains(Point p) const
{
    if (getDistance(p) <= radius * radius)
        return true;
    return false;
}
 
bool Circle2D::isContains(const Circle2D& circle) const
{
    if (getDistance(circle.point) + pow(circle.radius,2) <= pow(radius, 2))
        return true;
    return false;
}

bool Circle2D::isOverlaps(const Circle2D& circle) const
{
    if (getDistance(circle.point) <= pow(radius + circle.radius, 2))
    {
        return true;
    }
    return false;
}

double Circle2D::getDistance(const Point& p) const
{
    return pow(point.x - p.x, 2) + pow(point.y - p.y, 2);
}

std::ostream& operator<<(std::ostream& os, const Circle2D& c)
{
    using std::cout;
    os << "중점 좌표: (" << c.point.x << ", " << c.point.y << "), 반지름: " << c.radius;
    return os;
}