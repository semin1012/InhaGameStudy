#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include "StopWatch.h"
#define MAX 10
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

void MergeSort(int left, int right)
{
	if (left >= right)
		return;

	int pivot = (left + right) / 2;

	MergeSort(left, pivot);
	MergeSort(pivot + 1, right);

	cout << "merge" << endl;
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
	MergeSort(0, MAX);
	//PrintNums();
	timer.stop();

	cout << "------ 퀵 정렬 ------\n";
	cout << "데이터 수: " << MAX << "개, 소요 시간: " << timer.getElpasedTime() << "\n";
}