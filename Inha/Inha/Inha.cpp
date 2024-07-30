#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/* 
Q1. 점(x1, y1) 를 입력받아 그 점이 (x0, y0)를 중심으로 하고
	반지름 r 인 원의 내부에 존재하는지 검사하는 프로그램을 작성하라.
	ex>
		input > r : 10, x0 = 0, y0 = 0, x1 = 4, y1 = 5
		output > 점 (4, 5)는 중점이 (0, 0)이고 반지름이 10인 
		원 안에 있습니다.

	점이 원 내부에 존재하는지 검사하는 함수를 만들고,
	점(x1, y1), (x0, y0)를 인자로 넘겨줄 때 포인터 구조체를 
	이용해서 만들 것
*/

/*
struct POINT
{
	int x, y;
};

bool isIncluded(POINT* p1, POINT* p2, int* r)
{
	float d = sqrt(pow((p2->x - p1->x), 2) + pow((p2->y - p1->y), 2));
	if (d <= (*r))
	{
		return true;
	}
	return false;
}

int main()
{
	int r;
	POINT p1, p2;

	cout << "> r: ";
	cin >> r;
	cout << "> x0 y0: ";
	cin >> p1.x >> p1.y;
	cout << "> x1 y1: ";
	cin >> p2.x >> p2.y;

	if (isIncluded(&p1, &p2, &r))
		cout << "점 (" << p2.x << ", " << p2.y << ")는 중점이 (" << p1.x << ", " << p1.y << ")이고 반지름이 " << r << "인 원 안에 있습니다.\n";
	else cout << "점 (" << p2.x << ", " << p2.y << ")는 중점이 (" << p1.x << ", " << p1.y << ")이고 반지름이 " << r << "인 원 안에 없습니다.\n";
}
*/

/*
Q2. 선1의 두 점 (x1, y1)과 (x2, y2), 선2의 두 점 (x3, y3)과 (x4, y4)로 주어진
	두 선의 교차점을 구하는 프로그램을 작성하라.
	크래머 공식을 이용하라. 

	ex> 점 4개 입력: x1, y1, x2, y2, x3, y3, x4, y4
		>> 2 2 5 -1.0 4.0 2.0 -1.0 -2.0
		>> 교차점은 ( 000, 000 ) 이다. 

		>> 2 2 7 6.0 4.0 2.0 -1.0 -2.0
		>> 두 직선은 평행이다. 
*/

struct POINT
{
	float x, y;
};

bool isCrossed(POINT* p1, POINT* p2, POINT* p3, POINT* p4, POINT* result)
{
	float temp1, temp2;
	float a = p2->y - p1->y;
	float b = p1->x - p2->x;
	temp1 = a * p1->x + b * p1->y;

	float c = p4->y - p3->y;
	float d = p3->x - p4->x;
	temp2 = c * p3->x + d * p3->y;

	float r = (a * d) - (b * c);

	if (r == 0) return false;

	result->x = ((temp1 * d) - (temp2 * b)) / r;
	result->y = ((temp2 * a) - (temp1 * c)) / r;

	return true;
}

int main()
{
	POINT p1, p2, p3, p4;
	POINT result;

	cout << "점 4개 입력:  x1, y1, x2, y2, x3, y3, x4, y4\n";
	cout << ">> ";
	cin >> p1.x >> p1.y >> p2.x >> p2.y >> p3.x >> p3.y >> p4.x >> p4.y;

	if (isCrossed(&p1, &p2, &p3, &p4, &result))
		cout << "교차점은 (" << result.x << ", " << result.y << ") 이다.\n";
	else cout << "두 직선은 평행이다.\n";
}