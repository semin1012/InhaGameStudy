#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)


/*
p.343 길이가 가장 긴 단어 찾기
*/

#define MAX 128

int main()
{
	char ch;
	char temp[MAX];
	char result[MAX];
	int max = 0;
	int i = 0;

	while (1)
	{
		ch = getchar();
		if (ch == EOF) break;
		else if (ch != '\n')
		{
			temp[i++] = ch;
		}
		else 
		{
			if (max < (i)) 
			{
				max = i;
				strcpy(result, temp);
			}
			for (int j = 0; j < i; j++)
				temp[j] = '\0';
			i = 0;
		}
	}
	printf("가장 긴 단어의 길이: %d\n", max);
	printf("가장 긴 단어: %s\n", result);
}
