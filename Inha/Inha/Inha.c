#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q7. 사용자로부터 정수를 입력받아 그 값을 계속
	더해 나간다. 사용자가 0을 입력할 때까지
	계속되어야 하며, 0이 입력되면 입력된 모든 
	정수의 합을 출력한다.
	ex >	정수를 입력하시오: 4
			정수를 입력하시오: 3
			정수를 입력하시오: 0
			입력한 정수의 합은 7 입니다.
*/

int main()
{
	int a, sum = 0;
	do {
		printf("정수를 입력하시오: ");
		scanf("%d", &a);
		sum += a;
	} while (a != 0);
	printf("\n입력한 정수의 합은 %d 입니다. \n", sum);
}