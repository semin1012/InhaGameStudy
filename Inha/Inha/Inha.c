#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

/*
// 예제 8-1
int main()
{
	int ary[5];

	ary[0] = 10;
	ary[1] = 20;
	ary[2] = ary[0] + ary[1];
	scanf("%d", &ary[3]);

	printf("%d\n", ary[2]);
	printf("%d\n", ary[3]);
	printf("%d\n", ary[4]);
}
*/
// 예제 8-2
int main()
{
	int score[5];
	int i;
	int total = 0;
	double avg;

	for (i = 0; i < 5; i++)
	{
		scanf("%d", &score[i]);
	}
	for (i = 0; i < 5; i++)
	{
		total += score[i];
	}
	avg = total / 5.0;
	for (i = 0; i < 5; i++)
	{
		printf("%5d ", score[i]);
	}
	printf("\n");

	printf("평균: %.1lf\n", avg);

	return 0;
}