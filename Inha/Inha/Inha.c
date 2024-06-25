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
*/

int my_abs(int a);

int main()
{
	int n;
	while (1) {
		printf("정수 입력: ");
		scanf("%d", &n);
		if (n == 0)
			return 0;
		printf("절대값: %d\n", my_abs(n));
		printf("종료하려면 0을 입력하세요.\n\n");
	}
}

int my_abs(int a) 
{
	return (a < 0) ? -a : a;
}