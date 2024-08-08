#include <cmath>
#include "cVector3.h"
using std::sqrt;
using std::sin;
using std::cos;
using std::atan;
using std::atan2;
using std::cout;

namespace VECTOR
{
	const double Rad_to_deg = 45.0 / atan(1.0);


	cVector3::cVector3()
	{
		x = y = z = 0.0;
	}

	cVector3::cVector3(const double& n1, const double& n2, const double& n3)
	{
		x = n1, y = n2, z = n3;
	}

	cVector3::~cVector3()
	{
	}

	cVector3 cVector3::operator+(const cVector3& b) const
	{
		return cVector3(x + b.x, y + b.y, z + b.z);
	}

	cVector3 cVector3::operator-(const cVector3& b) const
	{
		return cVector3(x - b.x, y - b.y, z - b.z);
	}

	cVector3 cVector3::operator*(double n) const
	{
		return cVector3(x * n, y * n, z * n);
	}

	cVector3 cVector3::operator/(double n) const
	{
		return cVector3(x / n, y / n, z / n);
	}

	cVector3 operator*(double n, const cVector3& a)
	{
		return cVector3(a.x * n, a.y * n, a.z * n);
	}

	std::ostream& operator<<(std::ostream& os, const cVector3& v)
	{
		os << v.x << " " << v.y << " " << v.z;
		return os;
	}

	std::istream& operator>>(std::istream& is, cVector3& v)
	{
		is >> v.x >> v.y >> v.z;
		return is;
	}

	double cVector3::Dot(cVector3& v)
	{
		return x * v.x + y * v.y + z * v.z;
	}

	cVector3 cVector3::Cross(cVector3& v)
	{
		return cVector3(y * v.z - z * v.y, z * v.x - x * v.z, x * v.y - y * v.x);
	}

	double cVector3::Angle(cVector3& v)
	{
		double temp = Dot(v) / (Length() * v.Length());
		temp = std::max(-1.0, std::min(1.0, temp));
		return acos(temp) * (180 / 3.141592);
	}

	double cVector3::Length()
	{
		return sqrt(x * x + y * y + z * z);
	}

	cVector3 cVector3::Normalize()
	{
		return cVector3(x / Length(), y / Length(), z / Length());
	}

	bool cVector3::operator==(const cVector3& v) const
	{
		if (x == v.x && y == v.y && z == v.z) return true;
		return false;
	}

	bool cVector3::operator!=(const cVector3& v) const
	{
		if (x != v.x || y != v.y || z != v.z) return true;
		return false;
	}

}