#include "Circle2D.h"
#include <math.h>
#include <iostream>
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

bool Circle2D::isContains(Point p)
{
    if (getDistance(p) <= radius * radius)
        return true;
    return false;
}

bool Circle2D::isContains(const Circle2D& circle)
{
    if (getDistance(circle.point) + pow(circle.radius,2) <= pow(radius, 2))
        return true;
    return false;
}

bool Circle2D::isOverlaps(const Circle2D& circle)
{
    if (getDistance(circle.point) <= pow(radius + circle.radius, 2))
    {
        return true;
    }
    return false;
}

void Circle2D::printInfo()
{
    using std::cout;
    cout << "원의 중심 좌표 - (" << point.x << ", " << point.y << "), 반지름 - " << radius << '\n';
}

double Circle2D::getDistance(const Point& p)
{
    return pow(point.x - p.x, 2) + pow(point.y - p.y, 2);
}
