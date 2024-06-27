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

Q2. 길이가 6인 int형 배열을 선언하고, 1,2,3,4,5,6 으로 초기화한 다음 
	배열에 저장된 값의 순서가 반대로 6,5,4,3,2,1 이 되도록 변경하는
	프로그램을 작성하라.
	포인터를 활용하라.

Q3. 임의의 문자열을 입력받아 뒤집어 출력하는 프로그램을 작성하라.
	ex > 
		Input	> Hello World 
		Output	> dlroW olleH
*/

#define MAX 6

void reverseInt(int n[], int* pn)
{
}

int main()
{
	int n[MAX] = { 1,2,3,4,5,6 };
	int* pn = n;
	int temp;

	for (int i = 0; i < (MAX+1)/2; i++) {
		temp = *(pn + i);
		*(pn + i) = *(pn + MAX - i - 1);
		*(pn + MAX - i - 1) = temp;
	}
	for (int i = 0; i < MAX; i++)
		printf("%d ", n[i]);

	printf("\n\n문자열을 입력하세요: ");
	char str[128];
	char* pstr = str;

	gets(str);
	int length = strlen(str);

	for (int i = 0; i < (length + 1) / 2; i++) {
		temp = *(pstr + length -1 -i);
		*(pstr+length - 1 - i) = *(pstr + i);
		*(pstr+i) = temp;
	}
	for (int i = 0; i < length; i++)
		printf("%c", str[i]);
}