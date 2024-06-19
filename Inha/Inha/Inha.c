#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/* 
Q1.	인간 수명이 100년 이라고 가정하고
	담배 한 개비를 피우면 수명이 3시간 40분
	단축된다고 한다.
	어떤 사람이 성인(20살로 가정)이 된 이후에 
	N년간 하루에 M 개피씩 담배를 피웠다면
	수명은 얼마나 단축되었고 몇 살까지 살 수 
	있는지를 계산하는 프로그램을 작성하시오.
	M, N은 입력 받도록 한다. 

	기준> N = 20, M = 3 
	
	결과 >
	줄어든 수명 : ?? 년 ?? 일 ?? 시 ?? 분 
	기대 수명 : ?? 살 ?? 일 ?? 시 ?? 분 
*/

void main()
{
	int m, n;
	scanf("%d%d", &m, &n);
	int res = n * 365 * m * (3 * 60 + 40);
	int min = res % 60;
	int h = (res / 60) % 24;
	int d = (res / 60 / 24) % 365;
	int y = (res / 60 / 24 / 365);
	
	const int a = 100 * 365 * 24 * 60;
	int pres = a - res;
	int pmin = pres % 60;
	int ph = (pres / 60) % 24;
	int pd = (pres / 60 / 24) % 365;
	int py = (pres / 60 / 24 / 365);

	printf("줄어든 수명: %d 년 %d 일 %d 시 %d 분\n", y, d, h, min);
	printf("기대 수명: %d 년 %d 일 %d 시 %d 분\n", py, pd, ph, pmin);
}