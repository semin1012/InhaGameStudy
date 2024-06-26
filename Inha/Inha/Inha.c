#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>
#include <Windows.h>

/*
Q1. 길이가 5인 int형 배열을 선언하고,
	사용자로부터 5개의 정수를 입력받아
	다음의 내용을 출력하는 프로그램을 작성하라.
	1. 입력된 정수 중 최대값
	2. 입력된 정수 중 최소값
	3. 입력된 정수들의 총 합

p.260  대소문자 변환 프로그램

Q2. 문자열을 입력받아서 광고판에 광고 문자가 출력되는
	프로그램을 출력하라.
	문자열 흘러가듯이 출력되는 형태로 구현하라. 
	ex) -> Hello
	> Hello
	> ello H
	> llo He
	조건 1. 최대 127자까지 입력 가능하다. 
	조건 2. 광고판의 크기는 최대 20자까지 출력 가능하다.

*/

#define MAX 128

int main()
{
	char str[MAX];
	printf("내용을 입력하세요: ");
	gets(str);
	bool change = false;
	int idx = 0;
	char temp[MAX];
	while (1)
	{
		system("cls");

		strcpy(temp, str);
		for (int i = 1; i < MAX; i++) {
			if (str[i + 1] == '\0') {
				str[i + 1] = ' ';
				for (int j = 1; j < MAX - i; j++)
					str[i + 1 + j] = temp[j - 1];
			}
			str[i - 1] = str[i];
		}

		for (int i = 0; i <= 20; i++) {
			printf("%c", str[i]);
		}

		
		Sleep(500);
	}
}