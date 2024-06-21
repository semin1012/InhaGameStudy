#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q6. 사용자로부터 양의 두 정수를 입력받아 (M, N)
	N개 만큼 M의 배수를 출력하는 프로그램을 작성하라.
*/

int main()
{
	int M, N;
	printf("M의 배수를 N개 만큼 출력합니다.\nM과 N 입력: ");
	scanf("%d%d", &M, &N);
	for (int i = 1; i <= N; i++) {
		printf("%d * %d = %d\n", M, i, M * i);
	}
}