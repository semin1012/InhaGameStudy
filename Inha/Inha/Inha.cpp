#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stack>
#include <queue>
#include <string>
#include "MyPoint.h"
#include "Circle2D.h"
#include "Rectangle2D.h"
using namespace std;

/*
Q1. GeometricObject 베이스 클래스로 해서
	다음 클래스들을 설계하라.
	Circle2D, Rectangle2D, MyPoint 클래스를
	추상 클래스 상속 개념을 적용하여 다시 작성하라.
	UML 클래스 다이어그램 작성.
*/

struct OPERATOR
{
	string c;
	int num;
};

int main()
{
	cout << "* MyPoint 확인 *\n";
	MyPoint p1;
	MyPoint p2(10, 30.5);
	Circle2D circle(0, 0, 5.5);
	Rectangle2D rect(10, 10, 2, 2);

	cout << "p1 = " << p1 << '\n' << "p2 = " << p2 << '\n';
	cout << "circle = " << circle << '\n' << "rect = " << rect << "\n\n";

	cout << "p1과 p2 사이의 거리: " << p1.distance(p2.getX(), p2.getY()) << '\n';
	cout << boolalpha << "contains(circle, p1): " << contains(circle, p1) << '\n';
	cout << "contains(rect, p1): " << contains(rect, p1) << "\n\n";

	cout << "* Circle2D 확인 *\n";
	Circle2D c1(2, 2, 5.5);
	Circle2D c2(2, 2, 5.5);
	Circle2D c3(4, 5, 10.5);

	cout << "c1: " << c1 << '\n';

	cout << "c2: " << c2 << '\n';

	cout << "c3: " << c3 << '\n';

	cout << "c1의 면적: " << c1.getArea() << '\n';
	cout << "c1의 둘레: " << c1.getPerimeter() << '\n';

	cout << boolalpha << "c1.isContains(3,3): " << c1.contains(3, 3) << '\n';
	cout << "c1.isContains(c2): " << c1.contains(c2) << '\n';
	cout << "c1.isOverlaps(c3): " << c1.overlaps(c3) << "\n\n";

	cout << "* Rectangle2D 확인 *\n";

	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << "r1: " << r1 << '\n';
	cout << "r2: " << r2 << '\n';
	cout << "r3: " << r3 << '\n';

	cout << "r1의 면적: " << r1.getArea() << '\n';
	cout << "r1의 둘레: " << r1.getPerimeter() << '\n';
	cout << boolalpha << "r1.contains(3,3): " << r1.contains(3, 3) << '\n';
	cout << "r1.contains(r2): " << r1.contains(r2) << '\n';
	cout << "r1.overlaps(r3): " << r1.overlaps(r3) << '\n';
}