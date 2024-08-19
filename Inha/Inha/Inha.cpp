#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <iterator>
#include "StopWatch.h"
using namespace std;

/*
Q2. 단순 삽입 정렬 구현
	p.227 Q8처럼 정렬 과정을 표현하라.

*/

#define MAX 7

int nums[MAX] = { 6, 4, 8, 5, 2, 9, 7 };


void printArray(int num[], int in, int out)
{
	for (int i = 0; i < MAX; i++)
	{
		cout << num[i] << " ";
	}
	cout << "\n";
	for (int i = 0; i < MAX; i++)
	{
		if (i == in)
			cout << "+";
		else if (i == out)
			cout << "^-";
		else if (i < in && i > out)
			cout << "--";
		else cout << "  ";
	}

	cout << endl;

}

void insertSort()
{
	int j = 0;
	int tempnums[MAX];

	for (int i = 1; i < MAX; i++)
	{
		copy(begin(nums), end(nums), tempnums);
		int temp = nums[i];
		for (j = i; j > 0 && nums[j - 1] > temp; j--)
		{
			nums[j] = nums[j - 1];
		}
		printArray(tempnums, i, j);
		nums[j] = temp;
	}

}

int main()
{
	insertSort();
}