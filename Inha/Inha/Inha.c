#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>
#include <conio.h>

/*
Q1. 문자열을 입력받아서 광고판에 광고 문자가 출력되는
	프로그램을 출력하라.
	문자열 흘러가듯이 출력되는 형태로 구현하라.
	ex) -> Hello
	> Hello
	> ello H
	> llo He
	조건 1. 최대 127자까지 입력 가능하다.
	조건 2. 광고판의 크기는 최대 20자까지 출력 가능하다.

	<< 포인터를 사용해 보자! >>

*/

#define MAX 128

void init(char *str, int *length, int *j)
{
	printf("내용을 입력하세요: ");
	gets(str);

	*length = strlen(str);
	str[*length] = ' ';
	str[*length + 1] = '\0';
	*j = 0;
}

int main()
{
	char str[MAX];
	int length = 0, j = 0;
	char* temp = &str;
	
	init(str, &length, &j);

	while (1)
	{
		system("cls");

		for (int i = 0; i < 20; i++) {
			printf("%c", temp[(i+j)%(length+1)]);
		}
		j++;

		printf("\n\n문자를 입력하면 내용을 다시 입력합니다.\n");
		Sleep(300);

		if (_kbhit())   // 아무키나 눌려지면 멈춥니다
		{
			system("cls");
			for (int i = 0; i < MAX; i++) 
				str[i] = '\0';

			init(str, &length, &j);
		}
	}
}