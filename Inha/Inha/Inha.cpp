#include <iostream>
#include <algorithm>
#include <random>
#include <time.h>
#include "StopWatch.h"
#define MAX 50'000
using namespace std;

int nums[MAX];

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

void Heap(int idx, int lastIdx, bool isRight)
{
	if (idx > lastIdx) return;

	else if (idx == lastIdx)
	{
		if (nums[0] < nums[lastIdx]) 
			return;
		Swap(nums[0], nums[lastIdx]);
		return;
	}

	Heap(idx * 2 + 1, lastIdx, false);
	Heap(idx * 2 + 2, lastIdx, true);

	// 부모가 더 작다면 swap
	if (nums[(idx - 1) / 2] < nums[idx])
	{
		if (isRight)
		{
			// 형제가 나보다 더 크다면 형제가 부모랑 바뀌도록
			if (nums[idx - 1] > nums[idx])
			{
				Swap(nums[(idx - 1) / 2], nums[idx - 1]);
				return;
			}
		}
		Swap(nums[(idx - 1) / 2], nums[idx]);
	}
}

void HeapSort()
{
	int maxIdx = 0;

	for (int i = 1; i < MAX; i++)
		if (nums[maxIdx] < nums[i]) maxIdx = i;
	
	Swap(nums[0], nums[maxIdx]);

	for (int i = 0; i < MAX; i++)
		Heap(0, MAX - 1 - i, false);
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
	HeapSort();
	//PrintNums();
	timer.stop();

	cout << "------ 힙정렬 ------\n";
	cout << "데이터 수: " << MAX << "개, 소요 시간: " << timer.getElpasedTime() << "\n";
}