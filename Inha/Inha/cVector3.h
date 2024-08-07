#pragma once
#include <iostream>

namespace VECTOR
{
	class cVector3
	{
	private:
		double x;
		double y;
		double z;

	public:
		cVector3();
		cVector3(const double& n1, const double& n2, const double& n3);

		double Dot(cVector3& v);
		cVector3 Cross(cVector3& v);
		double Angle(cVector3& v);
		double Length();
		cVector3 Normalize();

		bool operator==(const cVector3& v) const;
		bool operator!=(const cVector3& v) const;

		~cVector3();
		
		cVector3 operator+(const cVector3& b) const;
		cVector3 operator-(const cVector3& b) const;
		cVector3 operator*(double n) const;
		cVector3 operator/(double n) const;

		friend cVector3 operator*(double n, const cVector3& a);
		friend std::ostream& operator<<(std::ostream& os, const cVector3& v);
		friend std::istream& operator>>(std::istream& is, cVector3& v);
	};
}