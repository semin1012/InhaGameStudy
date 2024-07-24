#define _CRT_SECURE_NO_WARNINGS
/*
*/
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

#define SIZE 6

void printArray(int a[])
{
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d ", a[i]);
	}

	printf("\n");
}

void ary_reverse(int a[])
{
	int temp; 

	printArray(a);

	for (int i = 0; i < (SIZE + 1) / 2; i++)
	{
		printf("a[%d]과 a[%d]를 교환합니다.\n", i, SIZE-1-i);
		temp = a[i];
		a[i] = a[SIZE - 1 - i];
		a[SIZE - 1 - i] = temp;

		printArray(a);
	}

	printf("역순 정렬을 종료합니다.\n");
}

int main()
{
	int nums[SIZE] = { 5, 10, 73, 2, -5, 42 };

	ary_reverse(nums);
}