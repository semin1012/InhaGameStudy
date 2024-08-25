#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "StopWatch.h"
using namespace std;

// #define MAX 10

//int arr[MAX];

//int QuickSort(int left, int right)
//{
//	int i = left, j = right;
//	int pivot = arr[i];
//
//	while (i != j)
//	{
//		while ( arr[i] )
//		{
//
//		}
//		arr[i];
//
//		arr[j];
//	}
//}


bool isUsedDown[100];
bool isUsedRight[100];
bool isUsedLeft[100];
bool board[100][100];
int cnt = 0;

void Queen(int level, int n)
{
	if (level == n )
	{
		cnt++;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[i][j] == true)
				{
					cout << "●";
				}
				else cout << "○";
			}
			cout << endl;
		}
		cout << endl;
		return;
	}

	else
	{
		for (int i = 0; i < n; i++)
		{
			if (isUsedDown[i] == true || isUsedRight[level - i + n - 1] == true || isUsedLeft[level + i] == true)
			{
				continue;
			}
				

			isUsedDown[i] = true;
			isUsedRight[level - i + n - 1] = true;
			isUsedLeft[level + i] = true;

			board[level][i] = true;

			Queen(level + 1, n);

			isUsedDown[i] = false;
			isUsedRight[level - i + n - 1] = false;
			isUsedLeft[level + i] = false;

			board[level][i] = false;
		}
	}
}

int main()
{
	Queen(0, 5);
	cout << endl << "개수: " << cnt << endl;
}