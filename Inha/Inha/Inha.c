#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더

/*
Q1. 길이가 5인 int형 배열을 선언하고,
	사용자로부터 5개의 정수를 입력받아
	다음의 내용을 출력하는 프로그램을 작성하라.
	1. 입력된 정수 중 최대값
	2. 입력된 정수 중 최소값
	3. 입력된 정수들의 총 합
*/

int main()
{
	int arr[5];
	int max = INT_MIN, min = INT_MAX, sum = 0;

	for (int i = 0; i < 5; i++)
	{
		printf("정수를 입력하세요: ");
		scanf("%d", &arr[i]);
		if (max < arr[i])
			max = arr[i];
		if (min > arr[i])
			min = arr[i];
		sum += arr[i];
	}
	printf("\n입력된 정수 중 최대값: %d\n", max);
	printf("입력된 정수 중 최소값: %d\n", min);
	printf("입력된 정수들의 총합: %d\n", sum);
}