#include "Rectangle2D.h"

void Rectangle2D::setRect()
{
	rect.left	= getX() - width / 2;
	rect.right	= getX() + width / 2;
	rect.top	= getY() + height / 2;
	rect.bottom = getY() - height / 2;
}

double Rectangle2D::getArea()
{
	return width * height;
}

double Rectangle2D::getPerimeter()
{
	return width * 2 + height * 2;
}

bool Rectangle2D::contains(double x, double y) const
{
	if (rect.right < x) return false;
	if (rect.left > x) return false;
	if (rect.top < y) return false;
	if (rect.bottom > y) return false;

	return true;
}

bool Rectangle2D::contains(const Rectangle2D& r) const
{
	if (rect.right >= r.rect.right && rect.left <= r.rect.left && rect.top >= r.rect.top && rect.bottom <= r.rect.bottom)
		return true;
	return false;
}

bool Rectangle2D::overlaps(const Rectangle2D& r) const
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
	os << "ÁßÁ¡ ÁÂÇ¥: (" << r.getX() << ", " << r.getY() << "), width = " 
		<< r.width << ", height = " << r.height;
	return os;
}
