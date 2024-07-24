#define _CRT_SECURE_NO_WARNINGS
/*
*/
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>
using namespace std;

// 방법 1. 2 ~ (n-1)
// 방법 2. 2 ~ (n-1) 사이의 홀수로만 계산
// 방법 3. 소수로만 계산
// 방법 4. 소수로 계산하면서, 자신의 숫자보다 큰 소수는 계산 안 함

/*
Q1. 소수를 판별하는 프로그램을 작성하고 개선하라.
	1. 1씩 증가하면서 소수 판단
	2. 홀수로만 계산하기
	3. 홀수 + 이전 계산된 소수로 나누어지지 않는 수
	4. 제곱근 n 이하의 모든 소수로 나누었을 때 나누어 떨어지지 않는 수
	   + 이전에 계산된 소수로 나누어지지 않는 수

	순서도 그리기 
	실행한 횟수 카운트 출력 - 각 케이스마다 몇 번을 계산했는지 cnt를 출력
	각각의 알고리즘에 성능 체크 - 시간 측정, 10만번 정도 돌려 보기
*/

int temp1[500'000] = { 2, 0, }; // 최대 오십만번 계산할 수 있도록 크기 지정, 2는 넣고 시작
int temp2[500'000] = { 2, 0, };

/*
	방법 1. 1씩 증가하면서 소수 판단
	반환: 계산된 횟수 cnt
*/
long long firstCase(int n)
{
	long long cnt = 0;
	bool isDecimal = true;
	for (int i = 2; i < n; i++)
	{
		isDecimal = true;
		for (int j = 2; j < i; j++)
		{
			cnt++;
			if (i % j == 0) {
				isDecimal = false;
				break;
			}
		}
		if (isDecimal == true);
			//printf("%d ", i);
	}
	//printf("\n");
	return cnt;
}

/*
	방법 2. 홀수로만 계산하기 (짝수면 소수 아님)
	반환: 계산된 횟수 cnt
*/
long long secondCase(int n)
{
	long long cnt = 0;
	bool isDecimal = true;
	//printf("%d ", 2);
	for (int i = 3; i < n; i+=2)
	{
		isDecimal = true;
		for (int j = 3; j < i; j+=2)
		{
			cnt++;
			if (i % j == 0) {
				isDecimal = false;
				break;
			}
		}
		if (isDecimal == true);
			//printf("%d ", i);
	}
	//printf("\n");
	return cnt;
}

/*
	방법 3. 홀수 + 이전 계산된 소수로 나누어지지 않는 수
	반환: 계산된 횟수 cnt
*/
long thirdCase(int n)
{
	long cnt = 0;
	int index = 1;
	bool isDecimal = true;
	//printf("%d ", 2);
	for (int i = 3; i < n; i += 2)
	{
		isDecimal = true;
		for (int j = 0; j < index; j++)
		{
			cnt++;
			if (i % temp1[j] == 0) {
				isDecimal = false;
				break;
			}
		}

		if (isDecimal == true)
		{
			//printf("%d ", i);
			temp1[index++] = i;
		}
	}
	//printf("\n");
	return cnt;
}

/*
	방법 4. 제곱근 n 이하의 모든 소수로 나누었을 때 나누어 떨어지지 않는 수
			+ 이전에 계산된 소수로 나누어지지 않는 수
	반환: 계산된 횟수 cnt
*/
long fourthCase(int n)
{
	long cnt = 0;
	int index = 1;
	int root = sqrt(n);
	bool isDecimal = true;
	//printf("%d ", 2);
	for (int i = 3; i <= n - 1; i+=2)
	{
		isDecimal = true;
		if (i == 2); //printf("%d ", i);
		if (i % 2 == 0) continue;		// 짝수면 계산 안 하도록

		for (int j = 0; j < index; j++)
		{
			cnt++;
			if (i % temp2[j] == 0) {
				isDecimal = false;
				break;
			}
		}

		if (isDecimal == true)
		{
			//printf("%d ", i);
			if( i <= root )			// n의 제곱근 이하일 때만 소수 저장
				temp2[index++] = i;
		}
	}
	//printf("\n");
	return cnt;

}

int main()
{
	int n;
	long long count = 0;
	clock_t start, end;
	float res;
	printf("n 을 입력하세요: ");
	scanf("%d", &n);

	
	/* case 1 시간 측정 */
	start = clock();
	count = firstCase(n);	// 방법 1로 계산
	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;
	printf("case 1:: 소요 시간: %.2f, 계산 횟수: %lld\n", res, count);

	/* case 2 시간 측정 */
	count = 0;
	start = clock();
	count = secondCase(n);	// 방법 2로 계산
	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;
	printf("case 2:: 소요 시간: %.2f, 계산 횟수: %lld\n", res, count);


	/* case 3 시간 측정 */
	count = 0;
	start = clock();
	count = thirdCase(n);	// 방법 3로 계산
	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;
	printf("case 3:: 소요 시간: %.2f, 계산 횟수: %lld\n", res, count);


	/* case 4 시간 측정 */
	count = 0;
	start = clock();
	count = fourthCase(n);	// 방법 4로 계산
	end = clock();
	res = (float)(end - start) / CLOCKS_PER_SEC;
	printf("case 4:: 소요 시간: %.2f, 계산 횟수: %lld\n", res, count);
}