#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

/* 
Q1. 선형 검색을 하기 위한 기본 순서도와 이를 바탕으로
	선형 검색 프로그램을 작성컴퓨터 바탕화면 키우기하라.
	ex > 데이터 입력: 6 5 2 1 8 9 7 4
	검색 데이터 > 9
	> 자료 중에 9가 있습니다.
	검색 데이터 > 3
	> 자료 중에 3은 없습니다. 

	1. 선형 검색으로만
	2. p.120 Q2와 같은 형태로 검색 과정을 표시하라.
	3. 보초법을 이용하여 선형 검색을 수정하고 성능을 비교하라.
*/

/*
*/
#define SIZE 200'000'000

int nums[SIZE + 1];

void LinearSearch(int nums[], int find_num);
void SentinelLinearSearch(int nums[], int find_num);

int main()
{
	int find_num;
	clock_t start, end;
	float res;

	for (int i = 0; i < SIZE; i++)
	{
		nums[i] = i;	// 그냥 0부터 99'999까지 넣는다 
	}

	while (1)
	{
		cout << "검색 데이터 > ";
		cin >> find_num;

		// 1. 일반 선형 검색 
		start = clock();
		LinearSearch(nums, find_num);	
		end = clock();
		res = (float)(end - start) / CLOCKS_PER_SEC;
		printf("선형 검색 소요 시간: %.7f\n", res);


		// 2. 보초법
		nums[SIZE] = find_num;	// 보초법

		start = clock();
		SentinelLinearSearch(nums, find_num);
		end = clock();
		res = (float)(end - start) / CLOCKS_PER_SEC;
		printf("보초법 소요 시간: %.7f\n", res);

		cout << "\n\n";
	}
}

void LinearSearch(int nums[], int find_num)
{
	for (int i = 0; i < SIZE; i++)
	{
		if (nums[i] == find_num)
		{
			cout << "> 자료 중에 " << find_num << "이(가) 있습니다.\n";
			return;
		}

		if (i == SIZE - 1)
		{
			cout << "> 자료 중에 " << find_num << "은(는) 없습니다.\n";
			return;
		}
	}
}

void SentinelLinearSearch(int nums[], int find_num)
{
	int i = 0;
	for (i; i <= SIZE; i++)
	{
		if (nums[i] == find_num)
		{
			break;
		}
	}

	if ( i == SIZE ) cout << "> 자료 중에 " << find_num << "은(는) 없습니다.\n";
	else cout << "> 자료 중에 " << find_num << "이(가) 있습니다.\n";
}

/*
#define SIZE 8

void LinearSearch(int nums[], int find_num);

int main()
{
	int nums[SIZE] = { 6, 4, 3, 2, 1, 9, 8, 7 };
	int find_num;

	cout << "> 검색 데이터: ";
	cin >> find_num;
	
	LinearSearch(nums, find_num);
}

void LinearSearch(int nums[], int find_num)
{
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE; j++)
		{
			if (i == j) cout << "* ";
			else cout << "  ";
		}
		cout << "\n";

		for (int j = 0; j < SIZE; j++)
		{
			cout << nums[j] << " ";
		}
		cout << "\n";

		if (nums[i] == find_num)
		{
			cout << find_num << "은(는) nums[" << i  << "]에 존재합니다.\n";
			return;
		}

		if (i == SIZE - 1)
		{
			cout << "> 자료 중에 " << find_num << "은(는) 없습니다.\n";
			return;
		}
	}
}
*/