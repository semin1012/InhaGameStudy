#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>
#include <conio.h>

/*
p. 289 미니 정렬 프로그램

*/
void swap(double* pa, double* pb);
void line_up(double* maxp, double* midp, double* minp);

int main()
{
	double max, mid, min;

	printf("실수값 3개 입력: ");
	scanf("%lf%lf%lf", &max, &mid, &min);
	line_up(&max, &mid, &min);
	printf("정렬된 값 출력: %.1lf, %.1lf, %.1lf\n", max, mid, min);
}


void swap(double* pa, double* pb)
{
	double temp;

	temp = *pa;
	*pa = *pb;
	*pb = temp;
}

void line_up(double* maxp, double* midp, double* minp)
{
	if (*maxp < *midp) swap(maxp, midp);
	if (*maxp < *minp) swap(maxp, minp);

	if (*minp > *midp) swap(minp, midp);
}
