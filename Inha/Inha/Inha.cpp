#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <math.h>
#include <limits>
#include <cmath>
using namespace std;

/*
Q1. 두 개의 원에 대해 중심점 좌표와 반지름을 입력받아
	두 번째 원이 첫 번째 원의 내부에 있는지
	첫 번째 원과 겹치는지를 결정하는 프로그램을 작성하라.
	
	ex>
	첫 번째 원 x,y,r: 0.5 5.1 13
	두 번째 원 x,y,r: 1 1.7 4.5
	두 번째 원은 첫 번째 원의 내부에 있다. 

Q2. 두 직사각형에 대해 중심점 (x,y), 폭 w, 높이 h를 입력받아
	두 번째 직사각형이 첫 번째 직사각형의 내부에 있는지,
	첫 번째 직사각형과 겹치는지를 결정하는 프로그램을 작성하라. 
	ex>
	첫 번째 사각형 x,y,w,h: 1 2 3 5.5
	두 번째 사각형 x,y,w,h: 3 4 4.5 5
	>> 두 번째 사각형은 첫 번째 사각형과 겹쳤다.
	ex 2>
	...
	>> 내부에 있다.
	ex 3>
	...
	>> 겹치지 않는다. 
*/


struct Circle
{
	double x, y, r;
};

struct Rectangle
{
	double x, y, w, h;
};

struct RectanglePos
{
	double left, right, top, bottom;
};

int isCollided(Circle c1, Circle c2);
int isCollided(Rectangle r1, Rectangle r2);

int main()
{
	// Q1
	cout << "원의 세 가지 케이스와 사각형의 다섯 가지 케이스를 입력받습니다.\n";
	Circle c1, c2;
	for (int i = 0; i < 3; i++)
	{
		cout << "> 첫번째 원 x, y, r: ";
		cin >> c1.x >> c1.y >> c1.r;
		cout << "> 두번째 원 x, y, r: ";
		cin >> c2.x >> c2.y >> c2.r;

		switch (isCollided(c1, c2))
		{
		case -1:
			cout << "두 번째 원은 첫 번째 원과 닿지 않는다.\n\n";
			break;
		case 0:
			cout << "두 번째 원은 첫 번째 원과 겹친다.\n\n";
			break;
		case 1:
			cout << "두 번째 원은 첫 번째 원의 내부에 있다.\n\n";
			break;
		}
	}

	// Q2
	for ( int i = 0; i < 5; i++ )
	{
		Rectangle r1, r2;
		cout << "> 첫 번째 사각형 x,y,w,h: ";
		cin >> r1.x >> r1.y >> r1.w >> r1.h;
		cout << "> 두 번째 사각형 x,y,w,h: ";
		cin >> r2.x >> r2.y >> r2.w >> r2.h;

		switch (isCollided(r1, r2))
		{
		case -1:
			cout << "두 번째 사각형은 첫 번째 사각형과 닿지 않는다.\n\n";
			break;
		case 0:
			cout << "두 번째 사각형은 첫 번째 사각형과 겹친다.\n\n";
			break;
		case 1:
			cout << "두 번째 사각형은 첫 번째 사각형의 내부에 있다.\n\n";
			break;
		}
	}
}

int isCollided(Circle c1, Circle c2)
{
	float d = pow((c1.x - c2.x), 2) + pow((c1.y - c2.y), 2);	// 제곱된 거

	if (d < pow((c1.r + c2.r), 2)) // 닿음
	{
		if (d < c1.r * c1.r)	// 내부에 있음
			return 1;

		return 0;
	}

	return -1;
}

int isCollided(Rectangle r1, Rectangle r2)
{
	RectanglePos rp1, rp2;
	rp1.left	= r1.x - (r1.w / 2);
	rp1.right	= r1.x + (r1.w / 2);
	rp1.top		= r1.y + (r1.h / 2);
	rp1.bottom	= r1.y - (r1.h / 2);

	rp2.right	= r2.x + (r2.w / 2);
	rp2.left	= r2.x - (r2.w / 2);
	rp2.top		= r2.y + (r2.h / 2);
	rp2.bottom	= r2.y - (r2.h / 2);
	
	// 안 닿는 경우에 대해서 조건 검사
	if (rp1.left > rp2.right) return -1;
	if (rp1.right < rp2.left) return -1;
	if (rp1.top < rp2.bottom) return -1;
	if (rp1.bottom > rp2.top) return -1;

	// 완전 겹치는 경우에 대해서 조건 검사
	if (rp1.left < rp2.left && rp1.right > rp2.right && rp1.top > rp2.top && rp1.bottom < rp2.bottom)
		return 1;

	// 그 외의 경우는 그냥 겹치는 것
	return 0;
}
