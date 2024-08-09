#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Rectangle2D.h"
#include "Circle2D.h"
#include "MyPoint.h"
using namespace std;

/*
Q1. x와 y축의 점을 표시하는 MyPoint 클래스를 설계하라.
	- 좌표를 나타내는 두 개의 x, y 데이터 필드
	- 점(0,0)을 생성하는 인수 없는 생성자
	- 지정 좌표의 점을 생성하는 생성자
	- x, y 데이터 필드를 위한 각각의 두 개의 get 함수
	- MyPoint 유형의 한 점에서 다른 점까지의 거리를 반환하는 
	  distance 함수
	
	클래스에 대한 UML 다이어그램
	두 개의 점(0,0)과 (10, 30.5)를 생성하고 두 점 사이의 
	  거리를 표시하는 프로그램을 작성하라.
	생성된 좌표의 점이 Circle2D 클래스의 객체나 Rectangle2D 객체의
	내부에 있는지 여부를 판단하는 contains 함수를 MyPoint 객체를
	인자로 하는 프렌드 함수를 구현하라. 
*/
//
//int main()
//{
//	MyPoint p1;
//	MyPoint p2(10, 30.5);
//	Circle2D circle(0, 0, 5.5);
//	Rectangle2D rect(10, 10, 2, 2);
//
//	cout << "p1 = " << p1 << '\n' << "p2 = " << p2 << '\n';
//	cout << "circle = " << circle << '\n' << "rect = " << rect << "\n\n";
//
//	cout << "p1과 p2 사이의 거리: " << p1.distance(p2.getX(), p2.getY()) << '\n';
//	cout << boolalpha << "contains(circle, p1): " << contains(circle, p1) << '\n';
//	cout << "contains(rect, p1): " << contains(rect, p1) << '\n';
//}