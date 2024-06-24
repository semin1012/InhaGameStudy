#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdbool.h>

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

Q5. 다음 식을 만족하는 모든 A와 Z를 구하는 프로그램을 작성하라.
	단, N은 10 미만의 정수이다.
		A Z
	+	Z A
	--------
		N N
	ex) N = 9
		A Z		6 3
		Z A		3 6
	-------- -------
		9 9		9 9

	=> A = 0	Z = 9
	=> A = 1	Z = 8
	   ......
	=> A = 9	Z = 0

Q. 소수 출력 프로그램 
*/

int main()
{
	int n;
	scanf("%d", &n);
	printf("N 은 %d 입니다.\n", n);
	for (int i = 0; i <= n; i++) {
		printf("A = %d  Z = %d\n", i, n - i);
	}
}