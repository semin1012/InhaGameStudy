#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
#include <time.h>
#include <chrono>
#include <limits>
using namespace std;

/*
Q1. p.557 문제 5, 6

Q2. 이진 검색 프로그램을 작성하라.
	p.122 연습 문제 4처럼 이진 검색 과정을 자세히 출력하라. 
	순서도 포함.
	선형검색과 이진검색의 속도를 비교하라.
*/

#define MAX 100'000

void LinearSearch(int nums[], long long find_num);
void BinarySearch(int nums[], long long find_num);

void ShowLinearSearch(int nums[], long long find_num);
void ShowBinarySearch(int nums[], long long find_num);

int nums[MAX];

int main()
{
	clock_t start, end;
	long long find_num;

	// 0~MAX-1 인덱스까지 1~MAX의 값을 넣는다 
	for (int i = 0; i < MAX; i++)
	{
		nums[i] = i + 1;
	}

	/*========================Binary Search========================*/
	start = clock();
	for (int i = 0; i < MAX; i++)
	{
		find_num = i + 1;
		BinarySearch(nums, find_num);
	}
	end = clock();
	cout << "Binary Search 시간: " << (double)(end - start)/CLOCKS_PER_SEC << " ms" << endl;


	clock_t start1, end1;
	/*========================Linear Search========================*/
	start1 = clock();
	for (int i = 0; i < MAX; i++)
	{
		find_num = i + 1;
		LinearSearch(nums, find_num);
	}
	end1 = clock();
	cout << "Linear Search 시간: " << (double)(end1 - start1) / CLOCKS_PER_SEC << " ms" << endl << endl;

}

void LinearSearch(int nums[], long long find_num)
{
	for (int i = 0; i < MAX; i++)
	{
		if (nums[i] == find_num)
		{
			//cout << find_num << "은 nums[" << i << "]에 존재합니다.\n";
			return;
		}
	}
	//cout << find_num << "은 nums에 존재하지 않습니다.\n";
}

void BinarySearch(int nums[], long long find_num)
{
	int start = 0, end = MAX-1;

	while (start <= end)
	{
		int middle = (start + end) / 2;
		if (nums[middle] == find_num)
		{
			//cout << find_num << "은 nums[" << middle << "]에 존재합니다.\n";
			break;
		}
		else if (start == end)
		{
			//cout << find_num << "은 nums에 존재하지 않습니다.\n";
			break;
		}
		else if (find_num > nums[middle])
		{
			start = middle+1;
		}
		else if (find_num < nums[middle])
		{
			end = middle-1;
		}
	}
}

void ShowLinearSearch(int nums[], long long find_num)
{
	cout << "# LinearSearch #\n";
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < i; j++)
		{
			cout << "  ";
		}
		cout << "*\n";
		for (int j = 0; j < MAX; j++)
			cout << nums[j] << " ";
		cout << endl;
		if (nums[i] == find_num)
		{
			cout << find_num << "은 nums[" << i << "]에 존재합니다.\n";
			return;
		}
	}
	cout << find_num << "은 nums에 존재하지 않습니다.\n";
}

void ShowBinarySearch(int nums[], long long find_num)
{
	cout << "# BinarySearch #\n";
	int start = 0, middle = (MAX) / 2, end = MAX - 1;
	

	while (start <= end)
	{
		
		middle = (start + end) / 2;
		for (int i = 0; i < middle; i++)
		{
			cout << "   ";
		}
		cout << "*\n";
		for (int i = 0; i < MAX; i++)
		{
			printf("%2d ", nums[i]);
			//cout << nums[i] << " ";
		}
		cout << endl;
		if (nums[middle] == find_num)
		{
			cout << find_num << "은 nums[" << middle << "]에 존재합니다.\n";
			break;
		}
		else if (start == end)
		{
			cout << find_num << "은 nums에 존재하지 않습니다.\n";
			break;
		}
		else if (find_num > nums[middle])
		{
			start = middle + 1;
		}
		else if (find_num < nums[middle])
		{
			end = middle - 1;
		}
	}
}


	//while (start < end)
	//{
	//	if (nums[middle] == find_num)
	//	{
	//		cout << find_num << "은 nums[" << middle << "]에 존재합니다.\n";
	//		break;
	//	}
	//	else if (start == end)
	//	{
	//		cout << find_num << "은 nums에 존재하지 않습니다.\n";
	//		break;
	//	}
	//	else if (find_num > nums[middle])
	//	{
	//		start = middle;
	//		middle = middle + (end - middle+1) / 2;
	//	}
	//	else if (find_num < nums[middle])
	//	{
	//		end = middle;
	//		middle = start + (middle - start+1) / 2;
	//	}
	//}
