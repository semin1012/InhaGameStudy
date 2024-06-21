#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q2. 두 개의 정수를 입력받아 두 수의 차를 출력하는 프로그램을
	작성하라.
	단, 무조건 큰 수에서 작은 수를 빼야 한다.
	ex) 12 5 -> 7
		4 16 -> 12
	case 1. if 문 이용
	case 2. 조건연산자 이용 
*/

// case 1. if문 이용
void main()
{
	int a, b, result;
	scanf("%d%d", &a, &b);
	if (a > b) result = a - b;
	else result = b - a;
	printf("result: %d", result);
}

// case 2. 조건연산자 이용 
//void main()
//{
//	int a, b, result;
//	scanf("%d%d", &a, &b);
//	result = (a > b) ? a - b : b - a;
//	printf("result: %d", result);
//}