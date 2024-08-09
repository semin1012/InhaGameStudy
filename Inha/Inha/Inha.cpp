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

Q3. 하노이 타워 
*/
#include <vector>

vector<int> top[3];

int Factorial(int n)
{
	if (n == 1)
		return 1;
	int j = n * Factorial(n - 1);
	return j;
}

void print_top(int num)
{
	vector<int> temptop[3] = { top[0], top[1], top[2] };

	cout << "==============\n";

	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if ( temptop[j].size() > 0 && i >= num - top[j].size() )
			{
				printf("[%2d] ", temptop[j].back());
				temptop[j].pop_back();
			}
			else
			{
				printf("[%2d] ", 0);
			}
		}
		cout << '\n';
	}
	cout << '\n';
}

void Hanoi_top(int n, int from, int temp, int to, int num)
{
	static int i = 0;

	if (n == 0)
		return;

	Hanoi_top(n - 1, from, to, temp, num);

	i++;
	top[to-1].push_back(top[from-1].back());
	top[from-1].pop_back();

	cout << i << "번째 이동\n";
	print_top(num);

	Hanoi_top(n - 1, temp, from, to, num);
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		top[0].push_back(i + 1);
	}


	print_top(n);
	Hanoi_top(n, 1, 2, 3, n);
}