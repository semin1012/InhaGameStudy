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
	
	static float Dot(cVector3& v1, cVector3& v2);
	static Vector Cross(cVector3& v1, cVector3& v2);
	float Length();
	cVector3 Normalize();
	static float Angle(cVector3& v1, cVector3& v2);

	cVector3 operator/(double n) const;
*/

int main()
{
	int n;
	cin >> n;
	bool minus = false;

	for (int i = 0; i <= n; i++)
	{
		minus = false;
		for (int j = 0, k = 1; j <= 2 * n; j++)
		{
			if (n - i <= j && n + i >= j)
			{
				cout << k << " ";
				if (k >= pow(2, i) && minus == false) minus = true;
				if ( minus ) k /= 2;
				else k *= 2;
			}
			else cout << "  ";

		}
		cout << '\n';
	}
}

