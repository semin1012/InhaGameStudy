#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include "StopWatch.h"
#define MAX 500'000
using namespace std;

int nums[MAX] = { 1, 6, 5, 7, 9, 4, 10, 8, 2, 3 };

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void PrintNums()
{
	for (int i = 0; i < MAX; i++)
	{
		cout << nums[i] << " ";
	}
	cout << "\n";
}


void QuickSort(int left, int right)
{
	int pivot = (left + right + 1) / 2;
	int pl = left;
	int pr = right;
	
	//cout << pivot << ", " << nums[pivot] << endl;
	while (pl <= pr)
	{
		while (nums[pl] < nums[pivot]) pl++;
		while (nums[pr] > nums[pivot]) pr--;
		if (pl <= pr)
		{
			Swap(nums[pl], nums[pr]);
			pl++;
			pr--;
			//PrintNums();
		}
	}

	if (left < pr) QuickSort(left, pr);
	if (right > pl) QuickSort(pl, right);
}

int main()
{
	srand(time(NULL));

	for (int i = 0; i < MAX; i++)
		nums[i] = i + 1;

	random_shuffle(begin(nums), end(nums));

	StopWatch timer;
	timer.start();
	//PrintNums();
	QuickSort(0, MAX - 1);
	//PrintNums();
	timer.stop();

	cout << "------ 퀵 정렬 ------\n";
	cout << "데이터 수: " << MAX << "개, 소요 시간: " << timer.getElpasedTime() << "\n";
}