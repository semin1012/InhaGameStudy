#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>	// C언어에서의 bool 헤더
#include <limits.h>		// MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>	// system("cls")
#include <conio.h>		// Sleep(1000)

/*
Q1. 사용자로부터 문자열을 입력 받아서
	단어 단위로 역순으로 출력하는 프로그램을
	작성하라. "Quit"가 입력될 때까지 반복한다.

	ex>
		입력 > I am happy
		출력 > happy am I
		메모리 할당, 잘라서 카피(개수 알아야 함) 
*/

int main()
{
	char str[80];
	// char* pstr[20] = { 0 };
	char temp[80] = { 0 };
	int count = 0;
	int size = 2;
	char** pstr = (char**)calloc(size, sizeof(char));
	int i = 0;
	int j = 0;

	while (1)
	{
		printf("> ");
		gets(str);
		
		if (strcmp(str, "Quit") == 0) break;

		while(str[i] != '\0') {
			temp[j] = str[i];
			j++;
			i++;
			// 띄어쓰기 나오면
			if (str[i] == ' ') {
				if (size == count) {
					size += 5;
					printf("  size 변경, 현재 size: %d\n", size);
					pstr = (char**)realloc(pstr, size * sizeof(char));
				}

				temp[j] = '\0';
				pstr[count] = (char*)malloc(j + 1);
				// temp 내용을 pstr[count]에 저장
				strcpy(pstr[count], temp);
				count++;
				j = 0;
				i++; // 공백 넘어가기 위함
			}
		}

		// temp의 마지막 단어도 pstr[count]에 넣어주기
		temp[j] = '\0';
		pstr[count] = (char*)malloc(j + 1);
		strcpy(pstr[count], temp);


		// 바꾼 거 출력
		printf("> ");
		for (int i = 0; i <= count; i++)
		{
			printf("%s ", pstr[count - i]);
		}
		printf("\n  count: % d, size : % d\n", count, size);
		printf("\n");

		// 초기화
		count = 0;
		j = 0;
		i = 0;
	}
	for (int i = 0; pstr[i] != NULL ; i++)
	{
		free(pstr[i]);
	}
}