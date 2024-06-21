#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q4. Factorial 계산... 어떤 양의 정수 n을 입력받아서
	n! 을 구하는 프로그램을 작성하라.
	ex) 3! -> 3 * 2 * 1  ==> 6
*/

int main()
{
	int n, result;
	scanf("%d", &n);
	result = n;
	while (n > 1) {
		n--;
		result *= n;
	}
	printf("%d\n", result);
}