#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
#include "StopWatch.h"
using namespace std;

/*
Q1. StopWatch class 설계
	다음의 내용을 포함하는 클래스를 설계하라.
	- get 함수를 갖는 데이터 필드 startTime과 endTime
	- startTime을 현재 시간으로 초기화하는 인수 없는 생성자
	- startTime을 현재 시간으로 재설정하는 start() 함수
	- endTime을 현재 시간으로 설정하는 stop() 함수
	- 스톱워치의 경과 시간을 밀리초(milliseconds)로 반환하는 
	  getElpasedTime() 함수
	- UML 클래스 다이어그램 작성
*/


#define MAX 5

StopWatch watch;

void Swap(int& a, int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void printArray(int arr[], int tempi, int tempj)
{
	for (int i = 0; i < MAX; i++)
	{
		if (i == tempi || i == tempj)
			cout << setw(2) << " * ";
		else cout << setw(2) << "   ";
	}

	cout << "\n";

	for (int i = 0; i < MAX; i++)
	{
		cout << setw(2) << arr[i] << " ";
	}
	cout << "\n";
}

void printArray(int arr[])
{
	for (int i = 0; i < MAX; i++)
	{
		cout << arr[i] << " ";
	}
	cout << "\n";
}

void bubbleSortUpgrade(int arr[])
{
	int path = 1;
	int count;
	int change;
	int compair = 0;

	for (int i = 0; i < MAX; i++)
	{
		//cout << "\n패스" << path << ", 비교: " << compair << "\n";
		count = 0;
		for (int j = MAX - 1; j > i; j--)
		{
			compair++;
			if (arr[j] < arr[j - 1])
			{
				Swap(arr[j], arr[j - 1]);
				count++;
				change = j - 1;
			}
			else change = -1;
		}
		path++;
		if (count == 0) break;
	}
	//printArray(arr);
}

void insertSort(int arr[])
{
	int min;
	int tempj;
	for (int i = 0; i < MAX; i++)
	{
		min = arr[i];
		tempj = i;
		for (int j = i + 1; j < MAX; j++)
		{
			if (min > arr[j])
			{
				min = arr[j];
				tempj = j;
			}
		}
		printArray(arr, i, tempj);
		Swap(arr[i], arr[tempj]);
	}
	//printArray(arr);
}

void insertSortUpgrade(int arr[])
{
	int min;
	int tempj;
	for (int i = 0; i < MAX; i++)
	{
		for (int j = i + 1; j < MAX; j++)
		{
			if (arr[i] > arr[j])
			{
				Swap(arr[i], arr[j]);
				tempj = j;
				printArray(arr, i, tempj);
			}
		}
	}
	//printArray(arr);
}

int main()
{

	int arr[MAX];
	int arrTemp[MAX];

	for (int i = 0; i < MAX; i++)
	{
		arr[i] = i+1;
	}

	random_shuffle(begin(arr), end(arr));

	//cout << "원본 데이터:\n";
	//printArray(arr);
	cout << "\n\n";

	copy(begin(arr), end(arr), begin(arrTemp));
	cout << "버블 정렬(개선 1):\n";
	watch.start();
	bubbleSortUpgrade(arrTemp);
	watch.stop();
	cout << "시간: " << watch.getElpasedTime() << " ms" << endl;

	watch.start();
	cout << "\n\n기존 단순 선택 정렬:\n";
	insertSort(arrTemp);
	watch.stop();
	cout << "시간: " << watch.getElpasedTime() << " ms" << endl;

	copy(begin(arr), end(arr), begin(arrTemp));
	cout << "\n\n";

	cout << "개선? 단순 선택 정렬:\n";
	watch.start();
	insertSortUpgrade(arrTemp);
	watch.stop();
	cout << "시간: " << watch.getElpasedTime() << " ms" << endl;

}