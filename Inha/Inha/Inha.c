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

// 예제 7-2
/*int get_num(void);

int main()
{
	int result;
	result = get_num();
	printf("반환값: %d\n", result);
	return 0;
}

int get_num(void)
{
	int num;
	printf("양수 입력: ");
	scanf("%d", &num);

	return num;
}

// 예제 7-3
void print_star(char ch, int count);

int main(void)
{
	print_star('@', 5);
	return 0;
}

void print_star(char ch, int count)
{
	int i;
	for (i = 0; i < count; i++) 
	{
		printf("%c", ch);
	}
	return;
}
*/

// 예제 7-4
void print_line(void);

int main(void)
{
	print_line();
	printf("    학번        이름        전공        학점\n");
	print_line();

	return 0;
}

void print_line(void)
{
	for (int i = 0; i < 50; i++)
		printf("-");
	printf("\n");
	return;
}