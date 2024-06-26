#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>

/*
Q1. 길이가 5인 int형 배열을 선언하고,
	사용자로부터 5개의 정수를 입력받아
	다음의 내용을 출력하는 프로그램을 작성하라.
	1. 입력된 정수 중 최대값
	2. 입력된 정수 중 최소값
	3. 입력된 정수들의 총 합

p.260  대소문자 변환 프로그램

Q2. 문자열을 입력받아서 광고판에 광고 문자가 출력되는
	프로그램을 출력하라.
	문자열 흘러가듯이 출력되는 형태로 구현하라. 
	ex) -> Hello
	> Hello
	> ello H
	> llo He
	조건 1. 최대 127자까지 입력 가능하다. 
	조건 2. 광고판의 크기는 최대 20자까지 출력 가능하다.

*/

int main()
{
	int a = 10, b = 15, total;
	double avg;
	int* pa, *pb;
	int* pt = &total;
	double* pg = &avg;

	pa = &a;
	pb = &b;

	*pt = *pa + *pb;
	*pg = *pt / 2.0;

	printf("두 정수의 값: %d, %d\n", *pa, *pb);
	printf("두 정수의 합: %d\n", *pt);
	printf("두 정수의 평균: %.1lf\n", *pg);
}