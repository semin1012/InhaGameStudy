#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include <cstring>
#include "StopWatch.h"

#define MAX 1'000'000
#define MAX_INT 10000
using namespace std;

int nums[MAX];
int arr1[MAX], arr2[MAX];

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintNums(int arr[])
{
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void QuickSort(int arr[], int left, int right)
{
	int pivot = arr[(left + right + 1) / 2];
	int pl = left;
	int pr = right;

	while (pl <= pr)
	{
		while (arr[pl] < pivot) pl++;
		while (arr[pr] > pivot) pr--;
		if (pl <= pr)
		{
			Swap(arr[pl], arr[pr]);
			pl++;
			pr--;
		}
	}

	if (left < pr) QuickSort(arr, left, pr);
	if (right > pl) QuickSort(arr, pl, right);
}

void PrintCountingSort(int arr[])
{
	for (int i = 0; i < MAX_INT; i++)
	{
		for (int j = 0; j < arr[i]; j++)
		{
			//cout << i+1 << " ";
		}
	}
	//cout << "\n";
}

void CountingSort(int arr[])
{
	int *newArr = new int[MAX_INT];
	memset(newArr, 0, sizeof(int) * MAX_INT);

	for (int i = 0; i < MAX; i++)
	{
		newArr[arr[i] - 1] += 1;
	}

	PrintCountingSort(newArr);
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < MAX; i++)
		nums[i] = rand() % 5 + 1;

	StopWatch timer;
	copy(nums, nums + MAX, arr1);
	copy(nums, nums + MAX, arr2);

	cout << "Quick Sort\n";
	timer.start();
	QuickSort(arr1, 0, MAX - 1);
	timer.stop();

	cout << "------ 퀵 정렬 ------\n";
	cout << "데이터 수: " << MAX << "개, 소요 시간: " << timer.getElpasedTime() << "\n";
	
	cout << "\nCounting Sort\n";
	timer.start();
	CountingSort(arr2);
	timer.stop();

	cout << "------ 계수 정렬 ------\n";
	cout << "데이터 수: " << MAX << "개, 1부터 " << MAX_INT << "의 값까지, 소요 시간: " << timer.getElpasedTime() << "\n";
}