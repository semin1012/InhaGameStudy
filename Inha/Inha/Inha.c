#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q1. 야구 게임
	세 개의 숫자를 입력 받아서 다음과 같이 숫자가 있지만
	그 위치가 틀렸을 때는 "ball"을 출력하고 
	숫자와 위치가 맞으면 "strike"를 출력한다. 
	숫자와 위치가 다 틀리면 "out"을 출력하도록 한다.
	무엇이 볼이고 스트라이크인지는 출력하지 않는다.
	세 개의 숫자와 위치가 다 맞으면 "homerun"을 표시하고 게임을
	끝낸다.

	ex> 정답: 2 1 6 ( 보여지면 안 됨 + 중복 불가 )
	1 > 8 3 5 -> out
	2 > 6 5 9 -> 0s 1b (6이 있으나 위치가 달라 ball)
	3 > 2 6 4 -> 1s 1b (2의 위치가 맞으나 6은 위치가 다름)
	4 > 2 1 6 -> HR 

Q2. 다음과 같이 두 개의 int형 포인터 변수와 길이가 5인 
	int형 배열을 선언한다.
	int *maxPtr;
	int *minPtr;
	int arr[5];
	MaxAndMin이라는 함수를 정의하고 이를 호출해서 위 배열과 
	두 포인터를 변수로 전달한다.
	이 함수의 호출이 완료되면 
	포인터 변수 maxPtr에는 가장 큰 배열 요소의 주소값이 
	포인터 변수 minPtr에는 가장 작은 배열 요소의 주소값이
	저장되어야 한다. 
	arr 주소값, 최대/최소의 주소값 
	maxPtr, minPtr이 가진 주소에 저장된 값도 출력하라.
// 예제 15-7
int sum(int, int);
int sub(int a, int b);

int main()
{
	int (*fp)(int, int);
	int res;

	fp = sum;
	res = fp(10, 20);
	printf("sum result: %d\n", res);
	printf("   fp의 주소: %p\n", &res);
	printf("sum()의 주소: %p\n\n", &sum);

	fp = sub;
	res = fp(10, 20);
	printf("sub result: %d\n", res);
	printf("   fp의 주소: %p\n", &res);
	printf("sub()의 주소: %p\n\n", &sub);
}

int sum(int a, int b)
{
	return (a + b);
}

int sub(int a, int b)
{
	return (a - b);
}
// 예제 15-8
void func(int (*fp)(int, int));
int sum(int a, int b);
int mul(int a, int b);
int Max(int a, int b);

int main()
{
	int sel;

	printf("01 정수의 합\n");
	printf("02 정수의 곱\n");
	printf("03 정수 중에서 큰 값 계산\n");
	printf("원하는 연산을 선택하세요: ");
	scanf("%d", &sel);

	switch (sel)
	{
	case 1: func(sum); break;
	case 2: func(mul); break;
	case 3: func(Max); break;
	}
}

void func(int (*fp)(int, int))
{
	int a, b;
	int res;

	printf("두 정수의 값을 입력하세요: ");
	scanf("%d%d", &a, &b);
	res = fp(a, b);
	printf("결괏값은: %d\n", res);
}

int sum(int a, int b)
{
	return (a + b);
}

int mul(int a, int b)
{
	return (a * b);
}

int Max(int a, int b)
{
	if (a > b) return a;
	else return b;
}
*/
// 예제 15-9
int main()
{
	int a = 10;
	double b = 3.5;
	void* vp;
	
	vp = &a;
	printf("a: %d\n", *(int*)vp);
	printf("a: %f\n", *(float*)vp);	// 출력 0.0000 이렇게 나옴 

	vp = &b;
	printf("b: %.1lf\n", *(double*)vp);
	printf("b: %d\n", *(int*)vp);	// 출력 0 나옴 
}