#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q1. 1이상 100 미만인 정수중 M, N의 배수를 출력하라.
	단, M의 배수이면서 N의 배수인 정수는 한번만 출력하도록 한다.
*/
/*
Q2. 임의의 N을 입력 받아서 다음과 같은 형태로 출력하도록 하라.
	ex) N = 5
	* 
	**
	***
	****
	*****
	****
	***
	**
	* 
*/

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for ( int j = 0 ; j < i ; j++ )
			printf("*");
		printf("\n");
	}
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n -i; j++)
			printf("*");
		printf("\n");
	}
}

//int main() {
//	int M = 0, N = 0, a = 0, b = 0, i = 0;
//	printf("M과 N을 입력하세요: ");
//	scanf("%d%d", &M, &N);
//
//	for (int i = 1; i < 100; i++) {
//		if (i % M == 0 || i % N == 0)
//			printf("%d ", i);
//	}
//}