#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q1. 다음과 같이 A행렬의 행렬 B를 구현하라.
	ex>
	A 행렬					B 행렬
		1 2 3 4				5 1
		5 6 7 8		=>		6 2
							7 3
							8 4

	A 행렬					B 행렬
		1 2 3				7 4 1
		4 5 6		=>		8 5 2
		7 8 9				9 6 3

#define ROW 2
#define COL 4
#define MAX 3

void matrixTransformation(int* a, int* result, int row, int col);
void matrixPrint(int* a, int row, int col);

int main()
{
	int a[ROW][COL] = { 1, 2, 3, 4, 5, 6, 7, 8 };
	int b[MAX][MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int a_result[COL][ROW];
	int b_result[MAX][MAX];

	matrixTransformation(&a, &a_result, COL, ROW);
	matrixPrint(&a_result, COL, ROW);
	printf("\n");
	matrixTransformation(&b, & b_result, MAX, MAX);
	matrixPrint(&b_result, MAX, MAX);
	
}

void matrixTransformation(int* a, int* result, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(result + i * col + j) = *(a +(col-1-j)*row + i);
		}
	}
}

void matrixPrint(int* a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(a + i * col + j));
		}
		printf("\n");
	}
}
*/



/*
Q2. n x n 행렬에 대해서 전치행렬을 구하라.
	ex>
		A 행렬				B 행렬
		1 2 3				1 4 7
		4 5 6		=>		2 5 8
		7 8 9				3 6 9
*/
#define MAX 3

void transpose(int* a, int* result, int col, int row);
void printMatrix(int* a, int row, int col);

int main()
{
	int a[MAX][MAX] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int b[MAX][MAX];
	transpose(&a, &b, MAX, MAX);
	printMatrix(&b, MAX, MAX);
}

void transpose(int* a, int* result, int col, int row)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			*(result+i*row+j) = *(a+j*row+i);
		}
	}
}

void printMatrix(int* a, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			printf("%d ", *(a + i * col + j));
		}
		printf("\n");
	}
}