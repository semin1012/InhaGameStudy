#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Rectangle2D.h"
using namespace std;

/*
Q1. 다음을 포함하는 Circle2D 클래스를 정의하라.
	- 원의 중심을 나타내는 x, y라는 두 개의
	  double 데이터 필드와 get 상수 함수
	- double 데이터 필드의 radius와 get 상수 함수
	- (x, y)가 (0, 0), radius가 1인 기본 원을 생성하는
	  인수 없는 생성자
	- 지정된 x, y와 radius로 원을 생성하는 생성자
	- 원의 면적을 반환하는 getArea() 상수 함수
	- 원의 둘레를 반환하는 getPerimeter() 상수 함수
	- 지정된 점(x, y)가 생성된 원 내부에 있을 경우,
	  true를 반환하는 contains(double x, double y)
	  상수 함수
	- 지정된 원이 생성된 원 내부에 있을 경우 
	  true를 반환하는 contains(Circle2D& circle) 상수 함수
	- 지정된 원이 생성된 원과 중첩되는 경우, 
	  true를 반환하는 overlaps(const Circle2D& circle) 상수 함수

	클래스에 대한 UML 다이어그램을 그리고 클래스를 구현하라.

	Circle2D 객체 c1(2,2,5.5), c2(2,2,5.5), c3(4,5,10.5)를 생성하고 c1의 면적과 둘레,
	c1.contains(3,3), c1.contains(c2), c1.overlaps(c3)의 결과를 화면에 출력하라.

Q2. 다음을 포함하는 Rectangle2D 클래스를 정의하라.
	- 직사각형의 중심을 나타내는 x,y 두 개의 double 데이터 필드,
	  이에 대한 get 상수 함수와 set 함수, 사각형의 변은 x축과 y축에 평행인 것으로 
	  가정한다.
	- double 데이터 필드 width, height와 이에 대한 get 상수 함수와 set 함수
	- (x, y)는 (0, 0), width와 height는 모두 1인 기본 직사각형을 생성하는 인수 없는 
	  생성자
	- 지정된 x,y,width,height로 직사각형을 생성하는 생성자
	- 직사각형의 면적을 반환하는 getArea() 상수 함수
	- 직사각형의 둘레를 반환하는 getPerimeter() 상수 함수
	- 지정된 점(x, y)가 생성된 직사각형의 내부에 있을 경우 true를 반환하는 
	  contains(double x, double y) 상수 함수
	- 지정된 직사각형이 생성된 직사각형의 내부에 있을 경우 true를 반환하는 
	  contains(const Rectangle2D& r) 상수 함수
	- 지정된 직사각형이 생성된 직사각형과 중첩되는 경우 true를 반환하는 
	  overlaps(const Rectangle2D& r) 상수 함수
	
	클래스에 대한 UML 다이어그램을 그리고 클래스를 구현하라.

	세 개의 Rectangle2D 객체 r1(2,2,5.5,4.9), r2(4,5,10.5,3.2), r3(3,5,2.3,5.4)를 
	생성하고 r1의 면적과 둘레를 출력하며, r1.contains(3,3), r1.contains(r2), 
	r1.overlaps(r3)의 결과를 화면에 출력하는 테스트 프로그램을 작성하라.
*/

int main()
{
	Rectangle2D r1(2, 2, 5.5, 4.9);
	Rectangle2D r2(4, 5, 10.5, 3.2);
	Rectangle2D r3(3, 5, 2.3, 5.4);

	cout << "r1: " << r1 << '\n';
	cout << "r2: " << r2 << '\n';
	cout << "r3: " << r3 << '\n';

	cout << "r1의 면적: " << r1.getArea() << '\n';
	cout << "r1의 둘레: " << r1.getPerimeter() << '\n';
	cout << boolalpha << "r1.contains(3,3): " << r1.isContains(3, 3) << '\n';
	cout << "r1.contains(r2): " << r1.isContains(r2) << '\n';
	cout << "r1.overlaps(r3): " << r1.isOverlaps(r3) << '\n';
}