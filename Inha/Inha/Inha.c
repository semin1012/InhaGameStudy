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
*/


void AZZA();
void isDicimal();
void calculator();
float calculator_operation(int a, char b, int c);
void calculator_output(int a, char b, int c, float result);


int main()
{
	int p;
	while (1)
	{
		printf("1: AZ ZA   2: 소수 구하기   3: 사칙 연산 프로그램   0: 종료\n");
		printf("프로그램을 선택해주세요: ");
		scanf("%d", &p);
		switch (p) {
		case 1:
			AZZA();
			break;
		case 2:
			isDicimal();
			break;
		case 3:
			calculator();
			break;
		case 0:
			return 0;
		}
	}
}

void isDicimal()
{
	int n;
	printf("\n100 이하의 정수를 입력하세요: ");
	scanf("%d", &n);
	bool check;
	int col = 0;
	for (int i = 2; i <= n; i++)
	{
		check = true;
		for (int j = 2; j < i; j++)
		{
			if (i % j == 0) {
				check = false;
				break;
			}
		}
		if (check == true) {
			printf("%5d ", i);
			col++;
			if (col % 5 == 0)
				printf("\n");
		}
	}
	printf("\n");
}

void AZZA()
{
	int n;
	printf("\n10 미만의 정수를 입력해 주세요:  ");
	scanf("%d", &n);
	for (int i = 0; i <= n; i++) {
		printf("%2d + %2d = %2d\n", i, n, i + n);
	}
	printf("\n");
}


void calculator()
{
	int a1, a2;
	char c;
	printf("공백 없는 수식을 입력하세요: ");
	scanf("%d%c%d", &a1, &c, &a2);
	float result = calculator_operation(a1, c, a2);

	calculator_output(a1, c, a2, result);
}

float calculator_operation(int a, char b, int c)
{
	float result;
	if (b == '+')
	{
		result = a + c;
	}
	else if (b == '-')
	{
		result = a - c;
	}
	else if (b == '*')
	{
		result = a * c;
	}
	else if (b == '/')
	{
		result = (float)a / c;
	}
	else printf("다시 입력하세요. \n");

	return result;
}

void calculator_output(int a, char b, int c, float result)
{
	printf("%d %c %d = %.1f\n\n", a, b, c, result);
}
