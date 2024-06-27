#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>
#include <conio.h>

/*
Q1. 문자열을 입력받아서 광고판에 광고 문자가 출력되는
	프로그램을 출력하라.
	문자열 흘러가듯이 출력되는 형태로 구현하라.
	ex) -> Hello
	> Hello
	> ello H
	> llo He
	조건 1. 최대 127자까지 입력 가능하다.
	조건 2. 광고판의 크기는 최대 20자까지 출력 가능하다.

	<< 포인터를 사용해 보자! >>

Q2. 길이가 6인 int형 배열을 선언하고, 1,2,3,4,5,6 으로 초기화한 다음 
	배열에 저장된 값의 순서가 반대로 6,5,4,3,2,1 이 되도록 변경하는
	프로그램을 작성하라.
	포인터를 활용하라.

Q3. 임의의 문자열을 입력받아 뒤집어 출력하는 프로그램을 작성하라.
	ex > 
		Input	> Hello World 
		Output	> dlroW olleH
*/

void input_ary(double* pa, int size);
double find_max(double* pa, int size);
void print_ary(double* pa, int size);

int main()
{
	double ary[5];
	double max;
	int size = sizeof(ary) / sizeof(ary[0]);

	input_ary(ary, size);
	max = find_max(ary, size);
	print_ary(ary, size);
	printf("배열의 최댓값: %.1lf\n", max);
	print_ary(ary, size);
}

void input_ary(double* pa, int size)
{
	int i;
	
	printf("%d개의 실수값 입력: ", size);
	for (int i = 0; i < size; i++)
	{
		scanf("%lf", pa + i);
	}
}

double find_max(double* pa, int size)
{
	double max;
	int i;

	max = pa[0];
	for (i = 1; i < size; i++)
	{
		if (pa[i] > max) max = pa[i];
	}

	return max;
}

void print_ary(double* pa, int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%.1lf ", pa[i]);
	}
	printf("\n");
}