#include "Rectangle2D.h"

Rectangle2D::Rectangle2D()
{
	point.x = point.y = 0;
	width	= height = 1;
	setRect();
}

Rectangle2D::Rectangle2D(double x, double y, double w, double h)
{
	point.x = x;
	point.y = y;
	width	= w;
	height	= h;
	setRect();
}

Rectangle2D::~Rectangle2D()
{

}

void Rectangle2D::setRect()
{
	rect.left	= point.x - width / 2;
	rect.right	= point.x + width / 2;
	rect.top	= point.y + height / 2;
	rect.bottom = point.y - height / 2;
}

double Rectangle2D::getArea()
{
	return width * height;
}

double Rectangle2D::getPerimeter()
{
	return width * 2 + height * 2;
}

bool Rectangle2D::isContains(double x, double y) const
{
	if (rect.right < x) return false;
	if (rect.left > x) return false;
	if (rect.top < y) return false;
	if (rect.bottom > y) return false;

	return true;
}

bool Rectangle2D::isContains(const Rectangle2D& r) const
{
	if (rect.right >= r.rect.right && rect.left <= r.rect.left && rect.top >= r.rect.top && rect.bottom <= r.rect.bottom)
		return true;
	return false;
}

bool Rectangle2D::isOverlaps(const Rectangle2D& r) const
{
	if (rect.right < r.rect.left) return false;
	if (rect.left > r.rect.right) return false;
	if (rect.top < r.rect.bottom) return false;
	if (rect.bottom > r.rect.top) return false;

	return true;
}

std::ostream& operator<<(std::ostream& os, const Rectangle2D& r)
{
	using std::cout;
	os << "ÁßÁ¡ ÁÂÇ¥: (" << r.point.x << ", " << r.point.y << "), width = " 
		<< r.width << ", height = " << r.height;
	return os;
}
