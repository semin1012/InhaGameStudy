#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
Q1. 입력받은 값의 절대값을 구하는 함수 abs()를
	구현하라. 입력은 계속 받는다.

	ex)
		종료하려면 0을 입력하시오.
		정수 입력: -34
		절대값은: 34

Q2. 이전 문제 AZ ZA, 소수 구하기, 
	사칙 연산 프로그램을 함수를 사용하는 형태로
	수정하라.
	사칙 연산 프로그램은 입력 부분, 계산 부분,
	출력 부분을 각각 함수로 구현하라.

p.234. 1부터 10까지의 합 계산 (재귀호출)
*/

//int rec_func(int n)
//{
//	int sum = n;
//	if (n > 1) {
//		sum += rec_func(n - 1);
//	}
//	return sum;
//}

int rec_func(int n)
{
	if (n == 1)
		return 1;
	return n + rec_func(n - 1);
}

int main()
{
	printf("%d\n", rec_func(10));
}