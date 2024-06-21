#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q4. 키보드로 수식을 입력하면 계산 결과를 출력하는
	프로그램을 작성하세요. 정수 사칙연산만 입력합니다. 
*/

int main()
{
	int a, b;
	double result = 0;
	char c;
	printf("사칙연산 입력(정수): ");
	scanf("%d%c%d", &a, &c, &b);
	switch (c) {
	case '+':
		result = a + b;
		break;
	case '-':
		result = a - b;
		break;
	case '*':
		result = a * b;
		break;
	case '/':
		result = (double)a / b;
		break;
	default:
		printf("Error\n");
		return 0;
	}
	if ( c != '/')
		printf("%d%c%d = %d", a, c, b, (int)result);
	else printf("%d%c%d = %.2lf", a, c, b, result);
}