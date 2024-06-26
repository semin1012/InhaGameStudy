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
*/

/*
// 예제 8-4
int main()
{
	char str[80] = "applejam";
	printf("최초 문자열: %s\n", str);
	printf("문자열 입력: ");
	scanf("%s", str);
	printf("입력 후 문자열: %s\n", str);
}
// 예제 8-5
int main()
{
	char str1[80] = "cat";
	char str2[80];

	strcpy(str1, "tiger");
	strcpy(str2, str1);
	printf("%s, %s\n", str1, str2);
}
*/

int main()
{
	int a = 10;
	int b;
	b = a;
	printf("a: %d, b: %d", &a, &b);
}