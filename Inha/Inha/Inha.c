#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>
#include <limits.h> // MAX, MIN 값을 자동으로 출력해주는 헤더
#include <string.h>

/*
Q1. 길이가 5인 int형 배열을 선언하고,
	사용자로부터 5개의 정수를 입력받아
	다음의 내용을 출력하는 프로그램을 작성하라.
	1. 입력된 정수 중 최대값
	2. 입력된 정수 중 최소값
	3. 입력된 정수들의 총 합

p.260  대소문자 변환 프로그램

*/

int main()
{
	char str[100];
	int change = 0;
	printf("문장 입력: ");
	gets(str);

	for (int i = 0; i < 100; i++) 
	{
		if (str[i] == '\0')
			break;
		if (str[i] >= 65 && str[i] <= 90) 
		{
			str[i] = str[i] + 32;
			change++;
		}
	}

	printf("바뀐 문장: ");
	puts(str);
	printf("바뀐 문자 수: %d", change);
}