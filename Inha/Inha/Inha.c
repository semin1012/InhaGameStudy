#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
Q1. 1이상 100 미만인 정수중 M, N의 배수를 출력하라.
	단, M의 배수이면서 N의 배수인 정수는 한번만 출력하도록 한다.
*/
/*
Q2. 임의의 N을 입력 받아서 다음과 같은 형태로 출력하도록 하라.
	ex) N = 5
	* 
	**
	***
	****
	*****
	****
	***
	**
	* 

Q4. 임의의 N을 입력받아서 다음과 같은 형태로 출력하도록 하라.
	ex) N = 3
	* *
	 *
	* *
	ex) N = 4
	*  *
	 **
	 **
	*  *
*/

int main()
{
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
		{
			if (j == i || j == n - 1 - i)
				printf("*");
			else printf(" ");
		}
		printf("\n");
	}
}