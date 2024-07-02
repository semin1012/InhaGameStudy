#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
//예제 14-3
void assign10(void);
void assign20(void);

int a;

int main()
{
	printf("함수 호출 전 a 값: %d\n", a);

	assign10();
	assign20();

	printf("함수 호출 후 a 값:%d\n", a);
}

void assign10(void)
{
	a = 10;
}

void assign20(void)
{
	int a;
	a = 20;
}
// 예제 13-5
void auto_func(void);
void static_func(void);

int main()
{
	int i;

	printf("일반 지역 변수(auto)를 사용한 함수...\n");
	for (i = 0; i < 3; i++)
	{
		auto_func();
	}

	printf("정적 지역 변수(static)를 사용한 함수...\n");
	for (i = 0; i < 3; i++)
	{
		static_func();
	}
}

void auto_func(void)
{
	auto int a = 0;

	a++;
	printf("%d\n", a);
}

void static_func(void)
{
	static int a;

	a++;
	printf("%d\n", a);
}
// 예제 13-6
int* sum(int a, int b);

int main(void)
{
	int* resp;

	resp = sum(10, 20);
	int* resp2 = sum(50, 20);
	printf("두 정수의 합: %d\n", *resp);
}

int* sum(int a, int b)
{
	int res;
	res = a + b;
	return &res;
}
// 예제 14-2
int main()
{
	int num[3][4] = {
		1, 2,
		5, 6, 7, 8,
		9, 10, 11, 12
	};

	int i, j;
	for (i = 0; i < 3; i++) 
	{
		for (j = 0; j < 4; j++)
		{
			printf("%5d", num[i][j]);
		}
		printf("\n");
	}
}
// 예제 14-3
int main()
{
	char animals[5][20];
	int i;
	int count;

	count = sizeof(animals) / sizeof(animals[0]);
	for (i = 0; i < count; i++)
	{
		scanf("%s", animals[i]);
	}
	for (i = 0; i < count; i++)
	{
		printf("%s  ", animals[i]);
	}
}
*/
// 예제 14-5
int main()
{
	int score[4][3][2] = {
		72, 80, 95, 60, 68, 98, 83, 90, 75, 72, 84, 90,
		66, 85, 90, 88, 95, 92, 88, 95, 43, 72, 56, 75
	};

	int i, j, k;

	for (i = 0; i < 2; i++)
	{
		printf("%d반 점수...\n", i + 1);
		for (j = 0; j < 3; j++)
		{
			for (k = 0; k < 4; k++)
			{
				printf("%5d ", score[i][j][k]);
			}
			printf("\n");
		}
		printf("\n");
	}
}