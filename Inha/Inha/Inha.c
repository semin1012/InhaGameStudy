#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q4. 다음과 같이 배열에 숫자가 채워지도록 프로그램을 작성하라.
	N x N 인 경우만 해당

	ex> N = 3
		1 2 6
		3 5 7
		4 8 9
*/

//		0,0  1
//		1,0  2
//		0,1  3
//		0,2  4
//		1,1  5 
//		2,0  6
//		2,1  7
//		1,2  8
//		2,2  9

int main()
{
	int n;
	printf("> n 입력: ");
	scanf("%d", &n);
	printf("\n");

	int num = 1;
	int i = 0, j = 0;
	int result[64][64] = { 0 };
	int dir = 0;

	while (num <= n * n) 
	{
		result[i][j] = num;

		// dir이 0이면 대각선 '위'로 올라감
		if (dir == 0) {
			// j+1 연산이 배열 크기를 벗어난다면 진행 안 하고 그 자리에서 내려감
			if (j+1 == n) {
				i++;
				num++;
				dir = 1;	// 방향도 바꿈
				continue;
			}
			// j가 n 이상이거나 i가 0 이하이면 해당 방향으로 더 못 가니까 방향 바꿔줌
			// 방향은 바꾸지만 오른쪽 or 위쪽은 갈 수 있는 방향이라면 ++, -- 연산함
			if (j < n)
				j++;
			else dir = 1;
			if (i > 0)
				i--;
			else dir = 1;
		}							
		// dir이 1이면 대각선 '아래'로 내려감
		else {
			// i+1 연산이 배열 크기를 벗어나면 진행 안 하고 그 자리에서 옆으로 감
			if (i + 1 == n)
			{
				j++;
				num++;
				dir = 0;
				continue;
			}
			// i가 n 이상이거나 j가 0 이하이면 해당 방향으로 더 못 가니까 방향 바꿔줌
			// 방향은 바꾸지만 왼쪽 or 아래쪽은 갈 수 있는 방향이라면 ++, -- 연산함
			if (i < n)
				i++;
			else dir = 0;
			if (j > 0)
				j--;
			else dir = 0;
		}
		num++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%2d ", result[i][j]);
		}
		printf("\n");
	}
}