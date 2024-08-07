#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include "cVector3.h"
using namespace std;

/*
Q1. 다음과 같은 형태로 출력하는 프로그램을 작성하라.
	n을 입력받아 다음과 같이 2^n 형태의 값들을 
	출력하도록 프로그램을 작성하라.
	ex> n = 3
				1
			1	2	1
		1	2	4	2	1
	1	2	4	8	4	2	1

Q2. cVector3 클래스 정의	-> 교과서 3차원으로 바꿀 것
		직각좌표계 <-> 극 좌표계 변환하는 함수는 제거
	함수 추가
		cVector3 operator/(double n) const;
		static float Dot(cVector3& v1, cVector3& v2);
		static cVector3 Cross(cVector3& v1, cVector3& v2);
		static float Angle(cVector3& v1, cVector3& v2);
		float Length();
		cVector3 Normalize();

	ex >
		v1 x, y, z: 1 2 3
		v2 x, y, z: -4 -5 6
		v1 length: 3.7xxx 
		v2 length: 8.7xxx
		v1 * 3: 3 6 9
		3 * v1: 3 6 9
		v2 / 2: -2 -2.5 3
		v1.Dot(v2) = 4
		v2.Cross(v2) = 27 -18 3
		Angle(v1~v2): 83.xxxx
	ex >
		v1 -1 3 2
		v2 3 -4 1
		v1 + v2 > 2 -1 3
		v1 - v2 > -4 7 1
		v1.normalize -> -0.267xxx, 0.801xxx, 0.53xxxx
*/

int main()
{
	using namespace VECTOR;
	cVector3 v1, v2;
	cout << " v1 x, y, z: ";
	cin >> v1;

	cout << " v2 x, y, z: ";
	cin >> v2;

	cout << "v1 length: " << v1.Length() << endl;
	cout << "v2 length: " << v2.Length() << endl;

	cout << "v1 * 3 = " << v1 * 3 << endl;
	cout << "3 * v1 = " << 3 * v1 << endl;
	cout << "v2 / 2 = " << v2 / 2 << endl;

	cout << "v1.dot(v2): " << v1.Dot(v2) << endl;
	cout << "v1.cross(v2): " << v1.Cross(v2) << endl;
	cout << "angle(v1~v2): " << v1.Angle(v2) << endl;

	cout << " v1 x, y, z: ";
	cin >> v1;

	cout << " v2 x, y, z: ";
	cin >> v2;

	cout << "v1 + v2 > " << v1 + v2 << endl;
	cout << "v1 - v2 > " << v1 - v2 << endl;
	cout << "v1.normalize -> " << v1.Normalize() << endl;
}

