#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q3. N x N 의 2차원 배열에 숫자가 다음과 같이 시계 방향으로
	채워지도록 프로그램을 작성하라.

	ex> N = 3
			1 2 3
			8 9 4
			7 6 5
*/




int main()
{
	int n;
	int arr[64][64] = { 0 };
	printf("> N: ");
	scanf("%d", &n);

	int num = 1;
	int cnt = 0;

	while(num <= n*n) {
		for (int i = cnt; i < n - cnt; i++) {
			int j = cnt;
			if (arr[j][i] == 0) {
				arr[j][i] = num;
				num++;
			}
		}

		for (int i = 0; i < n - cnt; i++) {
			int j = (n - 1) - cnt;
			if (arr[i][j] == 0) {
				arr[i][j] = num;
				num++;
			}
		}

		for (int i = n - 1 - cnt; i >= 0; i--) {
			int j = n - 1 - cnt;
			if (arr[j][i] == 0) {
				arr[j][i] = num;
				num++;
			}
		}

		for (int i = n - 1 - cnt; i >= 0; i--) {
			int j = cnt;
			if (arr[i][j] == 0) {
				arr[i][j] = num;
				num++;
			}
		}
		cnt++;
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%5d ", arr[i][j]);
		}
		printf("\n");
	}
}