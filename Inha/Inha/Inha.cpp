#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "Rectangle2D.h"
using namespace std;

/*
Q1. n-Queen 문제
*/


//void NQueen(bool _board[][64], int n, int y)
//{
//	static int result = 0;
//	if (n == 1)
//	{
//		result++;
//		return;
//	}
//
//	// 대각선, 세로, 가로 못 가게 됨
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if ((y - 1 - i == y - 1 - j) || i == y - 1 || j == n - 1)
//			{
//				_board[i][j] = false;
//			}
//		}
//	}
//
//	// 세로로 1~n까지 다 검사해야 함
//	for (int i = 0; i < n; i++ )
//	{
//		if (_board[i][n-2] == true) // 갈 수 있음
//		{
//			NQueen(_board, n-1, i+1);
//		}
//	}
//
//	cout << result << endl;
//}

#define MAX 4

int board[MAX][MAX]{ true };

void PrintNQueen()
{
	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; j++)
		{
			if (board[i][j] == 1) cout << "■";
			else cout << "□";
		}
		cout << endl;
	}
}

void NQueen(int _board[][MAX], int x, int y, int n)
{
	static int result = 0;
	
	if (x == 1)
	{
		result++;
		PrintNQueen();
		cout << result << endl;
		return;
	}

	// N x N 크기니까 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (j == x - 1 && _board[i][j] != 1) _board[i][j] = -1;	// 가로 못 가게
			if (i == y - 1 && _board[i][j] != 1) _board[i][j] = -1;	// 세로 못 가게
			if (y - 1 + j == x - 1 + i && _board[i][j] != 1) _board[i][j] = -1; // 대각선 못 가게
			if (y - 1 - j == x - 1 - i && _board[i][j] != 1) _board[i][j] = -1; // 대각선 못 가게
		}
	}

	for (int i = 0; i < n; i++ )
	{
		if (_board[i][x-2] == 0) // 갈 수 있음
		{
			_board[i][x - 2] = 1;
			NQueen(_board, x-1, i+1, n);
		}
	}
} 


int main()
{
	int n = MAX;
	// cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		fill_n(board[0], MAX * MAX, 0);
		NQueen(board, n, n-i, n);
	}
}