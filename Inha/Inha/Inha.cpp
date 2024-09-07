#include <iostream>
#include <string>
#include <vector>
#include "StopWatch.h"
using namespace std;
#define MAX 10

int tempArr[MAX];

void MergeSort(int nums[], int left, int right)
{
	if (right - left <= 0)
		return;

	int mid = left + (right - left) / 2;
	int l = left;
	int m = mid + 1;
	int idx = left;

	MergeSort(nums, left, mid);
	MergeSort(nums, mid + 1, right);

	while ( l <= mid && m <= right )
	{
		if (nums[l] > nums[m])
		{
			tempArr[idx++] = nums[m++];
		}
		else
			tempArr[idx++] = nums[l++];
	}

	if (l <= mid )
	{
		while ( l <= mid )
			tempArr[idx++] = nums[l++];
	}
	else
	{
		while ( m <= right )
			tempArr[idx++] = nums[m++];
	}

	for (int i = left; i <= right; i++)
		nums[i] = tempArr[i];


	for (int i = 0; i <= right - left; i++)
		cout << nums[left + i] << " ";

	cout << endl;
}

int main()
{
	int nums[MAX] = { 5, 3, 1, 7, 2, 6, 4, 8, 9, 10 };

	MergeSort(nums, 0, MAX - 1);
}