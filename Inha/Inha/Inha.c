#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q5. 두 정수를 입력받아 두 수 사이에 존재하는 정수의
	합을 구하는 프로그램을 작성하라.
	ex) 3 5 -> 3+4+5 => 12
*/

int main()
{
	int a, b, sum=0;
	scanf("%d%d", &a, &b);
	if (b > a) {
		int temp = b;
		b = a;
		a = temp;
	}
	for (int i = b; i <= a; i++) {
		sum += i;
	}
	printf("합: %d\n", sum);
}