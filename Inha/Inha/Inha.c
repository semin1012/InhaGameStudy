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

// 예제 14-?
int main()
{
	int ary1[4] = { 1, 2, 3, 4 };
	int ary2[4] = { 11, 12, 13, 14 };
	int ary3[4] = { 21, 22, 23, 24 };
	int* pary[3] = { ary1, ary2, ary3, };
	int i, j;
	
	int maxJ = sizeof(ary1[0]);
	int maxI = sizeof(pary) / maxJ;

	for (i = 0; i < maxI; i++)
	{
		for (j = 0; j < maxJ; j++)
		{
			printf("%5d", pary[i][j]);
		}
		printf("\n");
	}

	printf("\n-----------------주소-----------------\n\n");

	for (i = 0; i < 3; i++)
	{
		printf("pary[%d]: %p, %x\n", i, pary[i], pary[i]);
		printf("ary1[%d]: %p, %x\n", i, &ary1[i], &ary1[i]);
		printf("\n");
	}
}
// 예제 15-1
int main()
{
	int a = 10;
	int* pi;
	int** ppi;

	pi = &a;
	ppi = &pi;

	printf("----------------------------------------------------\n");
	printf("  변수    변수값      &연산      *연산      **연산 \n");
	printf("----------------------------------------------------\n");
	printf("  a%12d%12u\n", a, &a);
	printf(" pi%12u%12u%12d\n", pi, &pi, *pi);
	printf("ppi%12u%12u%12u%12u\n", ppi, &ppi, *ppi, **ppi);
}
// 예제 15-2
void swap_ptr(char** ppa, char** ppb);

int main()
{
	char* pa = "success";
	char* pb = "failure";

	printf("pa -> %s, pb -> %s\n", pa, pb);
	swap_ptr(&pa, &pb);
	printf("pa -> %s, pb -> %s\n", pa, pb);
}

void swap_ptr(char** ppa, char** ppb)
{
	char* pt;
	pt = *ppa;
	*ppa = *ppb;
	*ppb = pt;
}
// 예제 15-4
int main()
{
	int ary[5];
	printf("  ary의 값: %u\t", ary);
	printf("ary의 주소: %u\n", &ary);
	printf("   ary + 1: %u\t", ary + 1);
	printf("  &ary + 1: %u\n", &ary + 1);
}
*/
// 배열 포인터
int main()
{
	int* pAry[5];
	int(*pa)[4];	//배열 포인터
}